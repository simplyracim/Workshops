#include <iostream>
#include <stack>
#include <vector>

class SortedList {
private:
    std::stack<int> sortedStack;   // pile triée (ordre croissant)

public:
    // Constructeur : on reçoit un vecteur non trié
    SortedList(const std::vector<int>& values) {
        // On clone les valeurs dans une pile de travail (origine)
        std::stack<int> origStack;
        for (int v : values) {
            origStack.push(v);
        }
        sort(origStack);
    }

    // Trie la pile origStack dans sortedStack
    void sort(std::stack<int>& origStack) {
        std::stack<int> tempStack;

        while (!origStack.empty()) {

            int in = origStack.top();  
            origStack.pop();

            // Déplacer les éléments plus grands que in
            while (!tempStack.empty() && tempStack.top() > in) {
                origStack.push(tempStack.top());
                tempStack.pop();
            }

            // Place in au bon endroit
            tempStack.push(in);
        }

        // tempStack est triée ; on la déverse dans sortedStack
        // pour que le plus petit soit tout en bas
        while (!tempStack.empty()) {
            sortedStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    // Affiche le contenu de la pile triée
    void print() {
        std::stack<int> copy = sortedStack;  // on protège la pile réelle !

        std::cout << "Liste triée : ";
        while (!copy.empty()) {
            std::cout << copy.top() << " ";
            copy.pop();
        }
        std::cout << "\n";
    }
};

/*
Comment l’encapsulation est-elle mise en exergue ?

La classe SortedList :
- cache complètement le fonctionnement interne (2 piles, algorithme de tri, détails techniques)
- n’expose qu’une interface simple : constructeur + print()
- le tri est fait automatiquement, sans que l’utilisateur voie les piles

Le principe d’encapsulation est respecté car l’utilisateur manipule
UN OBJET (SortedList), pas les détails internes.
*/

int main() {
    std::vector<int> values = {1, 11, 3, 7, 5};

    SortedList sl(values);

    sl.print();  // affiche : 1 3 5 7 11

    return 0;
}
