/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#include "room.h"
#include <iostream>
using namespace std;

room::room(double lenght,double width,double height,int people) : floor(lenght,width){
    if(height>2.7 || (height<2.7 && height>0)){
        this->height = height;
    }else{height = 2.7;}
    this->people = people;
}

double room::get_height(){
    return height;
};
double room::get_area_walls(){
    return get_perimeter()*height;
};
double room::get_volume(){
    return get_area()*height;
};
      
int room::add_people(int m){
    int people_now=people;

    if(get_area()/(people+m)>=8 && get_volume()/(people+m)>=10){
        people+=m;
    }else{
        cout<<"Spazio insufficiente !"<<endl;
        int i=0;
        while(get_area()/(people+1)>=8 && get_volume()/(people+1)>=10 && i<=m){
            people++;
            i++;
        }
        cout<<"Sono state aggiunte solo: "<<people-people_now<<" persone."<<endl; 
    }
    cout<<"Persone attuali "<<people<<endl;
    return (m+people_now-people);  
};

int room::remove_people(int n){
    if(people>0){
        cout<<"Sono presenti "<<people<<endl<<"Inserire numero di persone da rimuovere: ";
        if(n>people){
            do{
            
                cout<<"Errore: numero di persone da rimuovere superiore a quelle presenti!! "<<endl;
                cout<<"Inserire nuovo numero di persone: ";cin>>n;
            }while(n>people);
        }
        
        people-=n;            
    }else{cout<<"Nessuna persona presente nella stanza!"<<endl;}
    return (people);
};

int room::empty_room(){
    people=0;
    cout<<"Stanza vuota"<<endl;
    return people;
};

int room::get_people(){
    return people;
}

room* room::operator+(room& local2){
    double area=get_area()+local2.get_area();
    double lenght=get_lenght()+local2.get_lenght();
    double width=area/lenght;
    if(get_height()>local2.get_height()){
        height=get_height();
    }else{height=local2.get_height();}
    int new_people=get_people()+local2.get_people();
    room* local = new room(lenght,width,height,0);
    local->add_people(new_people);
    return local;
}

int room::free_people_space(){
    int n=0;
    int free_area=(get_area()-(people*8))/8;
    int free_volume=(get_volume()-(people*10))/10;
    if(free_area<free_volume){
        n=free_area;
    }else{n=free_volume;}

    return n;
}

void get_status(room& local){
    cout<<"Lunghezza stanza: "<<local.get_lenght()<<" m"<<endl;
    cout<<"Larghezza stanza: "<<local.get_width()<<" m"<<endl;
    cout<<"Altezza stanza: "<<local.get_height()<<" m"<<endl;
    cout<<"Area pavimento: "<<local.get_area()<<" m"<<endl;
    cout<<"Area delle pareti: "<<local.get_area_walls()<<" m"<<endl;
    cout<<"Volume stanza: "<<local.get_volume()<<" m"<<endl;
    cout<<"Persone nella stanza: "<<local.get_people()<<endl;
    return;
}