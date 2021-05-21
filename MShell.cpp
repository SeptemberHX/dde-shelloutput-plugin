//
// Created by ragdoll on 2021/5/19.
//

#include "MShell.h"

MShell::MShell()
    : interval(1)
    , type(IntervalType::SEC)
{

}

MShell:: MShell(QString name, QString command, QString outputReg, int interval, IntervalType type)
    : name(name)
    , command(command)
    , outputReg(outputReg)
    , interval(interval)
    , type(type)
{

}

const QString &MShell::getCommand() const {
    return command;
}

void MShell::setCommand(const QString &command) {
    MShell::command = command;
}

const QString &MShell::getOutputReg() const {
    return outputReg;
}

void MShell::setOutputReg(const QString &outputReg) {
    MShell::outputReg = outputReg;
}

int MShell::getInterval() const {
    return interval;
}

void MShell::setInterval(int interval) {
    MShell::interval = interval;
}

IntervalType MShell::getType() const {
    return type;
}

void MShell::setType(IntervalType type) {
    MShell::type = type;
}

const QString &MShell::getName() const {
    return name;
}

void MShell::setName(const QString &name) {
    MShell::name = name;
}
