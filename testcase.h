#ifndef TESTCASE_H
#define TESTCASE_H

#include <QString>

struct TestCase {

public:
    QString name, command;

    TestCase() = default;
    TestCase(QString name_param, QString command_param);

    QString toQString();

};

#endif // TESTCASE_H
