#include <iostream>
#include <vector>
#include <unordered_map>

class UniqueList {
private:
    std::vector<int> m_list;                // stockage des entiers
    std::unordered_map<int, bool> m_table;  // table de hachage

public:
    // Vérifie si une valeur est présente
    bool hasValue(int val) {
        return m_table.find(val) != m_table.end();
    }

    // Ajoute une valeur si elle n'existe pas déjà
    bool add(int val) {
        if (hasValue(val)) {
            std::cout << "Insertion de " << val << " refusee (doublon)\n";
            return false;
        }

        m_list.push_back(val);
        m_table[val] = true;
        std::cout << "Ajout de " << val << " reussi\n";
        return true;
    }

    // Supprime une valeur si elle est présente
    bool remove(int val) {
        if (!hasValue(val)) {
            std::cout << "Suppression de " << val << " impossible (absent)\n";
            return false;
        }

        // Retirer du vecteur : on cherche l'élément
        for (auto it = m_list.begin(); it != m_list.end(); ++it) {
            if (*it == val) {
                m_list.erase(it);
                break;
            }
        }

        // Retirer de la table de hachage
        m_table.erase(val);
        std::cout << "Suppression de " << val << " reussie\n";

        return true;
    }

    // Affiche le contenu
    void print() const {
        std::cout << "Contenu : [ ";
        for (int v : m_list) {
            std::cout << v << " ";
        }
        std::cout << "]\n";
    }
};

int main() {
    UniqueList ul;

    std::cout << "--- Tests d'ajout ---\n";
    ul.add(10);
    ul.add(20);
    ul.add(30);
    ul.add(20);  // doublon -> rejet
    ul.print();

    std::cout << "\n--- Tests de suppression ---\n";
    ul.remove(10);
    ul.remove(50); // absent -> rejet
    ul.print();

    std::cout << "\n--- Vérification présence ---\n";
    std::cout << "20 est present ? " << (ul.hasValue(20) ? "oui" : "non") << "\n";
    std::cout << "10 est present ? " << (ul.hasValue(10) ? "oui" : "non") << "\n";

    return 0;
}
