#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "circuference.h"
#include "curve_v.h"
#include "segment.h"
#include "vector.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    this->setFixedSize(QSize(790, 555));
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

    customPalette = createPalette(QColorConstants::Svg::white, QColorConstants::Svg::black, 16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnDrawG_clicked()
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

void MainWindow::refreshCanvas()
{
    updateCanvas();
    canvas.fill(Qt::white);
}

void MainWindow::on_BtnInterpolation_clicked()
{
    double dR, dG, dB;
    int cR, cG, cB;
    auto color1 = QColorConstants::Svg::green;
    auto color2 = QColorConstants::Svg::red;
    interpolateColors(color1, color2, dR, dG, dB, cR, cG, cB);
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

    cv.color0 = QColorConstants::Svg::pink;
    cv.type = 2;
    cv.radius = 2;
    cv.x0 = -3;
    cv.y0 = 3;
    cv.on(canvas);

    cv.color0 = QColorConstants::Svg::gold;
    cv.type = 3;
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
    cv.x0 = 3;
    cv.y0 = -1;
    cv.on(canvas);
    cv.color0 = QColorConstants::Svg::red;
    cv.radius = 2;
    cv.x0 = -3;
    cv.y0 = 3;
    cv.on(canvas);
    cv.color0 = QColorConstants::Svg::blue;
    cv.radius = 1.5;
    cv.x0 = -6;
    cv.y0 = -3;
    cv.on(canvas);
    updateCanvas();
}


void MainWindow::on_BtnExes_clicked()
{
    auto seg = Segment();
    seg.color0 = QColorConstants::Svg::maroon;
    seg.x0 = -10;
    seg.xf = 10;
    seg.on(canvas);
    seg.x0 = 0;
    seg.xf = 0;
    seg.y0 = -8.33;
    seg.yf = 8.33;
    seg.on(canvas);
    updateCanvas();
}


void MainWindow::on_BtnTaylor_clicked()
{
    auto vec = Vector();
    auto t = -10.0;
    const auto dt = .001;
    const auto tf = 10.0;
    do {
        vec.x0 = t;
        vec.y0 = pow(2, t);
        vec.color0 = QColorConstants::Svg::red;
        vec.on(canvas);
        vec.y0 = 1 + pow(t, 2) * pow(log(2), 2) / 2 + t * log(2);
        vec.color0 = QColorConstants::Svg::blue;
        vec.on(canvas);
        vec.y0 = 1 + pow(t, 2) * pow(log(2), 2) / 2 + t * log(2) + pow(t, 3) * pow(log(2), 3) / 6;
        vec.color0 = QColorConstants::Svg::purple;
        vec.on(canvas);
        t += dt;
    } while (t <= tf);
    updateCanvas();
}

