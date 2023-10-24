#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vector.h"

class Vector3D : public Vector
{
public:

    double Z0 = 0;
    double alpha = .5;
    double p = .55;

    static void axonometry(double x, double y, double z, double& ax, double& ay, double alpha = .8, double p = .55) {
        ax = x + p * y * cos(alpha);
        ay = p * y * sin(alpha) + z;
    }

    void on(QImage& canvas) {
        double ax, ay;
        int sx, sy;
        axonometry(X0, Y0, Z0, ax, ay, alpha, p);
        screen(ax, ay, sx, sy);
        if (sx >= Sx1 && sx < Sx2 && sy >= Sy1 && sy < Sy2){
            canvas.setPixelColor(sx, sy, color);
        }
    }

};

#endif // VECTOR3D_H
