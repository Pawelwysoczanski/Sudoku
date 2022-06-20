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
  // Funkcja zwracająca polozenie w ktorym kwadracie wprowadzana jest zmiana
  int KtoryKwadrat(int i, int j);
  // Funkcja sprawdzająca jedną część sudoku wiersza,kolumny lub kwadratu
  bool SprawdzJednaCzesc(int *smt[9][9], int k);
  // Funkcja sprawdzająca ostatnią wprowadzoną wartość
  int SprawdzOstatni();
  // Funkcja sprawdzająca wszystkie wprowadzone wartości
  bool SprawdzWszystkie();
  // Funkcja sprawdzająca zgodność tablicy sudoku z tablicą rozwiązania
  bool SprawdzRezultat();
  // Funkcja ktora wypisuje całą tablicę sudoku na standardowe wyjście
  void PokazTablice();
  // Funkcja która odświerza informację wysłane na standardowe wyjście
  void WyczyscObraz();
  // Funkcaj odpowiadająca za poruszanie się po tablicy
  void RuchTablicy();
  // Funkcja dodaje wartość podaną przez użytkownika
  void dodaj(int p, int numer);
  // Funkcja czyta plik bazowy
  void CzytajNazwe(char *nazwa);
  // Funkcja zapisuje postęp gry
  void ZapisGry(char *nazwa);
  // Fukcja tworząca menu startowe gry
  void start();
  // Zmienia wartości w tablicy w sposób losowy
  void ZmienLosowoWartosci();
  // Zmienia kolejność wierszy
  void ZamienWiersz(int a, int b);
  // Zmienia kolejność bloków kolumn
  void ZamienKolumne(int a, int b);
  // Zmienia kolejność bloków wierszy
  void ZamienBlokWierszy(int a, int b);
  // Zmienia kolejność bloków kolumn
  void ZamienBlokKolumn(int a, int b);
  // Funkcja uzupełnia z pliku bazowego tablicę sudoku
  void GenerujZPrzykladu(float gestosc);
};
