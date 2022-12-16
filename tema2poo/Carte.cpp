#include "Carte.h"
#include <iostream>
int Carte::numCarte = 0; // initializare varibile statice
// constructori
Carte::Carte(const std::string nume, const int an_aparitie)
{
    c_nume = nume;
    c_an_aparitie = an_aparitie;
    numCarte++;
}
Carte::Carte(const Carte &carte)
{
    c_nume = carte.c_nume;
    c_an_aparitie = carte.c_an_aparitie;
    numCarte++;
}

void Carte::afiseaza(void)
{
    std::cout << "Nume carte: " << c_nume << '\n';
    std::cout << "Anul_aparitiei: " << c_an_aparitie << '\n';
}

int Carte::getSize(void)
{
    return numCarte;
}

int Carte::getAn_aparitie(void)
{
    return c_an_aparitie;
}
void Carte::setAn_aparitie(const int an_aparitie)
{
    c_an_aparitie = an_aparitie;
}
std::string Carte::getNume(void)
{
    return c_nume;
}
void Carte::setNume(const std::string nume)
{
    c_nume = nume;
}
Carte& Carte::operator=(Carte const &carte)
{
    c_nume = carte.c_nume;
    c_an_aparitie = carte.c_an_aparitie;
    numCarte++;
    return *this;
}
std::istream& operator>>(std::istream &is, Carte &carte)
{
    std::cout << "Nume carte: ";
    is >> carte.c_nume;
    std::cout << "An aparitie: ";
    is >> carte.c_an_aparitie;
    return is;
}
std::ostream& operator<<(std::ostream &os, const Carte& carte)
{
    os << "Nume carte: " << carte.c_nume << std::endl;
    os << "An aparitie: " << carte.c_an_aparitie << std::endl;
    return os;
}
Carte::~Carte()
{
    numCarte--;
}