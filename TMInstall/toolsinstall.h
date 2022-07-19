#ifndef TOOLSINSTALL_H
#define TOOLSINSTALL_H

#include <io.h>
#include <direct.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <QWidget>
#include <iostream>
#include <QDebug>
#include <QSignalMapper>
#include "ui_toolsinstall.h"
#include <QMessageBox>
#include <windows.h>
#include <winbase.h>
#include <exception>
#include <QTime>


class ToolsInstall : public QWidget
{
    Q_OBJECT

public:
    ToolsInstall(QWidget *parent = nullptr);
    ~ToolsInstall();
    void createConnections();
    QString getLineEdit(QLineEdit *inLine);
    void insertSetColorRed(QTextEdit* inText, QString inString);
    void insertSetColorBlack(QTextEdit* inText, QString inString);


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
    void clearHboxLayout();


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
