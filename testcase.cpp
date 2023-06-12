#include "testcase.h"

TestCase::TestCase(QString name_param, QString command_param) : name(name_param), command(command_param) {

}

void TestCase::addVariable(QString variable_value) {

    command.append(" ");
    command.append(variable_value);

}

QString TestCase::toQString() {

    QString generated_string = "add_test(NAME ";

    generated_string.append(name);

    generated_string.append(" COMMAND ");
    generated_string.append(command);

    generated_string.append(")");
    return generated_string;

}
