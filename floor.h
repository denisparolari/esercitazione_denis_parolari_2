/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#ifndef FLOOR_H
#define FLOOR_H

class floor {
protected:
    double lenght;
    double width;
public:
    floor(double, double);
    double get_lenght();
    double get_width();
    double get_perimeter();
    double get_area();

};


#endif