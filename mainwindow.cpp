#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "testcase.h"

#include <QCheckBox>
#include <QClipboard>
#include <QStack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setCentralWidget(ui->menu_tabs);

    this->createEditor();

}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::createEditor() {

    editor = new QWidget;
    editor->hide();
    editor->setWindowTitle(tr("Variable Editor"));

    // Create the main layout
    QFormLayout *editor_form = new QFormLayout(editor);
    createGenericEditorHeader(editor_form);
    createIntegerVariableBody(editor_form);
    createGenericEditorFooter(editor_form);

}

void MainWindow::createGenericEditorHeader(QFormLayout *editor_form) {

    QLabel *variable_name_label = new QLabel;
    variable_name_label->setText("Variable Name: ");
    QLineEdit *variable_name_editor = new QLineEdit;


    QLabel *variable_type_label = new QLabel;
    variable_type_label->setText("Variable Type: ");
    QComboBox *variable_type_combobox = new QComboBox;
    variable_type_combobox->addItem("Integer");
    variable_type_combobox->addItem("Simple String");
    variable_type_combobox->addItem("Input String");
    connect(variable_type_combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(updatedVariableType(int)));

    editor_form->addRow(variable_name_label, variable_name_editor);
    editor_form->addRow(variable_type_label, variable_type_combobox);

}

void MainWindow::createGenericEditorFooter(QFormLayout *editor_form) {

    QCheckBox *variable_const_box = new QCheckBox;
    variable_const_box->setText("Constant value");

    QPushButton *confirm_button = new QPushButton();
    confirm_button->setText("Confirm");

    editor_form->addRow(variable_const_box, confirm_button);

}

void MainWindow::createIntegerVariableBody(QFormLayout *editor_form) {

    QLabel *integer_start_value_label = new QLabel;
    integer_start_value_label->setText("Start Value: ");
    QSpinBox *integer_start_value = new QSpinBox;
    integer_start_value->setValue(0);

    QLabel *integer_increment_label = new QLabel;
    integer_increment_label->setText("Increment value: ");
    QSpinBox *integer_increment = new QSpinBox;
    integer_increment->setValue(1);

    editor_form->addRow(integer_start_value_label, integer_start_value);
    editor_form->addRow(integer_increment_label, integer_increment);

}

void MainWindow::createSimpleStringVariableBody(QFormLayout *editor_form) {

    QLabel *simple_string_label = new QLabel;
    simple_string_label->setText("String value: ");
    QLineEdit *simple_string = new QLineEdit;
    simple_string->setText("");

    QLabel *simple_string_increment_label = new QLabel;
    simple_string_increment_label->setText("Increment value: ");
    QSpinBox *simple_string_increment = new QSpinBox;
    simple_string_increment->setValue(1);

    editor_form->addRow(simple_string_label, simple_string);
    editor_form->addRow(simple_string_increment_label, simple_string_increment);

}

void MainWindow::createInputStringVariableBody(QFormLayout *editor_form) {



}

void MainWindow::updatedVariableType(int selected_index) {

    QFormLayout *layout = (QFormLayout *)sender()->parent();

    // Change the editor window to provide better options that match with the variable type

    // We remove rows until we get the 2 base rows from the header, then add the relevant sections
    /*
    while (layout->rowCount() > 2) {
        layout->removeRow(layout->rowCount()-1);
    }
    */

    layout->update();

    switch(selected_index) {
    case 0: {
        // Integer
        createIntegerVariableBody(layout);
        createGenericEditorFooter(layout);
    } break;
    case 1: {
        // Simple String
    } break;
    case 2: {
        // Input String
    } break;
    default: {
        // Do nothing on default
    }
    }


}

void MainWindow::on_generate_button_released()
{

    // Reset the output browser
    ui->output_browser->setText("");

    QString base_name = ui->name_line->text();
    QString base_command = ui->command_line->text();

    if (base_name == "" || base_command == "") {
        return;
    }

    ui->menu_tabs->setCurrentIndex(1);

    int iterations = ui->iterations_spin->value();
    for (int i {}; i < iterations; i++) {

        QString name = base_name;
        name.append("_");
        name.append(QString::number(i));

        //Here we need to generate the correct command based on the variable conditions
        QString command = base_command;
        // For each variable, append what should be the correct string data

        TestCase test_case = TestCase(name, command);
        // Now we want to append this line to the text area on tab 2
        ui->output_browser->append(test_case.toQString());

    }

}

void MainWindow::on_clear_button_released()
{

    // Reset all fields
    ui->name_line->setText("");
    ui->command_line->setText("");

    ui->iterations_spin->setValue(1);
    ui->variable_spin->setValue(0);

    ui->output_browser->setText("");

}

void MainWindow::on_variable_spin_valueChanged(int arg1)
{

    // Here the number on the spinner is bigger than the number of elements in variable_stack
    if (arg1 > variable_stack.length()) {

        while (arg1 > variable_stack.length()) {
            QListWidgetItem *created_item = new QListWidgetItem;
            variable_stack.push(new VariableDetailer(created_item));

            QString label_name = "Variable " + QString::number(variable_stack.length());

            variable_stack.top()->setLabelName(label_name);

            ui->listWidget->addItem(variable_stack.top()->getListItem());
        }

    } else {

        while (arg1 < variable_stack.length()) {
            variable_stack.pop();

            ui->listWidget->takeItem(variable_stack.length());
        }

    }

}

void MainWindow::on_copy_button_released()
{

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->output_browser->toPlainText());

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

    // Open a new window that edits the settings for the given variable
    editor->show();

}

