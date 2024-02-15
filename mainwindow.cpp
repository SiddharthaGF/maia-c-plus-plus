#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Timer.h"
#include "circuference.h"
#include "curve_v.h"
#include "segment.h"
#include "vector.h"
#include "vector3d.h"
#include "vibrant_string.h"
#include "wave.h"
#include "wave3d.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    this->setFixedSize(QSize(880, 570));
    ui->setupUi(this);

    palette0.push_back(QColorConstants::Svg::black);
    palette0.push_back(QColorConstants::Svg::navy);
    palette0.push_back(QColorConstants::Svg::green);
    palette0.push_back(QColorConstants::Svg::aqua);
    palette0.push_back(QColorConstants::Svg::red);
    palette0.push_back(QColorConstants::Svg::purple);
    palette0.push_back(QColorConstants::Svg::maroon);
    palette0.push_back(QColorConstants::Svg::lightgray);
    palette0.push_back(QColorConstants::Svg::darkgray);
    palette0.push_back(QColorConstants::Svg::blue);
    palette0.push_back(QColorConstants::Svg::lime);
    palette0.push_back(QColorConstants::Svg::silver);
    palette0.push_back(QColorConstants::Svg::teal);
    palette0.push_back(QColorConstants::Svg::fuchsia);
    palette0.push_back(QColorConstants::Svg::yellow);
    palette0.push_back(QColorConstants::Svg::white);

    custom_palette.push_back(QColorConstants::Svg::thistle);
    custom_palette.push_back(QColorConstants::Svg::darkred);
    custom_palette.push_back(QColorConstants::Svg::red);
    custom_palette.push_back(QColorConstants::Svg::navy);
    custom_palette.push_back(QColorConstants::Svg::pink);
    custom_palette.push_back(QColorConstants::Svg::red);
    custom_palette.push_back(QColorConstants::Svg::teal);
    custom_palette.push_back(QColorConstants::Svg::purple);
    custom_palette.push_back(QColorConstants::Svg::royalblue);
    custom_palette.push_back(QColorConstants::Svg::darkcyan);
    custom_palette.push_back(QColorConstants::Svg::aqua);
    custom_palette.push_back(QColorConstants::Svg::blue);
    custom_palette.push_back(QColorConstants::Svg::silver);
    custom_palette.push_back(QColorConstants::Svg::white);
    custom_palette.push_back(QColorConstants::Svg::yellow);
    custom_palette.push_back(QColorConstants::Svg::darkgray);
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_btn_draw_g_clicked()
{
    QColor color = QColorConstants::Svg::purple;
    for (int i = 200; i <= 280; i++) {
        canvas.setPixelColor(300, i, color);
    }
    for (int i = 300; i <= 360; i++) {
        canvas.setPixelColor(i, 280, color);
    }
    for (int i = 300; i <= 360; i++) {
        canvas.setPixelColor(i, 200, color);
    }
    for (int i = 200; i <= 220; i++) {
        canvas.setPixelColor(360, i, color);
    }
    for (int i = 240; i <= 280; i++) {

        canvas.setPixelColor(360, i, color);
    }
    for (int i = 330; i <= 360; i++) {
        canvas.setPixelColor(i, 240, color);
    }
    updateCanvas();
}

void MainWindow::updateCanvas()
{
    ui->screen->setPixmap(QPixmap::fromImage(canvas));
}

void MainWindow::on_BtnOnPixel_clicked()
{
    auto v = Vector();
    double x = -2;
    double dx = 0.001;
    v.color0 = QColorConstants::Svg::purple;
    do {
        v.x0 = x;
        v.y0 = x * x;
        v.on(canvas);
        x += dx;
    } while (x <= 0);
    v.color0 = QColorConstants::Svg::red;
    do {
        v.x0 = x;
        v.y0 = x;
        v.on(canvas);
        x += dx;
    } while (x <= 2);
    updateCanvas();
}

void MainWindow::on_BtnInterpolation_clicked()
{
    double dR, dG, dB;
    int cR, cG, cB;
    auto color1 = QColorConstants::Svg::green;
    auto color2 = QColorConstants::Svg::red;
    interpolate_colors(color1, color2, dR, dG, dB, cR, cG, cB);
    for (auto j = 0; j < 500; j++) {
        for (auto i = 0; i < 600; i++) {
            double R = dR * i + cR;
            double G = dG * i + cG;
            double B = dB * i + cB;
            auto color = QColor::fromRgb(R, G, B);
            canvas.setPixelColor(i, j, color);
        }
    }
    updateCanvas();
}

