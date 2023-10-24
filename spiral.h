#ifndef SPIRAL_H
#define SPIRAL_H

#include "circle.h"
class Spiral : public Circle {
public:
    double length = 16;

    void on(QImage &canvas) override {
        double t = 0;
        double X = -X0;
        double Y = -Y0;
        color = color;
        do {
            X0 = X + radius * (t / 3) * cos(t);
            Y0 = Y + radius  * (t / 3) * sin(t);
            Vector::on(canvas);
            t += dt;
        } while (t <= length);
    }

};

#endif // SPIRAL_H
