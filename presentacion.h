#include<iostream>

#include "game.h"

using namespace std;

string words[5] = {"Hola","Daniel","Danilo","Cuevas","Mendez"};

int life;

void iniciar(){
    cout<<"\nEstablecer Vidas\n";
    cin>>life;
    if(life!=0){
        game(words, &life);
    }else{
        cout<<"\nNo puedes iniciar con 0 vidas";
        iniciar();
    }

}

void menu(){

cout<<"    __  __    ___     _   __   ______    __  ___    ___     _   __          ______    ___     __  ___    ______\n";
cout<<"   / / / /   /   |   / | / /  / ____/   /  |/  /   /   |   / | / /         / ____/   /   |   /  |/  /   / ____/\n";
cout<<"  / /_/ /   / /| |  /  |/ /  / / __    / /|_/ /   / /| |  /  |/ /         / / __    / /| |  / /|_/ /   / __/\n";
cout<<" / __  /   / ___ | / /|  /  / /_/ /   / /  / /   / ___ | / /|  /         / /_/ /   / ___ | / /  / /   / /___\n";
cout<<"/_/ /_/   /_/  |_|/_/ |_/   \\____/   /_/  /_/   /_/  |_|/_/ |_/          \\____/   /_/  |_|/_/  /_/   /_____/\n";

iniciar();

}
