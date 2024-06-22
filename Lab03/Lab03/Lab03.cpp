#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned char c = 48;
	c += 1;
	cout << endl << "Caracterul este " << c;

	c = 'a';
	cout << endl << "Caracterul este " << c;

	char nume[20];
	char prenume[] = "Gigel";

	const int nr_max_studenti = 100;

	cout << endl << "Numele este " << nume;
	nume[0] = 'A';
	nume[1] = 'n';
	nume[2] = 'a';
	nume[3] = '\0';
	cout << endl << "Numele este " << nume;

	strcpy_s(nume, 20, "Popescu");
	cout << endl << "Numele este " << nume;

	char* adresa;

	adresa = new char[strlen("Calea Dorobanti") + 1];
	strcpy_s(adresa, strlen("Calea Dorobanti") + 1, "Calea Dorobanti");

	cout << endl << "Adresa este " << adresa;

	delete[] adresa;

	adresa = new char[strlen("Calea Victoriei") + 1];
	strcpy_s(adresa, strlen("Calea Victoriei") + 1, "Calea Victoriei");

	cout << endl << "Adresa este " << adresa;

	string numeStudent = "Gigel";
	cout << endl << "Numele studentului este " << numeStudent;
	numeStudent += " Ionut";
	cout << endl << "Numele studentului este " << numeStudent;
	numeStudent = "Ion";
	cout << endl << "Numele studentului este " << numeStudent;
}
