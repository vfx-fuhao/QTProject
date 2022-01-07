#include "toolsinstall.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolsInstall w;
    w.show();

    return a.exec();
}