void MainWindow::on_BtnCleanScreen_clicked()
{
    canvas.fill(Qt::white);
    updateCanvas();
}

void MainWindow::on_BtnSegmentsCircunferences_clicked()
{
    auto seg = Segment();
    seg.x0 = -10;
    seg.y0 = -2;
    seg.xf = 6;
    seg.yf = 4;
    seg.color0 = QColorConstants::Svg::purple;
    seg.on(canvas);
    seg.x0 = 6;
    seg.y0 = 0;
    seg.color0 = QColorConstants::Svg::chocolate;
    seg.on(canvas);
    seg.xf = 10;
    seg.yf = 8.33;
    seg.color0 = QColorConstants::Svg::red;
    seg.on(canvas);

    auto cir = Circunference();
    cir.x0 = -2;
    cir.y0 = -1;
    cir.radius = 3;
    cir.color0 = QColorConstants::Svg::fuchsia;
    cir.on(canvas);
    cir.x0 = -3;
    cir.y0 = 1.2;
    cir.radius = 0.3;
    cir.color0 = QColorConstants::Svg::blue;
    cir.on(canvas);
    cir.x0 = 6;
    cir.y0 = 4;
    cir.radius = 1;
    cir.color0 = QColorConstants::Svg::red;
    cir.on(canvas);
    updateCanvas();
}

void MainWindow::on_BtnCurves_clicked()
{
    auto cv = CurveV();
    cv.color0 = QColorConstants::Svg::purple;
    cv.type = 1;
    cv.radius = 2.2;
    cv.x0 = 3;
    cv.y0 = -1;
    cv.on(canvas);
    cv.color0 = QColorConstants::Svg::darkcyan;
    cv.type = 6;
    cv.radius = 1;
    cv.x0 = -3;
    cv.y0 = 3;
    cv.on(canvas);
    cv.color0 = QColorConstants::Svg::green;
    cv.type = 5;
    cv.radius = 1.5;
    cv.x0 = -6;
    cv.y0 = -3;
    cv.on(canvas);
    updateCanvas();
}


void MainWindow::on_BtnCurves2_clicked()
{
    auto cv = CurveV();
    cv.color0 = QColorConstants::Svg::purple;
    cv.type = 4;
    cv.radius = 2.2;
    cv.x0 = -7;
    cv.y0 = 5.5;
    cv.on(canvas);
    cv.color0 = QColorConstants::Svg::red;
    cv.radius = 2;
    cv.x0 = 3;
    cv.y0 = -5.5;
    cv.on(canvas);
    cv.color0 = QColorConstants::Svg::blue;
    cv.radius = 1.5;
    cv.x0 = 7;
    cv.y0 = 3;
    cv.on(canvas);
    updateCanvas();
}


void MainWindow::on_BtnExes_clicked()
{
    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::maroon;
    seg.x0 = seg.x1;
    seg.xf = seg.x2;
    seg.y0 = 0;
    seg.yf = 0;
    seg.on(canvas);
    seg.x0 = 0;
    seg.xf = 0;
    seg.y0 = seg.y1;
    seg.yf = seg.y2;
    seg.on(canvas);
    updateCanvas();
}


void MainWindow::on_BtnTaylor_clicked()
{
    on_BtnExes_clicked();
    auto vec = Vector();
    auto t = -8.0;
    const auto dt = .001;
    const auto tf = 8.0;
    do {
        vec.x0 = t;
        vec.y0 = pow(3, t);
        vec.color0 = QColorConstants::Svg::red;
        vec.on(canvas);
        vec.y0 = 1 + 1.098 * t + 0.603 * pow(t, 2) + 0.22 * pow(t, 3) + 0.06 * pow(t, 4);
        vec.color0 = QColorConstants::Svg::green;
        vec.on(canvas);
        t += dt;
    } while (t <= tf);
    updateCanvas();
}


