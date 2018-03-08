#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "rubikscube_init_verif.h"

#define Blanc 1
#define Rouge 2
#define Bleu 3
#define Vert 4
#define Jaune 5
#define Orange 6

int main()
{
    Init_totale();

    if(verif_tot())
    {
        return 0;
    }

    return 0;
}
