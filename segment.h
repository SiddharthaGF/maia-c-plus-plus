#ifndef SEGMENT_H
#define SEGMENT_H

#include "vector.h"
class Segment : public Vector
{
public:
    double Xf = 0;
    double Yf = 0;
    double dx = 0.001;

    void on(QImage &canvas) override {
        double t = 0;
        double X = X0;
        double Y = Y0;
        do {
            X0 = (X * (t - 1)) + (Xf * t);
            Y0 = (Y * (t - 1)) + (Yf * t);
            Vector::on(canvas);
            t += dx;
        } while(t <= 1);
    }

};

#endif // SEGMENT_H
