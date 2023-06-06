#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "testcase.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->menu_tabs);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generate_button_released()
{

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
        name.append(i);

        //TestCase test_case = TestCase(name, base_command);

    }
}


void MainWindow::on_clear_button_released()
{
    // Reset all fields
    ui->name_line->setText("");
    ui->command_line->setText("");

    ui->iterations_spin->setValue(1);
    ui->variable_spin->setValue(1);
}

