#pragma once
#include "Data.hpp"
#include "Plus_i_minus.hpp"
#include "Moje_tablice.hpp"

int main()
{
    //Sprawdzenie jak dzialaja poszczegolne wlasciwosci, nie trzeba tlumaczyc, drukuja swoja funkcjonalnosc do konsoli
    Data d1{ 1,1,1111 };
    Data d2{ 25,12,0 };
    Data d4{ 24,12,0 };
    swieta s{};
    tablica_dat tab{};
    try
    {
        cout << "Daty, na ktorych przeprowadzane sa operacje dodawania i odejmowania:" << endl;
        d1.print("normalny");
        d2.print("normalny");
        cout << "Konstruktor przenoszacy, ktory jednoczesnie dodaje do siebie dwie daty \n";
        Data d3{ d1 + d2 };
        d3.print("normalny");
        cout << "Przenoszacy operator przypisania, ktory jednoczesnie odejmuje od siebie dwie daty \n";
        d1 = (d1 - d2);
        d1.print("odwrotny");
        cout << "\nPrzesuniecie wyniku dodawania o 30 (zapis amerykanski)" << endl;
        d3.przesun_dzien(30);
        d3.print("amerykanski");
        cout << "Cofniecie powyzszej daty o 26 miesiecy" << endl;
        d3.przesun_miesiac(-26);
        d3.print("slowny");
        cout << "Czy 25 grudnia to swieto?" << endl;
        s.print_czy_swieto(d2);
        tab.dodaj_date(d1);
        tab.dodaj_date(d2);
        tab.dodaj_date(d3);
        tab.dodaj_date(d4);
        tab.dodaj_date(Data{ 1,1,0 });
        tab.print();
        cout << "Sortowanie rosnace " << endl;
        tab.posortuj();
        tab.print();
        
        cout << "Teraz zrobimy wyjatek o tym, ze ktos stworzyl date o za duzej liczbie dni i chce ja dodac do istniejacej daty " << endl;
        Data d7{ 3333, 1, 1234 };
        cout << "wartosc przed bledem" << endl;
        d1.print("normalny");
        d1 = d3 + d7;
    }
    catch (int& wyjatek)
    {
        cout << "za duzo dni w d1 lub d2\n";
    }
    catch (float& wyjatek)
    {
        cout << "za dużo miesiecy w d1 lub d2\n";
    }
    catch (char& wyjatek)
    {
        cout << "ujemna data w d1 lub d2";
    }
    try
    {
        cout << "Teraz zrobimy wyjatek o tym, ze ktos stworzyl date o za malej liczbie miesiecy i chce ja dodac do istniejacej daty " << endl;
        Data d7{ 3333, -1, 1234 };
        cout << "wartosc przed bledem" << endl;
        d1.print("normalny");
        d1 = d2 + d7;
    }
    catch (int& wyjatek)
    {
        cout << "za duzo dni w d1 lub d2\n";
    }
    catch (float& wyjatek)
    {
        cout << "za dużo miesiecy w d1 lub d2\n";
    }
    catch (char& wyjatek)
    {
        cout << "ujemna data w d1 lub d2";
    }
    
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
