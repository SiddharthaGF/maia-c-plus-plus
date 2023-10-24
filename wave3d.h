#ifndef WAVE3D_H
#define WAVE3D_H

#include "vector3d.h"

class Wave3D : public Vector3D
{
public:
    int rangeX = 7;
    int rangeY = 6;
    std::vector<double> X = {0};
    std::vector<double> Y = {0};
    double w = 0;
    double v = 0;
    double m = 0;
    double t = 0;
    double dx = 0.1;
    double dy = 0.1;

    void on(QImage& canvas) override {
        X0 = -rangeX;
        double vt = v * t;
        while(X0 <= rangeX) {
            Y0 = -rangeY;
            while(Y0 <= rangeY) {
                Z0 = 0;
                for (int k = 0; k < X.size(); ++k) {
                    double x = X[k];
                    double y = Y[k];
                    double z =  w * sqrt((X0 - x) * (X0 - x) + (Y0 + y) * (Y0 + y)) - vt;
                    z = m * sin(z);
                    Z0 += z;
                }
                Vector3D::on(canvas);
                Y0 += dy;
            }
            X0 += dx;
        }
    }
};

#endif // WAVE3D_H
