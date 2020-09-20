#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::received(QJsonObject _json)
{
    this->_json = _json;
    QJsonDocument doc(_json);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    ui->textEdit_2->setText(strJson);
}

void MainWindow::on_URL_clicked()
{
   QUrl url = QUrl(ui->textEdit->toPlainText());
   client_.init(url, true, ROLE_RECEIVER);
   connect(&client_, &client::received, this, &MainWindow::received);
}
