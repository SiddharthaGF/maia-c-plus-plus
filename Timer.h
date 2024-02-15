#ifndef TIMER_H
#define TIMER_H

class Timer {
public:

    double t;
    double dt;

    Timer(double t, double dt) {
        this->t = t;
        this->dt = dt;
    };


    void increments() {
        t += dt;
    }

    void decrements() {
        t -= dt;
    }

    double getTime() {
        return t;
    }

};

#endif // TIMER_H
