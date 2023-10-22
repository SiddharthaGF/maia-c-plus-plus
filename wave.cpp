#include "wave.h"
#include <cmath>

Wave::Wave() : Vector()
{

}

void Wave::SimpleWave(QImage& canvas) {
    double x, y, z;
    int index;
    QColor color;
    for (int i = getSx1(); i < getSx2(); i+=step) {
        for (int j = getSy1(); j < getSy2(); j+=step) {
            card(i, j, x, y);
            z = w * (sqrt((x - getX0()) * (x - getX0()) + (y - getY0()) * (y - getY0())) - v * t);
            z = m * sin(z) + 1;
            index = static_cast<int>(z * 7.5);
            color = palette[index];
            canvas.setPixelColor(i, j, color);
        }
    }
}

void Wave::setM(double value) {
    m = value;
}

void Wave::setW(double value) {
    w = value;
}

void Wave::setV(double value) {
    v = value;
}

void Wave::setT(double value) {
    t = value;
}

void Wave::setStep(int value) {
    step = value;
}

void Wave::setPalette(std::vector<QColor>& value) {
    palette = value;
}

void Wave::incrementT(double value) {
    t += value;
}

int Wave::getStep() {
    return step;
}