void MainWindow::on_BtnCurves3_clicked()
{
    on_BtnExes_clicked();
    auto vec = Vector();
    auto t = -8.0;
    const auto dt = .001;
    const auto tf = 8.0;
    do {
        vec.x0 = t;
        vec.y0 = pow(2, t);
        vec.color0 = QColorConstants::Svg::red;
        vec.on(canvas);
        vec.y0 = pow(t, 2) / 5 - 3;
        vec.color0 = QColorConstants::Svg::blue;
        vec.on(canvas);
        vec.y0 = log(t);
        vec.color0 = QColorConstants::Svg::purple;
        vec.on(canvas);
        vec.y0 = sin(3 * M_E * t);
        vec.color0 = QColorConstants::Svg::green;
        vec.on(canvas);
        vec.y0 = pow(t, 3) + pow(t, 2) + 2;
        vec.color0 = QColorConstants::Svg::fuchsia;
        vec.on(canvas);
        t += dt;
    } while (t <= tf);
    updateCanvas();
}


void MainWindow::on_BtnTgCurve_clicked()
{
    on_BtnExes_clicked();
    auto vec = Vector();
    vec.color0 = QColorConstants::Svg::red;
    auto t = -10.0;
    const auto dt = .001;
    const auto tf = 10.0;
    do {
        vec.x0 = t;
        vec.y0 = -0.03 * pow(t, 2) + 3;
        vec.on(canvas);
        t += dt;
    } while (t <= tf);
    auto x_foco = 0.0;
    auto y_foco = 11.333;
    updateCanvas();
}


void MainWindow::on_BtnTn_clicked()
{
    auto xa = 3.0;
    auto ya = -0.03 * pow(xa, 2) + 3;
    auto m = -0.06 * xa;
    auto b = ya - m * xa;
    auto seg = new Segment();
    seg->color0 = QColorConstants::Svg::green;
    seg->x0 = -10;
    seg->y0 = b + m * seg->x0;
    seg->xf = 10;
    seg->yf = b + m * seg->xf;
    seg->on(canvas);
    xa = -5.0;
    ya = -0.03 * pow(xa, 2) + 3;
    m = -0.06 * xa;
    b = ya - m * xa;
    seg->x0 = -10;
    seg->y0 = b + m * seg->x0;
    seg->xf = 10;
    seg->yf = b + m * seg->xf;
    seg->on(canvas);
    xa = 0.0;
    ya = -0.03 * pow(xa, 2) + 3;
    m = -0.06 * xa;
    b = ya - m * xa;
    seg->x0 = -10;
    seg->y0 = b + m * seg->x0;
    seg->xf = 10;
    seg->yf = b + m * seg->xf;
    seg->on(canvas);
    updateCanvas();

    timer = new QTimer(this);
    timer->setInterval(3000);
    connect(timer, &QTimer::timeout, this, [=](){

        seg->off(canvas);
        updateCanvas();
        timer->stop();

        delete seg;
        delete timer;
    });
    timer->start();

}

void MainWindow::on_btn_texture_clicked()
{
    custom_palette = create_palette(QColor::fromRgb(39, 59, 118), QColor::fromRgb(182, 200, 236), 15);
    for (auto j = 0; j < 500; j++) {
        for (auto i = 0; i < 600; i++) {
            auto colorT = (int)fmod(i * cos(i) , 15);
            if (colorT < 0) colorT *= -1;
            else if (colorT == 0) colorT = 1;
            auto c = custom_palette[colorT];
            canvas.setPixelColor(i, j, c);
        }
    }
    updateCanvas();
}


