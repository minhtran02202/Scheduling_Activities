//Minh Tran
//7/16/2021
//Functions of the movie and array linked list
//The array linked list manage the movie data
//
#include "schedule.h" 

//Movie default constructor
movie::movie(): movie_name(nullptr), next(nullptr){}

//Copy constructor
movie::movie(const movie & src): schedule(src)
{
	movie_name = new char[strlen(src.movie_name)+1];
	strcpy(movie_name, src.movie_name);

	next = src.next;
}

//Destructor
movie::~movie()
{
	if(movie_name) delete[]movie_name;
}

//Add a movie schedule
char movie::add_movie()
{
	//add schedule first
	add_schedule();

	//then add movie name	
	char temp[WORD];
	cout<<"Enter the name of the movie: ";
	cin.get(temp, WORD);
	cin.ignore(100, '\n');

	movie_name = new char[strlen(temp)+1];
	strcpy(movie_name, temp);
	return temp[0];
}


//Removie a movie schedule
int movie::remove_movie(char * compare)
{
	//Only remove if movie name and compare name matched
	if(strcmp(movie_name, compare)==0){
		delete[]movie_name;
		if(name) delete[]name;
		if(add) delete[]add;
		if(email) delete[]email;
		movie_name = name = add = email = nullptr;
		cout<<"Movie schedule removed."<<endl;
		return 1;
	}
	return 0;

}

//Display movie schedule
int movie::display_movie()
{
	if(!movie_name){
		cout<<"Movie schedule does not exist."<<endl;
		return 0;
	}

	display_schedule();
	cout<<"Movie name is: "<<movie_name<<endl;
	return 1;
}

//movie node getter and setter
movie *& movie::get_next()
{
	return next;
}

void movie::set_next(movie * set)
{
	next = set;
}

//---------------------------

//Array of lll(ALL) Constructor
array_lll::array_lll()
{
	//head point to movie array of size 26
	head = new movie * [26];
	for(int i=0; i<26; ++i){
		head[i] = nullptr;
	}

}

array_lll::~array_lll()
{
	remove_all();
}

int array_lll::remove_all()
{
	//exit if ALL is empty
	if(!head) return 0;

	//remove lll at each array index
	for(int i=0; i<26; ++i){
		if(head[i]) remove_lll(head[i]);
	}
	delete[]head;
	return 1;
}

//Remove lll
int array_lll::remove_lll(movie *& head)
{
	//exit if lll is empty
	if(!head) return 0;

	//recursively remove all nodes
	remove_lll(head->get_next());
	delete head;
	head = nullptr;

	return 1;
}

//Insert a movie schedule to ALL
int array_lll::insert()
{
	//Add movie schedule data to a temp movie object
	movie current;
	int key = current.add_movie() % 26;

	//If the array index doesn't have a lll
	if(!head[key]){
		//create new movie and copy the data over
		head[key] = new movie(current);
		head[key]->set_next(nullptr);
		return 1;
	}

	//if there is already a lll
	else{
		//Create a movie object the end of the list 
		//and copy the data over
		movie * temp = head[key];
		while(temp->get_next() != nullptr){
			temp = temp->get_next();
		}

		temp->set_next(new movie(current));
		temp = temp->get_next();
		temp->set_next(nullptr);

	}
	return 1;

	
}

//Remove a movie schedule
int array_lll::remove(char * compare)
{
	//locate where the removal would be in the array
	int key = compare[0] % 26;

	//If there is no lll 
	if(!head[key]){
		cout<<"Movie name doesn't exist."<<endl;
		return 0;
	}

	movie * temp = head[key];

	//if the first node matched
	if(head[key]->remove_movie(compare)==1){
		head[key] = temp->get_next();
		delete temp;
		return 1;
	}


	//If the first node doesn't match
	movie * current;

	//travel untill the end of the list or found a match
	while(temp->get_next() != nullptr && temp->remove_movie(compare)==0){
		current = temp;
		temp = temp->get_next();
	}

	//remove the movie schedule if we found a match
	if(temp->remove_movie(compare) == 1){
		current->set_next(temp->get_next());
		delete temp;
		temp = nullptr;
	}

	return 1;
}

//Display all data
int array_lll::display()
{
	//exit if array not exist
	if(!head) return 0;

	//display the lll at each array index
	for(int i=0; i<26; ++i)
		display(head[i]);
	return 1;
}

//Display lll
int array_lll::display(movie * head)
{
	//exit if lll not exist
	if(!head) return 0;

	//display movie schedule data
	head->display_movie();

	//go to next node
	display(head->get_next());
	return 1;
}

