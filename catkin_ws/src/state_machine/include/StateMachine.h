#ifndef STATEMACHINE_H_INCLUDED
#define STATEMACHINE_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>

class State{
private:
    std::vector<std::string> names; //le vecteur stockant le nom des transitions
    std::vector<bool> conditions; //vecteur de bool�eens pour passerd'un �tat � un autre
    std::vector<State*> followState; //les liaisons avec les autres �tats
    int l; //longueur des vecteurs
    State(const State &); //verrouillage du constructeur de recopie
    State & operator = (const State &); //verrouillage de l'op�rateur d'affectation
public:
    State(void(*ptfoncaddress)(State*)); //Constructeur.il prend en argument l'adresse d'une fonction d�finie par l'utilisateur
    ~State(void); //Destructeur
    void(*ptfonc)(State*); //Un pointeur sur une fonction d�finie ult�rieurement par l'utilisateur
    void addTransition(std::string name,State* pt); //m�thode de construction des liaisons
    void setTransition(std::string name,bool b); //m�thode pour activer une transition (mettre � "true" le bool�en)

friend class SM;

};

class SM{
private:
    State* CurrentStatePointer; //Un pointeur sur l'�tat courant
    SM(const SM &); //verrouillage du constructeur de recopie
    SM & operator = (const SM &); //verrouillage de l'op�rateur d'affectation

public:
    SM(State* init); //Constructeur initialisant la SM sur un �tat donn�
    ~SM(void); //Destructeur
    void run(); //Il suffit d'appeler cette fonction apr�s construction de la SM, dans une boucle, et tout fonctionne tout seul !

};

#endif // STATEMACHINE_H_INCLUDED
