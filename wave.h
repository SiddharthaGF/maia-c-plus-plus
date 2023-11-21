#ifndef WAVE_H
#define WAVE_H

#include "qdebug.h"
#include "vector.h"
class Wave : Vector
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
        for (auto j = 0; j < 540; j += stepY)
        {
            auto y = cardY(j);
            QRgb* scanline = reinterpret_cast<QRgb*>(canvas.scanLine(j));
            for (auto i = 0; i < 700; i += stepX)
            {
                auto x = cardX(i);
                auto z1 = w * (sqrt((x + 3) * (x + 3) + (y - 0) * (y - 0)) - v * t);
                auto z2 = w * (sqrt((x + 2) * (x + 2) + (y - 0) * (y - 0)) - v * t);
                auto z3 = w * (sqrt((x + 1) * (x + 1) + (y - 0) * (y - 0)) - v * t);
                auto z4 = w * (sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0)) - v * t);
                auto z5 = w * (sqrt((x - 1) * (x - 1) + (y - 0) * (y - 0)) - v * t);
                auto z6 = w * (sqrt((x - 2) * (x - 2) + (y - 0) * (y - 0)) - v * t);
                auto z7 = w * (sqrt((x - 3) * (x - 3) + (y - 0) * (y - 0)) - v * t);
                z1 = sin(z1) + 1;
                z2 = sin(z2) + 1;
                z3 = sin(z3) + 1;
                z4 = sin(z4) + 1;
                z5 = sin(z5) + 1;
                z6 = sin(z6) + 1;
                z7 = sin(z7) + 1;
                auto z = z1 + z2 + z3 + z4 + z5 + z6 + z7;
                auto index = (int)(z * 1.1);
                auto color = palette[index];
                scanline[i] = color.rgb();
            }
        }
    }

    void simple(QImage &canvas) {
        for (auto j = 0; j < 540; j += stepY)
        {
            QRgb* scanline = reinterpret_cast<QRgb*>(canvas.scanLine(j));
            for (auto i = 0; i < 700; i += stepX)
            {
                double x, y;
                card(i, j, x, y);
                auto z = w * (sqrt((x - (-2)) * (x - (-2)) + (y - (2)) * (y - (2))) -  v * t);
                z = m * sin(z) + 1;
                auto index = (int)(z * 7.5);
                auto color = palette[index];
                scanline[i] = color.rgb();
            }
        }
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
