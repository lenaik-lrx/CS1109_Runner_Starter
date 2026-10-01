#include <iostream>
#include <vector>
#include <string>

struct Position {
    int x;
    int y;
};

void afficherEtat(const Position& joueur,
                  const std::vector<Position>& obstacles,
                  int score) {

    std::cout << "Score : " << score << std::endl;
    std::cout << "Joueur : (" << joueur.x << ", " << joueur.y << ")" << std::endl;

    for (const auto& obs : obstacles) {
        std::cout << "Obstacle : (" << obs.x << ", " << obs.y << ")" << std::endl;
    }
}

void traiterCommande(const std::string& cmd, Position& joueur, int& score) {
    if (cmd == "avance") {
        joueur.x += 1;
        score += 1;
    }
}

bool verifierCollision(const Position& joueur,
                       const std::vector<Position>& obstacles) {

    for (const auto& obs : obstacles) {
        if (obs.x == joueur.x && obs.y == joueur.y) {
            return true;
        }
    }
    return false;
}

int main() {

    std::cout << "Runner CS.1109" << std::endl;
    std::cout << "1. Jouer" << std::endl;
    std::cout << "2. Quitter" << std::endl;

    int choix;
    std::cin >> choix;

    if (choix == 2) {
        return 0;
    }

    Position joueur{0, 0};

    std::vector<Position> obstacles = {
        {5, 0},
        {10, 0},
        {15, 0}
    };

    int score = 0;
    std::string commande = "";

    while (commande != "quitte") {

        afficherEtat(joueur, obstacles, score);

        std::cout << "Commande (avance / quitte) ? ";
        std::cin >> commande;

        traiterCommande(commande, joueur, score);

        if (verifierCollision(joueur, obstacles)) {
            std::cout << "Collision !" << std::endl;
            break;
        }
    }

    std::cout << "Score final : " << score << std::endl;
    std::cout << "Merci d'avoir jouer" << std::endl;

    return 0;
}

