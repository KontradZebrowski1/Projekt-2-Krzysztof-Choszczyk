#pragma once
#include "Data.hpp"
Data operator+ (Data& d1, Data& d2)             //Przeciazenie operatora dodawania, pozwala na dodawanie majacych sens dat
{                                               //Jesli daty nie maja sensu wyrzuca blad jako wyjatek, ktory daje informacje co jest z datami nie tak
    if ((d1.get_day() < 1) || (d2.get_day() < 1) || (d1.get_month() < 1) || (d2.get_month() < 1))
    {
        char wyjatek{ 'a' };
        throw wyjatek;
    }
    if ((d1.get_day() > d1.maks_dni()) || (d2.get_day() > d2.maks_dni()))
    {
        int wyjatek{ 10000 };
        throw wyjatek;
    }
    if ((d1.get_month() > 12) || (d2.get_month() > 12))
    {
        float wyjatek{ 0.0 };
        throw wyjatek;
    }
    Data temp{ d1 };
    temp.przesun_rok(d2.get_year());
    temp.przesun_miesiac(d2.get_month());
    temp.przesun_dzien(d2.get_day());
    return temp;
}

Data operator- (Data& d1, Data& d2)                     //Przeciazenie operatora odejmowania, pozwala na odejmowanie majacych sens dat
{                                                       //Jesli daty nie maja sensu wyrzuca blad jako wyjatek, ktory daje informacje co jest z datami nie tak
    if ((d1.get_day() < 0) || (d2.get_day() < 0) || (d1.get_month() < 0) || (d2.get_month() < 0))
    {
        char wyjatek{ 'a' };
        throw wyjatek;
    }
    if ((d1.get_day() > 31) || (d2.get_day() > 31))
    {
        int wyjatek{ 1000 };
        throw wyjatek;
    }
    if ((d1.get_month() > 12) || (d2.get_month() > 12))
    {
        float wyjatek{ 0.0 };
        throw wyjatek;
    }
    Data temp{ d1 };
    temp.przesun_rok(-d2.get_year());
    temp.przesun_miesiac(-d2.get_month());
    temp.przesun_dzien(-d2.get_day());
    return temp;
}