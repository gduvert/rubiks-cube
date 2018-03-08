#ifndef RUBIKSCUBE_SOLUTION_H_INCLUDED
#define RUBIKSCUBE_SOLUTION_H_INCLUDED

struct face
{
    char cases[3][3];
};

typedef struct face face;

face face_blanche, face_rouge, face_bleue, face_verte, face_jaune, face_orange;
face transit_blanche, transit_rouge, transit_bleue, transit_verte, transit_jaune, transit_orange;


void Initi_cases(face *pt_Tab);
void Initialisation(face *pt_Tab);
void Init_totale(void);
char verif_coins(face *face);
char verif_tot(void);
char verif_centre(face *face);
char verif_arete(face *face);


#endif

