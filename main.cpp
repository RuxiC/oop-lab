#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_LINE 256
using namespace std;

class Carte {
private:
    char *c_titlu;
    char *c_autor;
    char *c_editura;
    int c_an_aparitie;
public:
// constructor
    Carte(const char *titlu = NULL, const char *autor = NULL, const char *editura = NULL, const int an_aparitie = 0) {
        if (titlu != NULL)
            cout << "Constructor apelat pentru ", titlu;
        else
            cout << "Constructor apelat fara parametrii";
        if (titlu != NULL) {
            c_titlu = (char *) malloc((strlen(titlu) + 1) * sizeof(char));
            strcpy(c_titlu, titlu);
        } else
            c_titlu = NULL;
        if (autor != NULL) {
            c_autor = (char *) malloc((strlen(autor) + 1) * sizeof(char));
            strcpy(c_autor, autor);
        } else
            c_autor = NULL;
        if (editura != NULL) {
            c_editura = (char *) malloc((strlen(editura) + 1) * sizeof(char));
            strcpy(c_editura, editura);
        } else
            c_editura = NULL;
        c_an_aparitie = an_aparitie;
    }

// constructor de copiere
    Carte(const Carte &carte) {
        cout << "Constructor de copiere" << endl;
        if (carte.c_titlu != NULL) {
            c_titlu = (char *) malloc((strlen(carte.c_titlu) + 1) * sizeof(char));
            strcpy(c_titlu, carte.c_titlu);
        } else
            c_titlu = NULL;
        if (carte.c_autor != NULL) {
            c_autor = (char *) malloc((strlen(carte.c_autor) + 1) * sizeof(char));
            strcpy(c_autor, carte.c_autor);
        } else
            c_autor = NULL;
        if (carte.c_editura != NULL) {
            c_editura = (char *) malloc((strlen(carte.c_editura) + 1) * sizeof(char));
            strcpy(c_editura, carte.c_editura);
        } else
            c_editura = NULL;
        c_an_aparitie = carte.c_an_aparitie;
    }

// destructor
    ~Carte() {
        // aici eliberez ce am alocat dinamic
        cout << endl << "Destructor pentru cartea " << c_titlu << endl;
        free(c_titlu);
        free(c_autor);
        free(c_editura);
    }

    int getAnaparitie() const {
        return c_an_aparitie;
    }

// supraincarcarea operatorilor de citire ">>"
    friend istream &operator>>(istream &is, const Carte &carte);

// supraincarcarea operatorilor de afisare "<<"
    friend ostream &operator<<(ostream &os, const Carte &carte);

// operator de atribuire
    Carte &operator == (const Carte &carte) {
        cout << "Apel operator atribuire" << endl;
        if (carte.c_titlu != NULL) {
            c_titlu = (char *) malloc((strlen(carte.c_titlu) + 1) * sizeof(char));
            strcpy(c_titlu, carte.c_titlu);
        } else
            c_titlu = NULL;
        if (carte.c_autor != NULL) {
            c_autor = (char *) malloc((strlen(carte.c_autor) + 1) * sizeof(char));
            strcpy(c_autor, carte.c_autor);
        } else
            c_autor = NULL;
        if (carte.c_editura != NULL) {
            c_editura = (char *) malloc((strlen(carte.c_editura) + 1) * sizeof(char));
            strcpy(c_editura, carte.c_editura);
        } else
            c_editura = NULL;
        c_an_aparitie = carte.c_an_aparitie;
        cout << "Final operator atribuire" << endl;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Carte &carte) {
        os << "Afisare carte:" << endl;
        os << "Titlu: " << carte.c_titlu << endl;
        os << "Autor: " << carte.c_autor << endl;
        os << "An aparitie: " << carte.c_an_aparitie << endl;
        return os;
    }

