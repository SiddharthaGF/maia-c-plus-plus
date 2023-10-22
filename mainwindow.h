#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QImage canvas;
    std::vector<QColor> palette0;
    std::vector<QColor> customPalette;
    std::vector<QColor> createPalette(QColor, QColor, int);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_to_do_something_clicked();

private:
    QTimer *timer;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
