/****************************************************** 
 * ** Program: play_game.cpp
 * ** Author: Janessa Munt
 * ** Date: 04/16/2016
 * ** Description: Game of blackjack, takes input for number of players
 * ** Input: Number of players
 * ** Output: Blackjack game 
******************************************************/

#include <iostream>
#include <string>

using namespace std;
#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"
#include "./dealer.h"
#include "./game.h"

int main(){
	bool continue_game;
	int player_number;

	cout << endl;
	cout << endl;
	cout <<"Welcome to Blackjack, each player starts with $100" << endl;
	cout << endl;
	cout << "How many players? "; //prompt for number of players
	cin >> player_number;


	game my_game(player_number); //create game with specified number of players

	do{
		my_game.round(); //start round
		cout << "Continue(1) or quit game(0)? " ; //ask if use would like to continue
		cin >> continue_game;
	}while(continue_game == true); //starts another round if use wants to continue


	return 0;
}
