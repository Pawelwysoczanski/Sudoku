#pragma once
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

#include "../inc/rlutil.h"
#include "../inc/wezel.h"
#include "../inc/klasa_sudoku.h"

class sudoku
{
  int tablica[81];
  int rozwiazanie[81];

public:
  int *wiersz[9][9];
  int *kolumna[9][9];
  int *kwadrat[9][9];
  vector<wezel> history;

  // Komstruktor klasy sudoku
  sudoku()
  {
    history.empty();
    for (int i = 0; i < 81; i++)
    {
      tablica[i] = 0;
      rozwiazanie[i] = 0;
    }

    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        wiersz[i][j] = &tablica[9 * i + j];
        kolumna[i][j] = &tablica[9 * j + i];
      }
    }

    int a, b, c, d;
    a = 0;
    b = 1;
    c = 2;
    d = 0;
    kwadrat[d][0] = &tablica[a];
    kwadrat[d][1] = &tablica[b];
    kwadrat[d][2] = &tablica[c];
    kwadrat[d][3] = &tablica[a + 9];
    kwadrat[d][4] = &tablica[b + 9];
    kwadrat[d][5] = &tablica[c + 9];
    kwadrat[d][6] = &tablica[a + 18];
    kwadrat[d][7] = &tablica[b + 18];
    kwadrat[d][8] = &tablica[c + 18];
    d++;
    kwadrat[d][0] = &tablica[a + 3];
    kwadrat[d][1] = &tablica[b + 3];
    kwadrat[d][2] = &tablica[c + 3];
    kwadrat[d][3] = &tablica[a + 9 + 3];
    kwadrat[d][4] = &tablica[b + 9 + 3];
    kwadrat[d][5] = &tablica[c + 9 + 3];
    kwadrat[d][6] = &tablica[a + 18 + 3];
    kwadrat[d][7] = &tablica[b + 18 + 3];
    kwadrat[d][8] = &tablica[c + 18 + 3];
    d++;
    kwadrat[d][0] = &tablica[a + 6];
    kwadrat[d][1] = &tablica[b + 6];
    kwadrat[d][2] = &tablica[c + 6];
    kwadrat[d][3] = &tablica[a + 9 + 6];
    kwadrat[d][4] = &tablica[b + 9 + 6];
    kwadrat[d][5] = &tablica[c + 9 + 6];
    kwadrat[d][6] = &tablica[a + 18 + 6];
    kwadrat[d][7] = &tablica[b + 18 + 6];
    kwadrat[d][8] = &tablica[c + 18 + 6];

    a += 27;
    b += 27;
    c += 27;
    d++;
    kwadrat[d][0] = &tablica[a];
    kwadrat[d][1] = &tablica[b];
    kwadrat[d][2] = &tablica[c];
    kwadrat[d][3] = &tablica[a + 9];
    kwadrat[d][4] = &tablica[b + 9];
    kwadrat[d][5] = &tablica[c + 9];
    kwadrat[d][6] = &tablica[a + 18];
    kwadrat[d][7] = &tablica[b + 18];
    kwadrat[d][8] = &tablica[c + 18];
    d++;
    kwadrat[d][0] = &tablica[a + 3];
    kwadrat[d][1] = &tablica[b + 3];
    kwadrat[d][2] = &tablica[c + 3];
    kwadrat[d][3] = &tablica[a + 9 + 3];
    kwadrat[d][4] = &tablica[b + 9 + 3];
    kwadrat[d][5] = &tablica[c + 9 + 3];
    kwadrat[d][6] = &tablica[a + 18 + 3];
    kwadrat[d][7] = &tablica[b + 18 + 3];
    kwadrat[d][8] = &tablica[c + 18 + 3];
    d++;
    kwadrat[d][0] = &tablica[a + 6];
    kwadrat[d][1] = &tablica[b + 6];
    kwadrat[d][2] = &tablica[c + 6];
    kwadrat[d][3] = &tablica[a + 9 + 6];
    kwadrat[d][4] = &tablica[b + 9 + 6];
    kwadrat[d][5] = &tablica[c + 9 + 6];
    kwadrat[d][6] = &tablica[a + 18 + 6];
    kwadrat[d][7] = &tablica[b + 18 + 6];
    kwadrat[d][8] = &tablica[c + 18 + 6];

    a += 27;
    b += 27;
    c += 27;
    d++;
    kwadrat[d][0] = &tablica[a];
    kwadrat[d][1] = &tablica[b];
    kwadrat[d][2] = &tablica[c];
    kwadrat[d][3] = &tablica[a + 9];
    kwadrat[d][4] = &tablica[b + 9];
    kwadrat[d][5] = &tablica[c + 9];
    kwadrat[d][6] = &tablica[a + 18];
    kwadrat[d][7] = &tablica[b + 18];
    kwadrat[d][8] = &tablica[c + 18];
    d++;
    kwadrat[d][0] = &tablica[a + 3];
    kwadrat[d][1] = &tablica[b + 3];
    kwadrat[d][2] = &tablica[c + 3];
    kwadrat[d][3] = &tablica[a + 9 + 3];
    kwadrat[d][4] = &tablica[b + 9 + 3];
    kwadrat[d][5] = &tablica[c + 9 + 3];
    kwadrat[d][6] = &tablica[a + 18 + 3];
    kwadrat[d][7] = &tablica[b + 18 + 3];
    kwadrat[d][8] = &tablica[c + 18 + 3];
    d++;
    kwadrat[d][0] = &tablica[a + 6];
    kwadrat[d][1] = &tablica[b + 6];
    kwadrat[d][2] = &tablica[c + 6];
    kwadrat[d][3] = &tablica[a + 9 + 6];
    kwadrat[d][4] = &tablica[b + 9 + 6];
    kwadrat[d][5] = &tablica[c + 9 + 6];
    kwadrat[d][6] = &tablica[a + 18 + 6];
    kwadrat[d][7] = &tablica[b + 18 + 6];
    kwadrat[d][8] = &tablica[c + 18 + 6];
  }
  // Funkcja zwracaj??ca polozenie w ktorym kwadracie wprowadzana jest zmiana
  int KtoryKwadrat(int i, int j);
  // Funkcja sprawdzaj??ca jedn?? cz?????? sudoku wiersza,kolumny lub kwadratu
  bool SprawdzJednaCzesc(int *smt[9][9], int k);
  // Funkcja sprawdzaj??ca ostatni?? wprowadzon?? warto????
  int SprawdzOstatni();
  // Funkcja sprawdzaj??ca wszystkie wprowadzone warto??ci
  bool SprawdzWszystkie();
  // Funkcja sprawdzaj??ca zgodno???? tablicy sudoku z tablic?? rozwi??zania
  bool SprawdzRezultat();
  // Funkcja ktora wypisuje ca???? tablic?? sudoku na standardowe wyj??cie
  void PokazTablice();
  // Funkcja kt??ra od??wierza informacj?? wys??ane na standardowe wyj??cie
  void WyczyscObraz();
  // Funkcaj odpowiadaj??ca za poruszanie si?? po tablicy
  void RuchTablicy();
  // Funkcja dodaje warto???? podan?? przez u??ytkownika
  void dodaj(int p, int numer);
  // Funkcja czyta plik bazowy
  void CzytajNazwe(char *nazwa);
  // Funkcja zapisuje post??p gry
  void ZapisGry(char *nazwa);
  // Fukcja tworz??ca menu startowe gry
  void start();
  // Zmienia warto??ci w tablicy w spos??b losowy
  void ZmienLosowoWartosci();
  // Zmienia kolejno???? wierszy
  void ZamienWiersz(int a, int b);
  // Zmienia kolejno???? blok??w kolumn
  void ZamienKolumne(int a, int b);
  // Zmienia kolejno???? blok??w wierszy
  void ZamienBlokWierszy(int a, int b);
  // Zmienia kolejno???? blok??w kolumn
  void ZamienBlokKolumn(int a, int b);
  // Funkcja uzupe??nia z pliku bazowego tablic?? sudoku
  void GenerujZPrzykladu(float gestosc);
};
