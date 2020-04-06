//
// Created by Colin on 30/03/2020.
//

#include "Graphe.h"
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>


//---------------------------------------Repris du TD2-------------------------------//
Graphe::Graphe(std::string cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if(!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    ifs >> m_estOriente;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'orientation du graphe.");
    }
    int ordre;
    ifs >> ordre;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de l'ordre du graphe.");
    }
    int taille;
    ifs >> taille;
    if(ifs.fail()) {
        throw std::runtime_error("Problème de lecture de la taille du graphe.");
    }
    for(int i=0; i<ordre; ++i) {
        m_sommets.push_back(new Sommet(i));
        m_numeroConnexe.push_back(new int(0));
    }
    int num1, num2, poids;
    for(int i=0; i<taille; ++i) {
        ifs >> num1 >> num2 >> poids;
        if(ifs.fail()) {
            throw std::runtime_error("Problème de lecture d'un.e arc/arête.");
        }
        m_sommets[num1]->addSuccesseur(m_sommets[num2-1], poids, m_aretes);
        if(!m_estOriente && num1 < num2) {
            m_sommets[num2-1]->addSuccesseur(m_sommets[num1-1], poids, m_aretes);
        }
    }
    m_nbConnexe = 0;
}

Graphe::~Graphe() {
    for(auto addrSommet : m_sommets) {
        delete addrSommet;
    }
   /* for(auto addrArete : m_aretes){
        delete addrArete;
    }*/
}

void  Graphe::afficher() const {
    std::cout << std::endl << "Graphe ";
    std::cout << (m_estOriente ? "orienté" : "non orienté") << std::endl;
    std::cout << "Ordre :" << m_sommets.size() << std::endl;
    std::cout << "Liste d'adjacences : " << std::endl;
    for(auto addrSommet : m_sommets){
        addrSommet->afficher();
        std::cout << std::endl;
    }
    std::cout << std::endl << "Liste des aretes: " << std::endl;
    for(auto addrArete : m_aretes){
        addrArete->afficher();
        std::cout << std::endl;
    }
}

int Graphe::getSize() const {
    return m_sommets.size();
}
//-----------------------------------------------------------------------------------//

bool triArete(Arete* i, Arete* j){
    if(i->getPoids() < j->getPoids()){
        return true;
    }
    else{
        return false;
    }
}

void Graphe::kruskal(){
    std::sort(m_aretes.begin(), m_aretes.end(), triArete);
    std::vector<int> compoConnexe;
    std::vector<Arete*> vectAretes;

    for(size_t i = 0; i < m_sommets.size(); i++){
        compoConnexe.push_back(i);
    }

    int i = 0;
    int poidsArbre = 0;
    std::cout << std::endl << "Lancement de l'algorithme de Kruskal" << std::endl;
    std::cout << "Liste des aretes de l'arbre couvrant : " << std::endl;

    while(vectAretes.size() < m_sommets.size()-1){
        std::vector<const Sommet*> sommet = m_aretes[i]->getSommets();
        if(compoConnexe[sommet[0]->getNumero()-1] != compoConnexe[sommet[1]->getNumero()-1]){
            int num = compoConnexe[sommet[1]->getNumero()-1];
            for(size_t j = 0; j < compoConnexe.size(); j++){
                if(compoConnexe[j] == num){
                    compoConnexe[j] = compoConnexe[sommet[0]->getNumero()-1];
                }
            }
            poidsArbre += m_aretes[i]->getPoids();
            vectAretes.push_back(m_aretes[i]);
            std::cout << "Arete : " << sommet[0]->getNumero() << "-" << sommet[1]->getNumero() << " / Poids :" << m_aretes[i]->getPoids() << std::endl;
        }
        i++;
    }
    std::cout << std::endl << "Poids total de l'arbre : " << poidsArbre << std::endl;
}