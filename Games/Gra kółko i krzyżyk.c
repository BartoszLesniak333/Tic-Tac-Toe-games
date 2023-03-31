#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>

int szachownica();
bool sprawdzanie(char);
int gra();
char tablica[3][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'}};

int main()
{
    printf("\n\n     Witamy w Grze Kolko i Krzyzyk\n\n\n");
    printf("     Gracz 1 --> X   Gracz 2 --> O\n\n\n");
    int ulozenie;
    ulozenie = szachownica();
    int granie;
    granie = gra();
    int koniec;

    return 0;

}


int szachownica()
{
    for(int i = 0;i<3;++i)
    {
        printf("   ---------------------------------\n");
        printf("   |          |          |         |\n");
        for(int j = 0; j<3; ++j)
        {
            printf("   | %5c ",tablica[i][j]);
        }
        printf("  | \n");
        printf("   |          |          |         |\n");
    }
    printf("   ---------------------------------\n");

}


bool sprawdzanie(char gracz)
{
    //wiersze
    for(int i = 0;i<3;++i) {
        if (tablica[i][0] == gracz and tablica[i][1] == gracz and tablica[i][2] == gracz) {
            return true;
        }
    }

    //kolumny
    for(int j = 0;j<3;++j)
    {
        if (tablica[0][j] == gracz and tablica[1][j] == gracz and tablica[2][j] == gracz) {
            return true;
        }
    }
    //przekatne
    if(tablica[0][0] == gracz and  tablica[1][1] == gracz and tablica[2][2] == gracz)
    {
        return true;
    }
    if(tablica[0][2] == gracz and  tablica[1][1] == gracz and tablica[2][0] == gracz)
    {
        return true;
    }
    return false;
}


int gra() {
    for (int x = 0; x < 5; ++x) {
        int Gracz_1;
        int Gracz_2;
        printf("Gracz pierwszy wybiera: ");
        scanf(" %d", &Gracz_1);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablica[i][j] == Gracz_1 + '0') {
                    tablica[i][j] = 'X';
                    szachownica();
                    if (sprawdzanie('X')) {
                        printf("Gracz pierwszy wygral\n");
                        return 0;
                    }

                }

            }

        }
        printf("Gracz drugi wybiera: ");
        scanf(" %d", &Gracz_2);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (tablica[i][j] == Gracz_2 + '0')
                {
                    tablica[i][j] = 'O';
                    szachownica();
                    if (sprawdzanie('O'))
                    {
                        printf("Gracz drugi wygral \n");
                        return 0;

                    }
                }


            }

        }
        printf("Remis");

    }
}





