#include <iostream>

using namespace std;
#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"
#include "./dealer.h"
#include "./game.h"

game::game(int num){
	num_players = num;

	players = new player[num];
	
}

game::~game(){
	delete [] players;
}


/*********************************************************************
 ** Function: deal_hand 
 ** Description: deals first hand to players and dealer
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions:prints starting hands 
 *********************************************************************/
void game::deal_hand(){
	for(int k=0; k<2; k++){ //iterates twice to deal two cards

		for(int i=0; i<num_players; i++){ //iterates through all players

			if(players[i].bet_amount() != 0){ //checks if player is playing this round
				players[i].p_get_card(cards.next_card()); //adds a card to the playerss hand
			}

			if(players[i].card_total_amount() != 0){ //only shows players who got dealt cards
				cout << " ○ Player " << i+1 << "'s hand total: "<< //prints hand total
				players[i].card_total_amount() <<  " ○" << endl;

				players[i].player_hand(); //prints hand
				cout << endl; //blank line for readability 

			}
		}		

		game_dealer.d_get_card(cards.next_card()); //adds a card to the dealers hand
		cout << " ○ Dealer's hand total: " << game_dealer.d_hand_value(1) 
		<< " ○"  << endl; //prints hand value
	
		game_dealer.show_hidden(1); //prints dealers hand
	}
}


/*********************************************************************
 ** Function: get_player_bets 
 ** Description: calls function to get bets for each player
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: player bets are set 
 *********************************************************************/
void game::get_player_bets(){
	cout << endl;
	for(int i=0; i< num_players; i++){ //iterates through all players
		cout << "Player " << (i+1) << " - Please enter bet amount: " ;
		players[i].set_bet(); //calls function to set bet for player i
	}	
}

/*********************************************************************
 ** Function: calculate_winnings
 ** Description: Calls function to calculate winnings for each player
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: player totals are updated 
 *********************************************************************/
void game::calculate_winnings(){
	cout << endl;
	cout << " ● Round Results ●" << endl;
	for(int i=0; i<num_players; i++){ //iterates through players
		cout << "Player " << i+1 << " " ;
		players[i].winnings(game_dealer.d_hand_value(0)); //calls function to calculate winnings/losings
	}

	cout << endl;
	cout << endl;
}


/*********************************************************************
 ** Function: hit_pass
 ** Description: asks if player wants to hit or pass
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions:players hand is printed to screen if they choose to hit 
 *********************************************************************/
void game::hit_pass(){
	bool again;
	bool hit;
	
	do{
		again = false;
		for(int i=0; i<num_players; i++){ //iterates through all players
			if(players[i].bet_amount() == 0){ //excludes players that are not playing
				cout << "Player " << i+1 << " is not currently playing" << endl;
			}
			else{ //asks player hit or pass
				cout << "Player " << i+1 << " (Hand total: " << 
				players[i].card_total_amount() << ") - Hit(1) or pass(0)? " ;			
				cin >> hit; 
				cout << endl;

				if(hit == true){ //gets player another card
					players[i].p_get_card(cards.next_card());
					cout << " ○ Player " << i+1 << "'s hand total: "<< 
					players[i].card_total_amount() <<  " ○" << endl;
					players[i].player_hand(); //prints hand
					again = true;
					cout << endl;
				}
			}
		}
	}while(again == true);
}


/*********************************************************************
 ** Function: discard_hands
 ** Description: resets dealer hand, and moves cards from hand to discard
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: cards are moved from hand to discard 
 *********************************************************************/
void game::discard_hands(){
	game_dealer.reset_d_hand(); //resets dealer hand
	cards.discard_card(); // moves cards from hand to discard pile
}


/*********************************************************************
 ** Function: round
 ** Description: plays through a round of blackjack
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: player total are changed 
 *********************************************************************/
void game::round(){
	get_player_bets(); //gets player bets	
	deal_hand(); //deals starting hand
	hit_pass(); //asks players if they want to hit or pass
	game_dealer.dealer_turn(&cards); //dealers turn
	calculate_winnings(); //calculates player winnings
	discard_hands(); //resets hand
}










/*********************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: 
 *********************************************************************/
