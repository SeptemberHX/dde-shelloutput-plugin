//
// Created by septemberhx on 2020/5/13.
//

#ifndef DDE_PSTATE_DDEPSTATEPLUGIN_H
#define DDE_PSTATE_DDEPSTATEPLUGIN_H

#include "DDEShellOutputPlugin.h"
#include <dde-dock/pluginsiteminterface.h>
#include <QObject>
#include <QThread>
#include <QMap>
#include <QList>
#include <QTimer>
#include <QLabel>

class DDEShellOutputPlugin : public QObject, public PluginsItemInterface {
    Q_OBJECT

    // 声明实现了的接口
    Q_INTERFACES(PluginsItemInterface)
    // 插件元数据
    Q_PLUGIN_METADATA(IID "com.deepin.dock.PluginsItemInterface" FILE "dde_shelloutput.json")

public:
    explicit DDEShellOutputPlugin(QObject *parent = nullptr);

    // 返回插件的名称，必须是唯一值，不可以和其它插件冲突
    const QString pluginName() const override;

    // 插件初始化函数
    void init(PluginProxyInterface *proxyInter) override;
    QWidget *itemWidget(const QString &itemKey) override;

    QWidget *itemPopupApplet(const QString &itemKey) override;

    bool pluginIsAllowDisable() override;
    bool pluginIsDisable() override;

    void pluginStateSwitched() override;

    const QString pluginDisplayName() const override;
    void pluginSettingsChanged() override;

//    int itemSortKey(const QString &itemKey) Q_DECL_OVERRIDE;
//    void setSortKey(const QString &itemKey, const int order) Q_DECL_OVERRIDE;

private slots:

private:
    QLabel *p_itemWidget;
};


#endif //DDE_PSTATE_DDEPSTATEPLUGIN_H
