#include <iostream>
#include <string>
using namespace std;

// ========= Classe Client =========
class Client {
public:
    int id;
    string nom;
    string prenom;

    // constructeur vide
    Client() : id(0), nom(""), prenom("") {}

    // constructeur avec valeurs
    Client(int i, const string& n, const string& p) : id(i), nom(n), prenom(p) {}

    // constructeur de copie (shallow est suffisant ici car pas d'allocation dynamique)
    Client(const Client& other) : id(other.id), nom(other.nom), prenom(other.prenom) {}

    // destructeur (rien de spécial à libérer)
    ~Client() {}

    void afficher() const {
        cout << "Client[" << id << "] " << prenom << " " << nom;
    }
};

// ========= Classe Compte =========
class Compte {
private:
    int numero;
    float solde;
    Client* client;                  // propriété détenue par Compte
    static int nbComptes;            // compteur global

public:
    // constructeur vide
    Compte() : numero(0), solde(0.0f), client(nullptr) {
        nbComptes++;
    }

    // constructeur avec paramètres (deep-copy du client fourni)
    Compte(int num, float s, const Client& c)
        : numero(num), solde(s), client(new Client(c)) {
        nbComptes++;
    }

    // constructeur de copie (deep copy pour éviter partage de pointeur)
    Compte(const Compte& other)
        : numero(other.numero), solde(other.solde),
          client(other.client ? new Client(*other.client) : nullptr) {
        nbComptes++;
    }

    // opérateur d'affectation (par sécurité, cohérent avec deep copy)
    Compte& operator=(const Compte& other) {
        if (this != &other) {
            numero = other.numero;
            solde = other.solde;
            // recréer un client indépendant
            delete client;
            client = other.client ? new Client(*other.client) : nullptr;
        }
        return *this;
    }

    // destructeur (libère le client possédé)
    ~Compte() {
        delete client;
        nbComptes--;
    }

    void afficher() const {
        cout << "Compte #" << numero << " | Solde: " << solde << " | ";
        if (client) client->afficher();
        else cout << "Client: (nullptr)";
        cout << endl;
    }

    static void afficherNbComptes() {
        cout << "Nombre total de comptes: " << nbComptes << endl;
    }

    // accesseurs simples pour tests
    int getNumero() const { return numero; }
    float getSolde() const { return solde; }
    void setSolde(float s) { solde = s; }
};

int Compte::nbComptes = 0;

// ========= Fonction utilitaire =========
// petite, simple -> inline OK (évite l'overhead d'appel)
inline float calculInteret(float solde, float taux) {
    return solde * (1.0f + taux);
}

// ========= main =========
int main() {
    // 1) créer des clients et des comptes
    Client c1(1, "Dupont", "Jean");
    Client c2(2, "El Amrani", "Maya");
    Client c3; // vide

    Compte::afficherNbComptes();
    Compte a;                      // vide
    Compte::afficherNbComptes();

    Compte b(1001, 1500.0f, c1);   // avec paramètres
    Compte::afficherNbComptes();

    Compte c(1002, 250.0f, c2);
    Compte::afficherNbComptes();

    // 2) copie de comptes (test constructeur de copie)
    Compte d = b;                  // copie profonde
    Compte e(c);                   // copie profonde
    Compte::afficherNbComptes();

    // 3) afficher infos
    cout << "\n--- Affichages ---\n";
    a.afficher();
    b.afficher();
    c.afficher();
    d.afficher();
    e.afficher();

    // 4) appliquer des intérêts
    cout << "\n--- Interets sur b et c ---\n";
    b.setSolde(calculInteret(b.getSolde(), 0.05f)); // +5%
    c.setSolde(calculInteret(c.getSolde(), 0.10f)); // +10%
    b.afficher();
    c.afficher();

    // 5) destruction de quelques comptes (scope + delete)
    cout << "\n--- Destructions manuelles ---\n";
    // ici a, b, c, d, e sont automatiques -> seront détruits en fin de scope
    // pour montrer delete, on en crée un dynamique
    Compte* p = new Compte(2000, 999.0f, c3);
    Compte::afficherNbComptes();
    p->afficher();
    delete p;                      // déclenche le destructeur
    Compte::afficherNbComptes();

    cout << "\n--- Fin du programme (destructeurs automatiques) ---\n";
    return 0;
}
