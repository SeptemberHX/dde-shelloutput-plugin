//
// Created by ragdoll on 2021/5/20.
//

#ifndef DDE_SHELLOUTPUT_DDESHELLOUTPUTCONFIG_H
#define DDE_SHELLOUTPUT_DDESHELLOUTPUTCONFIG_H

#include <QString>
#include <QList>
#include <MShell.h>
#include <QColor>

class DDEShellOutputConfig {

public:
    static DDEShellOutputConfig *getInst();

    const QList<MShell> &getShellList() const;

    void setShellList(const QList<MShell> &shellList);

    const QColor &getFontColor() const;

    void setFontColor(const QColor &fontColor);

    int getWidth() const;

    void setWidth(int width);

    bool isAutoWidth() const;

    void setAutoWidth(bool autoWidth);

private:
    DDEShellOutputConfig();
    void saveConfig();

    static DDEShellOutputConfig *inst;
    int width;
    bool autoWidth;

    QList<MShell> shellList;
    QColor fontColor;
};


#endif //DDE_SHELLOUTPUT_DDESHELLOUTPUTCONFIG_H
