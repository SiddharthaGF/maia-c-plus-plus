#ifndef RIBBON_H
#define RIBBON_H

#include "circle.h"
class Ribbon : public Circle {
public:

    void on(QImage &canvas) override {
        double t = 0;
        double X = X0;
        double Y = Y0;
        color = color;
        do {
            X0 = X + radius * sin(2 * t);
            Y0 = Y + radius * cos(3 * t);
            Vector::on(canvas);
            t += dt;
        } while (t <= 2 * M_PI);
    }

};

#endif // RIBBON_H
