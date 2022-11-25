/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#ifndef BUILDING_H
#define BUILDING_H

#include "room.h"
#include <iostream>
using namespace std;

class Building:public room{
protected:
    int    num_room;
    room** roomptr;
public:
    Building(int num_room,double lenght,double width,double height,int people);
    int    get_tot_room();
    double get_tot_area();
    double get_tot_wall_area();
    double get_tot_volume();
    int    get_tot_people();
    int    get_free_space();
    void   add_rooms(double lenght, double width,double height,int people,int n);
    void   move_people(int i, int j, int n);
    int    add_people(int n);
    void   fire_alarm();

};
void get_status_building(Building& build);
void add_new_room(Building& build);
void modify_building(Building& build);
#endif