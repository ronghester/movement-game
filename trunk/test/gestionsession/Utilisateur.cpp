#include <Utilisateur.h>

Utilisateur::Utilisateur(QString pseudo)
{
	// On initialise les attributs de l'utilisateur :
	this->pseudo = pseudo;	// Le pseudo est initialisé par le paramètre.
	this->difficulte = 1;	// La difficultée est initialisée par défaut à 1.
}

void Utilisateur::enregistrer_utilisateur(int place)
{
	// On créé le fichier de configuration qui aura pour nom le pseudo de l'utilisateur 
	QFile fichierConfiguration("Users/" + this->pseudo);
	fichierConfiguration.open(QIODevice::WriteOnly | QIODevice::Truncate);
	// On y enregistre sa configuration :
	QTextStream flux(&fichierConfiguration);
	flux << this->difficulte;	// La difficulté
	fichierConfiguration.close();
	// On enregistre le pseudo de l'utilisateur dans le fichier "session", à la place correspondante (passée en paramètre)
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

void Utilisateur::charger_utilisateur()
{
	// Ouverture du fichier grâce au pseudo
	QFile fichier("Users/" + pseudo);
   	if(fichier.open(QIODevice::ReadOnly))
   	{
   		// Lecture de la configuration :
   		this->difficulte = fichier.readLine().toInt();	// Son niveau de difficulté
   	}
   	else { std::cout << "Echec lors de l'ouverture du fichier de configuration\n"; }
}

QString Utilisateur::obtenir_pseudo()
{
	return pseudo;
}

int Utilisateur::obtenir_difficulte()
{
	return difficulte;
}
