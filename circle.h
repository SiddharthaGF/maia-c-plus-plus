#ifndef CIRCLE_H
#define CIRCLE_H

#include "vector.h"

class Circle : public Vector
{
private:
    double radius;
    double dt = 0.001;
public:
    Circle();
    void on(QImage& canvas) override;
    void setRadius(double value);
    double getRadius();
    void setDt(double value);
};

#endif // CIRCLE_H
