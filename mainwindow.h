#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wave.h"
#include "wave3d.h"
#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_WaveAnimation_clicked();
    void on_Wave3DAnimation_clicked();
    void on_StopAnimation_clicked();
    void on_ButtonTests_clicked();

private:
    QTimer *timer;
    QImage canvas;
    vector<QColor> palette0;
    vector<QColor> customPalette;
    Ui::MainWindow *ui;

    Wave *w = new Wave();
    Wave3D *w3 = new Wave3D();

    void updateCanvas();
    void refeshCanvas();
    void enableButtons(bool = true);
    void recogniceButtons();

    vector<QColor> createPalette(QColor start, QColor end, int variaciones) {
        vector<QColor> palette;
        double deltaR = (end.red() - start.red()) / (variaciones - 1);
        double deltaG = (end.green() - start.green()) / (variaciones - 1);
        double deltaB = (end.blue() - start.blue()) / (variaciones - 1);
        palette.push_back(start);
        for (int i = 1; i < variaciones - 1; i++) {
            int R = start.red() + deltaR * i;
            int G = start.green() + deltaG * i;
            int A = start.blue() + deltaB * i;
            palette.push_back(QColor::fromRgb(R, G, A));
        }
        palette.push_back(end);
        return palette;
    }

    void CleanMemory() {
        delete w;
        delete w3;
    }


};
#endif // MAINWINDOW_H
