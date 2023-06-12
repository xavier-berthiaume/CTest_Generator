#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "variabledetailer.h"

#include <QMainWindow>
#include <QFormLayout>
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

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void updatedVariableType(int selected_index);

private:
    QWidget *editor;

    Ui::MainWindow *ui;

    void createEditor();

    void createGenericEditorHeader(QFormLayout *editor_form);

    void createGenericEditorFooter(QFormLayout *editor_form);

    void createIntegerVariableBody(QFormLayout *editor_form);

    void createSimpleStringVariableBody(QFormLayout *editor_form);

    void createInputStringVariableBody(QFormLayout *editor_form);

};
#endif // MAINWINDOW_H
