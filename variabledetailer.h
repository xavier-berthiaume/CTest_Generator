#ifndef VARIABLEDETAILER_H
#define VARIABLEDETAILER_H

// #include "qcombobox.h"

#include "testcase.h"

#include <QWidget>
#include <QListWidgetItem>

class VariableDetailer
{
private:
    QListWidgetItem *list_item;

public:
    VariableDetailer(QListWidgetItem *list_item_param);
    ~VariableDetailer();

    QListWidgetItem *getListItem();
    QString getLabelName();

    void setLabelName(const QString &label_name_param);

};

#endif // VARIABLEDETAILER_H
