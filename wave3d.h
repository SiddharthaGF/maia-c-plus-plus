#ifndef WAVE3D_H
#define WAVE3D_H

#include "vector3d.h"

class Wave3D : public Vector3D
{
public:
    int rangeX = 9;
    int rangeY = 7;
    double w = 0;
    double v = 0;
    double m = 0;
    double t = 0;
    double dx = 0.1;
    double dy = 0.1;
    double skip = false;

    void interference(QImage& canvas) {
        if (skip) return;
        x0 = -rangeX;
        auto vt = v * t;
        while(x0 < rangeX) {
            y0 = -rangeY;
            while(y0 < rangeY) {
                double z1 =  w * sqrt((x0 - (0)) * (x0 - (0)) + (y0 - (3)) * (y0 - (3))) - vt;
                double z2 =  w * sqrt((x0 - (0)) * (x0 - (0)) + (y0 - (-3)) * (y0 - (-3))) - vt;
                z1 = m * sin(z1);
                z2 = m * sin(z2);
                z0 = z1 + z2;
                on(canvas);
                y0 += dy;
            }
            x0 += dx;
        }
    }

    void simple(QImage& canvas) {
        if (skip) return;
        x0 = -rangeX;
        auto vt = v * t;
        while(x0 < rangeX) {
            y0 = -rangeY;
            while(y0 < rangeY) {
                double z =  w * sqrt((x0 - (0)) * (x0 - (0)) + (y0 - (0)) * (y0 - (0))) - vt;
                z0 = m * sin(z);
                on(canvas);
                y0 += dy;
            }
            x0 += dx;
        }
    }

    auto getData(int i, int j, double t) {
        double z =  w * sqrt((i - (0)) * (i - (0)) + (j - (0)) * (j - (0))) - v * t;
        return  m * sin(z);
    }


    void skipFrame() {
        skip = !skip;
    }

};

#endif // WAVE3D_H
