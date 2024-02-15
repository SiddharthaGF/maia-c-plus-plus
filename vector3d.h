#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vector.h"

class Vector3D : public Vector
{
public:

    double z0 = 0;
    double alpha = M_PI_4;
    double p = .5;

    static void axonometry(double x, double y, double z, double& ax, double& ay, double alpha, double p) {
        ax = x + p * y * cos(alpha);
        ay = z + p * y * sin(alpha);
    }

    void on(QImage& canvas) {
        double ax, ay;
        int sx, sy;
        axonometry(x0, y0, z0, ax, ay, alpha, p);
        screen(ax, ay, sx, sy);
        if (sx >= sx1 && sx < sx2 && sy >= sy1 && sy < sy2){
            canvas.setPixelColor(sx, sy, color0);
        }
    }

};

#endif // VECTOR3D_H
