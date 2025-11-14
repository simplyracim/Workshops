#ifndef GESTION_OBJETS_H
#define GESTION_OBJETS_H

#include "Objet.h"

class GestionObjets {
private:
    Objet** objets;   // tableau de pointeurs
    int capacite;
    int nbObjets;

public:
    GestionObjets(int capacite);
    ~GestionObjets();

    void ajouterObjet(Objet* obj);
    void ajouterObjet(Objet* obj, int index);
    void afficherInfos();
};

#endif // GESTION_OBJETS_H