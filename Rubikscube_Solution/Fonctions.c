#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rubikscube_init_verif.h"
void test(face *pt_tab);

void Init_totale(void)
{
    printf("Code couleur :\n");
    printf("Blanc-rouge-bleu-vert-jaune-orange\n");
    printf("  1  -  2  -  3 - 4  -  5  -  6  \n\n");

    printf("Rentrez les cases de la face blanche\nen commencant par la case en haut a gauche\net en les rentrant de gauche a droite :\n\n");
    Initi_cases(&face_blanche);
    /*printf("\nLa face rouge :\n");
    Initi_cases(&face_rouge);
    printf("\nLa face bleue :\n");
    Initi_cases(&face_bleue);
    printf("\nLa face verte :\n");
    Initi_cases(&face_verte);
    printf("\nLa face jaune :\n");
    Initi_cases(&face_jaune);
    printf("\nLa face orange :\n");
    Initi_cases(&face_orange);

    test(&face_blanche);*/
    test(&face_rouge);
    test(&face_bleue);
    test(&face_verte);
    test(&face_jaune);
    test(&face_orange);

    Initialisation(&transit_blanche);
    Initialisation(&transit_rouge);
    Initialisation(&transit_bleue);
    Initialisation(&transit_verte);
    Initialisation(&transit_jaune);
    Initialisation(&transit_orange);
}

void test(face *pt_tab)
{
    char i=0,j=0;
    static unsigned char k = 1;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            (*pt_tab).cases[j][i] = k;
        }
    }

    k++;
}

void Initi_cases(face *pt_Tab)
{
    char i = 0, j = 0;
    unsigned short utilisateur = 0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            do
            {
                if((utilisateur>6)||(utilisateur<1))
                {
                    printf("\nRentrez un chiffre entre 1 et 6\n");
                }
                fflush(stdin);
                scanf("%hu", &utilisateur);
            }while((utilisateur>6)||(utilisateur<1));

            (*pt_Tab).cases[i][j] = utilisateur;

        }
    }
}

void Initialisation(face *pt_Tab)
{
    char i = 0, j = 0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            (*pt_Tab).cases[i][j] = 0;          /*i correspond aux lignes*/
        }
    }
}

char verif_coins(face *face)
{

     /*contient les compteurs des 6 couleurs*/

    static unsigned char compt_couleur[6]={0}, cpt_passage=0;
    unsigned char i,j,k;

    cpt_passage++;
    /*les coordonnées possible pour les 9 aretes*/
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            switch((*face).cases[i][j])
            {

                case 1:
                    compt_couleur[0]++;
                    break;
                case 2:
                    compt_couleur[1]++;
                    break;
                case 3:
                    compt_couleur[2]++;
                    break;
                case 4:
                    compt_couleur[3]++;
                    break;
                case 5:
                    compt_couleur[4]++;
                    break;
                case 6:
                    compt_couleur[5]++;
                    break;

                default : compt_couleur[0]=0;
            }
            j++;
        }
        i++;
    }
    /*comptage du nombre de couleurs total au bout du 6eme passage*/
    if(cpt_passage==6)
    {
        for(k=0;k<6;k++)
        {
            if(compt_couleur[k]!=4)
            {
                /*test resolution rubicube*/
                return 1;
            }
        }
    }

    return 0;
}

char verif_arete(face *face)
{
    static unsigned char compt_couleur[6]={0}, cpt_passage=0;
    unsigned char i, k;

    cpt_passage++;

    i = (*face).cases[0][1];

    compt_couleur[i-1]++;

    i = (*face).cases[1][0];

    compt_couleur[i-1]++;

    i = (*face).cases[1][2];

    compt_couleur[i-1]++;

    i = (*face).cases[2][1];

    compt_couleur[i-1]++;

    if(cpt_passage==6)
    {
        for(k=0;k<6;k++)
        {
            if(compt_couleur[k]!=4)
            {
                /*test resolution rubicube*/
                return 1;
            }
        }
    }

    return 0;
}

char verif_centre(face *face)
{
    static unsigned char compt_couleur[6]={0}, cpt_passage=0;
    unsigned char i, k;

    cpt_passage++;

    i = (*face).cases[1][1];

    compt_couleur[i-1]++;

    if(cpt_passage==6)
    {

        for(k=0;k<6;k++)
        {
            if(compt_couleur[k]!=1)
            {
                /*test resolution rubicube*/
                return 1;
            }
        }
    }

    return 0;
}

char verif_tot(void)
{
    unsigned char erreur = 0;

    erreur += verif_coins(&face_blanche);

    erreur += verif_coins(&face_rouge);

    erreur += verif_coins(&face_bleue);

    erreur += verif_coins(&face_verte);

    erreur += verif_coins(&face_jaune);

    erreur += verif_coins(&face_orange);



    erreur += verif_arete(&face_blanche);

    erreur += verif_arete(&face_rouge);

    erreur += verif_arete(&face_bleue);

    erreur += verif_arete(&face_verte);

    erreur += verif_arete(&face_jaune);

    erreur += verif_arete(&face_orange);



    erreur += verif_centre(&face_blanche);

    erreur += verif_centre(&face_rouge);

    erreur += verif_centre(&face_bleue);

    erreur += verif_centre(&face_verte);

    erreur += verif_centre(&face_jaune);

    erreur += verif_centre(&face_orange);




    if(erreur != 0)
    {
        printf("\nErreur d'initialisation! Cube impossible a resoudre!\n");
        return 1;
    }

    return 0;
}

