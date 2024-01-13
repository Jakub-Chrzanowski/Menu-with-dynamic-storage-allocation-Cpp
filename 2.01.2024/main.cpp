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
            return 0;
                            }       
            for (int i = pozycja; i < n - 1; i++) {
            p[i] = p[i + 1];
             }
            n--;
            }
        case 4:
            for(int i=0; i<n;i++)
            {
                 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                 cout<<p[i]<<",";
            }
            cout<<endl;
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}