    friend istream &operator>>(istream &is, Carte &carte) {

        char line[MAX_LINE];
        carte.c_an_aparitie = 0;
        memset(line, 0, MAX_LINE * sizeof(char));
        cout << "Citire carte:" << endl;
        cin.get();
        cout << "Titlu: " << endl;
        cin.getline(line, sizeof(line));
        carte.c_titlu = (char *) malloc((strlen(line) + 1) * sizeof(char));
        strcpy(carte.c_titlu, line);

        cout << "Autor: ";
        cin.getline(line, sizeof(line));
        carte.c_autor = (char *) malloc((strlen(line) + 1) * sizeof(char));
        strcpy(carte.c_autor, line);

        cout << "Editura: ";
        cin.getline(line, sizeof(line));
        carte.c_editura = (char *) malloc((strlen(line) + 1) * sizeof(char));
        strcpy(carte.c_editura, line);

        cout << "An aparitie: ";
        is >> carte.c_an_aparitie;
        return is;
    }
};

void citire_biblioteca(Carte **carti, int *nr_carti)
{
    cout << "Citire carti: " << endl;
    nr_carti[0] ++;
    Carte *carti2 = *carti;
    carti2 = (Carte*) realloc(carti2, nr_carti[0] * sizeof(Carte));
    *carti = carti2;
    carti2[nr_carti[0]-1] = Carte();
    cin >> carti2[nr_carti[0]-1];
}

void afisare_biblioteca(Carte *carti, int nr_carti)
{
    cout << "Afisare biblioteca: " << endl;
    for(int i = 0; i < nr_carti; i++)
        cout << carti[i];
}

void stergere_carte(Carte **carti, int *nr_carti)
{
    if(nr_carti[0] == 0)
    {
        cout << "Nu avem ce sterge" << endl;
        return;
    }
    cout << "Stergere cartea dupa cod_carte: ";
    Carte *carti2 = *carti;
    for(int i = 0; i < nr_carti[0]; i++)
    {
        cout << "\ncod_carte: " << i << endl;
        cout << carti2[i];
    }
    int id;
    cout << "Introduceti cod_carte: ";
    cin >> id;
    if(id >= nr_carti[0])
    {
        cout << "Cod_carte invalid" << endl;
        return;
    }

    for(int i = id; i < nr_carti[0]-1; i++)
    {
        carti2[i] = carti2[i+1];
    }
    nr_carti[0]--;
    carti2 = (Carte*) realloc(carti2, nr_carti[0]*sizeof(Carte));
    *carti = carti2;
    cout << "Stergerea a avut loc cu succes" << endl;
}

int cmp_biblioteca(const void *a, const void *b)
{
    const Carte carte1 = *((const Carte*) a);
    const Carte carte2 = *((const Carte*) b);
    return carte1.getAnaparitie() > carte2.getAnaparitie();
}
void Biblioteca_sortare(Carte *carti, int nr_carti)
{
    cout << "Sortam cartile" << endl;
    qsort(carti, nr_carti, sizeof(Carte), cmp_biblioteca);
}

enum MenuOption{
    Citire_carte,
    Afisare_carte,
    Sortare_carti,
    Stergere_carte,
};

MenuOption Biblioteca_menuoption(void)
{
    cout << endl << "Selectati o optiune:" << endl;
    cout << "1. Citire carte" << endl;
    cout << "2. Afisare carte" << endl;
    cout << "3. Sortare carti dupa anul aparitiei" << endl;
    cout << "4. Stergere carte" << endl;
    cout << endl << "Introduceti optiunea dorita: " << endl;
    char line[MAX_LINE];
    cin.getline(line, sizeof(line));
    int option;
    return (MenuOption) option;
}

int main() {
    int nr_carti;
    cout << "Introduceti numarul de carti: ";
    cin >> nr_carti;
    Carte *carti = (Carte *) malloc(nr_carti * sizeof(Carte));
    for (int i = 0; i < nr_carti; i++)
        cin >> carti[i];
    for (int i = 0; i < nr_carti; i++)
        cout << carti[i];

    bool ok = true;
    while (ok) {
        MenuOption option = Biblioteca_menuoption();
        switch (option) {
            case Citire_carte: {
                citire_biblioteca(&carti, &nr_carti);
                break;
            }
            case Afisare_carte: {
                afisare_biblioteca(carti, nr_carti);
                break;
            }
            case Sortare_carti: {
                Biblioteca_sortare(carti, nr_carti);
                break;
            }
            case Stergere_carte: {
                stergere_carte(&carti, &nr_carti);
                break;
            }
            default: {
                cout << "Nu se afiseaza";
                break;
            }
        }
    }
    free(carti);
    return 0;
}
