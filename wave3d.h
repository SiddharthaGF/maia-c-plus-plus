#ifndef WAVE3D_H
#define WAVE3D_H

#include "vector3d.h"

class Wave3D : public Vector3D
{
public:
    int rangeX = 7;
    int rangeY = 6;
    double w = 0;
    double v = 0;
    double m = 0;
    double t = 0;
    double dx = 0.1;
    double dy = 0.1;

    void interference(QImage& canvas) {
        x0 = -rangeX;
        auto vt = v * t;
        while(x0 <= rangeX) {
            y0 = -rangeY;
            while(y0 <= rangeY) {
                auto Y1 = (y0 - (0)) * (y0 - (0));
                auto Y2 = (y0 - (0)) * (y0 - (0));
                auto X1 = (x0 - (3)) * (x0 - (3));
                auto X2 = (x0 - (-3)) * (x0 - (-3));
                double Z1 =  w * sqrt(Y1 + X1) - vt;
                double Z2 =  w * sqrt(Y2 + X2) - vt;
                Z1 = m * sin(Z1);
                Z2 = m * sin(Z2);
                Z0 = Z1 + Z2;
                on(canvas);
                y0 += dy;
            }
            x0 += dx;
        }
    }

    void simple(QImage& canvas) {
        x0 = -rangeX;
        auto vt = v * t;
        while(x0 <= rangeX) {
            y0 = -rangeY;
            while(y0 <= rangeY) {
                auto Y = (y0 - (0)) * (y0 - (0));
                auto X = (x0 - (0)) * (x0 - (0));
                double z =  w * sqrt(Y + X) - vt;
                Z0 = m * sin(z);
                on(canvas);
                y0 += dy;
            }
            x0 += dx;
        }
    }

};

#endif // WAVE3D_H
