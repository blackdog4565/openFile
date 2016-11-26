#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
int main(int argc, char *argv[])
{
 QApplication app(argc, argv);

MainWindow mainWindow;
 mainWindow.showMaximized();
 return app.exec();
}
