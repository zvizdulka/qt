#include "browser.h"
#include "ui_browser.h"
#include <QUrl>
#include <QTextBrowser>
Browser::Browser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browser)
{
    ui->setupUi(this);
}

Browser::~Browser()
{
    delete ui;
}
void Browser::Reload(){
    //ui->preview->load(QUrl("http://www.google.com/"));
    ui->preview->load(QUrl::fromLocalFile("/Users/ulanabolotskih/build-test3-Qt_6_4_2_for_macOS-Debug/test3.app/Contents/MacOS/scan.html"));
}
