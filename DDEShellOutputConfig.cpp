//
// Created by ragdoll on 2021/5/20.
//

#include "DDEShellOutputConfig.h"
#include <QSettings>
#include <iostream>

DDEShellOutputConfig *DDEShellOutputConfig::inst = nullptr;

const QList<MShell> &DDEShellOutputConfig::getShellList() const {
    return shellList;
}

void DDEShellOutputConfig::setShellList(const QList<MShell> &shellList) {
    DDEShellOutputConfig::shellList = shellList;
}

const QColor &DDEShellOutputConfig::getFontColor() const {
    return fontColor;
}

void DDEShellOutputConfig::setFontColor(const QColor &fontColor) {
    DDEShellOutputConfig::fontColor = fontColor;
}

DDEShellOutputConfig *DDEShellOutputConfig::getInst() {
    if (inst == nullptr) {
        inst = new DDEShellOutputConfig();
    }
    return inst;
}

DDEShellOutputConfig::DDEShellOutputConfig() {
    QSettings settings("dde-shelloutput", "dde-shelloutput");
    this->fontColor = QColor(settings.value("config/fontColor", "#FFFFFF").toString());
    this->width = settings.value("config/width", 250).toInt();

    settings.beginGroup("shell");
    foreach (QString key, settings.childGroups()) {
        std::cout << key.toStdString() << std::endl;
        settings.beginGroup(key);
        MShell shell(
                key,
                settings.value("command").toString(),
                settings.value("regExp").toString(),
                settings.value("interval").toInt(),
                IntervalType(settings.value("intervalType").toInt())
        );
        this->shellList.append(shell);
        settings.endGroup();
    }
    settings.endGroup();
}

void DDEShellOutputConfig::saveConfig() {
//    QSettings settings("dde-shelloutput", "dde-shelloutput");
//    settings.setValue("config/fontColor", "#FFFFFF");
//    settings.beginGroup("shell");
//    MShell shell("test", "date", "", 1, IntervalType(0));
//    settings.beginGroup(shell.getName());
//    settings.setValue("name", shell.getName());
//    settings.setValue("command", shell.getCommand());
//    settings.setValue("regExp", shell.getOutputReg());
//    settings.setValue("interval", shell.getInterval());
//    settings.setValue("intervalType", shell.getType());
}

int DDEShellOutputConfig::getWidth() const {
    return width;
}

void DDEShellOutputConfig::setWidth(int width) {
    DDEShellOutputConfig::width = width;
}
