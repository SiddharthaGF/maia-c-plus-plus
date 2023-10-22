#include "vector.h"
#include <QProcessEnvironment>

int Vector::Sx1 = 0;
int Vector::Sx2 = 700;
int Vector::Sy1 = 0;
int Vector::Sy2 = 540;
double Vector::X1 = -8;
double Vector::X2 = 8;
double Vector::Y1 = - 6.15;
double Vector::Y2 = 6.15;

Vector::Vector()
{

}

void Vector::screen(double x, double y, int& sx, int& sy)
{
    sx = ((x - X1) / (X1 - X2) * (Sx1 - Sx2) + Sx1);
    sy = ((y - Y2) / (Y2 - Y1) * (Sy1 - Sy2) + Sy1);
}

void Vector::card(int xP, int yP, double& x, double& y) {
    x = ((xP - Sx1) * ((X1 - X2) / (Sx1 - Sx2)) + X1);
    y = ((yP - Sy2) * ((Y1 - Y2) / (Sy2 - Sy1)) + Y1);
}

void Vector::on(QImage& canvas) {
    int sx, sy;
    screen(X0, Y0, sx, sy);
    if (sx >= Sx1 && sx <= Sx2 && sy >= Sy1 && sy <= Sy2){
        canvas.setPixelColor(sx, sy, color);
    }
}

void Vector::setX0(double value) {
    X0 = value;
}

void Vector::setY0(double value) {
    Y0 = value;
}

void Vector::setColor(const QColor &value) {
    color = value;
}

double Vector::getX0() {
    return X0;
}

double Vector::getY0() {
    return Y0;
}

const QColor Vector::getColor() {
    return color;
}

int Vector::getSx2() {
    return Sx2;
}

int Vector::getSy2() {
    return Sy2;
}

int Vector::getSx1() {
    return Sx1;
}

int Vector::getSy1() {
    return Sy1;
}
