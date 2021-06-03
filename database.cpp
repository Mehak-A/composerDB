#include "database.h"
#include <iostream>
#include <algorithm>
using namespace std;

Database* Database::db = 0;

Database* Database::getDatabase()
{
		if (!db)
			db = new Database;
		return db;
}

Database::~Database()
{
	for (int i = 0; i < next_slot_; i++)
	{
		delete composers_[i];
	}
	delete db;
}

Composer& Database::AddComposer(string in_first_name, string in_last_name, string in_genre, int in_yob, string in_fact)
{
	// TODO: insert return statement here
	Composer* cp = new Composer(in_first_name, in_last_name, in_genre, in_yob, in_fact);
	composers_[next_slot_++] = cp;
	return *cp;
}

Composer& Database::GetComposer(string in_last_name)
{
	// TODO: insert return statement here
	for (int i = 0; i < next_slot_; i++)
	{
		Composer* result = nullptr;
		if (composers_[i]->last_name() == in_last_name)
		{
			result = composers_[i];
			return *result;
		}
		return *result;		
	}
}

void Database::DisplayAll()
{
	for (int i = 0; i < next_slot_; i++)
	{
		composers_[i]->Display();
	}
}

void Database::DisplayByRank()
{
	int ranks_arr[kMaxComposers];
	for (int i = 0; i < next_slot_; i++)
	{
		ranks_arr[i] = composers_[i]->ranking();
	}
	sort(ranks_arr, ranks_arr + next_slot_);
	for (int i = 0; i < next_slot_; i++)
	{
		for (int j = 0; j < next_slot_; j++)
		{
			if (composers_[i]->ranking() == ranks_arr[i])
				composers_[i]->Display();
		}
	}

}
