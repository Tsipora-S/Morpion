#include <stdio.h>
#include <stdlib.h>


/*
programme morpion
debut
    affichage de la grille
    tant que pas gagné et pas 9 coups joués
        saisie et affichage d'un coup
        contrôle si gagné
        changement de joueur
    fintantque
    affichage du résultat
fin
*/

void afficherGrille(char grille[3][3])
{
    printf("\t\t\t ----------- \n");
    for (int i=0; i<3; ++i)
    {
        printf("\t\t\t|");
        for (int j=0; j<3; ++j)
        {
            printf(" %c |", grille[i][j]);
        }
        printf("\n");
        printf("\t\t\t ----------- \n");
    }
}

bool testGagnant(char grille[3][3], char label)
{
    int count = 0;

    // test sur les lignes
    for (int i=0; i<3; ++i)
    {
        count = 0;
        for (int j=0; j<3; ++j)
        {
            if (grille[i][j] == label)
                count++;
        }
        if (count == 3)
            return true;
    }

    // test sur les colonnes
    for (int j=0; j<3; ++j)
    {
        count = 0;
        for (int i=0; i<3; ++i)
        {
            if (grille[i][j] == label)
                count++;
        }
        if (count == 3)
            return true;
    }

    // test sur les diagonales
    if (grille[0][0] == label && grille[1][1] == label && grille[2][2] == label)
        return true;
    if (grille[0][2] == label && grille[1][1] == label && grille[2][0] == label)
        return true;

    return false;
}

int main()
{
    char grille[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    int joueur = 1;
    int ligne = -1, colonne = -1;
    int nbcoups = 0;

    // affiche la grille vide
    afficherGrille(grille);

    while (nbcoups < 9)
    {
        // affiche la saisie
        printf("C'est au tour du joueur %d\n", joueur);
        do
        {
            printf("  - Ligne   : ");
            scanf("%d", &ligne);
        } while (ligne <= 0 || ligne > 3);
        do
        {
            printf("  - Colonne : ");
            scanf("%d", &colonne);
        } while (colonne <= 0 || colonne > 3);
        // repasse en indices c++
        ligne--;
        colonne--;

        // joue le coup
        if (grille[ligne][colonne] == ' ')
        {
            if (joueur == 1)
            {
                grille[ligne][colonne] = 'x';
            }
            else if (joueur == 2)
            {
                grille[ligne][colonne] = 'o';
            }
            nbcoups++;
        }
        else
        {
            system ("cls");
            printf("Case deja jouee");
            continue;
        }

        // affiche la grille
        afficherGrille(grille);

        // test si gagnant, sinon change le joueur
        // si je me trouve ici, c'est que le joueur a bien joue
        if (joueur == 1)
        {
            if (testGagnant(grille, 'x'))
            {
                printf("Bravo, le joueur 1 gagne la partie\n");
                break;
            }
            else
            {
                joueur = 2;
            }
        }
        else if (joueur == 2)
        {
            if (testGagnant(grille, 'o'))
            {
                printf("Bravo, le joueur 2 gagne la partie\n");
                break;
            }
            else
            {
                joueur = 1;
            }
        }
    }


    if (nbcoups==9)
    {
        printf("Match nul !\n");
    }
}
