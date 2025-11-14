#include "GestionObjets.h"

// constructeur et destructeur
GestionObjets::GestionObjets(int c) : capacite(c), nbObjets(0) {
    objets = new Objet*[capacite];
    for (int i = 0; i < capacite; ++i) {
        objets[i] = nullptr;
    }
}

GestionObjets::~GestionObjets() {
    delete[] objets;
}

// operations
void GestionObjets::ajouterObjet(Objet* obj) {
    if (nbObjets >= capacite) {
        std::cout << "Tabeau plein.\n";
        return;
    }
    objets[nbObjets] = obj;
    nbObjets++;
}

void GestionObjets::ajouterObjet(Objet* obj, int index) {
    if (index < 0 || index >= capacite) {
        std::cout << "Index " << index << " invalide.\n";
        return;
    }
    objets[index] = obj;

    if (index >= nbObjets) {
        nbObjets = index + 1;
    }
}

void GestionObjets::afficherInfos() {
    std::cout << "=== Informations des objets ===\n";
    for (int i = 0; i < capacite; ++i) {
        if (objets[i] != nullptr) {
            std::cout << "[Index " << i << "] ";
            objets[i]->afficherInfo(); // little bit of polymorphisme pour la route
        }
    }
}
