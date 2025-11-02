#include <iostream>
#include <vector>
using namespace std;

class Pile {
private:
    vector<int> elements; // tableau dynamique pour stocker les entiers

public:
    // constructeur
    Pile() {
        // rien de spécial ici
    }

    // empiler un élément (push)
    void empiler(int valeur) {
        elements.push_back(valeur);
    }

    // dépiler un élément (pop)
    void depiler() {
        if (elements.empty()) {
            cout << "La pile est vide, rien à dépiler." << endl;
        } else {
            elements.pop_back();
        }
    }

    // afficher la pile
    void afficher() {
        cout << "Pile : ";
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Pile p1, p2;

    // on ajoute des éléments
    p1.empiler(10);
    p1.empiler(20);
    p1.empiler(30);

    p2.empiler(5);
    p2.empiler(15);

    cout << "Contenu de p1 : ";
    p1.afficher();

    cout << "Contenu de p2 : ";
    p2.afficher();

    // on teste le dépilement
    cout << "On dépile un élément de p1..." << endl;
    p1.depiler();
    p1.afficher();

    cout << "On dépile deux éléments de p2..." << endl;
    p2.depiler();
    p2.depiler();
    p2.afficher();

    // test pile vide
    p2.depiler();

    return 0;
}
