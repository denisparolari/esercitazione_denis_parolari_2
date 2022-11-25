/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#ifndef ROOM_H
#define ROOM_H

#include "floor.h"

class room : public floor {
protected:
    double    height;
    int       people;
public:
    room(double Lenght, double Width, double Height, int people);
    double    get_height();
    double    get_area_walls();
    double    get_volume();
    int       get_people();
    int       add_people(int m);
    int       remove_people(int n);
    int       empty_room();
    int       free_people_space();
    room* operator+(room& local2);

};

void   get_status(room& local);

#endif