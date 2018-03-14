#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#include "./card.h"
#include "./deck.h"
#include "./hand.h"

hand::hand(){
	num_card = 0; //sets number of cards in hand
	cards = NULL;
}

hand::~hand(){
	delete [] cards; //frees memory used on heap
}


/*********************************************************************
 ** Function: draw_card
 ** Description: adds another card to hand
 ** Parameters: deck * 
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: cards gets a new member
 *********************************************************************/
void hand::draw_card(card new_card){
	card * temp; 
	temp = new card[num_card]; //temp array  
	

	//copy current cards to temp array
	for(int i=0; i< num_card; i++){ //iterates through array
		temp[i] = cards[i]; //copies card to temp
	}


	//delete old array and create new one of the correct size
	if (num_card >0)
		delete [] cards; //deletes old array

	cards = new card[num_card + 1]; //create new dynamic array of the correct size


	//fill dynamic array with the cards in temp
	for(int i=0; i< num_card; i++){ //iterate through cards
		cards[i] = temp[i]; //copies cards from temp
	}

	cards[num_card] = new_card; //adds the new card
	num_card += 1; //incriments number of cards

	delete [] temp; //deletes temp

}


/*********************************************************************
 ** Function: size
 ** Description: returns the number of cards in hand
 ** Parameters: none
 ** Pre-Conditions: all parameters are valid
 ** Post-Conditions: returns num_card
 *********************************************************************/
int hand::size() const{
	return num_card; //returns number of cards in hand
}


/*********************************************************************
 ** Function:reset 
 ** Description: resets hand
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: Hand is reset 
 *********************************************************************/
void hand::reset(){
	delete [] cards; //deletes dynamic array
	cards = NULL; //sets to null
	num_card = 0; //resets number of cards
}


/*********************************************************************
 ** Function: hand_val
 ** Description: adds up and returns value of hand
 ** Parameters: int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns hand value 
 *********************************************************************/
int hand::hand_val(int start) const{
	int total =0, aces =0;

	for(int i=start; i< num_card; i++){ //cycles through cards
		total += cards[i].card_value(); //adds up value of cards
		if(cards[i].card_value() == 1) //keeps track of number of aces
			aces ++;
	}

	for(int i=0; i<aces; i++){ //if there are aces, changes value to 11 if benificial
		if((total + 10) <= 21){
			total += 10;
		}
	}

	return total; //returns the value of the hand

}


/*********************************************************************
 ** Function: ascii_hand 
 ** Description: calls function to print out specified line of card
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: cards are printed to screen 
 *********************************************************************/
void hand::ascii_hand() const{
	for(int i=0; i<9; i++){ //loops through all lines
		for(int k=0; k< num_card;  k++){ //loops through all cards
			print_line(i, k); //calls function to print specified line and card
		}
		cout<<endl;
	}
}


/*********************************************************************
 ** Function: print_line
 ** Description: prints out specified line of specified card
 ** Parameters: int, int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: line of specified card is printed
 *********************************************************************/
void hand::print_line(int line_num, int card_num) const{
	string a = cards[card_num].get_value(); //gets card value
	string suit = cards[card_num].get_suit(); //gets card suit
	string b =  a.substr(0,1); 

	//makes hearts and diamonds red
	if(suit == "♥" || suit == "♦"){
		a = "\033[31m" +  a + "\033[0m" ;
		b = "\033[31m" +  b + "\033[0m" ;
		suit = "\033[31m" +  suit + "\033[0m" ;
	}

	string lines[9] = { //array holding ascii card template
				"┌─────────┐ ",
				" ",
				"│         │ ",
				"│         │ ",
				" ",
				"│         │ ",
				"│         │ ",
				" ",
				"└─────────┘ "};



	//lines that use variables in them
	if(line_num == 1)
		cout << "│"<< a  << "       │" ;

	if(line_num == 4)
		cout << "│    " << suit << "    │";

	if(line_num == 7 && a == "10")
		cout << "│       " << a  << "│ ";

	else if(line_num == 7)
		cout << "│        " << b << "│ ";

	else
		cout << lines[line_num];
}


/*********************************************************************
 ** Function: print_line_d
 ** Description: prints out specified line of specified card
 ** Parameters: int, int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: line of specified card is printed
 *********************************************************************/
void hand::ascii_hand_d() const{
	int test;
	for(int i=0; i<9; i++){ //loops through all lines
		for(int k=0; k< num_card;  k++){ //loops through all cards
			print_line_d(i, k); //calls function to print specified line and card
		}
		cout<<endl;
	}
}


/*********************************************************************
 ** Function: print_line_d
 ** Description: prints out specified line of specified card, and blank card for the first card
 ** Parameters: int, int
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: line of specified card is printed
 *********************************************************************/
void hand::print_line_d(int line_num, int card_num) const{
	string a = cards[card_num].get_value(); //gets card value
	string suit = cards[card_num].get_suit(); //gets card suit
	string b = a.substr(0,1); 

	//makes hearts and diamonds red
	if(suit == "♥" || suit == "♦"){
		a = "\033[31m" +  a + "\033[0m" ;
		b = "\033[31m" +  b + "\033[0m" ;
		suit = "\033[31m" +  suit + "\033[0m" ;
	}

	string lines[9] = { //array holding ascii card facing up
				"┌─────────┐ ",
				" ",
				"│         │ ",
				"│         │ ",
				" ",
				"│         │ ",
				"│         │ ",
				" ",
				"└─────────┘ "};


	string back[9] = { //array holding ascii card facing down
				"┌─────────┐ ",
				"│░░░░░░░░░│ ",
				"│░░░░░░░░░│ ",
				"│░░░░░░░░░│ ",
				"│░░░░░░░░░│ ",
				"│░░░░░░░░░│ ",
				"│░░░░░░░░░│ ",
				"│░░░░░░░░░│ ",
				"└─────────┘ " };


	if(card_num ==0){ //prints the first card facing down
		cout << back[line_num];
		return;
	}


	if(line_num == 1)
		cout << "│"<< a << "       │" ;

	if(line_num == 4)
		cout << "│    " << suit << "    │";

	if(line_num == 7 && a == "10")
		cout << "│       " <<  a  << "│ ";

	else if(line_num == 7)
		cout << "│        " <<  b << "│ ";

	else
		cout << lines[line_num];
}











/*********************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: 
 *********************************************************************/







