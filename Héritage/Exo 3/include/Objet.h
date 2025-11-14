#ifndef OBJET_H
#define OBJET_H

#include <iostream>

class Objet {
    public :
        virtual double aire() = 0;
        virtual double perimetre() = 0;
        virtual void afficherInfo() = 0;
};

#endif // OBJET_H