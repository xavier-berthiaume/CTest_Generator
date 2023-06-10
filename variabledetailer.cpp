#include "variabledetailer.h"

VariableDetailer::VariableDetailer(QListWidgetItem *list_item_param) : list_item(list_item_param)
{

}

VariableDetailer::~VariableDetailer() {

}

QListWidgetItem *VariableDetailer::getListItem() {
    return list_item;
}

QString VariableDetailer::getLabelName() {
    return list_item->text();
}

void VariableDetailer::setLabelName(const QString &label_name_param) {
    list_item->setText(label_name_param);
}
