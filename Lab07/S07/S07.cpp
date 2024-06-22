#include <iostream>
#include <string>

using namespace std;
using std::string;

class Smartphone
{
    string* contacte = nullptr;
    int nrContacte = 0;

    const string IMEI;
    char nivelBaterie = 0;
public:
    string* getContacte()
    {
        string* lista = new string[this->nrContacte];
        for (int i = 0; i < this->nrContacte; i++)
        {
            lista[i] = this->contacte[i];
        }
        return lista;
    }

    int getNrContacte()
    {
        return this->nrContacte;
    }

    void setContacte(string* lista, int nrContacte)
    {
        if (lista == nullptr)
        {
            throw exception("Lista este vida");
        }
        delete[] this->contacte;
        this->nrContacte = nrContacte;
        this->contacte = new string[nrContacte];
        for (int i = 0; i < nrContacte; i++)
        {
            this->contacte[i] = lista[i];
        }
    }

    void printConsola()
    {
        cout << endl << "IMEI: " << this->IMEI;
        cout << endl << "Nivel baterie: " << (int)this->nivelBaterie << "%";
        if (this->nrContacte == 0)
        {
            cout << endl << "Agenda nu contine contacte";
        }
        else
        {
            cout << endl << "Agenda: ";
            for (int i = 0; i < this->nrContacte; i++)
            {
                cout << " " << this->contacte[i];
            }
        }
    }

    Smartphone(string imei, string* contacte, int nrContacte) :IMEI(imei), nivelBaterie(100)
    {
        this->setContacte(contacte, nrContacte);
    }

    ~Smartphone()
    {
        cout << endl << "Apel destructor";
        delete[] this->contacte;
        this->contacte = nullptr;
    }

    Smartphone(const Smartphone& tel) :IMEI(tel.IMEI)
    {
        this->setContacte(tel.contacte, tel.nrContacte);
        this->nivelBaterie = tel.nivelBaterie;
    }

    void operator = (const Smartphone& tel)
    {
        if (this == &tel)
        {
            return;
        }
        this->setContacte(tel.contacte, tel.nrContacte);
        this->nivelBaterie = tel.nivelBaterie;
    }
};

Smartphone createSmartphone()
{
    string agenda[] = { "Gigel", "Ana", "Ionel" };
    int nrContacte = 3;

    Smartphone telefon("1234", agenda, nrContacte);
    return telefon;
}

int main()
{
    Smartphone telefon = createSmartphone();
    telefon.printConsola();

    string* agenda = new string[4];
    for (int i = 0; i < 4; i++)
    {
        agenda[i] = "Ana";
    }
    Smartphone telefon2("2222", agenda, 4);

    telefon2.printConsola();

    Smartphone clona = telefon2;
    string agenda2[] = {"Tia", "Ruxi", "Ana"};
    clona.setContacte(agenda2, 3);
    clona.printConsola();
    telefon2.printConsola();

    Smartphone clona2(clona);
    clona2.setContacte(agenda, 4);
    clona2.printConsola();
    clona.printConsola();

    int* pointer = new int[10];
    delete[] pointer;
    pointer = nullptr;
}

