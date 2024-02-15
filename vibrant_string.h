#ifndef VIBRANT_STRING_H
#define VIBRANT_STRING_H


#include "vector.h"
#include "vector3d.h"
class VibrantString : public Vector3D {
public:

    double t = 0.0;
    double l = 4.0;
    double c = 1;
    float dx = 0.008;
    double xf = x2;
    bool skip = false;

    void fourier(double x, double &fou) {
        auto sum = 0.0;
        auto k = 1.0;
        auto PIC = M_PI * c;
        auto PIXL = (M_PI * x) / l;
        auto PICT =  (PIC * t) / l;
        do {

            auto SIN_K_PI_2 = sin(k * M_PI_2);
            auto SIN_K_PI = sin(k * M_PI);
            auto KPICT = k * PICT;

            double ak = (l/6) * (4 * f(l/2) * SIN_K_PI_2 + f(l) * SIN_K_PI);
            ak = 2 * ak / l;

            double bk = (l/6) * (4 * g(l/2) * SIN_K_PI_2 + g(l) * SIN_K_PI);
            bk = 2 * bk / (k * PIC);

            sum += (ak * cos(KPICT) + bk * sin(KPICT)) * sin(k * PIXL);
            k++;
        } while (k <= 20);
        fou = sum;
    }

    double g(double x) {
        return 0.5;
    }

    double f(double x) {
        return 1.5*x;
    }

    void on(QImage &canvas) override {
        if (skip) return;
        double aux = x0;
        double x = x0;
        double fou;
        do {
            fourier(x, fou);
            x0 = x;
            y0 = fou;
            Vector::on(canvas);
            x += dx;
        } while (x <= xf);
        x0 = aux;
    }

    void skipFrame() {
        skip = !skip;
    }

};

#endif // VIBRANT_STRING_H
