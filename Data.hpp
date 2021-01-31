#pragma once
#include <iostream>
#include <vector>
#include <variant>
#include <algorithm>

using namespace std;        //dla wygody

struct Data
{
    Data() : day{ 1 }, month{ 1 }, year{ 1997 }{};
    Data(int dd, int mm, int yy) : day{ dd }, month{ mm }, year{ yy } {};
    Data(const Data& sth) :day{ sth.day }, month{ sth.month }, year{ sth.year } {};
    Data& operator=(const Data&) { return *this; }
    Data(Data&& sth) noexcept :day{ sth.day }, month{ sth.month }, year{ sth.year } {};
    Data& operator=(Data&& sth) noexcept        //wykorzystywany w paru miejscach przenoszacy operator przypisania, glowny powod, dla ktorego zdefiniowano cala piatke
    {                                           //poniewaz nie rzuca wyjatkow, dodane jest noexcept
        if (this != &sth)
        {
            day = sth.get_day();
            month = sth.get_month();
            year = sth.get_year();
        }
        return *this;
    };
    ~Data() {}

    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }

    void set_day(int a) { day = a; }    //settery, w sumie niewykorzystywane, ale moglyby sie przydac, gdyby zdefiniowano jakas metode jako funkcje
    void set_month(int a) { month = a; }
    void set_year(int a) { year = a; }
    string nazwij_miesiac() {       //Metoda, ktora nadaje nazwy miesiacom, wykorzystywana do drukowania slownie
        switch (month)
        {
        case 1:
            return "stycznia";
            break;
        case 2:
            return "lutego";
            break;
        case 3:
            return "marca";
            break;
        case 4:
            return "kwietnia";
            break;
        case 5:
            return "maja";
            break;
        case 6:
            return "czerwca";
            break;
        case 7:
            return "lipca";
            break;
        case 8:
            return "sierpnia";
            break;
        case 9:
            return "wrzesnia";
            break;
        case 10:
            return "pazdziernika";
            break;
        case 11:
            return "listopada";
            break;
        case 12:
            return "grudnia";
            break;
        }
    }

    //Przesuwanie dni, miesiecy o konkretna liczbe, ujemna przesuwa do tylu, wykorzystywane sa miedzy innymi w przeciazonych operatorach + i -
    void przesun_dzien(int liczba)
    {
        day += liczba;
        while (day > maks_dni())        //Dopoki liczba dni przekracza maksymalna liczbe dni w miesiacu
        {
            day -= maks_dni();          //Zmniejszamy liczbe dni aktualna o liczbe w danym miesiacu
            month++;                    //i zwiekszamy miesiac
            if (month > 12)             //nie wolno zapomniec o zmianie roku
            {
                year++;
                month -= 12;
            }
        }
        while (day < 1)
        {
            month--;
            day += maks_dni();
            if (month < 1)
            {
                year--;
                month += 12;
            }
        }
    }
    void przesun_miesiac(int liczba)
    {
        month += liczba;
        while (month < 1)
        {
            year--;
            month += 12;
        }
        while (month > 12)
        {
            year++;
            month -= 12;
        }
    }
    void przesun_rok(int liczba)
    {
        year += liczba;
    }

    int maks_dni()              //Metoda sprawdza liczbe dni przypisanych do danego miesiaca, potrzebne do przesuwania dni
    {
        switch (month)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if ((year % 4 == 0) && (year % 1000 != 0))
                return 29;
            else
                return 28;
            break;
        default:
            return 31;
            break;
        }
    }
    void print(string typ)                  //Druk daty w kilku roznych formatach
    {
        if (typ == "normalny")
            cout << day << "." << month << "." << year << endl;
        else if (typ == "amerykanski")
            cout << month << "." << day << "." << year << endl;
        else if (typ == "odwrotny")
            cout << year << "." << month << "." << day << endl;
        else if (typ == "slowny")
            cout << day << " " << nazwij_miesiac() << " " << year << endl;
    }

    bool operator==(Data& d1)           //Przeciazenie opoeratora porownania wykorzystane w sprawdzeniu czy data jest swietem
    {
        if ((day == d1.get_day()) && (month == d1.get_month()))
            return true;
        else
            return false;
    }
    bool operator<(Data& d1)                    //Przeciazenie operatora porownania wykorzystanego w algorytmie sort
    {
        if (year < d1.get_year())
            return true;
        else if (year == d1.get_year())
        {
            if (month < d1.get_month())
                return true;
            else if (month == d1.get_month())
            {
                if (day < d1.get_day())
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }

private:
    int day;
    int month;
    int year;
    string nazwa;
};