#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <client.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    client client_;
    void received(QJsonObject _json);
private slots:
    void on_URL_clicked();

private:
    Ui::MainWindow *ui;
    QJsonObject _json;
};

#endif // MAINWINDOW_H