void MainWindow::on_combo_textures_activated(int index)
{
    auto opc = this->ui->combo_textures->currentIndex();

    switch (opc) {
    case 0:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto index = (int)fmod((i * i * j + j * j), 15);
                auto color = palette0[index];
                canvas.setPixelColor(i, j, color);
            }
        }
        break;
    case 1:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = (int)fmod(abs(sin(3 * i) / cos(j)), 15);
                auto c = palette0[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 2:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = (int)fmod(pow(log(i+1), 6) / 2*log(j+3), 15);
                auto c = custom_palette[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 3:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = (int)fmod(2*pow(sin(i), 2) + 3*  pow(cos(j), 2), 15);
                auto c = custom_palette[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 4:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = (int)fmod(pow(sin(i), 4) + pow(log(j + 5), 3), 15);
                auto c = palette0[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 5:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = (int)fmod(log(3*i + j+4) *10, 10);
                auto c = custom_palette[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 6:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = gcd((int)fmod(cos(i) + sin(i) * j, 4), 0);
                auto c = palette0[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 7:
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = gcd((int)fmod(log(2 + sin(i*j*10)), 7), 0);
                auto c = custom_palette[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    case 8:
        custom_palette = create_palette(QColor::fromRgb(39,59,118), QColor::fromRgb(182,200,236), 5);
        for (auto j = 0; j < 500; j++) {
            for (auto i = 0; i < 600; i++) {
                auto colorT = (int)fmod((i + 4 * sqrt(i * 3) - cos(i) * 1.3 + (i * j) * sin(j) / 2) , 15);
                if (colorT < 0) colorT *= -1;
                auto c = custom_palette[colorT];
                canvas.setPixelColor(i, j, c);
            }
        }
        break;
    // Aqui añadimos mas texturas
    default:
        break;
    }
    updateCanvas();
}

void MainWindow::on_btn_off_curve_clicked()
{
    auto cir = new Circunference();
    cir->radius = 0.3;
    timer = new QTimer(this);
    timer->setInterval(10);
    auto tt = new Timer(-8.0, 0.02);
    connect(timer, &QTimer::timeout, this, [=](){
        auto t = tt->getTime();
        cir->x0 = t;
        if (t < -2) {
            cir->y0 = -(t * t + 10 * t + 16) / 2.25;
        } else if (t < 2) {
            cir->y0 = -(t * t - 4) / 1.333;
        } else if (t <= 4) {
            cir->y0 = -(t * t - 6 * t + 8) / .5;
        } else {;
            timer->stop();
            delete cir;
            delete tt;
            delete timer;
        }
        cir->on(canvas);
        updateCanvas();
        cir->off(canvas);
        tt->increments();
    });
    timer->start();
}


void MainWindow::on_btn_reflexion_clicked()
{
    on_BtnExes_clicked();
    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::red;

    seg.x0 = -1;
    seg.y0 = 0;
    seg.xf = -2;
    seg.yf = -8.33;
    seg.on(canvas);

    seg.x0 = -4;
    seg.y0 = 8.33;

    seg.on(canvas);

    updateCanvas();

    /*auto cir = new Circunference();
    cir->radius = 0.3;
    timer = new QTimer(this);
    timer->setInterval(10);
    auto tt = new Timer(-1.0, 0.02);
    connect(timer, &QTimer::timeout, this, [=](){
        auto t = tt->getTime();
        cir->x0 = t;
        if (t > -2) {
            cir->y0 = 8.33 * t + 8.33;
        } else if (t > -4) {
            cir->y0 = -8.33 * (t - 1);
        } else {
            timer->stop();
            delete cir;
            delete tt;
            delete timer;
        }
        cir->on(canvas);
        updateCanvas();
        cir->off(canvas);
        tt->decrements();
    });
    timer->start();*/
}


void MainWindow::on_btn_level_curves_clicked()
{
    auto vec = Vector();

    auto t = -8.0;
    auto dt = 0.001;
    on_BtnExes_clicked();
    while (t <= 8) {
        vec.x0 = t;
        vec.color0 = QColorConstants::Svg::purple;
        vec.y0 = 3 * pow(M_E, -4 * t);
        vec.on(canvas);
        vec.color0 = QColorConstants::Svg::green;
        vec.y0 = 6 * pow(M_E, -4 * t);
        vec.on(canvas);
         vec.color0 = QColorConstants::Svg::blue;
        vec.y0 = 8 * pow(M_E, -4 * t);
        vec.on(canvas);
        vec.color0 = QColorConstants::Svg::darkcyan;
        vec.y0 = -4 * pow(M_E, -4 * t);
        vec.on(canvas);
        vec.color0 = QColorConstants::Svg::fuchsia;
        vec.y0 = -7 * pow(M_E, -4 * t);
        vec.on(canvas);
        vec.color0 = QColorConstants::Svg::yellow;
        vec.y0 = -5 * pow(M_E, -4 * t);
        vec.on(canvas);
        vec.color0 = QColorConstants::Svg::royalblue;
        vec.y0 = -10 * pow(M_E, -4 * t);
        vec.on(canvas);
        t += dt;
    }
    updateCanvas();
}


void MainWindow::on_btn_vector_3d_clicked()
{
    auto v3d = Vector3D();
    v3d.color0 = QColorConstants::Svg::purple;
    auto t = 0.0;
    auto dt = 0.001;
    do {
        v3d.x0 = t / 3 - 2;
        v3d.y0 = 1 + 3 * sin(t);
        v3d.z0 = 2 + 3 * cos(t);
        v3d.on(canvas);
        t += dt;
    } while (t <= 15);
    updateCanvas();
}


void MainWindow::on_Libre_clicked()
{
    auto v3d = Vector3D();
    v3d.color0 = QColorConstants::Svg::purple;
    auto t = 0.0, dt = 0.1;
    do {
        auto h = 0.0, dh = 0.2;
        do {
            v3d.x0 = -4 + 2 * cos(t);
            v3d.y0 = 1 + 3 * sin(t);
            v3d.z0 = -2 + h / 3;
            v3d.on(canvas);
            h += dh;
        } while (h <= 9);
        t += dt;
    } while (t <= 2 * M_PI);

    v3d.color0 = QColorConstants::Svg::red;
    t = -M_PI_2, dt = 0.1;
    auto rd = 2.0;
    do {
        auto h = 0.0, dh = 0.07;
        do {
            v3d.x0 = 2 + rd * cos(t) * cos(h);
            v3d.y0 = 2 + rd * cos(t) * sin(h);
            v3d.z0 = 2 + rd * sin(t);
            v3d.on(canvas);
            h += dh;
        } while (h <= 2 * M_PI);
        t += dt;
    } while (t <= M_PI_2);

    v3d.color0 = QColorConstants::Svg::blue;
    t = 0, dt = 0.1;
    rd = 0.8;
    do {
        auto h = 0.0, dh = 0.07;
        do {
            v3d.x0 = 2 + rd * (4 + cos(t)) * cos(h);
            v3d.y0 = -2 + rd * (4 + cos(t)) * sin(h);
            v3d.z0 = -4 + rd * sin(t);
            v3d.on(canvas);
            h += dh;
        } while (h <= 2 * M_PI);
        t += dt;
    } while (t <= 2 * M_PI);

    updateCanvas();
}


void MainWindow::on_btn_platform_clicked()
{
    auto h1 = -3.67;
    auto h2 = -4.67;
    auto h3 = -6.07;
    auto h4 = -8;

    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::gray;

    seg.x0 = seg.x1;
    seg.xf = seg.x2;
    seg.y0 = h1;
    seg.yf = h1;

    seg.on(canvas);
    seg.y0 = h2;
    seg.yf = h2;

    seg.on(canvas);

    seg.y0 = h3;
    seg.yf = h3;
    seg.on(canvas);

    seg.y0 = h4;
    seg.yf = h4;
    seg.on(canvas);

    seg.y0 = h1;
    seg.yf = seg.y1;

    seg.x0 = 0.6;
    seg.xf = 3;
    seg.on(canvas);

    seg.x0 = 2;
    seg.xf = 8;
    seg.on(canvas);

    seg.x0 = 3;
    seg.xf = 21;
    seg.on(canvas);

    seg.x0 = 4;
    seg.xf = 55;
    seg.on(canvas);

    seg.x0 = 5;
    seg.xf = 144;
    seg.on(canvas);

    seg.x0 = -0.6;
    seg.xf = -3;
    seg.on(canvas);

    seg.x0 = -2;
    seg.xf = -8;
    seg.on(canvas);

    seg.x0 = -3;
    seg.xf = -21;
    seg.on(canvas);

    seg.x0 = -4;
    seg.xf = -55;
    seg.on(canvas);

    seg.x0 = -5;
    seg.xf = -144;
    seg.on(canvas);

    updateCanvas();
}


void MainWindow::on_btn_simple_wave_clicked()
{
    auto w = Wave();
    w.v = 9.3;
    w.w = 1.5;
    w.m = 1;
    w.x0 = -5;
    w.y0 = 0;
    w.palette = create_palette(QColor::fromRgb(200, 200, 200), QColor::fromRgb(30, 30, 30), 16);
    w.simple(canvas);
    updateCanvas();
}


void MainWindow::on_btn_simple_wave_2_clicked()
{
    auto w = Wave();
    w.v = 9.3;
    w.w = 1.5;
    w.m = 1;
    w.palette = palette0;
    w.interference(canvas);
    updateCanvas();
}


void MainWindow::on_btn_animation_simple_wave_clicked()
{
    auto w = new Wave();
    w->m = 1;
    w->w = 1.5;
    w->v = 9.3;
    w->palette = create_palette(QColor::fromRgb(200, 200, 200), QColor::fromRgb(30, 30, 30), 15);

    auto time = 4000;

    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        w->simple(canvas);
        updateCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= 10000) {
            timer->stop();
            timer = new QTimer(this);
        }
        if (w->stepX == 700) {
            w->stepX = 1;
        }
        else {
            w->stepX = 700;
        }
        w->t += 0.005;
    });
    timer->start();
}


void MainWindow::on_btn_animation_interference_clicked()
{
    auto w = new Wave();
    w->m = 1;
    w->w = 1.5;
    w->v = 9.3;
    w->palette = palette0;

    auto time = 10000;

    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        w->interference(canvas);
        updateCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= time) {
            timer->stop();
            timer = new QTimer(this);
            delete w;
        }
        w->skipFrame();
        w->t += 0.005;
    });
    timer->start();
}

