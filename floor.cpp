/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#include "floor.h"

floor::floor(double Lenght,double Width){
    lenght = Lenght;
    width = Width;
}

double floor::get_lenght(){
    return lenght;
}

double floor::get_width(){
    return width;
}
double floor::get_perimeter(){
    return (2*(lenght + width));
}

double floor::get_area(){
    return (lenght*width);
}

