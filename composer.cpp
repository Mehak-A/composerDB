#include "composer.h"

Composer::Composer(): first_name_(""), last_name_(""), composer_yob_(0), composer_genre_(""), fact_(""), ranking_(10)
{
}

Composer::Composer(string firstname, string lastname, string genre, int yob, string fact)
{
	first_name_ = firstname;
	last_name_ = lastname;
	composer_genre_ = genre;
	composer_yob_ = yob;
	fact_ = fact;
	ranking_ = 10;
}

Composer::~Composer()
{
}

void Composer::set_first_name(string in_first_name)
{
	first_name_ = in_first_name;
}

string Composer::first_name()
{
	return first_name_;
}

void Composer::set_last_name(string in_last_name)
{
	last_name_ = in_last_name;
}

string Composer::last_name()
{
	return last_name_;
}

void Composer::set_composer_yob(int in_composer_yob)
{
	composer_yob_ = in_composer_yob;
}

int Composer::composer_yob()
{
	return composer_yob_;
}

void Composer::set_composer_genre(string in_composer_genre)
{
	composer_genre_ = in_composer_genre;
}

string Composer::composer_genre()
{
	return composer_genre_;
}

void Composer::set_ranking(int in_ranking)
{
	ranking_ = in_ranking;
}

int Composer::ranking()
{
	return ranking_;
}

void Composer::set_fact(string in_fact)
{
	fact_ = in_fact;
}

string Composer::fact()
{
	return fact_;
}

void Composer::Promote(int increment)
{
	ranking_ += increment;
}

void Composer::Demote(int decrement)
{
	ranking_-= decrement;
}

void Composer::Display()
{
	cout <<  "\n\n" << first_name_ << " " << last_name_ << " \n" << composer_yob_ << " " << composer_genre_ << " " << ranking_ << " \n" <<  fact_;
}
