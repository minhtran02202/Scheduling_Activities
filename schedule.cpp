//Minh Tran
//7/16/2021
//Functions of the schedule class
//which has the commonlarity between
//the three activities
//Schedule class lets us add, remove, and display data
//with 3 constructors and a destructors

#include "schedule.h"

//Default constructor
schedule::schedule(): name(nullptr), add(nullptr), email(nullptr)
{
}

//Copy constructor
schedule::schedule(const schedule & src)
{
	//Copy data of another schedule class to the current one
	name = new char[strlen(src.name)+1];
	strcpy(name, src.name);

	add = new char[strlen(src.add)+1];
	strcpy(add, src.add);

	email = new char[strlen(src.email)+1];
	strcpy(email, src.email);
}	

//Destructor
schedule::~schedule()
{
	//Delete all data of the class
	if(name) delete[]name;
	if(add) delete[]add;
	if(email) delete[]email;
}

//Remove if name match
int schedule::remove_schedule(char * compare)
{
	//Delete all data if the name match with the argument
	if(strcmp(compare, name)==0){
		delete[]name;
		if(add) delete[]add;
		if(email) delete[]email;

		//Set all to null to avoid double free when reach the destructor
		name = email = add = nullptr;
		return 1;
	}
	return 0;
}

//Display all data
int schedule::display_schedule()
{
	//Display all data of class
	if(name){
		cout<<"Full name: "<<name<<endl
			<<"Address: "<<add<<endl
			<<"Email: "<<email<<endl;
			return 1;
	}
	return 0;
}

//Add data to class
int schedule::add_schedule()
{
	name = new char[WORD];
	add = new char[WORD];
	email = new char[WORD];

	//Ask user to enter in all data of class
	cout<<"Enter your full name: ";
	cin.get(name, WORD);
	cin.ignore(100, '\n');

	cout<<"Enter your address: ";
	cin.get(add, WORD);
	cin.ignore(100, '\n');

	cout<<"Enter your full email: ";
	cin.get(email, WORD);
	cin.ignore(100, '\n');

	return 1;
}

