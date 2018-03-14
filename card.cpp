#include <iostream>
#include <string>

using namespace std;
#include "./card.h"

card::card(){
	suit = "Clubs";
	value = "Ace";
	int_value = 1; 
	location = "deck";
}


card::~card(){

}


/*********************************************************************
 ** Function: set_card
 ** Description: sets card value based on input
 ** Parameters: int, int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: changes the value of card to specified input
 *********************************************************************/
void card::set_card(int value_num, int suit_num){
//	string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	string suits[4] = {"♣", "♦", "♥", "♠"};
	string type[13] = {"A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K "};
	int int_val[13] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10, 10, 10, 10};

	suit = suits[suit_num]; //assigns suit

	value = type[value_num];

	int_value = int_val[value_num]; //assigns value of card
}


/*********************************************************************
 ** Function: card_location
 ** Description: Accesses and returns card location
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns string 
 *********************************************************************/
string card::card_location() const{
	return location;
}


/*********************************************************************
 ** Function: move_card
 ** Description: changes card location to specified string
 ** Parameters: string
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: location is changed
 *********************************************************************/
void card::move_card(string new_location){
	location = new_location;
}


/*********************************************************************
 ** Function: card_value
 ** Description: returns value of card
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns int_value of a card 
 *********************************************************************/
int card::card_value() const{
	return int_value;
}


/*********************************************************************
 ** Function: get_value
 ** Description: Accesses and returns card suit
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns string 
 *********************************************************************/
string card::get_suit() const{
	return suit;
}



/*********************************************************************
 ** Function: card_location
 ** Description: Accesses and returns card value
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns string 
 *********************************************************************/
string card::get_value() const{
	return value;
}







/*********************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: 
********************************************************************/
