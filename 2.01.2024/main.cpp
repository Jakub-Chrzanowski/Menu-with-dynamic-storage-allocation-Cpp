#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>

using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int menu()
{
    int x;
    cout<<endl;
    /*    Nakłada kolor na tekst w konsoli
        */
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED );
    cout<<"1. Dodaj element tablicy"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    cout<<"2. Wstaw element tablicy"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout<<"3. Usun element tablicy"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    cout<<"4. Wyswietl element tablicy"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout<<"5. Wczytaj tablice z pliku"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
    cout<<"6. Wpisz tablice do pliku"<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    cout<<"7. Zamknij program"<<endl;
    cout<<endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
    cout<<"Podaj swoj wybor: ";
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    int pozycja,wartosc;
    while(true)
    {
        m = menu();
        switch(m)
        {
        case 1:
            {
             int * tmp = NULL;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED ); 
            cout<<"Podaj element tablicy: "<<endl;
            if(p==NULL)
            {
                p = new int[n+1];
                cin >>p[n];
                n++;
            }
            else
            {
                tmp = new int[n+1];
                for(int i=0;i<n;i++)
                {
                    tmp[i] = p[i];
                }
                cin>>tmp[n];
                n++;
                delete[] p;
                p = tmp;
            }
            break;
            }
        case 2:
            {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);    
            cout << "Podaj pozycje, na ktorej chcesz wstawic element: ";
            cin >> pozycja;
            if (pozycja > n) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                cout << "Podana pozycja jest wieksza niz rozmiar tablicy." << endl;
                break;
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            cout << "Podaj wartosc elementu: ";
            cin >> wartosc;
            for (int i = n - 1; i >= pozycja; i--) {
                p[i + 1] = p[i];
            }
            p[pozycja] = wartosc;
            n++;
            break;
            }
        case 3:
            {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);    
            cout << "Podaj pozycje, na ktorej znajduje sie element, ktory chcesz usunac: ";
            cin >> pozycja;
            if (pozycja >= n) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "Podana pozycja jest wieksza niz rozmiar tablicy." << endl;
                            }       
            for (int i = pozycja; i < n - 1; i++) {
            p[i] = p[i + 1];
             }
            n--;
            break;
            }
        case 4:
            {
            if(p==NULL)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                cout<<"Pusta tablica!";
            }
            for(int i=0; i<n;i++)
            {
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                 cout<<p[i]<<",";
            }
            cout<<endl;
            break;
            }
        case 5:
        /*
        Krótki komentarz wstępu do tego case'a:
        Komentarz tyczy się tutaj sposobu jak poprawnie powinien być sformułowany plik tekstowy,aby kod poprawnie się wykonał.
        Schemat pliku tekstowego:
        4 <- pierwsza linijka tekstu: podana tutaj liczba jest rozmiarem tablicy
        13 14 15 17 <- kolejna linijka tekstu: podane tutaj liczby są zawartością tablicy
        */
            {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "Podaj sciezke dostepu do pliku: ";
            string sciezka_pliku;
            cin >> sciezka_pliku;
            ifstream fin(sciezka_pliku,ios::app);
            if (!fin.is_open()) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "Nie mozna otworzyc pliku." << endl;
                break;  
            }
            int rozmiar;
            fin >> rozmiar;
            delete[] p;
            p = new int[rozmiar];
            for (int i = 0; i < rozmiar; i++) {
                fin >> p[i];
            }
            n = rozmiar;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            cout << "Tablica zostala wczytana z pliku." << endl;
            fin.close();
            break;
            }
        case 6:
        /*
        Krótki komentarz również tutaj:
        Plik zapisywany jest w następujący sposób:
        n <- rozmiar tablicy
        x y z a b c <- elementy tablicy
        */
            {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
            cout<<"Podaj sciezke dostepu do pliku, do ktorego chcesz zapisac tablice: "<<endl;
            string sciezka_pliku;
            cin>>sciezka_pliku;
            ofstream fout(sciezka_pliku,ios::out|ios::trunc);
            if(!fout.is_open())
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "Nie mozna otworzyc pliku." << endl;
                break; 
            }
            if(p==NULL)
            {
                cout<<"Nie mozna zapisac pustej tablicy.";
            }
            else
            {
                fout<<n<<endl;
                for(int i=0; i<n;i++)
                {
                    fout<<p[i]<<" ";
                }
                cout<<"Pomyslne zapisano tablice do pliku.";
            } 
            fout.close();
            break;
            }
        case 7:
            {
            exit(0);
            break;
            }
    }
    }
    return 0;
    
}
