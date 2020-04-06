#include <iostream>
#include "Graphe.h"

int main() {

    Graphe graphe{"../graphe-1.txt"};
    graphe.afficher();
    graphe.kruskal();

    return 0;
}
