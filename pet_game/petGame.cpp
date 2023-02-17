// Edward Arvinius
// A simple text based game

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      string species;       // private data member
      int happy;            // private data member
      int sleepiness;	    // private data member
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void nap();	    // public member function
      void print();         // public member function
      int check_health();   // public member function
      void random_event();  // public member function
};



int main()
{
   pet pet1;
   int choice;
   int health_check;
   do{

       pet1.print();
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Nap (3) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
       case 3:
           pet1.nap();
           break;
      }
      pet1.random_event();	// random event function call
      health_check = pet1.check_health();
   }while(choice != 0 && health_check != 1);
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     sleepiness = 0;
     cout << "What is your pet's name? ";
     getline(cin, name); 		// cin >> name
     cout << "Pet's species? ";
     cin >> species;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
	 cout << "Woff woff! Your pet liked to play fetch! But it made it hungry and sleepy!" << endl;
         happy += 10;
         hunger += 5;
         sleepiness += 10;
         break;
    case(2):
	 cout << "Weeee! Your pet liked to roll over! But it made it hungry and sleepy!" << endl;
         happy += 5;
         hunger += 1;
         sleepiness += 10;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    int choice = 0;
    cout << "What would you like to feed your pet with?\n";
    cout << "Pet-candy (1) \n Regular Food (2) \n Your Old Pizza (3)\n";
    cin >> choice;
    switch (choice){
    case(1):
    	 cout << "MMm that was jummy!" << endl;
   	 happy += 20;
   	 hunger -= 1;
         sleepiness += 10;
   	 break;
    case(2):
	 cout << "That's some good stuff!" << endl;
         happy += 10;
         hunger -= 10;
         sleepiness += 10;
         break;
    case(3):
         cout << "Ughh, your pet did not like that!" << endl;
         happy -= 10;
         hunger += 10;
         sleepiness -= 10;
         break;
    default:
	 cout << "Not a valid choice." << endl;
    }
}

/* Member function nap(), allows the user to make the pet nap. */
void pet::nap(){
    int choice = 0;
    cout << "If you want your pet to nap, press (1)\n";
    cin >> choice;
    switch (choice){
    case(1):
    	 cout << "That was a nice nap!" << endl;
	 sleepiness -= 20;
         hunger += 20;
         break;
    default:
         cout << "Not a valid choice." << endl;
    }
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet's name is " << name << " ";
    cout << "\nYour pet's species is  " << species << endl;
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "Sleepiness: " << sleepiness << endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    if(sleepiness >= 50){
         cout << "\nYour pet has fallen asleep.\n";
    }
    return 0;
}

// random event function
void pet::random_event(){

	int secretNumber = 0;
	srand(unsigned(time(0)));
	secretNumber = rand()%10+1;

	switch(secretNumber){
		case 1:
			cout << "\nYour pet found a bone! It made it happy!" << endl;
			happy += 10;
			break;
		case 2:
			cout << "\nYour pet has chased its own tail for a while, it is getting tired and hungry!" << endl;
			sleepiness += 10;
			hunger += 10;
			break;
		case 3:
			cout << "\nYour pet escaped and almost got hit by a car, it got scared!" << endl;
			happy -= 10;
			break;
		case 4:
			cout << " " << endl; // Nothing happens if rand = 4
			break;
		case 5:
			cout << " " << endl; // Nothing happens if rand = 5
			break;
		case 6:
			cout << " " << endl; // Nothing happens if rand = 6
			break;
		case 7:
			cout << " " << endl; // Nothing happens if rand = 7
			break;
		case 8:
			cout << " " << endl; // Nothing happans if rand = 8
			break;
		case 9:
			cout << " " << endl; // Nothing happens if rand = 9
			break;
		case 10:
			cout << " " << endl; // Nothing happens if rand = 10
			break;


	}

}

