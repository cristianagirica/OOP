#include <iostream>


void afisareValori(int valoare1, int valoare2)
{
	std::cout << std::endl << "valoare 1 = " << valoare1 << " valoare 2 = " << valoare2;
}

void interschimbare(int valoare1, int valoare2)
{
	int temp = valoare1;
	valoare1 = valoare2;
	valoare2 = temp;
}

void interschimbare2(int* pv1, int* pv2)
{
	int temp = *pv1;
	*pv1 = *pv2;
	*pv2 = temp;
}

void interschimbare3(int& pv1, int& pv2)
{
	int temp = pv1;
	pv1 = pv2;
	pv2 = temp;
}

int main()
{
	int nrStudenti = 0;

	int* pointerNrStudenti = nullptr;

	nrStudenti = 2000;
	pointerNrStudenti = &nrStudenti;

	printf("\n Valoare int de la adresa pointerului este %d", *pointerNrStudenti);

	*pointerNrStudenti = 3000;

	printf("\n Numar studenti: %d", nrStudenti);

	int* valori = new int[1000];
	int* valoare = new int;

	delete[] valori;
	delete valoare;

	int valoare1 = 10;
	int valoare2 = 20;

	afisareValori(valoare1, valoare2);

	interschimbare(valoare1, valoare2);
	afisareValori(valoare1, valoare2);

	interschimbare2(&valoare1, &valoare2);
	afisareValori(valoare1, valoare2);

	interschimbare3(valoare1, valoare2);
	afisareValori(valoare1, valoare2);
}

