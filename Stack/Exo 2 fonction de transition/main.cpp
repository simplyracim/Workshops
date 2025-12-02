#include <iostream>
#include <map>

// ---------------------------
// 1. Énumération des états
// ---------------------------
enum stateId {
    E1,
    E2,
    E3,
    E4,
    END  // correspond à ϵ (fin)
};

// ---------------------------
// 2. Classe abstraite AbstractState
// ---------------------------
class AbstractState {
public:
    virtual ~AbstractState() {}
    virtual void action() = 0;  // méthode obligatoire
};

// ---------------------------
// 3. États concrets
// ---------------------------
class State1 : public AbstractState {
public:
    void action() override {
        std::cout << "Action de l'état E1\n";
    }
};

class State2 : public AbstractState {
public:
    void action() override {
        std::cout << "Action de l'état E2\n";
    }
};

class State3 : public AbstractState {
public:
    void action() override {
        std::cout << "Action de l'état E3\n";
    }
};

class State4 : public AbstractState {
public:
    void action() override {
        std::cout << "Action de l'état E4\n";
    }
};

// ---------------------------
// 4. Classe Automata
// ---------------------------
class Automata {
private:
    std::map<stateId, stateId> delta;      // fonction de transition δ
    std::map<stateId, AbstractState*> states; 
    stateId current;                       // état actuel

public:
    Automata() : current(E1) {}            // point de départ

    // Initialisation de l’automate
    void initAutomata() {

        // Création des états
        states[E1] = new State1();
        states[E2] = new State2();
        states[E3] = new State3();
        states[E4] = new State4();

        // Fonction de transition δ:
        // E1 -> E2
        // E2 -> E3
        // E3 -> E4
        // E4 -> END
        delta[E1] = E2;
        delta[E2] = E3;
        delta[E3] = E4;
        delta[E4] = END;
    }

    // Exécute l’action de l’état courant
    void action() {
        if (current != END) {
            states[current]->action();
        }
    }

    // Transition vers l’état suivant
    void transition() {
        current = delta[current];  // passe à δ(current)
    }

    // Exécution complète de l’automate
    void run() {
        while (current != END) {
            action();
            transition();
        }
        std::cout << "Automate terminé (etat END)\n";
    }

    // Nettoyage mémoire
    ~Automata() {
        for (auto& p : states) {
            delete p.second;
        }
    }
};

// ---------------------------
// 5. Programme principal
// ---------------------------
int main() {
    Automata A;

    A.initAutomata();
    A.run();   // lance la machine

    return 0;
}