void MainWindow::on_btn_animation_simple3d_clicked()
{
    on_btn_platform_clicked();

    auto time = 10000;

    auto w = new Wave3D();
    w->m = 0.4;
    w->w = 2;
    w->v = 9.3;
    w->color0 = QColorConstants::Svg::crimson;

    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        on_btn_platform_clicked();
        w->simple(canvas);
        refreshCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= time) {
            timer->stop();
            timer = new QTimer(this);
            delete w;
        }
        w->t += 0.005;
    });
    timer->start();
}


void MainWindow::on_btn_animation_interferece3d_clicked()
{
    on_btn_platform_clicked();

    auto time = 10000;

    auto w = new Wave3D();
    w->m = 0.4;
    w->w = 2;
    w->v = 9.3;
    w->color0 = QColorConstants::Svg::royalblue;

    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        on_btn_platform_clicked();
        w->interference(canvas);
        refreshCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= time) {
            timer->stop();
            timer = new QTimer(this);
            delete w;
        }
        w->t += 0.005;
    });
    timer->start();
}

void MainWindow::refreshCanvas()
{
    updateCanvas();
    canvas.fill(Qt::white);
}


void MainWindow::on_btn_values_simple_wave_clicked()
{
    QDialog *modal = new QDialog(this);
    modal->setFixedSize(QSize(1000, 800));
    modal->setWindowTitle("Tabla de datos");

    auto w = new Wave();
    w->m = 0.6;
    w->w = 2;
    w->v = 9.3;
    w->t = 0;

    QTableWidget *dataTable = new QTableWidget(modal);
    dataTable->setRowCount(w->sy2);
    dataTable->setColumnCount(w->sx2);

    for (int row = 0; row < w->sy2; ++row) {
        for (int col = 0; col < w->sx2; ++col) {
            auto value = w->getData(col, row, 0);
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(value));
            dataTable->setItem(row, col, item);
        }
    }

    for (int col = 0; col < w->sx2; ++col) {
        dataTable->setColumnWidth(col, 50);
    }

    QFile file("datos 2d.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        for (int row = 0; row < 1; ++row) {
            for (int col = 0; col < 100; ++col) {
                stream << w->getData(col, row, 0) << "\n";
            }
        }

        file.close();
    }

    QVBoxLayout *layout = new QVBoxLayout(modal);
    layout->addWidget(dataTable);
    modal->setLayout(layout);

    modal->exec();
}


