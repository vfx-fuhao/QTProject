#include "toolsinstall.h"




ToolsInstall::ToolsInstall(QWidget *parent)
    : QWidget(parent)
{
    ui = new HFUIFile();
    ui->setupUi(this);

    textEditString = QString("");
    QString defaultText = "Copyright (c) 2022.01.11  Huanle Entertainment.Co.Ltd. All rights reserved.\nVersion: 1.0\nAuthor: Hal Foo\nEmail: haofu@huanle.com\n";
    ui->outTextEidt->setTextColor(Qt::blue);
    ui->outTextEidt->setText(textEditString);

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
    QIcon VigorIcon = QIcon(":/images/Logo_resize2.jpg");
    this->setWindowIcon(VigorIcon);
    this->setWindowIconText("Vigor");
    this->setWindowTitle("Vigor Tools Management Installer");
    this->setFixedSize(650, 450);
    this->setStyleSheet("QToolTip { color:#ffffff; background-color:#000000;border:0px;}");

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



QString ToolsInstall::getLineEdit(QLineEdit *inLine)
{
    return inLine->text();
}


void ToolsInstall::insertSetColorRed(QTextEdit *inText, QString inString)
{
    inText->moveCursor(QTextCursor::End);
    inText->setTextColor(Qt::red);
    inText->insertPlainText(inString);
}


void ToolsInstall::insertSetColorBlack(QTextEdit *inText, QString inString)
{
    inText->moveCursor(QTextCursor::End);
    inText->setTextColor(Qt::black);
    inText->insertPlainText(inString);
}


void ToolsInstall::clearHboxLayout()
{
//    int temp_count = ui->HLayout4->count();
////    qDebug() << temp_count;
//    for (int i=0;i<temp_count;i++)
//    {
////        qDebug() << i;
//        QLayoutItem *item = ui->HLayout4->itemAt(i);
//        if (!item->isEmpty())
//        {
//            QWidget *temp_widget = item->widget();
//            if (temp_widget)
//            {
//                temp_widget->deleteLater();
//            }
//        }
//    }
//    ui->infoLabel = new QLabel("Copyright (c) 2022.01.11  Huanle Entertainment.Co.Ltd. All rights reserved.");
//    ui->HLayout4->addWidget(ui->infoLabel, 0, Qt::AlignLeft);
    ui->HLayout4->removeWidget(ui->confirmBtn);
    ui->HLayout4->removeWidget(ui->closeBtn);
    ui->confirmBtn->deleteLater();
//    ui->HLayout4->addWidget(ui->huanleLogoLabel);
    ui->HLayout4->addStretch(100);
//    ui->HLayout4->addStretch(60);
    ui->HLayout4->addWidget(ui->finishedBtn);

//    ui->HLayout4->removeWidget()
//    ui->HLayout4->removeWidget(ui->confirmBtn);
//    ui->HLayout4->removeWidget(ui->closeBtn);

//    ui->HLayout4->addWidget(ui->infoLabel);
//    ui->HLayout4->addWidget(ui->finishedBtn);
}







int ToolsInstall::confirmSlot()
{
    QMessageBox msgBox;

    QString defaultText = "Copyright (c) 2022.01.11  Huanle Entertainment.Co.Ltd. All rights reserved.\nVersion: 1.0\nAuthor: Hal Foo\nEmail: haofu@huanle.com\n";

    textEditString = "";
    ui->outTextEidt->setText(textEditString);

    if (ui->mapCheckBox->isChecked())
    {
        mapState = true;
        textEditString += R"(Map \\10.0.127.121\TAcenter to Z drive successful.)";
        textEditString += "\n";

        try
        {
            system(R"(net use Z: \\10.0.127.121\TAcenter  /persistent:yes)");
            ui->outTextEidt->setTextColor(Qt::black);
            ui->outTextEidt->insertPlainText(textEditString);
        } catch (...)
        {
            textEditString = R"(Error: Failed to map \\10.0.127.121\TAcenter to Z)";
            insertSetColorRed(ui->outTextEidt, textEditString);
            msgBox.setText("Failed to map Z Drive.");
            return 0;
        }



    }

    std::string rootPath = "Z:/PipelineTools/ToolsManagement";

    if(_access(rootPath.c_str(), 0) == -1)
    {
        textEditString = "Error: Can't find the path Z:/PipelineTools/ToolsManagement";
        insertSetColorRed(ui->outTextEidt, textEditString);
//        qDebug() << "Can't find the path Z:/PipelineTools/ToolsManagement";
        msgBox.setText("Can't find the path Z:/PipelineTools/ToolsManagement");
        msgBox.exec();
        return 0;
    }


    if (ui->unmapCheckBox->isChecked())
    {
        unMapState = true;

        try
        {
            system("net use Z: /del /y");
//            qDebug() << "Unmap Z drive sucessful.";
            textEditString = "Unmap Z drive sucessful.\n";
            insertSetColorBlack(ui->outTextEidt, textEditString);
        } catch (...)
        {
            textEditString = "Failed to unmap Z drive.\n";
            insertSetColorRed(ui->outTextEidt,textEditString);
            msgBox.setText("Failed to unmap Z drive.");

        }

    }


    if (ui->checkBox_maya->isChecked())
    {
//        std::string ma_scripts = "C:/Users/" + name + "/Documents/maya/scripts/";
//        QString temp_qstr = QString(ma_scripts.c_str());
        mayaState = true;

        QString name = qgetenv("USER");
//        QString name = qgetenv("USERNAME");

        if (name.isEmpty())
        {
            name = qgetenv("USERNAME");
        }

//        qDebug() <<"The name var is: " << name;

        QString script_path ="C:/Users/" + name + "/Documents/maya/scripts/";
        script_path = script_path.replace("/", "\\");
//        QString temp_path = QString("C:/Users/%1/Documents/maya/scripts/").arg(name);
        QDir script_foder(script_path);

//        textEditString += "Maya CheckBox is set to true\n";
        if (!script_foder.exists())
        {
//            qDebug() << "Can't find path C:/Users/" << name <<"/Documents/maya/scripts/";
            QString outText = "Can't find path C:/Users/" + name + "/Documents/maya/scripts/";
            msgBox.setText(outText);
            msgBox.exec();
            return 0;
        }


//        QString mayaCommand = QString(R"(copy /y "Z:\PipelineTools\ToolsManagement\Install\maya\userSetup.py" %1)").arg(script_path);
        script_path = script_path.replace("\\", "/") + "userSetup.py";

        try
        {
//            qDebug() << "Script path is: " << script_path << "\n";
//            qDebug() << "Maya command cout is: " << mayaCommand.toStdString().c_str();
            CopyFileA("Z:/PipelineTools/ToolsManagement/Install/maya/userSetup.py", script_path.toStdString().c_str(), false);

//            system(mayaCommand.toStdString().c_str());
//            qDebug() << script_path;
            textEditString = script_path;
            textEditString = "Install for maya sucessful.";
            textEditString += "\n";
            insertSetColorBlack(ui->outTextEidt, textEditString);
        } catch (...)
        {
            textEditString = "Failed to install for maya.\n";
            insertSetColorRed(ui->outTextEidt, textEditString);

            msgBox.setText("Failed to install for maya.");
            msgBox.exec();
            return 0;
        }


    }


    if (ui->checkBox_max->isChecked())
    {
        QString max_lineEdit;
        maxState = true;
//        textEditString += "Max CheckBox is set to true\n";
        max_lineEdit = getLineEdit(ui->max_line) + "/scripts/Startup/";
        QDir dir(max_lineEdit);
        max_lineEdit = max_lineEdit.replace("/", "\\");

        QString temp_out = QString("Can't find path %1").arg(max_lineEdit);

        if (!dir.exists())
        {
            msgBox.setText(temp_out);
            msgBox.exec();
            return 0;
        }



//        QString maxCommand = QString(R"(copy /y "Z:\PipelineTools\ToolsManagement\Install\max\startup.ms" %1)").arg(max_lineEdit);

        try
        {
//            qDebug() << "Max command is: " << maxCommand << "\n";

//            const char* temp_commandStr = maxCommand.toLatin1().data();
//            qDebug() << "The max command cout is:  " <<temp_commandStr;

            max_lineEdit = max_lineEdit.replace("\\", "/") + "startup.ms";

            CopyFileA("Z:/PipelineTools/ToolsManagement/Install/max/startup.ms", max_lineEdit.toStdString().c_str(), false);

            textEditString = max_lineEdit;
            textEditString = "Install for max sucessful.";
            textEditString += "\n";
            insertSetColorBlack(ui->outTextEidt, textEditString);
        } catch (...)
        {
            textEditString = "Failed to install for 3ds Max.\n";
            insertSetColorRed(ui->outTextEidt, textEditString);

            msgBox.setText("Failed to install for 3ds Max.");
            msgBox.exec();
            return 0;
        }


    }


    if (ui->checkBox_hou->isChecked())
    {
        QString hou_lineEdit = getLineEdit(ui->hou_line);


        QDir houDir(hou_lineEdit);
        QString temp_out = QString("Can't find path %1").arg(hou_lineEdit);

        if (!houDir.exists())
        {
            msgBox.setText(temp_out);
            msgBox.exec();
            return 0;
        }

        hou_lineEdit = hou_lineEdit + "/houdini/MainMenuMaster.xml";
//        qDebug() << hou_lineEdit;

//        QString houCommand = QString(R"(copy /y "Z:\PipelineTools\ToolsManagement\Install\houdini\MainMenuMaster.xml" )") + hou_lineEdit;

        try
        {
//            qDebug() << "Houdini commad is: " << houCommand;
//            qDebug() << "The houdini cout is: " << houCommand.toStdString().c_str();

            CopyFileA("Z:/PipelineTools/ToolsManagement/Install/houdini/MainMenuMaster.xml", hou_lineEdit.toStdString().c_str(), false);

//            system(houCommand.toStdString().c_str());

            textEditString = "Install for houdini sucessful.\n";
            insertSetColorBlack(ui->outTextEidt, textEditString);
        } catch (...)
        {
            textEditString = "Failde to install for houdini.\n";
            insertSetColorRed(ui->outTextEidt, textEditString);
            msgBox.setText("Failde to install for houdini.");
            msgBox.exec();

            return 0;
        }


        textEditString = "Enjoy!";
        textEditString += "\n";
        ui->outTextEidt->setTextColor(Qt::blue);
        ui->outTextEidt->insertPlainText(textEditString);

    }

    int temp_ms = 200;
    Sleep(uint(temp_ms));

    clearHboxLayout();





//    ui->outTextEidt->setText(textEditString);
//    ui->outTextEidt->moveCursor(QTextCursor::End);
//    ui->outTextEidt->setTextColor(Qt::red);
//    ui->outTextEidt->insertPlainText(QTime::currentTime().toString());
    return 0;
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
    QObject::connect(ui->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->finishedBtn, SIGNAL(clicked()), this, SLOT(close()));

//    QObject::connect(ui->max_btn)

}
