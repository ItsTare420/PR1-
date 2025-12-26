#include <iostream>
using namespace std;

//Napisite program koji trazi da unesete broj koji je u opsegu od 100 do 100 000
//(ukljucujuci i granicne vrijednosti). Nakon sto korisnik unese broj, 
//rekurzivno saberite znamenke broja. Ako dobiveni rezultat zbira znamenki broja
//je veci od broja 10 (npr. Broj 546 = 5+4+6=15) nastavite sabirati znamenke 
//novog broja (15 = 1+5=6), sve dok ne dobijete rezultat koji je manji od 10.

int zbirCifara(int n) {

	if (n < 10)return n;

	return n % 10 + zbirCifara(n / 10);
}

int main() {
	
	int n;
	do {
		cout << "Unesite broj: ";
		cin >> n;
	} while (n < 100 || n>100000);

	int rez = zbirCifara(n);
	cout << "Zbir cifara unesenog broja je " << rez << endl;

	while (rez > 9) {
		rez = zbirCifara(rez);
		cout << "Zbir cifara novog broja je " << rez << endl;
	}

	return 0;
}



