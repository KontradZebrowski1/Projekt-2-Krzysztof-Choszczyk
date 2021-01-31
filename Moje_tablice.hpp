#pragma once
#include "Data.hpp"

struct swieta                                   //Klasa tworzy obiekt zawierajacy liste swiat i pozwala na ich porownanie
{                                               //Zdefiniowane oddzielnie, coby nie zasmiecac klasy Data niepotrzebnie
    swieta()                                    //tworzy sie jedna instancja tych stalych
    {
        tablica.push_back(Data{ 1,1,1 });
        tablica.push_back(Data{ 6,1,1 });
        tablica.push_back(Data{ 1,5,1 });
        tablica.push_back(Data{ 3,5,1 });
        tablica.push_back(Data{ 15,8,1 });
        tablica.push_back(Data{ 1,11,1 });
        tablica.push_back(Data{ 11,11,1 });
        tablica.push_back(Data{ 25,12,1 });
        tablica.push_back(Data{ 26,12,1 });
    }
    bool czy_swieto(Data d)                     //Sprawdzenie czy data jest swiateczna, wykorzystuje przeciazony operator
    {
        bool czy = false;
        for (Data e : tablica)
        {
            if (d == e)
            {
                czy = true;
                break;
            }
        }
        return czy;
    }
    void print_czy_swieto(Data d)               //Metoda drukuje odpowiedz na pytanie czy porownywana data jest swietem 
    {
        bool czy = czy_swieto(d);
        if (czy)
            cout << "Tak, to jest swieto" << endl;
        else
            cout << "Nie, to nie jest swieto" << endl;
    }
private:
    vector<Data> tablica;                       //chcialem uzyc jakiegos kontenera, a nie mialem lepszego pomyslu, wiec uzylem go tutaj
};

struct tablica_dat                                      //Tutaj robimy tablice, zeby wykorzystac jakis algorytm, w tym przypadku sort, robimy to w klasie
{                                                       //zeby miec pelna kontrole nad tablica, a jednoczesnie nie zasmiecac rozepchanej juz klasy Data
    tablica_dat() { tablica.push_back(Data{}); }        //konstruktor zwykly tworzy instancje domyslna
    tablica_dat(Data d) { tablica.push_back(d); }
    void dodaj_date(Data d) { tablica.push_back(d); }
    void posortuj()
    {
        sort(tablica.begin(), tablica.end());
    }
    void print()
    {
        cout << "Tablica dat " << endl;
        for (Data e : tablica)
            e.print("normalny");
    }
private:
    vector<Data> tablica;
};