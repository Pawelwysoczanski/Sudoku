#include "../inc/klasa_sudoku.h"

int sudoku::KtoryKwadrat(int i, int j)
{
    if (i < 3)
    {
        if (j < 3)
            return 0;
        else if (j < 6)
            return 1;
        else
            return 2;
    }
    else if (i < 6)
    {
        if (j < 3)
            return 3;
        else if (j < 6)
            return 4;
        else
            return 5;
    }
    else
    {
        if (j < 3)
            return 6;
        else if (j < 6)
            return 7;
        else
            return 8;
    }
}

bool sudoku::SprawdzJednaCzesc(int *smt[9][9], int k)
{
    int used[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; i++)
    {
        if (smt[k][i] != 0)
            used[(*smt[k][i]) - 1] += 1;
    }

    bool sukces = true;
    for (int i = 0; i < 9; i++)
        sukces &= (used[i] == 0 || used[i] == 1);

    return sukces;
}

int sudoku::SprawdzOstatni()
{
    int x = history.size() - 1;

    int i = history[x].i;
    int j = history[x].j;

    bool sukces = true;

    sukces &= SprawdzJednaCzesc(wiersz, i);
    sukces &= SprawdzJednaCzesc(kolumna, j);
    sukces &= SprawdzJednaCzesc(kwadrat, KtoryKwadrat(i, j));

    return 0;
}

bool sudoku::SprawdzWszystkie()
{
    bool sukces = true;

    for (int i = 0; i < 9; i++)
    {
        sukces &= SprawdzJednaCzesc(kwadrat, i);
        sukces &= SprawdzJednaCzesc(kolumna, i);
        sukces &= SprawdzJednaCzesc(wiersz, i);
    }

    return sukces;
}

bool sudoku::SprawdzRezultat()
{
    int x = 0;
    for (int i = 0; i < 81; i++)
        if (tablica[i])
            x++;

    if (x == 81 && SprawdzWszystkie())
        return true;
    else
        return false;
}

void sudoku::PokazTablice()
{
    rlutil::setColor(8);
    cout << "  ";
    for (int i = 0; i < 9; i++)
        cout << i << "  ";
    cout << "\n";
    rlutil::resetColor();

    for (int i = 0; i < 9; i++)
    {
        rlutil::setColor(8);
        cout << i;
        rlutil::resetColor();
        cout << "|";
        for (int j = 0; j < 9; j++)
        {
            if (tablica[9 * i + j])
                if (rozwiazanie[9 * i + j])
                {
                    rlutil::setColor(2);
                    cout << tablica[9 * i + j];
                    rlutil::resetColor();
                }
                else
                    cout << tablica[9 * i + j];
            else
                cout << " ";

            if ((j + 1) % 3)
                cout << ", ";
            else if (j == 8)
                cout << "| ";
            else
                cout << "| ";
        }
        cout << "\n";
        if (i == 2 || i == 5)
            cout << "\n";
    }
    cout << "\n";
}

void sudoku::WyczyscObraz()
{
    rlutil::cls();
    cout << "Poruszaj się WASD po planszy i wpisuj numery w pola" << endl;
    cout << "* wcisnij R aby odswiezyc          * wcisnij O aby zobaczyc rezultat" << endl;
    cout << "* wcisnij K aby zapisac i zamknac  * Esc zeby wyjsc" << endl;
    PokazTablice();
}

void sudoku::RuchTablicy()
{
    WyczyscObraz();
    //bool rezultat = false;
    int x = 3;
    int y = 5;
    int pozycja = 0;
    gotoxy(x, y);
    do
    {
        if (kbhit())
        {
            int k = rlutil::getkey();
            if (k == 'a')
            {
                if (x >= 4)
                {
                    x -= 3;
                    pozycja--;
                }
            }
            else if (k == 'd')
            {
                if (x <= 26)
                {
                    x += 3;
                    pozycja++;
                }
            }
            else if (k == 'w')
            {
                if (y == 9 || y == 13)
                {
                    y -= 2;
                    pozycja -= 9;
                }
                else if (y >= 6)
                {
                    y--;
                    pozycja -= 9;
                }
            }
            else if (k == 's')
            {
                if (y == 7 || y == 11)
                {
                    y += 2;
                    pozycja += 9;
                }
                else if (y <= 14)
                {
                    y++;
                    pozycja += 9;
                }
            }
            else if (k == '1')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 1);
                WyczyscObraz();
            }
            else if (k == '2')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 2);
                WyczyscObraz();
            }
            else if (k == '3')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 3);
                WyczyscObraz();
            }
            else if (k == '4')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 4);
                WyczyscObraz();
            }
            else if (k == '5')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 5);
                WyczyscObraz();
            }
            else if (k == '6')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 6);
                WyczyscObraz();
            }
            else if (k == '7')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 7);
                WyczyscObraz();
            }
            else if (k == '8')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 8);
                WyczyscObraz();
            }
            else if (k == '9')
            {
                if (!rozwiazanie[pozycja])
                    dodaj(pozycja, 9);
                WyczyscObraz();
            }
            else if (k == 'r')
            {
                WyczyscObraz();
            }
            else if (k == 'k')
            {
                gotoxy(0, 17);
                ZapisGry(const_cast<char *>("zapis.txt"));
                cout << "Zapisano.\nWcisnij dowolny klawisz...";
                break;
            }
            else if (k == rlutil::KEY_ESCAPE)
            {
                gotoxy(0, 17);
                cout << "Wcisnij dowlny klawisz ...";
                break;
            }
            // else if (k == 'o')
            //{
            //    rezultat = true;
            //}

            gotoxy(x, y); // Output player
            std::cout.flush();
        }
    } while (!SprawdzRezultat());
    if (SprawdzRezultat() == true)
    {
        WyczyscObraz();
        rlutil::setColor(3);
        cout << "_,-'*- WYGRALES -*'-._'" << endl;
        rlutil::setColor(2);
        cout << "      gratulacje!      " << endl;
        rlutil::resetColor();
    }
    else if (SprawdzRezultat() == false)
    {
        WyczyscObraz();
        rlutil::setColor(3);
        cout << "_,-'*- PRZEGRALES -*'-._'" << endl;
        rlutil::setColor(2);
        cout << "   SPROBUJ JESZCZE RAZ!   " << endl;
        rlutil::resetColor();
    }
}

