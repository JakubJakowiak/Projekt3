#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include "si.h"

using namespace std;


int main()
{
	int rozmiar, lznakow=0, n;
	char odnowa;
	cout << "           Witaj w grze kolko i krzyzyk!" << endl << endl;
	while(1){
        cout << "Podaj dlugosc planszy (ilosc pol w kolumnie lub wierszu): ";
        cin >> rozmiar;
        cout<< endl;
        if(rozmiar<3){
             while(3){
            cout << "Za mala wartosc!!" << endl<< endl;
            cout << "Podaj dlugosc planszy (ilosc pol w kolumnie lub wierszu): ";
            cin >> rozmiar;
            cout<< endl;
            if(rozmiar>3 || rozmiar==3) break;
             }
        }
        cout << "Podaj liczbe znakow w rzedzie wystarczajaca do wygranej: ";
        cin >> lznakow;
        cout<< endl;
        if(lznakow<3){
             while(3){
            cout << "Za mala wartosc!!" << endl<< endl;
            cout << "Podaj liczbe znakow w rzedzie wystarczajaca do wygranej: ";
            cin >> lznakow;
            cout<< endl;
            if(lznakow>3 || lznakow==3) break;
             }
        }
        if(lznakow>rozmiar){
            while(lznakow>rozmiar){
            cerr << "Wieksza od rozmiaru planszy?" << endl << endl<< "Podaj liczbe znakow w rzedzie potrzebna do wygranej jeszcze raz: ";
            cin >> lznakow;
            cout<< endl;
            if(lznakow>rozmiar) break;
        }
        cout << endl;
        }
        while(lznakow>rozmiar){
            cerr << "Wieksza od rozmiaru planszy? Podaj liczbe znakow w rzedzie potrzebna do wygranej jeszcze raz: ";
            cin >> lznakow;
        }
        cout << endl;
        n = rozmiar * rozmiar;

        char *t = new char[n+1], gracz;
        for(int i=1; i<=n; i++)
        t[i] = ' ';
        gracz = 'O';
        plansza(t, rozmiar, n);
        while(1){
            ruch(t, gracz, rozmiar, n, lznakow);
            plansza(t, rozmiar, n);
            if (wygrana(t, 'X', false, rozmiar, n, lznakow) ||
                wygrana(t, 'O', false, rozmiar, n, lznakow) ||
                remis(t, false, rozmiar, n))
                break;
        }
        cout << "Chcesz zagrac jeszcze raz? (T/N) ";
        cin >> odnowa;
        if(!(odnowa == 'T' || odnowa =='t')) break;
        else cout << endl;
    }
	cout << endl <<  " ___________________\n"<< "<Dzieki za gre szefito >\n";
cout<<" -------------------\n";
cout<<"        \   ^__^\n";
cout<<"         \  (oo)\_______\n";
cout<<"           (__)\       )\\/\\/"<<endl;
cout<<"               ||----w |\n";
cout<<"               ||     ||" << endl;


	return 0;
}