void MainWindow::on_btn_values_simple_wave_3d_clicked()
{
    QDialog *modal = new QDialog(this);
    modal->setFixedSize(QSize(1000, 800));
    modal->setWindowTitle("Tabla de datos");

    auto w = new Wave3D();
    w->m = 0.6;
    w->w = 2;
    w->v = 9.3;
    w->t = 0;

    QTableWidget *dataTable = new QTableWidget(modal);
    dataTable->setRowCount(w->rangeY * 2 * w->x2);
    dataTable->setColumnCount(w->rangeX * 2 * w->x2);

    for (int row = 0; row < w->sy2; ++row) {
        for (int col = 0; col < w->sx2; ++col) {
            auto value = w->getData(col, row, 0);
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(value));
            dataTable->setItem(row, col, item);
        }
    }

    for (int col = 0; col < w->rangeX * 2 * w->x2; ++col) {
        dataTable->setColumnWidth(col, 70);
    }

    QFile file("datos 3d.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        for (int row = 0; row < 1; ++row) {
            for (int col = 0; col < 100; ++col) {
                stream << w->getData(col, row, 0) << "\n";
            }
        }

        file.close();
    }

    QVBoxLayout *layout = new QVBoxLayout(modal);
    layout->addWidget(dataTable);
    modal->setLayout(layout);

    modal->exec();
}


