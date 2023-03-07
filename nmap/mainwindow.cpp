#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>
#include <arpa/inet.h>
#include <cstdlib>
#include <QMessageBox>
#include <QUrl>
#include <QApplication>
#include <QWidget>
#include "browser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString ipAddress = ui->adress->text();
    const char* ip = qPrintable(ipAddress);
    struct sockaddr_in sa;
    if(inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0) {
            QString cmd = "/usr/local/bin/nmap -sV --script vulners --script-args mincvss=5.0 -oX scan.xml --stylesheet=nmap-bootstrap.xsl " + ipAddress;
            system(qPrintable(cmd));
            system("xsltproc scan.xml -o scan.html");
            //system("open scan.html -a Safari");
            browser.Reload();
            browser.show();
    }
    else {
        QMessageBox::about(this, "", "IP ERROR! ");
    }
}
