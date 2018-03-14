#include <iostream>
using namespace std;
#include "./card.h"
#include "./deck.h"
#include "./hand.h"
#include "./player.h"


player::player(){
	
	playing_total = 100;
	card_total = 0;
	bet =0;
}

player::~player(){

}


/*********************************************************************
 ** Function: bet_amount
 ** Description: Returns bet amount
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: bet is returned 
 *********************************************************************/
int player::bet_amount() const{
	return bet; //returns bet amount
}


/*********************************************************************
 ** Function: update_card_total
 ** Description: updates the players card total
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: card_total is changed 
 *********************************************************************/
void player::update_card_total(){
	card_total = p_hand.hand_val(0); //calls function to get hand value and stores it

}


/*********************************************************************
 ** Function: card_total_amount
 ** Description: returns the amount of cards
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: card_total is returned 
 *********************************************************************/
int player::card_total_amount() const{
	return card_total; //returns card total
}


/*********************************************************************
 ** Function: player_hand
 ** Description: checks if user has blackjack or bust, and prints hand
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: player hand is printed and if user got blackjack or bust their money is updated 
 *********************************************************************/
void player::player_hand(){
	blackjack_bust(); // checks if blackjack or bust
	p_hand.ascii_hand();
}


/*********************************************************************
 ** Function: p_get_card
 ** Description: adds a card to p_hand
 ** Parameters: card
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions:p_hand gets another card 
 *********************************************************************/
void player::p_get_card(card newcard){
	p_hand.draw_card(newcard); //draws new card
	update_card_total(); // updates card total
}


/*********************************************************************
 ** Function: update_total
 ** Description: compares and player hand to dealer's and updates money accordingly
 ** Parameters:int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: Results of round are printed and playing_total is updated
 *********************************************************************/
void player::winnings(int dealer_total){
	if(card_total == 0){ //checks if player was in round 
		cout << "did not play this round." << endl;
		return;
	}

	if(card_total > 21) //checks if player busted
		cout << "was a bust! (╯°□°）╯︵ ┻━┻" ;

	else if(card_total == 21) //checks if player got blackjack
		cout << "blackjack! " ;
	
	else if(dealer_total > 21){ //checks if dealer busted
		cout << "wins! Dealer was a bust" ; 
		playing_total += bet;
	}

	else if(dealer_total > card_total){ //checks if dealer won
		cout << "lost to dealer." ;
		playing_total -=bet;
	}

	else if(dealer_total < card_total){ //checks if player won
		cout << "won to dealer!" ;
		playing_total += bet;
	}

	else if(dealer_total == card_total) //checks if draw
		cout << "draw." ;


	cout <<	" Money left $" << playing_total << endl;

	bet =0; //resets bet amount
	card_total =0; //resets card total
}


/*********************************************************************
 ** Function: set bet
 ** Description: asks for bet from players
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: changes bet amount
 *********************************************************************/
void player::set_bet(){
	
	p_hand.reset(); //resets hand at beginning of turn

	if(playing_total == 0){ //checks if player has money left
		cout << "Error, no money left" << endl;
		return;
	}


	//get bet and make sure it is larger than 0 and <= players money total
	do{ 
		cin >> bet;
		if(bet > playing_total)
			cout << "Not enough money, please enter " << playing_total << " or less: " ;

		if(bet == 0)
			cout << "Please pick an amount larger than 0" << endl;

	}while(bet > playing_total || bet == 0);

}


/*********************************************************************
 ** Function: blackjack_bust 
 ** Description: checks if player got a blackjack or bust
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: updates winnings if blackjack or bust 
 *********************************************************************/
void player::blackjack_bust(){
	if(card_total == 21){ //checks for blackjack
		cout << "Blackjack! You win 1.5x your bet" << endl;
		playing_total += (bet*1.5);//updates winnings
		bet = 0; //resets bet
		cout << "You now have $" << playing_total << endl;
		return;
	}

	if(card_total > 21){
		cout << "Bust! You lose your bet" << endl;
		cout << "(╯°□°）╯︵ ┻━┻" << endl;
		playing_total -= bet; //updates winnings
		bet = 0; // resets bet
		cout << "You now have $" << playing_total << endl;
		return;
	}
}










/*********************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: 
 *********************************************************************/



