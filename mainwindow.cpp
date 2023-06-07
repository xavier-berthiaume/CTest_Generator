#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "testcase.h"

#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->menu_tabs);
    variable_count = ui->variable_spin->value();
}

MainWindow::~MainWindow()
{
    delete ui;
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

    // Here the user increased the number of variables
    if (arg1 > variable_count) {

    // Here the user decreased the number of variables
    } else {

    }

    variable_count = ui->variable_spin->value();

}


void MainWindow::on_copy_button_released()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->output_browser->toPlainText());
    // ui->output_browser->copy();
}
