#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <treeviewer.h>


#define APP_VERSION "0.1"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // read settings
    this->setWindowTitle(tr("My Family Tree - v%1").arg(APP_VERSION));
    this->settings = new QSettings("settings.ini", QSettings::IniFormat, this);
    this->move(settings->value("pos").toPoint());
    this->resize(settings->value("size").toSize());

    // set openglwidget
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    settings->setValue("pos", QVariant(this->pos()).toPoint());
    settings->setValue("size", QVariant(this->size()).toSize());
}

