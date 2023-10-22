#ifndef VECTOR_H
#define VECTOR_H


#include "qcolor.h"
#include "qimage.h"

class Vector
{
private:
    static int Sx1;
    static int Sy1;
    static int Sx2;
    static int Sy2;
    static double X2;
    static double Y2;
    static double X1;
    static double Y1;
    double X0 = 0;
    double Y0 = 0;
    QColor color;
    static void screen(double, double, int&, int&);
public:
    Vector();
    virtual void on(QImage&);
    static void card(int, int, double&, double&);
    void setX0(double);
    void setY0(double);
    void setColor(const QColor&);
    double getX0();
    double getY0();
    int getSy2();
    int getSx2();
    int getSy1();
    int getSx1();
    const QColor getColor();
};

#endif // VECTOR_H
