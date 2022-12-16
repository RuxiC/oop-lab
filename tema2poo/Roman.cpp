#include "Roman.h"
#include <iostream>
int Roman::numRomane = 0;
Roman::Roman(const std::string nume, const int an_aparitie, const std::string autor) : Carte(nume, an_aparitie)
{
    c_autor = autor;
    numRomane++;
}
Roman::Roman(const Roman &roman) : Carte(roman)
{
    c_autor = roman.c_autor;
    numRomane++;
}
// destructor
Roman::~Roman()
{
    numRomane--;
}
Roman& Roman::operator=(const Roman& roman)
{
    // apelaza operator= din clasa de baza
    Carte::operator=(roman);
    // face acelasi lucru pentru campurile proprii
    c_autor = roman.c_autor;
    numRomane++;
    return *this;
}
std::istream& operator>>(std::istream &is, Roman& roman)
{
    // ne folosim de operator>> din clasa de baza
    is >> static_cast<Carte&>(roman);
    // afisam si ce avem noi
    std::cout << "Autor: ";
    is >> roman.c_autor;
    return is;
}
std::ostream& operator<<(std::ostream &os, const Roman& roman)
{
    os << "---\nRoman\n";
    // ne folosim de operator<< din clasa de baza
    os << static_cast<const Carte&>(roman);
    // afisam si ce avem noi
    os << "Autor: " << roman.c_autor << "\n";
    return os;
}
// functie virtuale pure implementate in clasa derivata
void Roman::tip_carte(void)
{
    std::cout << "Roman\n";
}

void Roman::afiseaza(void)
{
    std::cout << "Roman:\n";
    Carte::afiseaza();
    std::cout << "Autor: " << c_autor << '\n';
}

int Roman::getSize(void)
{
    return numRomane;
}