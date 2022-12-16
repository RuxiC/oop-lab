#include "Carti.h"
#include "Carte.h"
#include "Roman.h"
#include "Carte_Povesti.h"
#include <iostream>
Carte* Carti::citesteCarte(void)
{
    CartiEnum option = NONE;
    Carte *carte = nullptr;
    while(option != ROMAN && option != CARTE_POVESTI)
    {
        std::cout << "Optiunile sunt:\n";
        std::cout << "ROMAN - 0 \n";
        std::cout << "CARTE_POVESTI - 1 \n";
        std::cout << "Introduceti tipul de carte dorit: ";
        int tmpOption;
        std::cin >> tmpOption;
        if(tmpOption < 0 || tmpOption >= Carti::NUM_ELEMS)
        {
            std::cout << "Optiune gresita\n";
        }
        else
        {
            option = (CartiEnum) tmpOption;
        }
    }
    switch(option)
    {
        case Carti::ROMAN: {
            Roman *tmpRoman = new Roman();
            std::cin >> *tmpRoman;
            carte = (Carte*) tmpRoman;
            break;
        }
        case Carti::CARTE_POVESTI: {
            Carte_Povesti *tmpCarte_Povesti = new Carte_Povesti();
            std::cin >> *tmpCarte_Povesti;
            carte = (Carte*) tmpCarte_Povesti;
            break;
        }
        default:
        {
            break;
        }
    }
    return carte;
}