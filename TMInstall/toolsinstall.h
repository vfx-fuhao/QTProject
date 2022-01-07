#ifndef TOOLSINSTALL_H
#define TOOLSINSTALL_H

#include <io.h>
#include <direct.h>
#include <string>
#include <stdlib.h>
#include <QWidget>
#include <iostream>
#include <QDebug>
#include <QSignalMapper>
#include "ui_toolsinstall.h"
#include <QMessageBox>


class ToolsInstall : public QWidget
{
    Q_OBJECT

public:
    ToolsInstall(QWidget *parent = nullptr);
    ~ToolsInstall();
    void createConnections();

private slots:
    void print_test();
    void createFileDialog1();
    void createFileDialog2();
    int confirmSlot();
    void updateCheckStateMaya(bool checked);
    void updateCheckStateMax(bool checked);
    void updateCheckStateHou(bool checked);
    void updateCheckStateMap(bool checked);
    void updateCheckStateUnmap(bool checked);


private:
    HFUIFile* ui;
    QString dir;
    QString textEditString;
    QSignalMapper mapper;

    bool mapState;
    bool unMapState;
    bool mayaState;
    bool maxState;
    bool houState;

};

#endif // TOOLSINSTALL_H
