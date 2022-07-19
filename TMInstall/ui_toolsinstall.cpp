#include "ui_toolsinstall.h"

void HFUIFile::setupUi(QWidget* ToolsInstall)
{
    this->createWidgets();
    this->layoutWidgets(ToolsInstall);
    this->createConnections();
}


void HFUIFile::createWidgets()
{
    defaultMaxPath = "C:\\Program Files\\Autodesk\\3ds Max 2020";
    defaultHouPath = "C:\\Program Files\\Side Effects Software\\Houdini 18.5.351";
    this->createGroupBoxHF();

    // Max Path set widgets create.
    max_label = new QLabel();
    max_label->setText("Install Path: ");
    max_line = new QLineEdit(defaultMaxPath);
    max_btn = new QPushButton("...");
    max_btn->setMaximumWidth(50);
    outTextEidt = new QTextEdit();
    outTextEidt->setReadOnly(true);
    outTextEidt->setStyleSheet("background-image: url(:/images/versionInfo.jpg);background-position: top left;");

    // Houdini path set widgets create.
    houPathGroupBox = new QGroupBox("Houdinii Path Set");
    hou_label = new QLabel("Install Path: ");
    hou_line = new QLineEdit(defaultHouPath);
    hou_btn = new QPushButton("...");
    hou_btn->setMaximumWidth(50);

    // Map Z drive widgets create
    mapGroupbox = new QGroupBox("Map  Drive");
    mapCheckBox = new QCheckBox("Map Z Drive");
    mapCheckBox->setToolTip(R"(Map \\10.0.127.121\TAcenter to local Z drive. Environment rely on the Z drive, Please confirm the Z drive is exists. )");
    mapCheckBox->setChecked(true);

    unmapCheckBox = new QCheckBox("Unmap Z Dirve");
    unmapCheckBox->setToolTip(R"(Unmap Z drive to \\10.0.127.121\TAcenter. If U don't need Z drive,check it on.)");

    infoLabel = new QLabel("Copyright (c) 2022.01.11  Huanle Entertainment.Co.Ltd. All rights reserved.");
    QPixmap logoImage = QPixmap(":/images/huanleLogoSmall2.jpg");
    huanleLogoLabel = new QLabel();
//    huanleLogoLabel->setMaximumSize(60, 30);
    huanleLogoLabel->setPixmap(logoImage);

    confirmBtn = new QPushButton("Confirm");
    closeBtn = new QPushButton("Cancel");
    finishedBtn = new QPushButton("Finished");
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
    HLayout4->addWidget(huanleLogoLabel);
    HLayout4->addStretch(100);
//    HLayout4->addWidget(infoLabel);
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

    mayaSupVersion = new QLabel("Sup Version: 2017 - 2021");
    mayaSupVersion->setStyleSheet("QLabel { color : blue; }");
    maxSupVersion = new QLabel("Sup Version: 2018 - 2020");
    maxSupVersion->setStyleSheet("QLabel { color : blue; }");
    houSupVersion = new QLabel("Sup Version 17.5 - 18.5");
    houSupVersion->setStyleSheet("QLabel { color : blue; }");

    HLayout3 = new QHBoxLayout();
    HVersionLayout = new QHBoxLayout();

    HLayout3->addWidget(checkBox_maya);

    HLayout3->addWidget(checkBox_max);

    HLayout3->addWidget(checkBox_hou);


    HVersionLayout->addWidget(mayaSupVersion);
    HVersionLayout->addWidget(maxSupVersion);
    HVersionLayout->addWidget(houSupVersion);

    VCheckVersionLayout = new QVBoxLayout();
    VCheckVersionLayout->addLayout(HLayout3);
    VCheckVersionLayout->addLayout(HVersionLayout);

    groupBox1->setLayout(VCheckVersionLayout);

    return groupBox1;

}
