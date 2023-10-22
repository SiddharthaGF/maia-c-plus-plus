#include "circle.h"
#include <cmath>

Circle::Circle()
{

}

void Circle::on(QImage& canvas) {
    double t = 0;
    const double tf = 2 * M_PI;
    Vector *v = new Vector();
    v->setColor(getColor());
    do {
        v->setX0(getX0() + radius * cos(t));
        v->setY0(getY0() + radius * sin(t));
        v->on(*&canvas);
        t += dt;
    } while (t <= tf);
}

void Circle::setRadius(double value) {
    radius = value;
}

double Circle::getRadius() {
    return radius;
}

void Circle::setDt(double value) {
    dt = value;
}
