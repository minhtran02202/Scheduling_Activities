//Minh Tran
//7/16/2021
//Functions of the pool and circular linked list
//The circular linked list manage the movie data
//

#include "schedule.h" 

//Pool Constructor and Destructor
pool::pool(): equipment(0), next(nullptr)
{
}

pool::pool(const pool & src): schedule(src){
	equipment = src.equipment;

	//May come back
	next = src.next;
}

//Add pool object
int pool::add_pool()
{
	//add schedule part
	add_schedule();

	//finaly add number of equipment
	cout<<"Enter the number of equipment (floaties, glasses, bags...)"
		<<" that you will bring to the pool: "<<endl;
	cin>>equipment;
	cin.ignore(100, '\n');
	return 1;
}

//Remove pool object
int pool::remove_pool(char * compare)
{
	//Remove if the user name match
	if (remove_schedule(compare) == 1){
		equipment = 0;
		cout<<"Pool schedule removed."<<endl;
		return 1;
	}
	return 0;
}

//Display pool object
void pool::display_pool()
{
	if(display_schedule()==1)
	{
		cout<<"Number of equipment(s): "<<equipment<<endl;
		return;
	}
	cout<<"Pool schedule does not exist."<<endl;
	return;

}	

//Pool node setter and getter
pool *& pool::get_next(){
	return next;
}

void pool::set_next(pool * set){
	next = set;
}

//----------------------------

//CLL Constructor and Destructor
cll::cll(): rear(nullptr)
{
}

cll::cll(const cll & src)
{
	copy(src.rear, rear, src.rear);
}
int cll::copy(pool * src, pool *& rear, pool * store)
{
	if(!src){
		rear = nullptr;
		return 0;
	}
	if(src == store){
		rear = this->rear;
		return 1;
	}
	rear = new pool(*src);
	copy(src->get_next(), rear->get_next(), store);
	return 0;
}

cll::~cll()
{
	remove_all();
}

int cll::remove_all()
{
	//exit if list not exist
	if (!rear) return 0;

	//only when there are 2+ pool schedule
	while (rear->get_next() != rear){
		pool * temp = rear->get_next()->get_next();
		delete rear->get_next();
		rear->set_next(temp);
	}

	//if only 1 pool schedule
	if (rear->get_next() == rear){
		delete rear;
		rear = nullptr;
	}
	return 1;
}

//Insert a pool to the list
int cll::insert()
{
	//if list is empty
	if (!rear){
		rear = new pool;
		rear->add_pool();
		rear->set_next(rear);
	}
	
	//if list is not empty
	else{
		pool * temp = rear->get_next();
		rear->get_next() = new pool;
		rear = rear->get_next();
		rear->add_pool();
		rear->set_next(temp);
	}
	return 1;
}

//Remove the oldest pool schedule
void cll::remove()
{
	//exit if list is empty
	if(!rear) return;

	//if only one pool schedule in the list
	if (rear == rear->get_next()){
		delete rear;
		rear = nullptr;
		return;
	}

	//if 2+ pool schedules in the list
	else{
		pool * temp = rear->get_next()->get_next();
		delete rear->get_next();
		rear->set_next(temp);
	}

}

//Display all pool schedules
void cll:: display()
{
	//Display the rear first
	rear->display_pool();

	//Call function to display the rest
	display(rear->get_next());
}

void cll:: display(pool * rear)
{
	//Exit if we reach the original rear
	if(rear==this->rear)
		return;

	//Display the current pool schedule
	rear->display_pool();

	//Go to next pool schedule
	display(rear->get_next());
}


