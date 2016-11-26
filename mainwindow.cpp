#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
 : QMainWindow(parent)
{
 // создаем кнопку
 m_button = new QPushButton("My Button", this);
 // устанавливаем размер и положение кнопки
 m_button->setGeometry(QRect(QPoint(100, 100),
 QSize(200, 50)));

// подключаем сигнал к соответствующему слоту
 connect(m_button, SIGNAL (released()), this, SLOT (open()));
}
static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}
void MainWindow::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}
void MainWindow::createActions()
{
    m_button->setText("Example");
    QAction *openAct = m_button->addAction(&MainWindow::open);
    openAct->setShortcut(QKeySequence::Open);
}
void MainWindow::handleButton()
{
 // меняем текст
 m_button->setText("Example");
 // изменяем размер кнопки
 m_button->resize(100,100);

}

MainWindow::~MainWindow()
{

}
