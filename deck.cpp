#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#include "./card.h"
#include "./deck.h"


deck::deck(){
	int c=0; //index to keep track of place in array
	for(int i=0; i<13; i++){ //cycles through all values
		for(int k=0; k<4; k++){ //cycles through all suits
			(cards[c]).set_card(i, k); //changes from default value
			c++; 
		}
	}
	shuffle(); //shuffles deck apon creation
	num_cards = 0; //deck starts with index at 0
}


deck::~deck(){

}


/*********************************************************************
 ** Function: shuffle 
 ** Description: shuffles the deck, and moves cards from discard to deck
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: order of array cards is randomized
 *********************************************************************/
void deck::shuffle(){
	int counter=0, deck_counter =0;

	srand(time(NULL));
	for(int i=0; i < 52; i++){ //iterates through all cards
		int k = i + (rand() % (52 - i)); //finds a random value that has not been moved yet
		card temp = cards[i];
		cards[i] = cards[k];
		cards[k] = temp;
	}


	for(int i=0; i<52; i++){ //moves card from the "discard" pile to "deck"
		if(cards[i].card_location() == "deck"){ //checks for cards in deck
			deck_counter ++; //keeps track of cards in deck
		}

		if(cards[i].card_location() == "discard"){ //checks for cards in discard pile
			counter ++; //keeps track of cards in discard pile
			cards[i].move_card("deck"); //moves cards from discard pile to deck
		}
	}

	if(counter == 0 && deck_counter ==0){ //checks if there are no cards in discard pile
		cout << "No cards in discard pile, new deck is being added" << endl;
		for(int i=0; i<52; i++){ //moves all cards to deck
			cards[i].move_card("deck"); 
		}
	}
}


/*********************************************************************
 ** Function: discard_card
 ** Description: moves all cards in hand to discard
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: cards with location hand are moved to discard 
 *********************************************************************/
void deck::discard_card(){
	for(int i=0; i<52; i++){
		if(cards[i].card_location() == "hand") //moves cards from "hand" to discard pile
			cards[i].move_card("discard");
	}
}


/*********************************************************************
 ** Function: cards_left
 ** Description: returns index of deck location
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns int 
 *********************************************************************/
int deck::cards_left() const{
	return num_cards; //returns what point in the deck we are at
}


/*********************************************************************
 ** Function: next_card
 ** Description: Returns the next card in the deck that isn't in the discard pile. If entire deck has been dealt out the discard pile will be shuffled.
 ** Parameters: none
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: returns a card 
 *********************************************************************/
card deck::next_card(){

	if(num_cards > 51){ //checks if deck has been iterated through
		cout << "Full deck has been dealt, shuffling discard pile" << endl;
		num_cards = 0; //resets index
		shuffle(); //shuffles deck
		return next_card(); //calls function
	}

	else if(cards[num_cards].card_location() == "deck"){ //checks if card is in the deck
		cards[num_cards].move_card("hand"); //moves card location to hand
		num_cards += 1; //incriments index
		return cards[num_cards - 1]; //returns card
	}

	else{ //if card is not in the deck, moves on to the next card
		num_cards += 1; //incriments index
		return next_card(); // calls function again
	}

}








/*********************************************************************
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: All parameters are valid
 ** Post-Conditions: 
 *********************************************************************/
