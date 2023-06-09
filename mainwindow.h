#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "variabledetailer.h"

#include <QMainWindow>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QStack<VariableDetailer *> variable_stack;


private slots:
    void on_generate_button_released();

    void on_clear_button_released();

    void on_variable_spin_valueChanged(int arg1);

    void on_copy_button_released();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