void MainWindow::on_btn_vibrant_string_clicked()
{
    auto vs = new VibrantString();
    vs->color0 = QColorConstants::Svg::purple;
    vs->dx = 0.002;
    vs->l = 6;
    vs->x0 = 0;
    vs->xf = 6;
    auto time = 20000;

    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        vs->on(canvas);
        vs->skipFrame();
        refreshCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= time) {
            timer->stop();
            timer = new QTimer(this);
            delete vs;
        }
        vs->t += 0.0025;
    });
    timer->start();
}

double dydt(double t, double y, double gamma = 0.001) {
    return gamma * y * (500 - y);
}

double dydt2(double t, double y, double gamma = 0.0011) {
    return gamma * y * (500 - y);
}


void MainWindow::on_btn_pandemic_simulation_clicked()
{
    auto t0 = 0.0;
    auto y0 = 1.0;
    auto tf = 20.0;
    auto h = 0.5;

    auto n = (int)(tf - t0) / h;

    QDialog *modal = new QDialog(this);
    modal->setWindowTitle("Tabla de datos");

    QTableWidget *dataTable = new QTableWidget(modal);
    dataTable->setRowCount(n);
    dataTable->setColumnCount(3);

    auto i = 0;

    auto seg_x = Segment();
    auto seg_y = Segment();
    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::purple;
    auto cir = Circunference();
    cir.radius = 0.1;
    cir.color0 = QColorConstants::Svg::red;

    seg_x.x0 = -0.3;
    seg_x.xf = 19.0;
    seg_x.y0 = 0.0;
    seg_x.yf = 0.0;
    seg_x.on(canvas);

    seg_y.x0 = 0.0;
    seg_y.xf = 0.0;
    seg_y.y0 = -0.3;
    seg_y.yf = 15.66;
    seg_y.on(canvas);
    auto M = 500.0;
    double gamma = 0.001;

    auto x = new vector<double>;
    auto y = new vector<double>;

    do {
        auto k1 = dydt2(t0, y0);
        auto k2 = dydt2(t0 + 0.5 * h, y0 + 0.5 * h * k1);
        auto k3 = dydt2(t0 + 0.5 * h, y0 + 0.5 * h * k2);
        auto k4 = dydt2(t0 + h, y0 + h * k3);
        auto yi = y0 + (h/6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        t0 += h;
        y0 = yi;
        x->push_back(t0);
        y->push_back(y0);
        QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(t0));
        dataTable->setItem(i, 0, item);
        item = new QTableWidgetItem(QString("%1").arg(yi));
        dataTable->setItem(i, 1, item);
        i++;
    } while (t0 < tf);


    double scale_x = seg_x.xf / x->at(x->size() - 1);
    double scale_y = seg_y.yf / y->at(y->size() - 1);

    seg.x0 = 0.0;
    seg.y0 = 0.0;
    cir.x0 = 0.0;
    cir.y0 = 0.0;
    cir.on(canvas);

    for (i = 0; i < x->size(); i++) {
        cir.x0 = x->at(i) * scale_x;
        cir.y0 = y->at(i) * scale_y;
        cir.on(canvas);
        seg.xf = cir.x0;
        seg.yf = cir.y0;
        seg.on(canvas);
        seg.x0 = cir.x0;
        seg.y0 = cir.y0;
    }

    updateCanvas();

    QVBoxLayout *layout = new QVBoxLayout(modal);
    layout->addWidget(dataTable);
    modal->setLayout(layout);

    modal->exec();
}


