//Minh Tran
//7/16/2021
//Functions of the bolwing and vector data structure
//The vector data structure manages the movie data
//
#include "schedule.h" 

bowling::bowling(): shoe_size(0), ball_size(0){}

//Copy constructor
bowling::bowling(const bowling & src): schedule(src)
{
	shoe_size = src.shoe_size;
	ball_size = src.ball_size;
}


//Add schedule and other data
int bowling::add_bowling()
{
	//add schedule data first
	add_schedule();

	//add bowling data
	cout<<"Enter your shoe size: ";
	cin>>shoe_size; cin.ignore(100,'\n');	
	cout<<"Enter your ball weight: ";
	cin>>shoe_size; cin.ignore(100,'\n');	

	return 1;
}

//removie all data
int bowling::remove_bowling(char * compare)
{
	//Only run if schedule removed successfully
	if (remove_schedule(compare) == 1){
		shoe_size = 0;
		ball_size = 0;
		cout<<"Bowling schedule removed."<<endl;
		return 1;
	}

	return 0;
}

//Display all data
int bowling::display_bowling()
{
	//only run if scheduled displayed 
	if(display_schedule()==1)
	{
		cout<<"Your shoe size is: "<<shoe_size<<endl;
		cout<<"Your ball weight is: "<<shoe_size<<endl;
		return 1;
	}

	//Error message
	cout<<"Bowling schedule does not exist."<<endl;
	return 0;
}

//----------------------------------

//Add a bowling schedule to the vector
int vertex::insert()
{
	//Get info
	bowling temp;
	temp.add_bowling();

	//pass it into the vector
	v.push_back(temp);
	return 1;
}

//Remove the newest bowling schedule
int vertex::remove()
{
	//Remove the last schedule
	v.erase(v.end());
	return 1;
}

//Display all bowling in the vector
int vertex::display()
{
	//Loop to display bowling at each vector index
	for(int i=0; i<v.size(); ++i)
		v[i].display_bowling();
	return 1;
}

//Remove all bowling schedule
int vertex::remove_all()
{
	//Remove all
	v.clear();
	return 1;
}
