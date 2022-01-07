#include "toolsinstall.h"




ToolsInstall::ToolsInstall(QWidget *parent)
    : QWidget(parent)
{
    ui = new HFUIFile();
    ui->setupUi(this);

    textEditString = QString("");

    mapState = false;
    unMapState = false;
    mayaState = false;
    maxState = false;
    houState = false;

    if (ui->checkBox_maya->isChecked())
    {
        mayaState = true;
//        textEditString += "Maya CheckBox is set to true\n";
    }

    if (ui->checkBox_max->isChecked())
    {
        maxState = true;
//        textEditString += "Max CheckBox is set to true\n";
    }

    if (ui->checkBox_hou->isChecked())
    {
        houState = true;
//        textEditString += "Houdini CheckBox is set to true\n";
    }

    if (ui->mapCheckBox->isChecked())
    {
        mapState = true;
//        textEditString += "Map CheckBox is set to true\n";
    }

    if (ui->unmapCheckBox->isChecked())
    {
        unMapState = true;
//        textEditString += "Unmap CheckBox is set to true\n";
    }



    createConnections();
    this->setWindowTitle("Tools Management Installer");
    this->setFixedSize(600, 400);
}

ToolsInstall::~ToolsInstall()
{

}


void ToolsInstall::updateCheckStateMaya(bool checked)
{
    if (checked)
    {
        mayaState = true;
        qDebug() << "mayaState set to true";
    }
}



void ToolsInstall::updateCheckStateMax(bool checked)
{
    if (checked)
    {
        maxState = true;
    }
}


void ToolsInstall::updateCheckStateHou(bool checked)
{
    if (checked)
    {
        houState = true;
    }
}



void ToolsInstall::updateCheckStateMap(bool checked)
{
    if (checked)
    {
        mapState = true;
    }
}



void ToolsInstall::updateCheckStateUnmap(bool checked)
{
    if (checked)
    {
        unMapState = true;
    }
}



void ToolsInstall::print_test()
{
    qDebug() << "Hal Test...";
}

void ToolsInstall::createFileDialog1()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty())
    {
        ui->max_line->setText(dir);
    }
}

void ToolsInstall::createFileDialog2()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty())
    {
        ui->hou_line->setText(dir);
    }
}

int ToolsInstall::confirmSlot()
{
    QMessageBox msgBox;

    textEditString = "";

    if (ui->mapCheckBox->isChecked())
    {
        mapState = true;
//        textEditString += "Map CheckBox is set to true\n";
        system(R"(net use Z: \\10.0.127.121\TAcenter  /persistent:yes)");

    }

    std::string rootPath = "Z:/PipelineTools/ToolsManagement";

    if(_access_s(rootPath.c_str(), 0) == -1)
    {
        msgBox.setText("Can't find the path Z:/PipelineTools/ToolsManagement");
//        textEditString += "Error: Can't find the path Z:/PipelineTools/ToolsManagement";
        return 0;
    }


    if (ui->unmapCheckBox->isChecked())
    {
        unMapState = true;
//        textEditString += "Unmap CheckBox is set to true\n";
        system("net use Z: /del /y");
    }


    if (ui->checkBox_maya->isChecked())
    {
        std::string ma_scripts = "C:/Users/%username%/Documents/maya/scripts/";
        mayaState = true;
//        textEditString += "Maya CheckBox is set to true\n";
//        if ()
    }


    if (ui->checkBox_max->isChecked())
    {
        maxState = true;
        textEditString += "Max CheckBox is set to true\n";
    }


    if (ui->checkBox_hou->isChecked())
    {
        houState = true;
        textEditString += "Houdini CheckBox is set to true\n";
    }




    ui->outTextEidt->setText(textEditString);
//    system("calc");
}


void ToolsInstall::createConnections()
{
    QObject::connect(ui->max_btn, SIGNAL(clicked()), this, SLOT(createFileDialog1()));
    QObject::connect(ui->hou_btn, SIGNAL(clicked()), this, SLOT(createFileDialog2()));
    QObject::connect(ui->confirmBtn, SIGNAL(clicked()), this, SLOT(confirmSlot()));

    QObject::connect(ui->checkBox_maya, SIGNAL(toggled(bool)), this, SLOT(updateCheckStateMaya(bool)));
    QObject::connect(ui->checkBox_max, SIGNAL(toggled(bool)), this, SLOT(updateCheckStateMax(bool)));
    QObject::connect(ui->checkBox_hou, SIGNAL(toggled(bool)), this, SLOT(updateCheckStateHou(bool)));
    QObject::connect(ui->mapCheckBox, SIGNAL(toggled(bool)), this, SLOT(updateCheckStateMap(bool)));
    QObject::connect(ui->unmapCheckBox, SIGNAL(toggled(bool)), this, SLOT(updateCheckStateUnmap(bool)));

//    QObject::connect(ui->max_btn)

}
