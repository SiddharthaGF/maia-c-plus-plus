#ifndef WAVE_H
#define WAVE_H

#include "vector.h"
class Wave : public Vector
{
private:
    double w;
    double v;
    double m;
    double t;
    int step = 1;
    std::vector<QColor> palette;
public:
    Wave();
    void SimpleWave(QImage&);
    void setW(double);
    void setV(double);
    void setM(double);
    void setT(double);
    void incrementT(double);
    double getT();
    int getStep();
    void setStep(int);
    void setPalette(std::vector<QColor>&);
};

#endif // WAVE_H
