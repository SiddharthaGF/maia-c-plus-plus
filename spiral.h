#ifndef SPIRAL_H
#define SPIRAL_H

#include "circuference.h"
class Spiral : public Circunference {
public:
    double length = 16;

    void on(QImage &canvas) override {
        auto t = 0.0;
        auto X = -x0;
        auto Y = -y0;
        color0 = color0;
        do {
            x0 = X + radius * (t / 3) * cos(t);
            y0 = Y + radius * (t / 3) * sin(t);
            Vector::on(canvas);
            t += dt;
        } while (t <= length);
    }

};

#endif // SPIRAL_H
