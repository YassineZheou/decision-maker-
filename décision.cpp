#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Eleve {
public:
    string nom;
    double math, science, economie, lettres, informatique; 
    double moyenneGenerale;
    string filiere;

    Eleve(string n) : nom(n), math(0), science(0), economie(0), lettres(0), informatique(0), moyenneGenerale(0), filiere("") {}
    void saisirNotes() {
        cout << "Entrez les notes pour " << nom << " :\n";
        cout << "Mathématiques : ";
        cin >> math;
        cout << "Sciences naturelles : ";
        cin >> science;
        cout << "Economie : ";
        cin >> economie;
        cout << "Lettres : ";
        cin >> lettres;
        cout << "Informatique : ";
        cin >> informatique;

        
        double coefMath = 3, coefScience = 2, coefEconomie = 2, coefLettres = 2, coefInformatique = 3;
        moyenneGenerale = (math * coefMath + science * coefScience + economie * coefEconomie + lettres * coefLettres + informatique * coefInformatique) /
                          (coefMath + coefScience + coefEconomie + coefLettres + coefInformatique);
    }

    
    void choisirFiliere() {
        cout << "Choisissez la filière pour " << nom << " (Mathématiques, Lettres, Informatique) : ";
        cin >> filiere;
    }

    
    bool verifierAdmission() {
        if (moyenneGenerale < 10) {
            cout << "Échec : La moyenne générale est inférieure à 10.\n";
            return false;
        }

        if (filiere == "Mathématiques" && math < 10) {
            cout << "Échec : La note en Mathématiques est inférieure à 10.\n";
            return false;
        }

        if (filiere == "Lettres" && (lettres < 10)) {
            cout << "Échec : La note en Lettres est inférieure à 10.\n";
            return false;
        }

        if (filiere == "Informatique" && informatique < 10) {
            cout << "Échec : La note en Informatique est inférieure à 10.\n";
            return false;
        }

        return true;
    }

    
    void afficherDecision() {
        if (verifierAdmission()) {
            cout << "L'élève " << nom << " peut entrer en filière " << filiere << ".\n";
        } else {
            cout << "L'élève " << nom << " ne peut pas entrer en filière " << filiere << ".\n";
        }
    }
    void enregistrerFichier() {
        ofstream fichier(nom + "_bulletin.txt");
        fichier << "Nom: " << nom << "\n";
        fichier << "Moyenne générale: " << moyenneGenerale << "\n";
        fichier << "Filière choisie: " << filiere << "\n";
        fichier << "Mathématiques: " << math << "\n";
        fichier << "Sciences naturelles: " << science << "\n";
        fichier << "Economie: " << economie << "\n";
        fichier << "Lettres: " << lettres << "\n";
        fichier << "Informatique: " << informatique << "\n";
        fichier.close();
    }
};

int main() {
    string nom;
    cout << "Entrez le nom de l'élève : ";
    cin >> nom;

    Eleve e(nom);
    e.saisirNotes();
    e.choisirFiliere();
    e.afficherDecision();
    e.enregistrerFichier();

    return 0;
}

