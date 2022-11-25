/*-----------------------------------------------------------------
--------creato da Denis Parolari in data 25/11/2022----------------
-----------------------------------------------------------------*/

#include "building.h"

Building::Building(int num_room,double lenght,double width,double height,int people):room(lenght,width,height,people){
    
    if(num_room<0){
        cout<<"Errore: numero di stanze negativo!"<<endl;
        this->num_room=0;
        this->roomptr=nullptr;
    }else{
        this->num_room = num_room;
        roomptr = new room* [num_room];
        for(int i=0;i<num_room;i++){
            roomptr[i]= new room(lenght,width,height,people);
        }
    }
};
int    Building::get_tot_room(){
    return num_room;
}
double Building::get_tot_area(){
    double tot_area=0;
    for(int i=0;i<num_room;i++){
        tot_area +=(roomptr[i]->get_area());
    }
    return tot_area;
}
double Building::get_tot_wall_area(){
    double tot_wall_area=0;
    for(int i=0;i<num_room;i++){
        tot_wall_area+=(roomptr[i]->get_area_walls());
    }
    return tot_wall_area;
}
double Building::get_tot_volume(){
    double tot_volume=0;
    for(int i=0;i<num_room;i++){
        tot_volume +=(roomptr[i]->get_volume());
    }
    return tot_volume;
}
int    Building::get_tot_people(){
    int tot_people=0;
    for(int i=0;i<num_room;i++){
        tot_people +=(roomptr[i]->get_people());
    }
    return tot_people;
    
}
void Building::add_rooms(double lenght, double width,double height,int people,int n){

    if(n<0){
        cout<<"Errore: il numero di stanze da aggiungere deve essere positivo!!"<<endl;
    }else{
        int new_num_rooms=num_room+n;
        room** new_room_ptr=new room*[new_num_rooms];
        for(int i=0;i<num_room;i++){
            new_room_ptr[i]=roomptr[i];
        }
        for(int i=num_room;i<new_num_rooms;i++){
            new_room_ptr[i]=new room(lenght,width,height,0);
            new_room_ptr[i]->add_people(people);
        }
        num_room=new_num_rooms;
        delete[] roomptr;
        roomptr = new_room_ptr;
    }
    return;
}
void  Building::move_people(int i, int j, int n){
    if(i>(num_room - 1) || j>(num_room - 1) ){
        cout<<"Stanza non trovata: il palazzo ha: "<<num_room<<" stanze"<<endl;
    }else{
        cout<<"Sposto "<<n<<" persone dalla stanza "<<i<<"alla stanza "<<j<<endl;
        if(roomptr[i]->get_people() >=n){
            cout<<"--------trasferimento persone--------------"<<endl;
            int remaining = roomptr[j]->add_people(n);
            roomptr[i]->remove_people(n-remaining);
            cout<<"Sono state trasferite con successo "<<n-remaining<<" persone"<<endl;
        }else{
            cout<<"Errore: non ci sono abbastanza persone nella stanza "<<i<<endl;
            cout<<"Verranno trasferitie: "<<roomptr[i]->get_people()<<" persone"<<endl;
            roomptr[j]->add_people(roomptr[i]->get_people());
            roomptr[i]->empty_room();
            cout<<"Trasferimento completato con successo"<<endl;
        }
    }
    return;

}
int    Building::add_people(int n){
    int i=0;
    while(n>0 && i<num_room){
        cout<<"----------Inserimento persone-------------"<<endl;
        cout<<"Stanza nr: "<<i<<endl;
        int remaining=roomptr[i]->add_people(n);
        cout<<"Persone non inserite: "<<remaining<<endl;
        n=remaining;
        i++;
    }
    cout<<"-------------------------------------------"<<endl;
    if(n==0){
        cout<<"Tutte le persone sono state inserite correttamente all'interno delle stanze"<<endl;
    }else{
        cout<<n<<" persone non sono state inserite nelle stanze perche il palazzo e gia pieno"<<endl;
    }
    return n;
}
int    Building::get_free_space(){
    int n=0;
    for(int i=0;i<num_room;i++){
        n+=roomptr[i]->free_people_space();
    }
    return n;
}
void Building::fire_alarm(){  
    cout<<endl<<"--------------ATTENZIONE INCENDIO--------------------"<<endl;
    cout<<endl<<"-------------EVACUAZIONE EDIFICIO-----------------------"<<endl;
    for(int i=0; i<num_room; i++){        
        cout<<"---------------------Stanza "<<i<<"-----------------"<<endl;
        roomptr[i]->empty_room();
        cout<<"---------------------------------------------"<<endl;
    }
    return;

}
void get_status_building(Building& build){
    cout<<"---------------------------------------------"<<endl;
    cout<<"numero di stanze: "<<build.get_tot_room()<<endl;
    cout<<"numero di persone: "<<build.get_tot_people()<<endl;
    cout<<"superficie totale dei pavimenti: "<<build.get_tot_area()<<endl;
    cout<<"superficie totale delle pareti: "<<build.get_tot_wall_area()<<endl;
    cout<<"volume totale: "<<build.get_tot_volume()<<endl;
    cout<<"---------------------------------------------"<<endl;
}
void add_new_room(Building& build){
    double length=0, width=0, height=0;
    int num_people=0;
    bool check=true;
    while(check){
        cout<<"Inserire valore di lunghezza: "<<endl;cin>>length;
        if(length<0){
            cout<<"Errore: valore inserito errato, inserire nuovo valore: ";cin>>length;
        }else{
            check = false;
        }       
    }
    check=true;
    while(check){
        cout<<"Inserire valore di larghezza: "<<endl;cin>>width;
        if(width<0){
            cout<<"Errore: valore inserito errato, inserire nuovo valore: ";cin>>width;
        }else{
            check = false;
        }       
    }
    check=true;
    while(check){
        cout<<"Inserire valore di altezza: "<<endl;cin>>height;
        if(height<0){
            cout<<"Errore: valore inserito errato, inserire nuovo valore: ";cin>>height;
        }else{
            check = false;
        }       
    }
    cout<<"Inserire numero di persone all'interno della stanza: "<<endl;cin>>num_people;
    if(num_people<0){
        cout<<"Errore: numero inserito non valido. La stanza verrà creata con un'unica persona all'interno"<<endl;
        num_people=1;
    }
    cout<<"Nuova stanza creata: "<<endl;
    cout<<"lunghezza: "<<length<<endl;
    cout<<"larghezza: "<<width<<endl;
    cout<<"altezza: "<<height<<endl;    
    build.add_rooms(length,width,height,num_people,1);
    return;
}
void modify_building(Building &build){
    int check=0;
    while(check==0){
        cout<<"---------------------------------------------"<<endl;
        cout<<"Inserire una nuova stanza nel palazzo?"<<endl;        
        cout<<"si -> digitare: 0"<<endl;
        cout<<"no -> digitare: 1"<<endl;
        if(!(cin>>check)){
            cout<<"Codice inserito non valido. Non verrà creata una nuova stanza"<<endl;
            check=1;
        }
        if(check==0)
            add_new_room(build);
    }
    return;
}