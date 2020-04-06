//
// Created by Colin on 30/03/2020.
//

#include "Sommet.h"

//------------------------------Repris du TD2----------------------------------//
Sommet::Sommet(int num) : m_numero{num} {}

void Sommet::addSuccesseur(const Sommet *succ, int poids, std::vector<Arete*>& vectAreteGen) {
    m_successeurs.push_back(succ);
    std::vector<Arete*> vectArete = succ->getArete();
    bool enDouble = false;

    for(size_t i = 0; i < vectArete.size(); i++){
        if(vectArete[i]->getExtremites(succ->getNumero())->getNumero() == this->getNumero()){
            m_aretes.push_back(vectArete[i]);
            enDouble = true;
            i = vectArete.size();
        }
    }

    if(enDouble == false){
        Arete* tmp = new Arete(this, succ, poids);
        m_aretes.push_back(tmp);
        vectAreteGen.push_back(tmp);
    }
}

const std::vector<const Sommet*>& Sommet::getSuccesseurs() const {
    return m_successeurs;
}

int Sommet::getNumero() const {
    return m_numero;
}

void Sommet::afficher() const {
    std::cout << "  Sommet " << m_numero << " : ";
    for(auto addrSommet : m_successeurs) {
        std::cout << addrSommet->getNumero() << " ";
    }
}
//----------------------------------------------------------------------------//

const std::vector<Arete*>& Sommet::getArete() const {
    return m_aretes;
}

int Sommet::getNbSuccesseurs() const {
    return m_successeurs.size();
}

Arete::Arete(const Sommet* som1, const Sommet* som2, int poids) {
    m_extremites.push_back(som1);
    m_extremites.push_back(som2);
    m_marque = false;
    m_poids = poids;
}

const std::vector<const Sommet*>& Arete::getSommets() const {
    return m_extremites;
}

const Sommet* Arete::getExtremites(int num) const {
    if(num == m_extremites[0]->getNumero()){
        return m_extremites[1];
    } else{
        return m_extremites[0];
    }
}

void Arete::afficher() const {
    std::cout << "Arete : " << m_extremites[0]->getNumero() << "-" << m_extremites[1]->getNumero() << " / Poids : " << m_poids;
}

int Arete::getPoids() const {
    return m_poids;
}