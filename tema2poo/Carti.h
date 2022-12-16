#ifndef POO_CARTI_H
#define POO_CARTI_H
#include "Carte.h"
class Carti {
public:
    enum CartiEnum
    {
        ROMAN,
        CARTE_POVESTI,
        NUM_ELEMS,
        NONE
    };
    static Carte* citesteCarte(void);
};
#endif
