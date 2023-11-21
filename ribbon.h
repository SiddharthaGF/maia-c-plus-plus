#ifndef RIBBON_H
#define RIBBON_H

#include "circuference.h"
class Ribbon : public Circunference {
public:

    void on(QImage &canvas) override {
        auto t = 0.0;
        auto vec = Vector();
        vec.color0 = color0;
        color0 = color0;
        do {
            vec.x0 = x0 + radius * sin(2 * t);
            vec.y0 = y0 + radius * cos(3 * t);
            vec.on(canvas);
            t += dt;
        } while (t <= 2 * M_PI);
    }

};

#endif // RIBBON_H
