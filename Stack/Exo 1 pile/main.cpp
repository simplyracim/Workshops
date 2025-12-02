#include <iostream>
#include <stack>

class ChangeBase {
private:
    std::stack<int> result;  // pile contenant les chiffres dans la nouvelle base

public:
    // Conversion d'un entier n en base b à l'aide d'une pile
    std::stack<int> toBase(int n, int b) {
        if (n <= 0 || b <= 1 || b > 10) {
            std::cout << "Valeurs invalides.\n";
            return result;
        }

        // Vide la pile précédente si re-utilisation
        result = std::stack<int>();

        // Algorithme de conversion classique : divisions successives
        while (n != 0) {
            int r = n % b;      // chiffre obtenu
            result.push(r);     // empile le chiffre
            n /= b;
        }

        return result;
    }

    // Affiche le contenu de la pile sous forme de nombre
    void print() {
        if (result.empty()) {
            std::cout << "Aucun resultat a afficher.\n";
            return;
        }

        std::cout << "Resultat : ";

        // On dépile pour obtenir les chiffres dans le bon ordre
        while (!result.empty()) {
            std::cout << result.top();
            result.pop();
        }

        std::cout << "\n";
    }
};

/*
Pourquoi utiliser une pile ?

Lors de la conversion en base b, on obtient d'abord le CHIFFRE DE POIDS FAIBLE
(n % b), puis celui d'après, etc.

Donc les chiffres arrivent dans l'ORDRE INVERSE de l'écriture finale.

Exemple : convertir 13 en base 2
13 % 2 = 1
 6 % 2 = 0
 3 % 2 = 1
 1 % 2 = 1

On a obtenu : 1,0,1,1 (du moins significatif au plus significatif)

Une pile (LIFO) permet :
- d'empiler les chiffres au fur et à mesure,
- puis de les dépiler pour les afficher dans le BON ORDRE.

Sans pile il faudrait inverser la liste, ce qui est moins naturel.
*/

int main() {
    ChangeBase cb;

    int n = 25;
    int b = 2;

    std::cout << "Conversion de " << n << " en base " << b << " :\n";

    cb.toBase(n, b);
    cb.print();

    std::cout << "\nAutre exemple :\n";
    cb.toBase(255, 8);
    cb.print();

    return 0;
}
