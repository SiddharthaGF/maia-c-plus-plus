#ifndef VECTOR_H
#define VECTOR_H


#include "qcolor.h"
#include "qimage.h"

class Vector
{
public:

    const static int Sx1 = 0;
    const static int Sx2 = 700;
    const static int Sy1 = 0;
    const static int Sy2 = 540;
    constexpr const static double X1 = -8.0;
    constexpr const static double X2 = 8.0;
    constexpr const static double Y1 = -6.15;
    constexpr const static double Y2 = 6.15;
    double X0 = 0;
    double Y0 = 0;
    QColor color = Qt::black;

    virtual void on(QImage& canvas) {
        int sx, sy;
        screen(X0, Y0, sx, sy);
        if (sx >= Sx1 && sx < Sx2 && sy >= Sy1 && sy < Sy2){
            canvas.setPixelColor(sx, sy, color);
        }
    }

    static void screen(double x, double y, int& sx, int& sy)
    {
        sx = ((x - X1) / (X1 - X2) * (Sx1 - Sx2) + Sx1);
        sy = ((y - Y2) / (Y2 - Y1) * (Sy1 - Sy2) + Sy1);
    }

    static void card(int xP, int yP, double& x, double& y) {
        x = ((xP - Sx1) * ((X1 - X2) / (Sx1 - Sx2)) + X1);
        y = ((yP - Sy2) * ((Y1 - Y2) / (Sy2 - Sy1)) + Y1);
    }

    static double cardX(int xP) {
        return ((xP - Sx1) * ((X1 - X2) / (Sx1 - Sx2)) + X1);
    }

    static double cardY(int yP) {
        return ((yP - Sy2) * ((Y1 - Y2) / (Sy2 - Sy1)) + Y1);
    }
};

#endif // VECTOR_H
