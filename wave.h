#ifndef WAVE_H
#define WAVE_H

#include "vector.h"
class Wave : public Vector
{
public:
    int stepX = 1;
    int stepY = 1;
    double w = 0;
    double v = 0;
    double m = 0;
    double t = 0;
    vector<QColor> palette;

    void interference(QImage &canvas) {
        for (auto j = sy1; j < sy2; j += stepY)
        {
            auto y = cardY(j);
            QRgb* scanline = reinterpret_cast<QRgb*>(canvas.scanLine(j));
            for (auto i = sx1; i < sx2; i += stepX)
            {
                auto x = cardX(i);
                auto z1 = w * (sqrt((x - (-4)) * (x - (-4)) + (y - (-2)) * (y - (-2))) - v * t);
                auto z2 = w * (sqrt((x - (-4)) * (x - (-4)) + (y - (+2)) * (y - (+2))) - v * t);
                auto z3 = w * (sqrt((x - (0)) * (x - (0)) + (y - (0)) * (y - (0))) - v * t);
                z1 = sin(z1) + 1;
                z2 = sin(z2) + 1;
                z3 = sin(z3) + 1;
                auto z = z1 + z2 + z3;
                auto index = (int)(z * 2.5);
                auto color = palette[index];
                scanline[i] = color.rgb();
            }
        }
    }

    void simple(QImage &canvas) {
        for (auto j = sy1; j < sy2; j += stepY)
        {
            QRgb* scanline = reinterpret_cast<QRgb*>(canvas.scanLine(j));
            for (auto i = sx1; i < sx2; i += stepX)
            {
                double x, y;
                card(i, j, x, y);
                auto z = w * (sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0)) -  v * t);
                z = m * sin(z) + 1;
                auto index = (int)(z * 7.5);
                auto color = palette[index];
                scanline[i] = color.rgb();
            }
        }
    }

    auto getData(int i, int j, double t) {
        double x, y;
        card(i, j, x, y);
        auto z = w * (sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0)) -  v * t);
        z = m * sin(z) + 1;
        return z * 7.5;
    }

    void skipFrame() {
        if (stepX == 1)  {
            stepX = 700;
        }
        else {
            stepX = 1;
        }
    }

};

#endif // WAVE_H
