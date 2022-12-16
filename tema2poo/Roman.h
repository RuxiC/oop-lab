#ifndef POO_ROMAN_H
#define POO_ROMAN_H
#include "carte.h"
class Roman : public Carte {
private:
    std::string c_autor;
    static int numRomane;
public:
    Roman(const std::string nume = "", const int an_aparitie = 0, const std::string autor = ""); // constructor parametrizat
    Roman(const Roman &roman);  // constructor de copiere
    virtual void tip_carte(void);
    void afiseaza(void);
    // supraincarcarea operatorilor
    friend std::istream& operator>>(std::istream &is, Roman& roman);
    friend std::ostream& operator<<(std::ostream &os, const Roman& roman);
    Roman& operator=(const Roman& roman);
    static int getSize(void);  // functie statica
    ~Roman(); // destructor
};
#endif
