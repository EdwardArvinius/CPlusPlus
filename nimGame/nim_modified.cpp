/* The modified game of NIM
   Edward Arvinius
   Ass #3
   Section 01 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int print_rules(int,int);
int think_comp(int,int,int);

int main(){
    int PlayAgain = 0;
do{
     //---------------------- Variable Declarations-----------------------
    int num_objects = 25;
    int current_player = 1;
    int move;
    int max_move = 4;
    int min_move =1;
    int player_win = 0;
    int com_win = 0;
    //------------ Beginning of the game loop ---------------------------
    print_rules(min_move, max_move);


      do{
        //-------------------------- Commentary ---------------------------
        if(num_objects == 20)
			cout << "Still early on, anyone can win.\n\n";
		if(num_objects == 12)
			cout << "Not many objects left! The game could be over in a couple of moves. Let's see what you got!\n\n";
		if(num_objects == 18)
			cout << "Good move! Let's see how this goes.\n\n";
		if(num_objects == 17)
			cout << "Well played, this is getting interesting!\n\n";
		if(num_objects == 8)
			cout << "Its getting close! Not many moves left, let's see what happens.\n\n";
		if(num_objects == 5)
			cout << "Very few objects left! The game will probably be decided soon. Be smart!\n\n";
		if(num_objects == 4)
			cout << "The game can be ended by one move! Let's see it!\n\n";

        srand(time(NULL));

        if (current_player == 1){
          cout << "Player 1 enter your move ";
          cin >> move;
          while (move < min_move || move > max_move || move >num_objects){
            cout << "Illegal move. \nEnter a new move ("<< min_move << " - " << max_move <<"): ";
            cin >> move;
          }
        }else{
          do { // Make sure move is legal
            move = think_comp(num_objects, max_move, min_move); //random computer move
                if(num_objects == 1 && current_player == 0){
                    move = 1;
                }
          } while(move < min_move || move > max_move || move > num_objects);
            cout << "Computer removed " << move << endl;
        }
        num_objects = num_objects - move; //Implement the move
        if(num_objects > 0){
            for(int i = 0; i < num_objects; i++){
                 cout << "*";
            }
        }
        cout << endl;
        cout << num_objects << " objects remaining.\n";
        current_player = (current_player + 1) % 2; // switch players
      }while(num_objects > 0);
      //----------------- End of the game loop -----------------------------
      if(current_player == 1){
        player_win += 1;
      }else {
      com_win += 1;
      }
      cout << "The game has been won by Player "<< current_player << ", congratulations champion!!!\n";
      cout << "You have won " << player_win << " time/s and the computer has won " << com_win << "time/s\n";
      cout << "Do you wish to play again? (enter 1 for yes and 0 for no): ";
      cin >> PlayAgain;
  }while(PlayAgain == 1);
  cin.ignore();
  cout << "\nPress enter to quit.\n";
  cin.ignore();
  return 0;
}

//--------------------- print_rules function --------------------------
int print_rules(int min_move,int max_move){
  cout << endl;
  cout << "Welcome to the Game of NIM" << endl;
  cout << "This is a fairly simple game" << endl;
  cout << "There are 25 objects" << endl;
  cout << "Each player has the option to remove a certain number" << endl;
  cout << "Within the range of "<< min_move <<" and " << max_move << endl;
  cout << "The player forced to make the last move losses" << endl;
  cout << "The computer is Player 0 and you are Player 1"<< endl;
  cout << "Good luck and don't forget it's just a game" << endl;
  cout << endl;
}

// ---------------------- think_comp function -------------------------

int think_comp(int num_objects, int max_move, int min_move){
    int move = 0;
    if(num_objects == (min_move + min_move)){
      move = min_move;
      return move;}
    else if(num_objects - max_move < min_move){
        move = max_move - 1;
        return move;
    }else if(num_objects == (max_move + min_move) ){
        move = max_move;
        return move;
    }else if(num_objects == (max_move + 1)){
        move = max_move;
        return move;
    }else if(num_objects > min_move && num_objects < max_move ){
        move = (max_move - min_move) + 1;
        return move;
    }else {
        move = 1 + rand()% max_move;
        return move;
    }
}



