#include <iostream>
#include <QFile>
#include <QTextStream>
#include <utilisateur.h>

utilisateur::utilisateur(QString pseudo)
{
   this->pseudo = pseudo;
   this->difficulte = 1;
}

void utilisateur::sauverUtilisateur(int place)
{
   QFile fichierConfig("Users/" + this->pseudo);
   fichierConfig.open(QIODevice::WriteOnly | QIODevice::Truncate);
   QTextStream flux(&fichierConfig);
   flux << this->difficulte;
   fichierConfig.close();
   
   QFile session("sessions");
   QString lecture;
   QString sautLigne;
   session.open(QIODevice::ReadWrite);
   for (int i=1;i<place;i++)
   {
      lecture = lecture + session.readLine();
   }
   sautLigne = session.readLine();
   lecture = lecture + this->pseudo + "\n";
   for (int j=0;j<4-place;j++)
   {
      lecture = lecture + session.readLine();
   }
   session.close();
   session.open(QIODevice::WriteOnly | QIODevice::Truncate);
   QTextStream fluxB(&session);
   fluxB << lecture;
   session.close();
   
}

void utilisateur::chargerUtilisateur()
{
	QFile fichier("Users/" + pseudo);
   	if(fichier.open(QIODevice::ReadOnly))
   	{
   		this->difficulte = fichier.readLine().toInt();
   	}
   	else { std::cout << "Echec lors de l'ouverture du fichier de configuration\n"; }
}

int utilisateur::getDifficulte()
{
	return difficulte;
}

QString utilisateur::getPseudo()
{
	return pseudo;
}

