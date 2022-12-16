#ifndef POO_CARTE_POVESTI_H
#define POO_CARTE_POVESTI_H
#include "Carte.h"
class Carte_Povesti : public Carte {
private:
    std::string c_autor;
    static int numCarte_Povesti;
public:
    Carte_Povesti(const std::string nume = "", const int an_aparitie = 0, const std::string autor = ""); // constructor parametrizat
    Carte_Povesti(const Carte_Povesti& carte_povesti);    // constructor de copiere
    virtual void tip_carte(void); // functie virtuala
    void afiseaza(void);
    static int getSize(void); // functie statica
    friend std::istream& operator>>(std::istream &is, Carte_Povesti& carte_povesti);
    friend std::ostream& operator<<(std::ostream &os, const Carte_Povesti& carte_povesti);
    Carte_Povesti& operator=(const Carte_Povesti& carte_povesti);
    ~Carte_Povesti(); // destructor
};
#endif
