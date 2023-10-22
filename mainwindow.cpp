#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSettings>
#include "wave.h"
#include <vector>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    canvas(700,540 , QImage::Format_ARGB32)
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

    QColor start = QColor::fromRgb(0, 0, 50);
    QColor end = QColor::fromRgb(0, 255, 255);
    customPalette = createPalette(start, end, 16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_to_do_something_clicked()
{
    Wave* w = new Wave();
    w->setM(1);
    w->setW(1.5);
    w->setV(9.3);
    w->setPalette(palette0);
    w->setT(0);
    w->setX0(0);
    w->setY0(-6.15);

    QTime timeStart = QTime::currentTime();
    int duration = 10000;

    connect(timer, &QTimer::timeout, this, [=](){
        w->SimpleWave(canvas);
        ui->screen->setPixmap(QPixmap::fromImage(canvas));
        w->incrementT(0.005);
        w->setStep(w->getStep() == 1 ? 4 : 1);
        if (timeStart.msecsTo(QTime::currentTime()) >= duration && w->getStep() % 2 == 0) {
            timer->stop();
            timer = new QTimer(this);
        }
    });

    timer->start();
}

std::vector<QColor> MainWindow::createPalette(QColor start, QColor end, int variaciones) {
    std::vector<QColor> palette;
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
