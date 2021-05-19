//
// Created by ragdoll on 2021/5/19.
//

#ifndef DDE_SHELLOUTPUT_MSHELL_H
#define DDE_SHELLOUTPUT_MSHELL_H

#include <QString>

enum IntervalType {
    SEC = 0,
    MIN = 1,
    HOUR = 2,
};

class MShell {

public:
    MShell();
    MShell(QString command, QString outputReg, int interval, IntervalType type);

    const QString &getCommand() const;

    void setCommand(const QString &command);

    const QString &getOutputReg() const;

    void setOutputReg(const QString &outputReg);

    int getInterval() const;

    void setInterval(int interval);

    IntervalType getType() const;

    void setType(IntervalType type);

private:
    QString command;
    QString outputReg;
    int interval;
    IntervalType type;
};


#endif //DDE_SHELLOUTPUT_MSHELL_H
