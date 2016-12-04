#ifndef PLAGEHORAIRE_H
#define PLAGEHORAIRE_H
#include <stdio.h>
#include <time.h>

class PlageHoraire {
protected:

    struct tm plage;

public:
    PlageHoraire(int annee, int mois, int jour, int heure, int min){
        plage.tm_year = annee;
        plage.tm_mon = mois;
        plage.tm_mday = jour;
        plage.tm_hour = heure;
        plage.tm_min = min;
    }
    int annee() {return plage.tm_year;}
    int mois() {return plage.tm_mon;}
    int jour() {return plage.tm_mday;}
    int heure() {return plage.tm_hour;}
    int min() {return plage.tm_min;}
};

#endif // PLAGEHORAIRE_H