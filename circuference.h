#ifndef CIRCUFERENCE_H
#define CIRCUFERENCE_H

#include "vector.h"

class Circunference : public Vector
{
public:

    double radius = 1;
    double dt = 0.001;

    virtual void on(QImage& canvas) override {
        auto t = -M_PI;
        auto vec = Vector();
        vec.color0 = color0;
        do {
            vec.x0 = x0 + radius * cos(t);
            vec.y0 = y0 + radius * sin(t);
            vec.on(canvas);
            t += dt;
        } while (t <= M_PI);
    }
};

#endif // CIRCUFERENCE_H

