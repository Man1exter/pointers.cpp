#include <iostream>
using namespace std;

//---------------------------------------------------------------------
//  PRZEKAZYWANIE WSKAŹNIKA DO FUNKCJI
//  PRZEKAZYWANIE TABLICY
void dodaj_1(int tab[], int wielkosc){
  cout << "Adres tablicy w dodaj_1() - " << tab << endl;
  for (int i=0; i<wielkosc; i++){
    *(tab+i)+=1;
  }
}

void drukuj(int tab[], int w){
  cout << endl << endl;
  for (int i=0; i<w; i++){
    cout << tab[i] << ", ";
  } 
  cout << endl << endl;
}

//-----------------------------

// PRZEKAZYWANIE ZMIENNEJ

/* Przekazanie zmiennej w normalny sposób sprawi, że w funkcji powstanie kopia przekazywanej zmiennej */

void dodaj(int a){
  a=a+333;
  cout << "Adres 'a' w dodaj() - " << &a << endl;
  cout << "'a' w funkcji dodaj() = " << a << endl;
}

/* Przekazywanie wskaźnika do zmiennej sprawi, że funkcja będzie pracować na oryginalnej zmiennej - ostrożnie pracuj ze wskaźnikami gdyż łatwo jest wywołać z nimi błąd, a trudno go znaleźć gdy masz już cały gotowy program.*/

void dodaj_przez_wsk(int &b){
  b=b+333;
  cout << "Adres 'b' w dodaj() - " << &b << endl;
  cout << "'b' w funkcji dodaj_przez_wsk() = " << b << endl;
}
//---------------------------------------------------------------------




int main() 
{
/* WSKAŹNIKI

& - ampersand odnosi się do adresu zmiennej

int jakas_liczba = 0;
cout << jakas_liczba;  ---- pokaże 0
cout << &jakas_liczba; ---- pokaże adres zmiennej w pamięci

int *wskaznik = &jakas_liczba
wskaznikowi "wskaznik" przypisujemy adres zmiennej "jakas_liczba"

cout << *wskaznik;   ---- pokaże 0
cout << wskaznik;    ---- pokaże adres

wskaznik == &zmienna
*wskaznik == zmienna

jakas_liczba = 100;   ==    *wskaznik = 100;

*/
//---------------------------------------------------------------------
  cout << "\n\n========== WSKAŹNIKI I ADRESY ZMIENNYCH ==========\n\n\n";
  int liczba = 100;
  int mnozenie_x5 = 500;

  cout << "\nliczba = " << liczba << endl;
  cout << "mnozenie *5 = " << mnozenie_x5 << endl << endl;

  int *wsk_l = &liczba;
  int *wsk_mn = &mnozenie_x5;

  cout << "wsk_l = " << wsk_l << endl;
  cout << "*wsk_l = " << *wsk_l << endl;

  cout << endl;

  cout << "wsk_mn = " << wsk_mn << endl;
  cout << "*wsk_mn = " << *wsk_mn << endl;
  
  cout << endl;

  cout << "ZMIANA liczby poprzez wskaznik:" << endl;
  *wsk_l = 350;
  cout << "*wsk_l = " << *wsk_l << endl ;
  cout << "liczba = " << liczba << endl << endl;
//---------------------------------------------------------------------
/*

TABLICE I WSKAŹNIKI

ADRES TABLICY JEST JEDNOCZEŚNIE ADRESEM JEJ PIERWSZEGO ELEMENTU

int tablica[5]{1,2,3,4,5};
cout << tablica     ---- pokaze adres tablicy
cout << &tablica[0] ---- pokaze adres pierwszego elementu == adres tablicy
cout << tablica[0]  ---- pokaze zawartosc 1szego elementu

*/
//---------------------------------------------------------------------
  cout << "\n\n========== ADRES TABLICY I JEJ ELEMENTÓW ==========\n\n\n";
  int tablica[5]{1,5,10,15,20};
  cout << tablica << " = adres tablicy (cout << tablica)"  << endl;
  cout << &tablica[0] << " = adres 1-go elementu (cout << &tablica[0])" <<  endl;
  cout << tablica[0] << " = zawartosc 1-go elementu (cout << tablica[0])"  << endl;

  cout << endl;

  cout << "PĘTLA z adresami i zawartością:" << endl;
  int j=0;
  do
  {
    if (j<5){
    cout << "---------------------j="<<j<<"-------------------------" << endl;
    }
    else{
      cout << "-!!!!!!!UWAGA!!!!!-j="<<j<<"-----losowa zawartosc----" << endl;
    }
    cout << "&tablica["<<j<<"] = " << &tablica[j] << endl;
    cout << "*tablica+"<<j<<" = " << *tablica+j << endl;
    cout << "*(tablica+"<<j<<") = " << *(tablica+j) << endl;
    cout << "tablica["<<j<<"] = " << tablica[j] << endl;
    j++;
  }while(j<=5);

//---------------------------------------------------------------------

// PRZEKAZYWANIE WSKAZNIKA DO FUNKCJI
// TABLCA

cout << "\n\n========== PRZEKAZYWANIE TABLICY DO FUNKCJI ==========\n\n\n";
int tab[5]{1,2,3,4,5};
cout << "Adres tablicy w main - " << tab << endl;

cout << "tab przed dodaj_1(): ";
drukuj(tab, 5);

dodaj_1(tab, 5);

cout << "tab po dodaj_1(): ";
drukuj(tab, 5);

//-------------------------------
//  ZMIENNA

cout << "\n\n========== PRZEKAZYWANIE ZMIENNEJ DO FUNKCJI ==========\n========== w normalny sposób ==========\n\n";
int a = 5;
cout << "adres 'a' w main - " << &a << endl;
cout << "'a' w main przed dodaj() = " << a << endl;
dodaj(a);
cout << "'a' w main po dodaj() = " << a << endl;

cout << "\n========== sposób przez referencje (wskaźnikiem) ==========\n\n";

int b = 5;
cout << "adres 'b' w main - " << &b << endl;
cout << "'b' w main przed dodaj_przez_wsk() = " << b << endl;
dodaj_przez_wsk(b);
cout << "'b' w main po dodaj_przez_wsk() = " << b << endl;
}