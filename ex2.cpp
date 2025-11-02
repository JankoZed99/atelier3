#include <iostream>
using namespace std;

class Fichier {
private:
    char* P;       // pointeur vers la zone memoire
    int longueur;  // taille du fichier en octets

public:
    Fichier() {
        P = nullptr;
        longueur = 0;
        cout << "Constructeur appele." << endl;
    }

    void Creation(int taille) {
        longueur = taille;
        P = new char[longueur];  // allocation dynamique
        cout << "Memoire de " << longueur << " octets allouee." << endl;
    }

    void Remplit() {
        if (P == nullptr) {
            cout << "Aucune memoire allouee." << endl;
            return;
        }
        // remplir la memoire avec des lettres
        for (int i = 0; i < longueur; i++) {
            P[i] = 'A' + (i % 26);
        }
        cout << "Zone memoire remplie." << endl;
    }

    void Affiche() {
        if (P == nullptr) {
            cout << "Rien a afficher." << endl;
            return;
        }
        cout << "Contenu du fichier : ";
        for (int i = 0; i < longueur; i++) {
            cout << P[i];
        }
        cout << endl;
    }

    ~Fichier() {
        delete[] P;  // liberation de la memoire
        cout << "Destructeur appele, memoire liberee." << endl;
    }
};

int main() {
    Fichier* f = new Fichier();  // creation dynamique

    f->Creation(20);
    f->Remplit();
    f->Affiche();

    delete f;  // destruction de l'objet

    return 0;
}
