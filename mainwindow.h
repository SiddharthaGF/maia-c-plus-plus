#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtimer.h"
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
    void refreshCanvas();
    ~MainWindow();

private slots:
    void on_BtnDrawG_clicked();

    void on_BtnOnPixel_clicked();

    void on_BtnInterpolation_clicked();

    void on_BtnCleanScreen_clicked();

    void on_BtnSegmentsCircunferences_clicked();

    void on_BtnCurves_clicked();

    void on_BtnCurves2_clicked();

    void on_BtnExes_clicked();

    void on_BtnTaylor_clicked();

private:
    Ui::MainWindow *ui;
    QImage canvas = QImage(600, 500, QImage::Format_ARGB32);
    QTimer timer = QTimer(this);
    vector<QColor> palette0;
    vector<QColor> customPalette;

    void updateCanvas();

    vector<QColor> createPalette(QColor start, QColor end, int variaciones) {
        vector<QColor> palette;
        double dR, dG, dB;
        int cR, cG, cB;
        interpolateColors(start, end, dR, dG, dB, cR, cG, cB);
        for (int i = 0; i < variaciones - 1; i++) {
            int R = cR + dR * i;
            int G = cG + dG * i;
            int B = cB + dB * i;
            palette.push_back(QColor::fromRgb(R, G, B));
        }
        return palette;
    }

    static void interpolateColors(QColor initial, QColor final, double &delta_r, double &delta_g, double &delta_b, int &const_R, int &const_G, int &const_B, double delta_x = 600)
    {
        delta_r = (final.red() - initial.red()) / delta_x;
        delta_g = (final.green() - initial.green()) / delta_x;
        delta_b = (final.blue() - initial.blue()) / delta_x;
        const_R = initial.red();
        const_G = initial.green();
        const_B = initial.blue();
    }
};
#endif // MAINWINDOW_H
