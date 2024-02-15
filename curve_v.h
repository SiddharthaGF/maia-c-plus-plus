#ifndef CURVE_V_H
#define CURVE_V_H


#include "circuference.h"
class CurveV : public Circunference {
public:

    int type = 1;

    void on(QImage &canvas) override {
        auto t = 0.0;
        auto vec = Vector();
        vec.color0 = color0;

        double const radius1 = 1.8;
        double const radius2 = 1.3;

        switch (type) {
        case 1:
            do {
                vec.x0 = x0 + radius * sin(2 * t);
                vec.y0 = y0 + radius * cos(3 * t);
                vec.on(canvas);
                t += dt;
            } while (t <= 2 * M_PI);
            break;
        case 2:
            do {
                vec.x0 = x0 + radius * cos(4 * t) * cos(t);
                vec.y0 = y0 + radius * cos(4 * t) * sin(t);
                vec.on(canvas);
                t += dt;
            } while (t <= 2 * M_PI);
            break;
        case 3:
            do {
                vec.x0 = x0 + radius * pow(sin(t), 3);
                vec.y0 = y0 + radius * pow(cos(t), 3);
                vec.on(canvas);
                t += dt;
            } while (t <= 2 * M_PI);
            break;
        case 4:
            do {
                vec.x0 = x0 + radius * sin(1.6 * t) * cos (t);
                vec.y0 = y0 + radius * sin(1.6 * t) * sin (t);
                vec.on(canvas);
                t += dt;
            } while (t <= 10 * M_PI);
            break;
        case 5:
            do {
                vec.x0 = x0 + (radius1 - radius2) * cos(t) + radius2 * cos(t * (1 - radius1 / radius2));
                vec.y0 = y0 + (radius1 - radius2) * sin(t) + radius2 * sin(t * (1 - radius1 / radius2));
                vec.on(canvas);
                t += dt;
            } while (t <= 26 * M_PI);
            break;
        case 6:
            do {
                vec.x0 = x0 + radius * (sin(t) * (pow(M_E, cos(t)) - 2 * cos(4 * t) - pow(sin(t/12), 5)));
                vec.y0 = y0 + radius * (cos(t) * (pow(M_E, cos(t)) - 2 * cos(4 * t) - pow(sin(t/12), 5)));
                vec.on(canvas);
                t += dt;
            } while (t <= 12 * M_PI);
            break;
        case 7:
            do {
                vec.x0 = x0 + (radius1 + radius2) * cos(t) + radius2 * cos(t * (1 + radius1 / radius2));
                vec.y0 = y0 + (radius1 + radius2) * sin(t) + radius2 * sin(t * (1 + radius1 / radius2));
                vec.on(canvas);
                t += dt;
            } while (t <= 26 * M_PI);
            break;
        // Aqui añadimos mas curvas
        default:
            break;
        }
    }

};

#endif // CURVE_V_H
