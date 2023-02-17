/* 
   In this game, the user explores different rooms with different taskts in them  
   */
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

// Functions
void room1();
void room2();
void room3();
void room4();
void room5();
void room6();

void Choose_move();
int Still_In(int, int);
void ranking();

// Structures
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


//Global variables
int opp_health; //opponents health
int damage;//How much health is removed from this attack
int battles = 0; // Battles won
int Win;
int health = 100; // Users health
int strength = 10;
int maze = 0;
int mover;
int attack;
int armor = 500;

int main(){
    //------------------- Introduction ----------------------------
    cout << "Welcome to the MAZE Game\n You will be challenged to walk through the maze\n You have three attacks; Jab, Kick and Slam\n\n";
    cout << "Your health is 100\n Prepare for your journey\n";
    //------------------- Battle --------------------------
    while(maze < 7){
        if(maze == 0){
            maze += 1;
            room1();
        }else if(maze == 1){
            maze += 1;
            room2();
        }else if(maze == 2){
            maze += 1;
            room3();
        }else if(maze == 3){
            maze += 1;
            room4();
        }else if(maze == 4){
            maze += 1;
            room5();
        }else if(maze == 5){
            maze += 1;
            room6();
        }else if(maze == 6){
            int choice;
            cout << "Would you like to play again? 1 for YES and 2 for NO: ";
            cin >> choice;
            if(choice == 1){
                maze = 0;
                cout << "Here we go!!";
            }else{
                cout << "Alright see you later!!";
            }
        }
    }
    return 0;
}




//----------------------- Print data mage function-----------------
void printdata(adventurer player){
    ranking();
    player.currentHealth = health;
    player.armorValue = armor;
    cout << "Name: " << player.name << endl;
	cout << "Health: " << player.currentHealth << endl;
	cout << "Armor: " << player.armorValue << endl;

}




//-----------------------Choose_Move Function----------------------
void choose_attack(){
    int attack = 0;
    cout << "Choose a move:\n 1 for Jab\n 2 for Kick\n 3 for Slam\n";
    cin >> attack;
    }

//-----------------------------Still_In Function ----------------------
int Still_In( int opp_health, int health){
    if(health < 0){
     cout << "You have been defeated\n";
     switch(maze){
         case 0:
             health = 50;
             break;
         case 1:
             health = 60;
             break;
         case 2:
             health = 80;
             break;
         case 3:
             health = 120;
             break;
         case 4:
             health = 150;
             break;
         case 5:
             health = 200;
             break;

                }
                cout << "You must battle again, your health has been replenished to " << health << endl;
                return 0;
    }
    if(opp_health < 0){
        cout << "You Have won\n";
            return 1;
    }
    return 0;
}

void ranking(){
    switch(maze){
    case 0:
        health = 50;
        strength = 10;
        break;
    case 1:
        health = 60;
        strength = 15;
        break;
    case 2:
        health = 80;
        strength = 25;
        break;
    case 3:
        health = 120;
        strength = 40;
        break;
    case 4:
        health = 150;
        strength = 50;
        break;
    case 5:
        health = 200;
        strength = 60;
        break;
    }
}

void room1(){// Weak legs
cout << endl;
      cout << "Your current health is " << health  << "/" <<  endl;



    Win = 0;
    opp_health = 50;
    cout << "You enter the maze! You see a trol in front of you! His legs are weak!\n";
    cout << "His Health is " << opp_health << endl;
    while(Win == 0){
            choose_attack();
            if(mover == 1){
                attack = strength * 1.5;
            } else{
                attack = strength;
            }
            opp_health -= attack;
            cout << "You attacked, Galph has " << opp_health << " remaining\n";
            health -= 10;
            cout << "Galph attacked, your health is " << health << endl;
            Win = Still_In(opp_health,health);
    }

}

void room2(){
    Win = 0;
    opp_health = 70;
    cout << "Mordecai is the second mage you will battle he is a steel mage\n";
    cout << "His Health is " << opp_health << endl;
    while(Win == 0){
        choose_attack();
        if(mover == 2){
            attack = strength * 1.5;
        } else{
            attack = strength * 0.5;
            cout << "This attack is not very effective\n";
        }
        opp_health -= attack;
        cout << "You attacked, Mordecai has " << opp_health << " remaining\n";
        health -= 15;
        cout << "Mordecai attacked, your health is " << health << endl;
        Win = Still_In(opp_health,health);
    }

}

void room3(){
    Win = 0;
    opp_health = 140;
    cout << "Rick is the third mage you will battle he is a tech mage\n";
    cout << "His Health is " << opp_health << endl;
    while(Win == 0){
        choose_attack();
        attack = strength;
        opp_health -= attack;
        cout << "You attacked, Rick has " << opp_health << " remaining\n";
        health -= 10;
        cout << "Rick attacked, your health is " << health << endl;
        Win = Still_In(opp_health,health);
    }
}

void room4(){
    Win = 0;
    opp_health = 200;
    cout << "King is the fourth mage you will battle he was the former Mage king\n";
    cout << "His Health is " << opp_health << endl;
    while(Win == 0){
        choose_attack();
        if(mover == 3){
            attack = strength * 2.0;
        } else{
            attack = strength ;
        }
        opp_health -= attack;
        cout << "You attacked, King has " << opp_health << " remaining\n";
        health -= 40;
        cout << "King attacked, your health is " << health << endl;
        Win = Still_In(opp_health,health);
     }
}

void room5(){
    srand(time(NULL));
    Win = 0;
    opp_health = 200;
    cout << "Rain is the fifth mage you will battle, he is unpredictable so watch out\n";
    cout << "His Health is " << opp_health << endl;
    while(Win == 0){
        choose_attack();
        if(mover == 2){
            attack = strength * 2.0;
        } else{
            attack = strength ;
        }
        opp_health -= attack;
        cout << "You attacked, Rain has " << opp_health << " remaining\n";
        health -= rand()% 51 + 20;
        cout << "Rain attacked, your health is " << health << endl;
        Win = Still_In(opp_health,health);
    }
}

void room6(){
    srand(time(NULL));
    Win = 0;
    opp_health = 400;
    cout << "Rain is the last mage you will battle, he is practically unbeatable\n";
    cout << "His Health is " << opp_health << endl;
    while(Win == 0){
        choose_attack();
        if(mover == 3){
            attack = strength * 1.4;
        } else{
            attack = strength * 1.6;
        }
        opp_health -= attack;
        cout << "You attacked, Rain has " << opp_health << " remaining\n";
        health -= rand()% 51 + 20;
        cout << "Rain attacked, your health is " << health << endl;
        if(opp_health < 100 && health > 100 ){
            opp_health += 150;
            cout << "Rain used a heal spell, his health is now " << opp_health << endl;
        }
        if(health <= 0) {
            int choice = 0;
            cout << "Would you like to play again: 1 for yes and 0 for no\n";
            cin >> choice;
            if(choice = 1){
                Win = 0;
                int ranking(battles);
                opp_health =400;
                cout << "Alright Essketit (lets get it)!!!!!!!!!\n";
            }
        }
        Win = Still_In(opp_health,health);
    }
    cout << "Your are now the champion\n";
}




