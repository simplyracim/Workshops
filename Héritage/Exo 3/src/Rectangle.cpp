#include "Rectangle.h"

Rectangle::Rectangle(double l, double lg) :
    longueur(l), largeur(lg) {}

double Rectangle::getLargeur() {
    return this->largeur;
};

double Rectangle::getLongueur() {
    return this->longueur;
};

// from Objet.h
double Rectangle::aire() {
    return longueur * largeur;
};

double Rectangle::perimetre() {
    return (2 * longueur) + (2 * largeur);
};

void Rectangle::afficherInfo() {
    std::cout << "\nLe rectangle de longueur " << longueur << " et de largeur " << largeur << ":\n"
        << "--> A une aire de " << aire() << "\n"
        << "--> A un perimetre de " << perimetre() << "\n";
};