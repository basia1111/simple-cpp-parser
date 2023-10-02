#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student {
    string imie;
    string nazwisko;
    string nr_albumu;
    Student* next;
};

Student* head = nullptr;

Student* create_object() {
    Student* nowy = new Student;
    if (!nowy) {
        cerr << "Błąd dodawania\n";
        exit(1);
    }
    
    cout << "Podaj imie: ";
    cin >> nowy->imie;
    cout << "Podaj nazwisko: ";
    cin >> nowy->nazwisko;
    cout << "Podaj numer albumu: ";
    cin >> nowy->nr_albumu;

    nowy->next = nullptr;
    return nowy;
}

void wstaw() {
    ofstream plik;
    plik.open("rejestr.txt", ios::app);
    if (!plik) {
        cerr << "Error opening file\n";
        return;
    }

    Student* nowy = create_object();

    if (!head) {
        head = nowy;
    } else {
        nowy->next = head;
        head = nowy;
    }

    plik << nowy->imie << " " << nowy->nazwisko << " " << nowy->nr_albumu << "\n";
    plik.close();
}

void wypisz() {
    ifstream plik("rejestr.txt");
    if (!plik) {
        cerr << "Error opening file\n";
        return;
    }

    Student* aktualny = new Student;

    while (plik >> aktualny->imie >> aktualny->nazwisko >> aktualny->nr_albumu) {
        cout << "Imie: " << aktualny->imie << "\n";
        cout << "Nazwisko: " << aktualny->nazwisko << "\n";
        cout << "Numer albumu: " << aktualny->nr_albumu << "\n\n";
    }

    delete aktualny;
    plik.close();
}

void szukaj() {
    ifstream plik("rejestr.txt");
    if (!plik) {
        cerr << "Error opening file\n";
        return;
    }

    cout << "Podaj imie: ";
    string imie;
    cin >> imie;

    cout << "Podaj nazwisko: ";
    string nazwisko;
    cin >> nazwisko;

    Student* aktualny = new Student;

    while (plik >> aktualny->imie >> aktualny->nazwisko >> aktualny->nr_albumu) {
        if (aktualny->imie == imie && aktualny->nazwisko == nazwisko) {
            cout << "Imie: " << aktualny->imie << "\n";
            cout << "Nazwisko: " << aktualny->nazwisko << "\n";
            cout << "Numer albumu: " << aktualny->nr_albumu << "\n";
        }
    }

    delete aktualny;
    plik.close();
}

void PrintList(Student* head) {
    Student* bierzacy = head;

    if (!head) {
        cout << "Brak ostatnio dodanych danych\n";
    } else {
        while (bierzacy != nullptr) {
            cout << bierzacy->imie << " " << bierzacy->nazwisko << " " << bierzacy->nr_albumu;
            bierzacy = bierzacy->next;
        }
    }
    cout << "\n";
}

int main() {
    
 
        cout << "-----------------------------\n";
        cout << "-     REJESTR STUDENTÓW     -\n";
        cout << "-----------------------------\n\n";
        
        cout << "Wybierz opcje:\n\n";
        cout << "1. Dodaj studenta\n";
        cout << "2. Wyświetl ostatnio dodanych studentów\n";
        cout << "3. Wyświetl całą listę studentów\n";
        cout << "4. Wyszukaj studenta\n";
        cout << "5. Wyjście\n\n";
    
    
        int opcja;
        cout << "Opcja: ";
        cin >> opcja;
        switch (opcja) {
            case 1:
                wstaw();
                cout << "\nNACIŚNIJ ENTER ABY WRÓCIĆ DO MENU\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                main();
            case 2:
                cout << "---OSTATNIO DODANE---\n";
                PrintList(head);
                cout << "\nNACIŚNIJ ENTER ABY WRÓCIĆ DO MENU\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                main();
            case 3:
                cout << "---LISTA STUDENTÓW---\n\n";
                wypisz();
                cout << "\nNACIŚNIJ ENTER ABY WRÓCIĆ DO MENU\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                main();
            case 4:
                cout << "---WYSZUKIWANIE---\n\n";
                szukaj();
                cout << "\nNACIŚNIJ DOWOLNY  ENTER ABY WRÓCIĆ DO MENU\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                main();
            case 5:
                break;
            default:
                cout << "Wybierz opcje 1-5\n";
        }
    
    return 0;
}
