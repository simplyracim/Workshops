#ifndef CARRE_H
#define CARRE_H

#include "Objet.h"

class Carre : public Objet {
    private :
        double cote;

    public :
        Carre(double c);
        double getCote();

        double aire() override;
        double perimetre() override;
        void afficherInfo() override;
};

#endif // CARRE_H