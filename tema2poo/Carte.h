#ifndef POO_CARTE_H
#define POO_CARTE_H
#include <string>

class Carte{
protected:
    std::string c_nume;
    int c_an_aparitie;
    static int numCarte;
public:
    Carte(const std::string nume, const int an_aparitie); // constructor parametrizat
    Carte(const Carte &carte);   // constructor de copiere
    void afiseaza(void);
    static int getSize(void);
    int getAn_aparitie(void);
    void setAn_aparitie(const int an_aparitie);
    std::string getNume(void);
    void setNume(const std::string nume);
    virtual void tip_carte(void) = 0; // functie virtuala pura(face clasa abstracta)
    Carte& operator=(Carte const &carte);
    friend std::istream& operator>>(std::istream &is, Carte& carte);
    friend std::ostream& operator<<(std::ostream &os, const Carte& carte);
    ~Carte(); // destructor
};
#endif
