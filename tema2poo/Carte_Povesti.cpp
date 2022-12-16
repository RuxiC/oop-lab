#include "Carte_Povesti.h"
#include <iostream>
int Carte_Povesti::numCarte_Povesti  = 0; // initializare varibile statice

// apeleaza constructorul din clasa de baza pentru campurile comune
Carte_Povesti::Carte_Povesti(const std::string nume, const int an_aparitie, const std::string autor) : Carte(nume, an_aparitie)
{
    c_autor = autor;
    numCarte_Povesti++;
}

// apeleaza constructorul din clasa de baza pentru campurile comune
Carte_Povesti::Carte_Povesti(const Carte_Povesti& carte_povesti) : Carte(carte_povesti)
{
    c_autor = carte_povesti.c_autor;
    numCarte_Povesti++;
}
void Carte_Povesti::tip_carte(void)   // functie virtuala pura implementata in clasa derivata
{
    std::cout << "Carte de povesti\n";
}
Carte_Povesti& Carte_Povesti::operator=(const Carte_Povesti& carte_povesti)
{
    // apelaza operator= din clasa de baza
    Carte::operator=(carte_povesti);
    // face acelasi lucru pentru campurile proprii
    c_autor = carte_povesti.c_autor;
    numCarte_Povesti++;
    return *this;
}
std::istream& operator>>(std::istream &is, Carte_Povesti& carte_povesti)
{
    std::cout << "Introduceti datele pentru cartea de povesti:\n";
    is >> static_cast<Carte&>(carte_povesti);
    std::cout << "Autor: ";
    is >> carte_povesti.c_autor;
    return is;
}
std::ostream& operator<<(std::ostream &os, const Carte_Povesti& carte_povesti)
{
    os << "---\nCarte Povesti\n";
    os << static_cast<const Carte&>(carte_povesti);
    os << "Autor: " << carte_povesti.c_autor << "\n";;
    return os;
}
void Carte_Povesti::afiseaza(void)
{
    std::cout << "Carte de povesti:\n";
    // apeleaza functia de afisare din clasa de baza
    Carte::afiseaza();
    // face acelasi lucru pentru campurile proprii
    std::cout << "Autor: " << c_autor << "\n";
}
int Carte_Povesti::getSize(void)
{
    return numCarte_Povesti;
}
Carte_Povesti::~Carte_Povesti()
{
    numCarte_Povesti--;
}