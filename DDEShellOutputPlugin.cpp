//
// Created by septemberhx on 2020/5/13.
//

#include "DDEShellOutputPlugin.h"
#include <QJsonObject>
#include <QDebug>
#include <iostream>

#define PLUGIN_STATE_KEY "enable"

DDEShellOutputPlugin::DDEShellOutputPlugin(QObject *parent) : QObject(parent) {
    this->p_itemWidget = new QLabel();
    this->p_itemWidget->setText("DDE Shell Output Plugin");
    this->p_itemWidget->setFixedWidth(250);

    this->shellTimer_p = new QTimer(this);

    MShell testShell("date", "", 1, SEC);
    this->applyShell(testShell);
}

const QString DDEShellOutputPlugin::pluginName() const {
    return QStringLiteral("dde_shelloutput");
}

void DDEShellOutputPlugin::init(PluginProxyInterface *proxyInter) {
    this->m_proxyInter = proxyInter;

    if (!pluginIsDisable()) {
        this->m_proxyInter->itemAdded(this, this->pluginName());
        m_proxyInter->saveValue(this, PLUGIN_STATE_KEY, true);
    }
}

bool DDEShellOutputPlugin::pluginIsAllowDisable() {
    return true;
}

bool DDEShellOutputPlugin::pluginIsDisable() {
    return !(m_proxyInter->getValue(this, PLUGIN_STATE_KEY, true).toBool());
}

void DDEShellOutputPlugin::pluginStateSwitched() {
    m_proxyInter->saveValue(this, PLUGIN_STATE_KEY, pluginIsDisable());

    if (pluginIsDisable()) {
        m_proxyInter->itemRemoved(this, pluginName());
        return;
    }

    m_proxyInter->itemAdded(this, pluginName());
}

const QString DDEShellOutputPlugin::pluginDisplayName() const {
    return QStringLiteral("DDE Shell Output");
}

void DDEShellOutputPlugin::pluginSettingsChanged() {
    if (pluginIsDisable()) {
        m_proxyInter->itemRemoved(this, pluginName());
        return;
    }

    m_proxyInter->itemAdded(this, pluginName());
}

QWidget *DDEShellOutputPlugin::itemWidget(const QString &itemKey) {
    Q_UNUSED(itemKey)
    return this->p_itemWidget;
}

QWidget *DDEShellOutputPlugin::itemPopupApplet(const QString &itemKey) {
    Q_UNUSED(itemKey)
    return nullptr;
}

void DDEShellOutputPlugin::applyShell(MShell mShell) {
    this->currShell = mShell;

    qlonglong t = this->currShell.getInterval();
    switch (this->currShell.getType()) {
        case SEC:
            t *= 1000;
            break;
        case MIN:
            t *= 60 * 1000;
            break;
        case HOUR:
            t *= 60 * 60 * 1000;
            break;
        default:
            break;
    }
    this->shellTimer_p->singleShot(t, this, &DDEShellOutputPlugin::timerFinished);
}

void DDEShellOutputPlugin::timerFinished() {
    this->shellTimer_p->stop();
    process.start(this->currShell.getCommand());
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    this->p_itemWidget->setText(output.trimmed());
    this->applyShell(this->currShell);
}
