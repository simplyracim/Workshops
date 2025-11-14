#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Objet.h"

class Rectangle : public Objet {
    private :
        double longueur;
        double largeur;

    public :
        Rectangle(double l, double lg);

        double getLargeur();
        double getLongueur();

        double aire() override;
        double perimetre() override;
        void afficherInfo() override;
};

#endif // RECTANGLE_H