void MainWindow::on_btn_pandemic_simulation_analitic_clicked()
{
    auto t0 = 0.0;
    auto y0 = 1.0;
    auto tf = 20.0;
    auto h = 1.0;

    auto n = (int)(tf - t0) / h;

    QDialog *modal = new QDialog(this);
    modal->setWindowTitle("Tabla de datos");

    QTableWidget *dataTable = new QTableWidget(modal);
    dataTable->setRowCount(n);
    dataTable->setColumnCount(3);

    auto i = 0;

    auto seg_x = Segment();
    auto seg_y = Segment();
    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::fuchsia;
    seg.dx = 0.05;
    auto cir = Circunference();
    cir.radius = 0.1;
    cir.color0 = QColorConstants::Svg::blue;

    seg_x.x0 = -0.3;
    seg_x.xf = 19.0;
    seg_x.y0 = 0.0;
    seg_x.yf = 0.0;
    seg_x.on(canvas);

    seg_y.x0 = 0.0;
    seg_y.xf = 0.0;
    seg_y.y0 = -0.3;
    seg_y.yf = 15.66;
    seg_y.on(canvas);
    auto M = 500.0;
    double gamma = 0.0013;

    updateCanvas();

    auto x = new vector<double>;
    auto y = new vector<double>;

    do {
        auto yi = M / (1 + (M -1) * pow(M_E, -gamma * M * t0));
        t0 += h;
        y0 = yi;

        x->push_back(t0);
        y->push_back(y0);

        QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(t0));
        dataTable->setItem(i, 0, item);
        item = new QTableWidgetItem(QString("%1").arg(yi));
        dataTable->setItem(i, 1, item);
        i++;
    } while (t0 < tf);

    double scale_x = seg_x.xf / x->at(x->size() - 1);
    double scale_y = seg_y.yf / y->at(y->size() - 1);

    seg.x0 = 0.0;
    seg.y0 = 0.0;
    cir.x0 = 0.0;
    cir.y0 = 0.0;
    cir.on(canvas);

    for (i = 0; i < x->size(); i++) {
        cir.x0 = x->at(i) * scale_x;
        cir.y0 = y->at(i) * scale_y;
        cir.on(canvas);
        seg.xf = cir.x0;
        seg.yf = cir.y0;
        seg.on(canvas);
        seg.x0 = cir.x0;
        seg.y0 = cir.y0;
    }

    updateCanvas();

    QVBoxLayout *layout = new QVBoxLayout(modal);
    layout->addWidget(dataTable);
    modal->setLayout(layout);

    modal->exec();
}


void MainWindow::on_btn_pandemic_simulation_rk_1_clicked()
{
    auto t0 = 0.0;
    auto y0 = 1.0;
    auto tf = 20.0;
    double h = 1.0;

    auto n = (int)(tf - t0) / h;

    QDialog *modal = new QDialog(this);
    modal->setWindowTitle("Tabla de datos");

    QTableWidget *dataTable = new QTableWidget(modal);
    dataTable->setRowCount(n);
    dataTable->setColumnCount(3);

    auto i = 0;

    auto seg_x = Segment();
    auto seg_y = Segment();
    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::purple;
    auto cir = Circunference();
    cir.radius = 0.1;
    cir.color0 = QColorConstants::Svg::red;

    seg_x.x0 = -0.3;
    seg_x.xf = 19.0;
    seg_x.y0 = 0.0;
    seg_x.yf = 0.0;
    seg_x.on(canvas);

    seg_y.x0 = 0.0;
    seg_y.xf = 0.0;
    seg_y.y0 = -0.3;
    seg_y.yf = 15.66;
    seg_y.on(canvas);
    auto M = 500.0;
    double gamma = 0.0011;

    auto x = new vector<double>;
    auto y = new vector<double>;

    do {
        auto k1 = dydt(t0, y0);
        auto k2 = dydt(t0 + 0.5 * h, y0 + 0.5 * h * k1);
        auto k3 = dydt(t0 + 0.5 * h, y0 + 0.5 * h * k2);
        auto k4 = dydt(t0 + h, y0 + h * k3);
        auto yi = y0 + (h/6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        t0 += h;
        y0 = yi;
        x->push_back(t0);
        y->push_back(y0);
        QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(t0));
        dataTable->setItem(i, 0, item);
        item = new QTableWidgetItem(QString("%1").arg(yi));
        dataTable->setItem(i, 1, item);
        i++;
    } while (t0 < tf);


    double scale_x = seg_x.xf / x->at(x->size() - 1);
    double scale_y = seg_y.yf / y->at(y->size() - 1);

    seg.x0 = 0.0;
    seg.y0 = 0.0;
    cir.x0 = 0.0;
    cir.y0 = 0.0;
    cir.on(canvas);

    for (i = 0; i < x->size(); i++) {
        cir.x0 = x->at(i) * scale_x;
        cir.y0 = y->at(i) * scale_y;
        cir.on(canvas);
        seg.xf = cir.x0;
        seg.yf = cir.y0;
        seg.on(canvas);
        seg.x0 = cir.x0;
        seg.y0 = cir.y0;
    }

    updateCanvas();

    QVBoxLayout *layout = new QVBoxLayout(modal);
    layout->addWidget(dataTable);
    modal->setLayout(layout);

    modal->exec();
}

