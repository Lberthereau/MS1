#pragma hdrstop
#pragma argsused
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <ctime>
#include <fstream>
#include "SNAfficheur.h"
#include "SNLigne.h"
#include "PortSerieAfficheur.h"


using namespace  std;

int SaisirBinaire()
{
	char bin[100];
	int nombre = 0;
	cin >> bin;
	cin.get();
	for (int i =0; i < strlen(bin); i++)
	{
		nombre = nombre*2+(bin[i]-'0');
	}
	return nombre;
}
string EntierVersChaineEnBinaire(int nombre)
{
   ostringstream oss;
   bool copie = false;
   for (int i=31; i >=0 ; i--)
   {
		if (((nombre >>i)&1) == 1)
		{
			copie = true;
		}
		if (copie == true)
		{
			oss<<((nombre>>i)&1);
		}
		}
		return oss.str();
   }


int _tmain(int argc, _TCHAR* argv[])
{
	int choix,  base, nb, nb1;
	float valeur1, valeur2, resultat;
	char operateur;
	char fonction [10], phrase[200];
	float k=1;
	ofstream fichier;

    char buffer[256];
	time_t timestamp = time(NULL);

	strftime(buffer, sizeof(buffer), "%A %d %B %Y - %X  ", localtime(&timestamp));
	printf("%s\n", buffer);

	sprintf(phrase, "%.3f %c %.3f = %.3f", valeur1, operateur, valeur2, resultat);
	cout << "Calcul (1) , Trigo (2) , Conversion(3): ";
	cin >> choix;
	cin.get();

	if (choix == 1)
	{
		cout << "Menu Calcul" << endl;

			cout << "saisir l'operation: ";
			cin >> valeur1 >> operateur >> valeur2;
			cin.get();

				if (operateur == '+')
		{
			resultat = valeur1 + valeur2;

		}
		else if (operateur == '-')
		{
			resultat = valeur1 - valeur2;
		}
		else if (operateur == '*')
		{
			resultat = valeur1 * valeur2;
		}
		else if (operateur == '/')
		{
			resultat = valeur1 / valeur2;
		}
		sprintf(phrase, "%.3f %c %.3f = %.3f", valeur1, operateur, valeur2, resultat);
		//cout << phrase;

	}
	else if (choix == 2)
	{
		cout << "Menu Trigo" << endl;
        cout << "Voulez-vous le resultat en degres (0) ou en radian (1)";
		cin >> choix;
		if (choix == 0)
		{
			k=3.14159265359/180;
		}
		cout << "saisir l'operation : ";
		cin >> fonction >> valeur1;
		cin.get();
		valeur1=valeur1*k;
		if (strcmp(fonction, "cos")==0) {
		   resultat = cos ( valeur1 );
		}
		else if (strcmp(fonction, "sin")==0)
		{
		 resultat = sin ( valeur1 );
		}
		else if (strcmp(fonction, "tan")==0)
		{
		 resultat = tan ( valeur1 );
		}

		sprintf(phrase, "%s %.3f = %.3f", fonction, valeur1, resultat);
	}

	else if (choix == 3)
	{
		cout << "Menu conversion" << endl;
		cout << "Choix de la base de saisie: Decimale (0), Hexa (1), Binaire (2) : " <<endl;
		cin >> choix;
		cin.get();
		if (choix==0) { //DECIMALE
			cout << " Saisir la base d'affichage: Hexa (1), Binaire (2) :  " <<endl;
			cin >> choix;
			cin.get();
			if (choix==1) {    // D to HEXA
			  cout << " Saisir nombre entier" <<endl;
			  cin >> nb;
			  cin.get();
			  nb1 = nb;
			  sprintf(phrase, "(%i)base 10 => (%x)base 16", nb1, nb);

			}
			else if (choix==2)       // D to BINAIRE
			{
			  cout << " Saisir nombre entier : " <<endl;
			  cin>>nb;
			  cin.get();
			  nb1 = nb;
			  EntierVersChaineEnBinaire(nb);

			  sprintf(phrase, "(%i)base 10 => (%s)base 2", nb1, EntierVersChaineEnBinaire(nb).c_str());
			}

		}
		else if (choix==1)  // HEXA
		{

			cout << " Saisir la base d'affichage: Decimal (0), Binaire (2) : "<<endl;
			cin >> choix;
			cin.get();
			if (choix==0)    // H to Decimale
			{
			 cout << " Saisir nombre entier" <<endl;
			 cin>>hex>>nb;
			 cin.get();
			 nb1 = nb;
			 sprintf(phrase, "(%x)base 16 => (%d)base 10", nb1, nb);
			}
			else if (choix==2)               // H to Binaire
			{
				cout << " Saisir nombre entier:" <<endl;
				cin>>hex>>nb;
				cin.get();
				nb1 = nb;
				EntierVersChaineEnBinaire(nb);


				sprintf(phrase, "(%x)base 16 => (%s)base 2", nb1, EntierVersChaineEnBinaire(nb).c_str());
			}
		}
		else if (choix==2)  //BINAIRE
		{
			cout<< " Saisir la base d'affichage: Decimal (0), Hexa (1) ";
			cin>>choix;
			cin.get();
			if (choix==0)   //B to DECIMALE
			{
			 cout<< " Saisir nombre en binaire: " <<endl;
			 nb=SaisirBinaire ();
			 EntierVersChaineEnBinaire(nb);
			 nb1 = nb;
			 //cout <<dec<<nb;

				sprintf(phrase, "(%s)base 2 => (%i)base 10", EntierVersChaineEnBinaire(nb1).c_str(), nb);
			}
			else if (choix==1)   // B to Hexa
			{
				cout<< " Saisir nombre en binaire: " <<endl;
			 nb=SaisirBinaire ();
			 EntierVersChaineEnBinaire(nb);
			 nb1 = nb;
			 //cout<<hex<<nb;
				sprintf(phrase, "(%s)base 2 => (%x)base 16", EntierVersChaineEnBinaire(nb1).c_str(),nb);
			}


		}
	}


	/*cout << "saisir l'operation :";
	cin >> valeur1 >> operateur >> valeur2;
	cin.get();

	cout << " saisir l'operateur: ";
	cin >> operateur;
	cin.get();

	cout << "saisir valeur 2: ";
	cin >> valeur2;
	cin.get();    */


   /*	if (operateur == '+')
	{
		resultat = valeur1 + valeur2;
	}
	else if (operateur == '-')
	{
		resultat = valeur1 - valeur2;
	}
	else if (operateur == '*')
	{
		resultat = valeur1 * valeur2;
	 }
	else if (operateur == '/')
	{
		resultat = valeur1 / valeur2;
	}
	cout <<  " = " << resultat; */

		cout << buffer << phrase <<endl;


	   //	cout<< "Le resultat est :  "<< phrase;

		fichier.open("calculatrice.log");
		fichier<<buffer<<phrase;
	   //	fichier<<phrase;
		fichier.close();
		SNAfficheur aff;
		aff.ModifierAdresseIPDuServeurUDP("172.20.182.57");
		aff.ModifierPortDuServeurUDP(4321);
		SNLigne lg;
		lg.ModifierMessage(phrase);
		aff.EnvoyerLigneEnUDP(lg);

	cin.get();
	return 0;

}


