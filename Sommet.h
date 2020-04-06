//
// Created by Colin on 30/03/2020.
//

#ifndef TP5_SOMMET_H
#define TP5_SOMMET_H

#include <iostream>
#include <vector>

class Arete;

class Sommet { //Repris du TD2
private:
    int m_numero;
    std::vector<const Sommet*> m_successeurs;
    std::vector<Arete*> m_aretes;

public:
    Sommet(int num);
    int getNumero() const;
    void addSuccesseur(const Sommet* succ, int poids, std::vector<Arete*>& vectAreteGen);
    const std::vector<const Sommet*>& getSuccesseurs() const;
    const std::vector<Arete*>& getArete() const;
    void afficher() const;
    int getNbSuccesseurs() const;
};

class Arete { //Repris du TD2
private:
    int m_poids;
    bool m_marque;
    std::vector<const Sommet*> m_extremites;

public:
    Arete(const Sommet* som1, const Sommet* som2, int poids);
    const std::vector<const Sommet*>& getSommets() const;
    const Sommet* getExtremites(int num) const;
    int getPoids() const;
    void afficher() const;

};

#endif //TP5_SOMMET_H
