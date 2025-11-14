#include "Carre.h"

Carre::Carre(double c) : cote(c) {}

double Carre::getCote() {
    return this->cote;
};

// from Objet.h
double Carre::aire() {

    return cote * cote;
};

double Carre::perimetre() {

    return cote * 4;
};
void Carre::afficherInfo() {
    std::cout << "\nLe carre de cote " << cote << ":\n"
        << "--> A une aire de " << aire() << "\n"
        << "--> A un perimetre de " << perimetre() << "\n";
};