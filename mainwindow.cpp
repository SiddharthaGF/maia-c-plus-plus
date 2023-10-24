#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSettings>
#include "ribbon.h"
#include "wave.h"
#include "wave3d.h"
#include <vector>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , canvas(700,540 , QImage::Format_ARGB32)
{
    ui->setupUi(this);
    timer = new QTimer(this);


    palette0.push_back(Qt::black);
    palette0.push_back(QColorConstants::Svg::navy);
    palette0.push_back(Qt::green);
    palette0.push_back(QColorConstants::Svg::aqua);
    palette0.push_back(Qt::red);
    palette0.push_back(QColorConstants::Svg::purple);
    palette0.push_back(QColorConstants::Svg::maroon);
    palette0.push_back(QColorConstants::Svg::lightgray);
    palette0.push_back(QColorConstants::Svg::darkgray);
    palette0.push_back(Qt::blue);
    palette0.push_back(QColorConstants::Svg::lime);
    palette0.push_back(QColorConstants::Svg::silver);
    palette0.push_back(QColorConstants::Svg::teal);
    palette0.push_back(QColorConstants::Svg::fuchsia);
    palette0.push_back(Qt::yellow);
    palette0.push_back(Qt::white);

    QColor start = QColor::fromRgb(250, 255, 255);
    QColor end = QColor::fromRgb(0, 0, 0);
    customPalette = createPalette(start, end, 16);
}

MainWindow::~MainWindow()
{
    CleanMemory();
    delete ui;
}

void MainWindow::on_WaveAnimation_clicked()
{
    enableButtons(false);
    w = new Wave();
    w->m = 1;
    w->w = 1.5;
    w->v = 9.3;
    w->palette = palette0;
    w->X = {-8, 6.15};
    w->Y = {8, -6.15};
    w->multiplier = 4;

    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        w->on(canvas);
        updateCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= 10000) {
            timer->stop();
            timer = new QTimer(this);
            enableButtons();
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

void MainWindow::on_Wave3DAnimation_clicked()
{
    enableButtons(false);
    w3 = new Wave3D();
    w3->m = .4;
    w3->w = 2.2;
    w3->v = 9.3;
    w3->X = {3, -3};
    w3->Y = {0, 0};
    w3->alpha = 0.8;
    w3->color = QColorConstants::Svg::red;
    QTime timeStart = QTime::currentTime();
    connect(timer, &QTimer::timeout, this, [=](){
        w3->on(canvas);
        refeshCanvas();
        if (timeStart.msecsTo(QTime::currentTime()) >= 10000) {;
            timer->stop();
            timer = new QTimer(this);
            enableButtons();
        }
        w3->t += 0.005;
    });

    timer->start();
}


void MainWindow::on_StopAnimation_clicked()
{
    timer->stop();
    timer = new QTimer(this);
    enableButtons();
}


void MainWindow::on_ButtonTests_clicked()
{
    Ribbon *s = new Ribbon();
    s->color = QColorConstants::Svg::purple;
    s->on(canvas);
    updateCanvas();
    delete s;
}

void MainWindow::updateCanvas()
{
    ui->screen->setPixmap(QPixmap::fromImage(canvas));
}

void MainWindow::refeshCanvas()
{
    updateCanvas();
    canvas.fill(Qt::white);
}

void MainWindow::enableButtons(bool value)
{
    ui->StopAnimation->setEnabled(!value);
    ui->Wave3DAnimation->setEnabled(value);
    ui->WaveAnimation->setEnabled(value);
    ui->ButtonTests->setEnabled(value);
}

