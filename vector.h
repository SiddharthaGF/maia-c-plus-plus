#ifndef VECTOR_H
#define VECTOR_H


#include "qcolor.h"
#include "qimage.h"
#include "qdebug.h"

using namespace std;

class Vector
{
public:

    const static auto sx1 = 0;
    const static auto sx2 = 600;
    const static auto sy1 = 0;
    const static auto sy2 = 500;
    constexpr const static auto x1 = -0.5; //-0.5
    constexpr const static auto x2 = 19.5; // 19.5
    constexpr const static auto y1 = -0.5; // -0.5
    constexpr const static auto y2 = 16.16; // 16.16
    double x0 = 0;
    double y0 = 0;
    QColor color0 = Qt::black;

    virtual void on(QImage& canvas) {
        int sx, sy;
        screen(x0, y0, sx, sy);
        if (sx >= sx1 and sx < sx2 and sy >= sy1 and sy < sy2)
            canvas.setPixelColor(sx, sy, color0);
    }

    void off(QImage &canvas) {
        auto aux = color0;
        color0 = Qt::white;
        on(canvas);
        color0 = aux;
    }

    static void screen(double x, double y, int& sx, int& sy)
    {
        sx = ((x - x1) / (x1 - x2) * (sx1 - sx2) + sx1);
        sy = ((y - y2) / (y2 - y1) * (sy1 - sy2) + sy1);
    }

    static void card(int xP, int yP, double& x, double& y) {
        x = (xP - sx1) * ((x1 - x2) / (sx1 - sx2)) + x1;
        y = (yP - sy2) * ((y1 - y2) / (sy2 - sy1)) + y1;
    }

    static double cardX(int xP) {
        return ((xP - sx1) * ((x1 - x2) / (sx1 - sx2)) + x1);
    }

    static double cardY(int yP) {
        return ((yP - sy2) * ((y1 - y2) / (sy2 - sy1)) + y1);
    }

};

#endif // VECTOR_H
