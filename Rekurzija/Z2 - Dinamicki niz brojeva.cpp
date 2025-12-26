#include <iostream>
#include<time.h>
using namespace std;

//Napisite program u kojem je potrebno unijeti velicinu dinamickog niza cjelobrojnih vrijednosti.
//nakon unosa velicine niza, program treba da uradi dinamicku alokaciju niza.
//Zatim je potrebno da se elementi niza popune sa slucajnim vrijednostima
//u opsegu od 1 do 40 (ukljucujuci i granicne vrijednosti) i to iskljucivo pomocu rekurzivne funkcije.
//Zatim, rekurzivnom funkcijom pronađite najveci neparni broj u nizu i broj parnih brojeva u nizu. 
//Obavezno uraditi sve neophodne dealokacije.
//U zadatku obavezno koristiti operator '*' umjesto '[]' prilikom dereferenciranja adresa/pokazivaca.

void dodajElemente(int * niz,int vel,int indeks) {

	if (indeks == vel)return;

	*(niz + indeks) = rand() % 40 + 1;

	dodajElemente(niz, vel, indeks + 1);
	return;
}

int najveciNeparni(int* niz, int vel, int indeks, int najveciNeparniBroj) {
	if (indeks == vel)return najveciNeparniBroj;

	if (*(niz + indeks) % 2 != 0) {
		if (*(niz + indeks) > najveciNeparniBroj)
			najveciNeparniBroj = *(niz + indeks);
	}
	return najveciNeparni(niz, vel, indeks + 1, najveciNeparniBroj);

}

int brojParnih(int* niz, int vel, int indeks) {

	if (indeks == vel)return 0;
	if (*(niz + indeks) % 2 == 0)
		return 1+ brojParnih(niz, vel, indeks + 1);

	return brojParnih(niz, vel, indeks + 1);
}

int main() {
	srand(time(0));
	int vel;
	cout << "Unesite velicinu niza: ";
	cin >> vel;

	int* niz = new int[vel];
	dodajElemente(niz, vel, 0);
	cout << "Elementi niza su: ";
	for (int i = 0; i < vel; i++)
		cout << niz[i] << " ";
	cout << endl;
	int biggestOdd = najveciNeparni(niz, vel, 0, 0);
	if (biggestOdd == 0) {
		cout << "Ne postoji neparni broj unutar niza" << endl;
	} else cout<<"Najveci neparni broj unutar niza je "<< najveciNeparni(niz, vel, 0, 0)<<endl;
	
	int numberOfEven = brojParnih(niz, vel, 0);
	if (numberOfEven == 0)
		cout << "Ne postoji parni broj unutar niza!" << endl;
	else cout<<"Broj parnih brojeva unutar niza: "<< brojParnih(niz, vel, 0)<<endl;


	delete[] niz; niz = nullptr;
	return 0;
}



