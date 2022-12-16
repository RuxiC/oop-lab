#ifndef POO_OPTIONS_H
#define POO_OPTIONS_H
#include <vector>
#include "Carte.h"
#include "Roman.h"
#include "Carte_Povesti.h"
class Options{
public:
    enum Option
    {
        AFISEAZA_TOATE,
        ADAUGA_OBIECT,
        STERGE_DUPA_IDX,
        GET_NR_ROMANE,
        GET_NR_CARTI_POVESTI,
        MODIFICA_DUPA_IDX,
        CEl_MAI_VECHI_ROMAN,
        CEA_MAI_NOUA_CARTE_DE_POVESTI,
        EXIT_PROGRAM,
        NUM_OPTIONS
    };
    static void printMenu(void);
    static Options::Option readOption(void);
    static void afiseazaToate(std::vector<Carte*>& vec_carti);
    static void adaugaObiect(std::vector<Carte*>& vec_carti);
    static void stergeDupaIdx(std::vector<Carte*>& vec_carti);
    static int getNrRomane(std::vector<Carte*>& vec_carti);
    static int getNrCartiPovesti(std::vector<Carte*>& vec_carti);
    static void modificaDupaIdx(std::vector<Carte*>& vec_carti);
    static void celMaiVechiRoman(std::vector<Carte*>& vec_carti);
    static void ceaMaiNouaCarteDePovesti(std::vector<Carte*>& vec_carti);
    static bool exitProgram(void);
};
#endif
