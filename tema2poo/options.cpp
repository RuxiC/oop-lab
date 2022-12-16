#include "options.h"
#include "Carti.h"
#include <iostream>
void Options::printMenu(void)
{
    printf("Optiunile sunt:\n"
           "1. Afiseaza toate elementele din vector\n"
           "2. Adauga obiecte in vector\n"
           "3. Sterge obiect din vector dupa index\n"
           "4. Cate romane sunt in vector\n"
           "5. Cate carti de povesti sunt in vector\n"
           "6. Modifica un element din vector dupa index\n"
           "7. Cel mai vechi roman\n"
           "8. Cea mai noua carte de povesti\n"
           "9. Exit din program\n");
}
Options::Option Options::readOption(void)
{
    int option = -1;
    while(option < 1 || option > Options::NUM_OPTIONS)
    {
        printf("Optiunea aleasa este: ");
        std::cin >> option;
        if(option < 1 || option > Options::NUM_OPTIONS)
        {
            std::cout << "Optiune gresita\n";
            printMenu();
        }
    }
    return (Options::Option) (option-1);
}

void Options::adaugaObiect(std::vector<Carte*>& vec_carti)
{
    Carte *carte = Carti::citesteCarte();
    vec_carti.push_back(carte);
}
void Options::stergeDupaIdx(std::vector<Carte*>& vec_carti)
{
    std::cout << "Indexul pe care doriti sa il stergeti: ";
    int index;
    std::cin >> index;
    if(index > vec_carti.size()-1)
    {
        std::cout << "Indexul nu se afla in dimensiunea vectorlui: " << vec_carti.size() << "\n";
        return;
    }
    vec_carti.erase(vec_carti.begin() + index);
}
int Options::getNrRomane(std::vector<Carte*>& vec_carti)
{
    int nrRomane = 0;
    for(auto it = vec_carti.begin(); it != vec_carti.end(); it++)
    {
        if(dynamic_cast<Roman*>(*it) != nullptr)
            nrRomane++;
    }
    return nrRomane;
}
int Options::getNrCartiPovesti(std::vector<Carte*>& vec_carti)
{
    int nrCartiPovesti = 0;
    for(auto it = vec_carti.begin(); it != vec_carti.end(); it++)
    {
        if(dynamic_cast<Carte_Povesti*>(*it) != nullptr)
            nrCartiPovesti++;
    }
    return nrCartiPovesti;
}

void Options::afiseazaToate(std::vector<Carte*>& vec_carti)
{
    Roman *roman;
    Carte_Povesti *carte_povesti;
    for(auto it = vec_carti.begin(); it != vec_carti.end(); it++)
    {
        Carte *carte = *it;
        if((roman = dynamic_cast<Roman*>(carte)) != nullptr)
        {
            std::cout << *roman;
        }
        else if((carte_povesti = dynamic_cast<Carte_Povesti*>(carte))!= nullptr)
        {
            std::cout << *carte_povesti;
        }
    }
}

void Options::modificaDupaIdx(std::vector<Carte*>& vec_carti)
{
    std::cout << "Inca este neimplementat\n";
}
void Options::celMaiVechiRoman(std::vector<Carte*>& vec_carti)
{
    Roman *roman = nullptr;
    int an_aparitie = 0;
    for(auto it = vec_carti.begin(); it != vec_carti.end(); it++)
    {
        Roman *tmp;
        if((tmp = dynamic_cast<Roman*>(*it)) != nullptr)
        {
            if(tmp->getAn_aparitie() > an_aparitie)
            {
                an_aparitie = tmp->getAn_aparitie();
                roman = tmp;
            }
        }
    }
    if(roman == nullptr)
        std::cout << "Nu exista roman in vector\n";
    else{
        std::cout << "Romanul cel mai vechi este:\n";
        std::cout << *roman;
    }
}
void Options::ceaMaiNouaCarteDePovesti(std::vector<Carte*>& vec_carti)
{
    Carte_Povesti *carte_povesti = nullptr;
    int an_aparitie = 0;
    for(auto it = vec_carti.begin(); it != vec_carti.end(); it++)
    {
        Carte_Povesti *tmp;
        if((tmp = dynamic_cast<Carte_Povesti*>(*it)) != nullptr)
        {
            if(tmp->getAn_aparitie() < an_aparitie)
            {
                an_aparitie = tmp->getAn_aparitie();
                carte_povesti = tmp;
            }
        }
    }
    if(carte_povesti == nullptr)
        std::cout << "Nu exista carti de povesti in vector\n";
    else{
        std::cout << "Cartea de povesti cea mai noua este:\n";
        std::cout << *carte_povesti;
    }
}
bool Options::exitProgram(void)
{
    return false;
}
