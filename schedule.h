//Minh Tran
//7/16/2021
//Where all classes are defined
//Schedule class, the three activities, and the three
//data structures that manage each activity.

#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;
//Constant
const int WORD = 100;

//Base class
class schedule{
	public:
		//Default Constructor
		schedule();
		//Copy Constructor
		schedule(const schedule &);
		//Destructor
		~schedule();
		
		//Remove if name match;
		int remove_schedule(char * compare);
		//Display all data
		int display_schedule();
		//Add data to class
		int add_schedule();

	protected:
		//Personal Info
		char * name;
		char * add;
		char * email;
};

//Pool activity
class pool: public schedule{
	public:
		//Default Constructor	
		pool();
		//Copy Constructor
		pool(const pool &);
		
		//Add schedule and num of equipment
		int add_pool();
		//Remove schedule and equipment
		int remove_pool(char * compare);
		//Display all data
		void display_pool();

		//Getter and setter for next node
		pool *& get_next();
		void set_next(pool * set);

	protected:
		int equipment;
		pool * next;
};

//Pool manager 
class cll{
	public:
		//Default constructor and destructor
		cll();
		~cll();
		//Copy Constructor
		cll(const cll & src);
		//Copy cll
		int copy(pool * src, pool *& rear, pool * store);

		//Add pool node
		int insert();
		//Remove the oldest pool schedule
		void remove();
		//Display wrapper
		void display();
		//Delete the whole list
		int remove_all();
	private:
		//Display pool node
		void display(pool * rear);
		pool * rear;
};

//Movie activity
class movie: public schedule{
	public:
		//Default Constructor
		movie();
		//Copy Constructor
		movie(const movie &);
		//Destructor
		~movie();

		//add schedule and movie name
		char add_movie();
		//remove if movie name match
		int remove_movie(char * compare);
		//Display all data
		int display_movie();
		
		//Getter and setter
		movie *& get_next();
		void set_next(movie * set);

	protected:
		char * movie_name;
		movie * next;
};

//Movie manager (Array of linked list)
class array_lll{
	public:
		//Constructor and Destructor
		array_lll();
		//array_lll(const array_lll &);
		~array_lll();

		//Add a movie node
		int insert();
		//Display wrapper function
		int display();
		//Delete all movie nodes
		int remove_all();
		int remove(char * compare);
	private:
		//Display all movie nodes
		int display(movie * head);
		//Delete the linked list
		int remove_lll(movie *& head);
		movie ** head;
};

//Bowling Activity
class bowling: public schedule{
	public:
		//Default Constructor
		bowling();
		//Copy constructor
		bowling(const bowling &);

		//Add schedule and other data
		int add_bowling();
		//removie all data
		int remove_bowling(char * compare);
		//Display all data
		int display_bowling();

	protected:
		int shoe_size;
		int ball_size;
};

//Bowling manager with example functions
class vertex{
	public:
		//Add a bowling schedule to the vector
		int insert();
		//Remove the newest bowling schedule
		int remove();
		//Display all bowling in the vector
		int display();
		//Remove all bowling schedule
		int remove_all();
	private:
		//Vector data structure
		vector<bowling> v;
};