void sudoku::dodaj(int p, int numer)
{
    int i, j;
    i = p % 9;
    j = p - 9 * i;

    wezel temp;
    temp.i = i;
    temp.j = j;
    temp.nr = numer;
    temp.prev = tablica[p];
    history.push_back(temp);

    tablica[p] = numer;
}

void sudoku::CzytajNazwe(char *nazwa)
{
    fstream plik;
    vector<int> data;
    int temp;
    plik.open(nazwa, ios::in);
    if (plik.good())
    {
        do
        {
            plik >> temp;
            data.push_back(temp);
        } while (!plik.eof());

        // std::cout << "Odczytano pomyslnie" << std::endl;
    }
    else
        std::cout << "Blad odczytu" << std::endl;

    plik.close();
    data.pop_back();

    if (data.size() == 81)
    {
        for (int i = 0; i < 81; i++)
            tablica[i] = data[i];
    }
    else
    {
        cout << "Zla ilosc danych w pliku" << endl;
    }

    for (int i = 0; i < 81; i++)
        rozwiazanie[i] = tablica[i];
    history.clear();
}

void sudoku::ZapisGry(char *nazwa)
{
    fstream plik;
    plik.open(nazwa, ios::out);
    if (plik.good())
    {
        for (int i = 0; i < 81; i++)
        {
            plik << tablica[i] << " ";
        }
        std::cout << "Zapisano pomyslnie" << std::endl;
    }
    else
        std::cout << "Blad zapisu" << std::endl;

    plik.close();
}

void sudoku::start()
{
    cout << "Wybierz powiom trudności lub wczytaj zapisana gre: " << endl;
    cout << "0. Testowy (98 procent)" << endl;
    cout << "1. Bardzo latwy (80 procent)" << endl;
    cout << "2. Latwy \t(60 procent)" << endl;
    cout << "3. Sredni \t(40 procent)" << endl;
    cout << "4. Trudny \t(25 procent)" << endl;
    cout << "\n5. Wczytaj zapisana gre" << endl;
    int opcja;
    cin >> opcja;
    switch (opcja)
    {
    case 0:
        GenerujZPrzykladu(0.98);
        break;

    case 1:
        GenerujZPrzykladu(0.8);
        break;

    case 2:
        GenerujZPrzykladu(0.6);
        break;

    case 3:
        GenerujZPrzykladu(0.4);
        break;

    case 4:
        GenerujZPrzykladu(0.25);
        break;

    case 5:
        CzytajNazwe(const_cast<char *>("zapis.txt"));
        break;

    default:
        break;
    }
    cout << "\n\n";
}

void sudoku::ZamienWiersz(int a, int b)
{
    int temp;
    if (a != b)
        for (int i = 0; i < 9; i++)
        {
            temp = tablica[9 * a + i];
            tablica[9 * a + i] = tablica[9 * b + i];
            tablica[9 * b + i] = temp;
        }
}

void sudoku::ZamienKolumne(int a, int b)
{
    int temp;
    if (a != b)
        for (int i = 0; i < 9; i++)
        {
            temp = tablica[9 * i + a];
            tablica[9 * i + a] = tablica[9 * i + b];
            tablica[9 * i + b] = temp;
        }
}

void sudoku::ZamienBlokWierszy(int a, int b)
{
    if (a != b)
        for (int i = 0; i < 3; i++)
            ZamienWiersz(3 * a + i, 3 * b + i);
}

void sudoku::ZamienBlokKolumn(int a, int b)
{
    if (a != b)
        for (int i = 0; i < 3; i++)
            ZamienKolumne(3 * a + i, 3 * b + i);
}
// genewierszanie planszy przez losowa ilosc losowych opracji na już wypenionej
// planszy
void sudoku::GenerujZPrzykladu(float gestosc)
{
    CzytajNazwe(const_cast<char *>("baza.txt"));

    ZmienLosowoWartosci();

    for (int i = 0; i < rand() % 50; i++)
    {
        bool b = rand() % 2;
        if (b)
            ZamienBlokKolumn(rand() % 3, rand() % 3);
        else
            ZamienBlokWierszy(rand() % 3, rand() % 3);
    }

    for (int i = 0; i < rand() % 50; i++)
    {
        int a = rand() % 3;
        int b = rand() % 3;
        int c = rand() % 3;

        bool x = rand() % 2;
        if (x)
            ZamienKolumne(3 * a + b, 3 * a + c);
        else
            ZamienWiersz(3 * a + b, 3 * a + c);
    }

    int liczbaDoZmiany = 81 - (81 * gestosc);
    cout << liczbaDoZmiany << endl;
    do
    {
        int a = rand() % 81;

        if (tablica[a])
        {
            tablica[a] = 0;
            liczbaDoZmiany--;
        }
    } while (liczbaDoZmiany);

    for (int i = 0; i < 81; i++)
        rozwiazanie[i] = tablica[i];
}

void sudoku::ZmienLosowoWartosci()
{
    int x = rand() % 9;

    for (int i = 0; i < 81; i++)
        tablica[i] = (tablica[i] + x) % 9 + 1;
}
