#ifndef CIRCLE_H
#define CIRCLE_H

#include "vector.h"

class Circle : public Vector
{
public:

    double radius = 1;
    double dt = 0.001;

    virtual void on(QImage& canvas) override {
        double t = 0;
        double X = X0;
        double Y = Y0;
        color = color;
        do {
            X0 = X + radius * cos(t);
            Y0 = Y + radius * sin(t);
            Vector::on(canvas);
            t += dt;
        } while (t <= 2 * M_PI);
    }
};

#endif // CIRCLE_H

