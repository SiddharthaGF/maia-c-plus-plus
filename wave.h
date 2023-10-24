#ifndef WAVE_H
#define WAVE_H

using namespace std;

#include "vector.h"
class Wave : Vector
{
public:
    int indexX = 0;
    int indexY = 0;
    vector<double> X = {0};
    vector<double> Y = {0};
    int stepX = 1;
    int stepY = 1;
    double w = 0;
    double v = 0;
    double m = 0;
    double t = 0;
    double multiplier = 1;
    vector<QColor> palette;

    void on(QImage &canvas) override {
        double vt = v * t;
        for (int i = Sx1; i < Sx2; i+=stepX)
        {
            double x = cardX(i);
            for (int j = Sy1; j < Sy2; j+=stepY)
            {
                double y = cardY(j);
                double z = 0.0;
                for (int k = 0; k < X.size(); ++k) {
                    double xk = (x - X[k]) * (x - X[k]);
                    double yk = (y - Y[k]) * (y - Y[k]);
                    double r = w * (sqrt(xk + yk) - vt);
                    z += m * sin(r) + 1;
                }
                int index = static_cast<int>(z * multiplier);
                QColor color = palette[index];
                canvas.setPixelColor(i, j, color);
            }
        }
    }
};

#endif // WAVE_H
