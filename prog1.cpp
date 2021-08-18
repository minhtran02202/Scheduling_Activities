//Minh Tran
//7/16/2021
//Where the main menu client program locate
//The menu is used to test the functions of the 3 activities 
#include "schedule.h" 

int main()
{
	int access, access2;
	char response, res;
	cll pool;
	array_lll movie;
	vertex bowling;	

	do{
		cout<<"Which schedule you want to add?. Pool (1),"
			<<" Movie (2), or Bowling (3): ";
		cin>>access; cin.ignore(100,'\n');

		//Pool option
		if(access == 1){

			//Insert many times
			do{
				pool.insert();
				cout<<"Do you want to add more?(Y/N): ";
				cin>>res; cin.ignore(100,'\n');
			} while (toupper(res) == 'Y');

			cout<<"Do you want to display the scheduels(1) or remove the oldest schedule(2)?: ";
			cin>>access2; cin.ignore(100,'\n');

			//Display all
			if(access2 == 1)
				pool.display();

			//Remove the oldest data
			else if(access2 == 2){
				pool.remove();
				cout<<"Here are the schedules after the removal"<<endl;
				pool.display();
			}
		}

		//Movie option
		if(access == 2){
			//Insert many times
			do{
				movie.insert();
				cout<<"Do you want to add more?(Y/N): ";
				cin>>res; cin.ignore(100,'\n');
			} while (toupper(res) == 'Y');

			cout<<"Do you want to display the scheduels(1) or remove a schedule(2)?: ";
			cin>>access2; cin.ignore(100,'\n');

			//Display all
			if(access2 == 1)
				movie.display();

			//Remove a schedule
			else if(access2 == 2){
				char temp[WORD];
				cout<<"Enter movie name to remove: ";
				cin.get(temp, WORD); cin.ignore(100,'\n');
				movie.remove(temp);
				cout<<"Here are the schedules after the removal"<<endl;
				movie.display();
			}
		}
		
		//Bowling option
		if(access == 3){

			//Insert many times
			do{
				bowling.insert();
				cout<<"Do you want to add more?(Y/N): ";
				cin>>res; cin.ignore(100,'\n');
			} while (toupper(res) == 'Y');

			cout<<"Do you want to display the scheduels(1) or remove the latest schedule(2)?: ";
			cin>>access2; cin.ignore(100,'\n');

			//Display all
			if(access2 == 1)
				bowling.display();

			//Remove the latest data
			else if(access2 == 2){
				bowling.remove();
				cout<<"Here are the schedules after the removal"<<endl;
				bowling.display();
			}
		}

		//Repeat program
		cout<<"Do you want to use the program again?(Y/N): ";
		cin>>response; cin.ignore(100,'\n');
	} while(toupper(response) == 'Y');

	//Ending message
	cout<<"Thank you for using the program. Have a great day!"<<endl;

	return 0;
}
