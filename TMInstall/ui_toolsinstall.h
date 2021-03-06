#ifndef UI_TOOLSINSTALL_H
#define UI_TOOLSINSTALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QCheckBox>
#include <QFileDialog>


class HFUIFile
{
public:
    void setupUi(QWidget *ToolsInstall);
    void retranslateUi(QWidget *ToolsInstall);
    void createWidgets();
    void layoutWidgets(QWidget* ToolsInstall);
    void createConnections();

    QGroupBox* createGroupBoxHF();



public:
    QLabel *max_label;
    QLineEdit *max_line;
    QPushButton *max_btn;
    QTextEdit *outTextEidt;

    QLabel *hou_label;
    QLineEdit *hou_line;
    QPushButton *hou_btn;

    QLabel *huanleLogoLabel;
    QPushButton *confirmBtn;
    QPushButton *closeBtn;
    QPushButton *finishedBtn;

    QLabel *infoLabel;

    QHBoxLayout *HLayout1;
    QHBoxLayout *HLayout2;
    QHBoxLayout *HLayout3;
    QHBoxLayout *HLayout4;
    QHBoxLayout *HLayout5;
    QHBoxLayout *HVersionLayout;
    QVBoxLayout *VLayout1;
    QVBoxLayout *VCheckVersionLayout;

    QGroupBox *groupBox1;
    QGroupBox *maxPathGroupBox;
    QGroupBox *houPathGroupBox;
    QGroupBox *mapGroupbox;

    QCheckBox *checkBox_maya;
    QCheckBox *checkBox_max;
    QCheckBox *checkBox_hou;

    QLabel *mayaSupVersion;
    QLabel *maxSupVersion;
    QLabel *houSupVersion;

    QCheckBox *mapCheckBox;
    QCheckBox *unmapCheckBox;

private:
    QString defaultMaxPath;
    QString defaultHouPath;

//    QFileDialog *maxDialog;
//    QFileDialog *houDialog;

};

#endif // UI_TOOLSINSTALL_H
