/*Edward Arvinius
*Section 1
*2/26/2018
*Assignment 7 */

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;


struct adventurer{
char name[10];	//character name
int maxHealth;	// Maximum health
int currentHealth; // current health
float armorValue;	// armor value

};

struct adventurer initializeAdventurer(struct adventurer player){

cout << "Enter username: " << endl;
cin.getline( player.name, 10);
player.maxHealth = 100;
player.currentHealth = 100;
player.armorValue = 500;
return player;
}

void print(struct adventurer player){
cout << "Your character's name is: " << player.name << endl;
cout << "Your maximum healh is: " << player.maxHealth << endl;
cout << "Your current health is: " << player.currentHealth << endl;
cout << "Your armor value is: " << player.armorValue << endl;
}


//---------- Function Prototypes -----------
void print_menu();
double get_value();
const double pi=3.1415;

double room1(double, double);
double room2(double, double);
double room3(double, double);
double room4(double, double);
double room5(double, double);
double room6(double, double);


//--------------  Main -------------------
int main(){

struct adventurer player1;
player1 = initializeAdventurer(player1);
print (player1);

double operand1, operand2, answer;
  int choice, valid_choice;
  int gold = 0;


  do{
    print_menu();
    cin >> choice;
    valid_choice = 1;           // assume choice is valid
    switch(choice){
    case 0:                    // program will exit
      break;
    case 1:                    // room 1
      cout << endl;
      cout << "Your current health is " << player1.currentHealth << "/" << player1.maxHealth << endl;
      cout << "Your current armor value is " << player1.armorValue << "/500 " << endl;
      cout << endl;

      cout << "This room is empty and there's nothing to do in here, go back to the corridor" << endl;
      cout << "Wait! There's gold on the floor, press (1) to pick it up" << endl;
      operand2 = get_value();
      cout << "There's more! Press (3) to pick it up! " << endl;
      operand1 = get_value();
      answer = room1(operand1, operand2);
      cout << "\n\n" << endl;
      cout << "Well done! You now have " << answer << "gold" << endl;
      gold = gold + 10;

      player1.currentHealth = player1.currentHealth - 10;
      cout << "You somehow took damage! Your current health is: " << player1.currentHealth << "/" << player1.maxHealth << endl;
      player1.armorValue = player1.armorValue - 30;
      cout << "Your armor is damaged! Your armor value is: " << player1.armorValue << "/500 " << endl;

      break;
    case 2:                    // room 2
      cout << endl;
      cout << "Your current health is " << player1.currentHealth << "/" << player1.maxHealth << endl;
      cout << "Your current armor value is " << player1.armorValue << "/500 " << endl;
      cout << endl;

      cout << "You are now in the 2nd room " << endl;
      cout << "Spiders are comming down the walls!! " << endl;
      cout << "Press (3) twice to fight them!" << endl;
      operand1 = get_value();
      cout << "You killed all the spiders but one, press (3) to eliminate the last one" << endl;
      operand2 = get_value();
      answer = room2(operand1, operand2);
      cout << "Good job, you killed " << answer << "amount of spiders" << endl;

      player1.currentHealth = player1.currentHealth - 10;
      cout << "You took damage to your health as well as armor! Your current health is: " << player1.currentHealth << "/" << player1.maxHealth << endl;
      player1.armorValue = player1.armorValue - 90;
      cout << "Your armor value is: " << player1.armorValue << "/500 " << endl;


       break;
    case 3:			// room 3
      cout << endl;
      cout << "Your current health is " << player1.currentHealth << "/" << player1.maxHealth << endl;
      cout << "Your current armor value is " << player1.armorValue << "/500 " << endl;
      cout << endl;

      cout << "You entered room number 3" << endl;
      cout << "You see a chest infront of you " << endl;
      cout << "Press (5) to collect the treasure " << endl;
      
      operand1 = get_value();
      cout << "Oh, that didn't work, try pressing (7) instead" << endl;
      operand2 = get_value();
      answer = room3(operand1, operand2);
      cout << "Wohoo, you foud " << answer << " gold! " << endl;
      gold = gold + 45;
      break;
    case 4:			// room 4
      cout << endl;
      cout << "Your current health is " << player1.currentHealth << "/" << player1.maxHealth << endl;
      cout << "Your current armor value is " << player1.armorValue << "/500 " << endl;
      cout << endl;
      cout << "Wlecome to room 4" << endl;
      cout << "You see two elexirs ifront of you" << endl;
      cout << "you need to poor 3 drops of the first elexir into the kettel" << endl;
      cout << "and 5 drops of the second elexir" << endl;
      cout << endl;
      cout << "Now poor the first elexir (3)" << endl;
      operand1 = get_value();
      cout << "Now poor the second elexir (5)" << endl;
      operand2 = get_value();
      answer = room4(operand1, operand2);
      cout << "Good job! You may now exit the room." << endl;
      break;
    case 5:			// room 5
      cout << endl;

      cout << "Your current health is " << player1.currentHealth << "/" << player1.maxHealth << endl;
      cout << "Your current armor value is " << player1.armorValue << "/500 " << endl;
      cout << endl;

      cout << "Watch out! There are a troll and a goblin infront of you!! " << endl;
      cout << "Fun fact about trolls and goblins, they love gold! " << endl;
      cout << "Give the troll 5 gold. " << endl;
      operand1 = get_value();
      cout << "Now, give the goblin 5 gold." << endl;
      operand2 = get_value();
      answer = room5(operand1, operand2);
      cout << "You gave them a total of " << answer << "gold, good job!" << endl;
      gold = gold - 10;
    case 6:			// room 6
      cout << endl;
      cout << "Your current health is " << player1.currentHealth << "/" << player1.maxHealth << endl;
      cout << "Your current armor value is " << player1.armorValue << "/500 " << endl;
      cout << endl;
      
      cout << "You are now in room 6" << endl;
      cout << "You're standing infront of a mirror, it can tell you what your lucky number is!" << endl;
      cout << "Tell the mirror your first favourite number" << endl;
      operand1 = get_value();
      cout << "Now tell the mirror your second favourite number." << endl;
      operand2 = get_value();
      answer = room6(operand1, operand2);
      cout << "Your lucky number is: " << answer << endl;
      gold = gold - rand()%3;
      cout << "Watch out! Someone/something stole gold from you! " << endl;
    default:
      valid_choice = 0;   // choice is invalid
      cout << "Invalid Choice." << endl;
    }
    if(valid_choice){   // if choice is valid, print the answer
      cout << endl << "Good job, you now have " << gold << " gold ,go ahead and choose another room" << endl;
    }
  }while(choice != 0);    // if not 0, loop back to start
  return 0;
}

//----------------- get_value function ----------------
double get_value(){
  double temp_value;
  cin >> temp_value;
  return temp_value;
}
//-------------------- print_menu function -------------
void print_menu(){
  cout << endl;
  cout << "There are 6 rooms to explore" << endl;
  cout << "Please enter either the first room(1), second room (2), third room (3)," << endl;
  cout << "fourth room (4), fifth room (5), or sixth room (6)" << endl;
  cout << "Exit (0)" << endl;
  cout << "Enter your choice: ";
}


// ----- room 1 function----------
double room1(double goold, double gooldz){
  double room1 = goold + gooldz;
  return room1;
}


// --------- room 2 function ---------
double room2(double spider , double spiderz){
  double room2 = spider * spiderz;
  return room2;
}

// --------------- room 3 function -----------
double room3(double treasure, double treasurez){
  double room3 = treasure * treasurez;
  return room3;

}

//-------room 4 function-----
double room4(double mixe, double mixer){
  double room4 = mixe + mixer;
  return room4;
}
   
//------- room 5 function--------
double room5(double troll, double goblin){
  double room5 = troll + goblin;
  return room5;
}
//-----------room 6 function-------
double room6(double mult, double multi){
  double room6 = (mult*multi)*pi;
  return room6;
}

