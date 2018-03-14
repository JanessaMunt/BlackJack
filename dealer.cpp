#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;
#include "./card.h"
#include "deck.h"
#include "./hand.h"
#include "./player.h"
#include "./dealer.h"

dealer::dealer(){

}

dealer::~dealer(){

}


/*********************************************************************
 ** Function: d_get_card 
 ** Description: adds a new card to d_hand
 ** Parameters: card
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: d_card gets a new card 
 *********************************************************************/
void dealer::d_get_card(card newcard){
	d_hand.draw_card(newcard); //draws card
}

/*********************************************************************
 ** Function: d_hand_value
 ** Description: gets value of dealers hand
 ** Parameters: int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns value of dealers hand
 *********************************************************************/
int dealer::d_hand_value(int start) const{
	return d_hand.hand_val(start); //returns hand value
}

/*********************************************************************
 ** Function: show_hidden
 ** Description: prints dealers hand with option of hiding first card
 ** Parameters: bool
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: dealers hand is printed
 *********************************************************************/
void dealer::show_hidden(bool hidden) const{
	if(hidden == true)
		d_hand.ascii_hand_d(); //calls function to print hand with hidden card
	else
		d_hand.ascii_hand(); //calls function to print hand and show hidden card

}

/*********************************************************************
 ** Function: dealer_turn
 ** Description: reveals dealer's hidden card and draws a card if total is less than 17
 ** Parameters: deck
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: dealers hand and value is printed 
 *********************************************************************/
void dealer::dealer_turn(deck * pack){
	cout << " ○ Dealer's hand total: " << d_hand.hand_val(1) << " ○" << endl; //prints hand value
	show_hidden(1); //prints dealers hand with hidden card
	cout << endl;


	cout << " ○ Dealer's hand total: " << d_hand.hand_val(0) << " ○" << endl; //prints hand value
	show_hidden(0); //prints dealers full hand

	while(d_hand_value(0) < 17){ //draws another card while hand total is under 17
		d_hand.draw_card(pack->next_card()); //draws card
		cout << " ○ Dealer's hand total: " << d_hand.hand_val(0) << " ○" << endl; //prints hand value
		show_hidden(0); //prints hand
	}	
}



/*********************************************************************
 ** Function: reset_d_hand
 ** Description: calls function to reset d_hand
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: d_hand is reset 
 *********************************************************************/
void dealer::reset_d_hand(){
	d_hand.reset(); //calls function to reset hand
}


