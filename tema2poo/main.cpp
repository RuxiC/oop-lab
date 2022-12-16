#include "Roman.h"
#include "Carte_Povesti.h"
#include "Carte.h"
#include "Carti.h"
#include "options.h"
#include <iostream>
#include <vector>

int main()
{
    // instantiere roman
    Roman roman = Roman("Ion", 1920, "Liviu Rebreanu");

    // instantiere carte de povesti
    Carte_Povesti carte_povesti = Carte_Povesti("Povesti", 2000, "Ion Creanga");

    // declarare vector de 2 pointeri catre carte
    Carte **carte = new Carte*[2];

    // upcasting - transform din ptr la ob din clasele derivate la ptr la obiect din clasa de baza
    carte[0] = &roman;
    carte[1] = &carte_povesti;
    // apelare functii virtuale prin pointeri catre clasa de baza
    for(int i = 0; i < 2; i++)
        carte[i]->tip_carte();

    // downcasting - transform din pointer la clasa de baza in ob de tip clasa derivata
    Roman roman_din_carte =  *((Roman*) carte[0]);
    Carte_Povesti carte_povesti_din_carte = *((Carte_Povesti*) carte[1]);
    roman_din_carte.tip_carte();
    carte_povesti_din_carte.tip_carte();

    // dynamic cast - iteram peste toate elementele din vector si incercam sa le convertim la tipurile din clasa de baza corespunzatoare
    for(int i = 0; i < 2; i++)
    {
        Roman *tmpRoman;
        Carte_Povesti *tmpCarte_Povesti;
        if((tmpRoman = dynamic_cast<Roman*>(carte[i])) != nullptr)
        {
            printf("carte[%d] este roman\n", i);
            tmpRoman->tip_carte();
        }
        else if((tmpCarte_Povesti = dynamic_cast<Carte_Povesti*>(carte[i])) != nullptr)
        {
            printf("carte[%d] este carte de povesti\n", i);
            tmpCarte_Povesti->tip_carte();
        }
    }
    Roman r1 = Roman(roman);
    r1.tip_carte();
    Carte_Povesti c1 = Carte_Povesti(carte_povesti);
    c1.tip_carte();
    Carte_Povesti c2 = carte_povesti;
    c2.tip_carte();
    Carte_Povesti c3(carte_povesti);
    c3.tip_carte();
    Roman roman2 = Roman("Enigma Otiliei", 1938, "George Calinescu");
    Carte_Povesti  carte_povesti2  = Carte_Povesti("Carte povesti", 2010, "Emil Garleanu");
    r1 = roman2;
    r1.afiseaza();
    c1 = carte_povesti2;
    c1.afiseaza();

    delete[] carte;
    printf("Pana acum avem %d carti dintre care %d romane si %d carti de povesti\n", Carte::getSize(), Roman::getSize(), Carte_Povesti::getSize());

    // STL citirea a n carti
    std::vector<Carte*> vec_carti;
    int nrCarti;
    std::cout << "citirea a n obiecte de tip carte diferite:\n";
    std::cout << "nrObiecte: ";
    std::cin >> nrCarti;
    for(int i = 0; i < nrCarti; i++)
    {
        Carte *carte = Carti::citesteCarte();
        vec_carti.push_back(carte);
    }

    std::cout << "afisarea celor " << nrCarti <<" obiecte de tip pointeri catre clasa de baza\n";
    Options::afiseazaToate(vec_carti);
    std::cout << "Meniu interactiv\n";

    bool ok = true;
    while(ok == true)
    {
        Options::printMenu();
        Options::Option option = Options::readOption();
        switch(option)
        {
            case Options::AFISEAZA_TOATE:{
                Options::afiseazaToate(vec_carti);
                break;
            }
            case Options::ADAUGA_OBIECT: {
                Options::adaugaObiect(vec_carti);
                break;
            }
            case Options::STERGE_DUPA_IDX: {
                Options::stergeDupaIdx(vec_carti);
                break;
            }
            case Options::GET_NR_ROMANE: {
                std::cout << "nr romane: " << Options::getNrRomane(vec_carti) << '\n';
                break;
            }
            case Options::GET_NR_CARTI_POVESTI: {
                std::cout << "nr carti de povesti: " << Options::getNrCartiPovesti(vec_carti) << '\n';
                break;
            }
            case Options::MODIFICA_DUPA_IDX: {
                Options::modificaDupaIdx(vec_carti);
                break;
            }
            case Options::CEl_MAI_VECHI_ROMAN: {
                Options::celMaiVechiRoman(vec_carti);
                break;
            }
            case Options::CEA_MAI_NOUA_CARTE_DE_POVESTI: {
                Options::ceaMaiNouaCarteDePovesti(vec_carti);
                break;
            }
            case Options::EXIT_PROGRAM: {
                ok = Options::exitProgram();
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}