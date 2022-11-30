#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string SelectWord(string words[5]){
    srand(time(NULL));
    int number = rand()%5;
    return words[number];
}

string censor(string Word){
    string aux = "";
    for( int i=0; i<Word.size(); i++){
        aux = aux + "*";
    }
    return aux;
}

int Ncensor(string word){
    int aux = 0;
    for(int i=0; i<word.size();i++){
        if(word[i]=='*') aux++;
    }
    return aux;
}

void Llife(int *life){
    *life=*life-1;
}

void Cletter(string *word, char letter, int *life, string *CW){
    int aux = 0;
    string auxs = *word;
    string auxCW = *CW;

    for(int i=0; i<auxs.size(); i++){
        if(auxs[i]==letter){
            aux=1;
            auxCW[i] = letter;
        }
    }

    *CW = auxCW;

    if(aux==0){
        cout<<"\nLa letra no se encuentra en la palabra\n";
        Llife(life);
    }
}

void Cletters(string *word, string Uletters, char letter, int *life, string *CW){

    for(int i=0; i<Uletters.size(); i++){
        if(Uletters[i]==letter){
            Llife(life);
            cout<<"Ya has escogido esta letra";
            break;
        }
        if(i==Uletters.size()-1){
            Cletter(word,letter,life,CW);
        }
    }

    if(0==Uletters.size()){
            Cletter(word,letter,life,CW);
    }

}

void win(int *life, string word){

    if(*life==0){
        cout<<"\nGame over\n la palabra era " + word + "\n";
    }else{
        cout<<"\nYou Win\n la palabra era " + word + "\n";
    }

}

void game(string words[5], int *life){
    string Word = SelectWord(words);
    string CensorWord = censor(Word);
    string Uletters = "";
    char letter;
    while(*life!=0 && Ncensor(CensorWord)!=0){
        cout<<"\n"<<CensorWord<<" "<<*life<<"\n";
        cin>>letter;
        Cletters(&Word, Uletters, letter, life, &CensorWord);
        Uletters = Uletters+letter;
    }
    win(life, Word);
}
