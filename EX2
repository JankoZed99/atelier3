#include <iostream>
using namespace std;

struct Element {
    int valeur;
    Element* suivant;
};

class Liste {
private:
    Element* tete; // pointeur sur le premier élément

public:
    Liste() { // constructeur
        tete = nullptr;
    }

    ~Liste() { // destructeur pour éviter fuite mémoire
        while (tete != nullptr) {
            Element* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }

    void ajouterDebut(int v) {
        Element* nouveau = new Element;
        nouveau->valeur = v;
        nouveau->suivant = tete;
        tete = nouveau;
    }

    void supprimerDebut() {
        if (tete == nullptr) {
            cout << "La liste est vide, rien à supprimer." << endl;
        } else {
            Element* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }

    void afficher() {
        Element* courant = tete;
        cout << "Liste : ";
        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    Liste maListe;

    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(30);

    maListe.afficher();  // affiche : 30 -> 20 -> 10 -> NULL

    maListe.supprimerDebut();
    maListe.afficher();  // affiche : 20 -> 10 -> NULL

    maListe.supprimerDebut();
    maListe.supprimerDebut();
    maListe.supprimerDebut(); // essaie de supprimer quand c’est vide

    return 0;
}
