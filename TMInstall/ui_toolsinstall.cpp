#include "ui_toolsinstall.h"

void HFUIFile::setupUi(QWidget* ToolsInstall)
{
    this->createWidgets();
    this->layoutWidgets(ToolsInstall);
    this->createConnections();
}


void HFUIFile::createWidgets()
{
    this->createGroupBoxHF();

    // Max Path set widgets create.
    max_label = new QLabel();
    max_label->setText("Install Path: ");
    max_line = new QLineEdit();
    max_btn = new QPushButton("...");
    max_btn->setMaximumWidth(50);
    outTextEidt = new QTextEdit();
    outTextEidt->setReadOnly(true);

    // Houdini path set widgets create.
    houPathGroupBox = new QGroupBox("Houdinii Path Set");
    hou_label = new QLabel("Install Path: ");
    hou_line = new QLineEdit();
    hou_btn = new QPushButton("...");
    hou_btn->setMaximumWidth(50);

    // Map Z drive widgets create
    mapGroupbox = new QGroupBox("Map  Drive");
    mapCheckBox = new QCheckBox("Map Z Drive");
    mapCheckBox->setChecked(true);
    unmapCheckBox = new QCheckBox("Unmap Z Dirve");

    confirmBtn = new QPushButton("Confirm");
    closeBtn = new QPushButton("Cancel");
}

void HFUIFile::layoutWidgets(QWidget* ToolsInstall)
{
    maxPathGroupBox = new QGroupBox("3DS Max Path Set");
    HLayout1 = new QHBoxLayout();
    HLayout1->addWidget(this->max_label);
    HLayout1->addWidget(this->max_line);
    HLayout1->addWidget((this->max_btn));
    maxPathGroupBox->setLayout(HLayout1);

    HLayout2 = new QHBoxLayout();
    HLayout2->addWidget(this->hou_label);
    HLayout2->addWidget(this->hou_line);
    HLayout2->addWidget(this->hou_btn);
    houPathGroupBox->setLayout(HLayout2);

    HLayout4 = new QHBoxLayout();
    HLayout4->addStretch(100);
    HLayout4->addWidget(this->confirmBtn);
    HLayout4->addStretch(10);
    HLayout4->addWidget(this->closeBtn);

    HLayout5 = new QHBoxLayout();
    HLayout5->addWidget(mapCheckBox);
    HLayout5->addWidget(unmapCheckBox);
    mapGroupbox->setLayout(HLayout5);

    VLayout1 = new QVBoxLayout(ToolsInstall);
    VLayout1->addWidget(mapGroupbox);
    VLayout1->addWidget(groupBox1);
    VLayout1->addWidget(maxPathGroupBox);
    VLayout1->addWidget(houPathGroupBox);

    VLayout1->addWidget(outTextEidt);
    VLayout1->addLayout(HLayout4);
}


void HFUIFile::createConnections()
{

}


void HFUIFile::retranslateUi(QWidget *ToolsInstall)
{

}


QGroupBox* HFUIFile::createGroupBoxHF()
{
    groupBox1 = new QGroupBox("Install for");
    checkBox_maya = new QCheckBox("Maya");
    checkBox_maya->setChecked(true);
    checkBox_max = new QCheckBox("Max");
    checkBox_max->setChecked(true);
    checkBox_hou = new QCheckBox("Houdini");
    checkBox_hou->setChecked(true);

    HLayout3 = new QHBoxLayout();
    HLayout3->addWidget(checkBox_maya);
    HLayout3->addWidget(checkBox_max);
    HLayout3->addWidget(checkBox_hou);

    groupBox1->setLayout(HLayout3);

    return groupBox1;

}
