#ifndef VARIABLEDETAILER_H
#define VARIABLEDETAILER_H

// #include "qcombobox.h"

#include <QWidget>
#include <QListWidgetItem>

class VariableDetailer
{
private:
    const QListWidgetItem *list_item;

public:
    VariableDetailer(QListWidgetItem *list_item_param);
};

#endif // VARIABLEDETAILER_H
