#include  <iostream>
#include "database.h";
using namespace std;

int main()
{
	Database* database = Database.getDatabase();
	cout << "Composer Database\n\n" <<

		"1) Add a new composer" <<
		"2) Retrieve a composer's data" <<
		"3) Promote / demote a composer's rank" <<
		"4) List all composers" <<
		"5) List all composers by rank" <<
		"0) Quit";
	int choice;
	do {
		cout << "enter your choice : ";
		cin >> choice;
		if(choice <0 || choice>5)
		{
			cout << "invalid choice"; continue;
		}
		switch (choice)
		{
		case 0: break;
		case 1:
			string firstn, lastn, genre;
			int yob, fact;
			cout << "enter first name : "; cin >> firstn;
			cout << "enter last name : "; cin >> lastn;
			cout << "enter genre : "; cin >> genre;
			cout << "enter yob: "; cin >> yob;
			cout << "enter some fact about the composer: "; cin >> fact;

			database->AddComposer(frstn, lastn,genre, yob, fact);
			break;

		case 2:
			cout << "enter last name of the composer: "; cin >> lastn;
			Composer cp = Database->GetComposer(lastn);
			cp.Display();
			break;

		case 3:
			int ans, amount ;
			cout << "promote / demote (p/d) : ";
			cin >> ans;
			cout << "by how much?  "; cin >> amount;
			cout << "enter last name of the composer : "; cin >> lastn;
			cp = Database->GetComposer(lastn);
			if (ans == 'p')
				cp.Promote(amount);
			if (ans == 'd')
				cp.Demote(amount);
			break;

		case 4:
			Database->DisplayAll();
			break;
		case 5:
			Database->DisplayByRank();
			break;
		}
	} while (choice != 0);

}
