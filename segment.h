#ifndef SEGMENT_H
#define SEGMENT_H

#include "vector.h"
class Segment : public Vector
{
public:
    double xf = 0;
    double yf = 0;
    double dx = 0.001;

    void on(QImage &canvas) override {
        auto t = 0.0;
        auto vec = Vector();
        vec.color0 = color0;
        do {
            vec.x0 = -(x0 * (t - 1)) + (xf * t);
            vec.y0 = -(y0 * (t - 1)) + (yf * t);
            vec.on(canvas);
            t += dx;
        } while(t <= 1);
    }

};

#endif // SEGMENT_H
