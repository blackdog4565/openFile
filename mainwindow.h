#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class QAction;
class QMenu;
namespace Ui {
 class MainWindow;
}

class MainWindow : public QMainWindow
{
 Q_OBJECT

public:
 explicit MainWindow(QWidget *parent = 0);
 virtual ~MainWindow();

private slots:
    void open();
 void handleButton();

private:
 void createActions();
 QPushButton *m_button;
};

#endif // MAINWINDOW_H
