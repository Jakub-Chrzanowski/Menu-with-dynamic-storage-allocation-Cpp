#include <iostream>
#include <fstream>
using namespace std;

int menu()
{
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usuñ element tablicy"<<endl;
    cout<<"4. Wyœwietl element tablicy"<<endl;
    cout<<"5. Wczytaj tablice z pliku"<<endl;
    cout<<"6. Wpisz tablice do pliku"<<endl;
    cout<<"7. Zamknij program"<<endl;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = menu();
        switch(m)
        {
        case(1):
            int * tmp = NULL;
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
        case(4):
            for(int i=0; i<n;i++)
            {
                cout<<p[i]<<",";
            }
            cout<<endl;
            break;
        }

    }
    }
