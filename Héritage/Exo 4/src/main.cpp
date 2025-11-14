#include <iostream>
#include "Carre.h"
#include "Rectangle.h"
#include "GestionObjets.h"

int main() {
    // création d'objets
    Carre c1(5.0);
    Carre c2(10.0);
    Rectangle r1(3.0, 4.0);
    Rectangle r2(2.5, 8.0);

    // tableau de capacité 5
    GestionObjets gestion(5);

    // ajout d'objets
    gestion.ajouterObjet(&c1);
    gestion.ajouterObjet(&r1);

    // ajout à un index spécifique
    gestion.ajouterObjet(&c2, 3);
    gestion.ajouterObjet(&r2, 4);

    gestion.afficherInfos();

    return 0;
}
