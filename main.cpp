/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#include <iostream>
#include "floor.h"
#include "room.h"
#include "building.h"
using namespace std;

int main(){
    Building palazzo(1,9,9,3,4);
    get_status_building(palazzo);

    modify_building(palazzo);
    get_status_building(palazzo);

    cout<<"Riempimento palazzo in corso!!"<<endl;
    int m = palazzo.get_free_space();
    palazzo.add_people(m);
    get_status_building(palazzo);

    palazzo.fire_alarm();
    get_status_building(palazzo);

    cout<<endl<<endl;
    cout<<"----------SOMMA DI DUE STANZE--------------"<<endl;
    room stanza1(5,6,3,3);
    room stanza2(9,9,3.2,4);

    cout<<endl<<"----------PRIMA STANZA-------------------"<<endl<<endl;

    get_status(stanza1);

    cout<<endl<<"----------SECONDA STANZA-------------------"<<endl<<endl;

    get_status(stanza2);

    cout<<endl<<"----------STANZA NUOVA-------------------"<<endl<<endl;
    
    room* stanza3=stanza1+stanza2;
    
    cout<<"Lunghezza stanza: "<<stanza3->get_lenght()<<" m"<<endl;
    cout<<"Larghezza stanza: "<<stanza3->get_width()<<" m"<<endl;
    cout<<"Altezza stanza: "<<stanza3->get_height()<<" m"<<endl;
    cout<<"Area pavimento: "<<stanza3->get_area()<<" m"<<endl;
    cout<<"Area delle pareti: "<<stanza3->get_area_walls()<<" m"<<endl;
    cout<<"Volume stanza: "<<stanza3->get_volume()<<" m"<<endl;
    cout<<"Persone nella stanza: "<<stanza3->get_people()<<endl;

    return 0;

}