#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>

class utilisateur
{

private:
    QString pseudo;
    int difficulte;

public:
    utilisateur(QString pseudo);
    void sauverUtilisateur(int place);
    void chargerUtilisateur();
    int getDifficulte();
    QString getPseudo();

    
};

#endif
