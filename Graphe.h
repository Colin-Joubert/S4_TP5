//
// Created by Colin on 30/03/2020.
//

#ifndef TP5_GRAPHE_H
#define TP5_GRAPHE_H

#include <iostream>
#include <string>
#include <vector>
#include "Sommet.h"

class Graphe {                          //repris en partie du TD2
private:
    bool m_estOriente;
    int m_nbConnexe;
    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;
    std::vector<int*> m_numeroConnexe;

public:
    Graphe(std::string cheminFichierGraphe);
    ~Graphe();
    void afficher() const;
    void kruskal();
    int getSize() const;
};
#endif //TP5_GRAPHE_H
