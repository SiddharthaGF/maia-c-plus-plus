#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QTimer"
#include <QMainWindow>
#include <chrono>
#include <QTime>
#include <QDebug>

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
    void on_btn_draw_g_clicked();

    void on_BtnOnPixel_clicked();

    void on_BtnInterpolation_clicked();

    void on_BtnCleanScreen_clicked();

    void on_BtnSegmentsCircunferences_clicked();

    void on_BtnCurves_clicked();

    void on_BtnCurves2_clicked();

    void on_BtnExes_clicked();

    void on_BtnTaylor_clicked();

    void on_BtnCurves3_clicked();

    void on_BtnTgCurve_clicked();

    void on_BtnTn_clicked();

    void on_combo_textures_activated(int index);

    void on_btn_texture_clicked();

    void on_btn_off_curve_clicked();

    void on_btn_reflexion_clicked();

    void on_btn_level_curves_clicked();

    void on_btn_vector_3d_clicked();

    void on_Libre_clicked();

    void on_btn_platform_clicked();

    void on_btn_simple_wave_clicked();

    void on_btn_simple_wave_2_clicked();

    void on_btn_animation_simple_wave_clicked();

    void on_btn_animation_interference_clicked();

    void on_btn_animation_simple3d_clicked();

    void on_btn_animation_interferece3d_clicked();

    void on_btn_values_simple_wave_clicked();

    void on_btn_values_simple_wave_3d_clicked();

    void on_btn_vibrant_string_clicked();

    void on_btn_pandemic_simulation_clicked();

    void on_btn_pandemic_simulation_analitic_clicked();

    void on_btn_pandemic_simulation_rk_1_clicked();

private:
    Ui::MainWindow *ui;
    QImage canvas = QImage(600, 500, QImage::Format_ARGB32);
    QTimer *timer = new QTimer(this);
    vector<QColor> palette0;
    vector<QColor> custom_palette;

    void updateCanvas();

    vector<QColor> create_palette(QColor start, QColor end, int variaciones) {
        vector<QColor> palette;
        double dR, dG, dB;
        int cR, cG, cB;
        interpolate_colors(start, end, dR, dG, dB, cR, cG, cB, variaciones);
        qDebug() << cR << "+" << dR << "* X";
        qDebug() << cG << "+" << dG << "* X";
        qDebug() << cB << "+" << dB << "* X";
        for (int i = 0; i < variaciones; i++) {
            int R = cR + dR * i;
            int G = cG + dG * i;
            int B = cB + dB * i;
            palette.push_back(QColor::fromRgb(R, G, B));
        }
        return palette;
    }

    static void interpolate_colors(QColor initial, QColor final, double &delta_r, double &delta_g, double &delta_b, int &const_R, int &const_G, int &const_B, double delta_x = 600)
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
