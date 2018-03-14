class deck {
	private:
		card cards[52]; //array of the cards in the deck
		int num_cards; //stores the index of where in the deck is the current location
	
	public:
		deck(); //constructor
		~deck(); //destructor

		int cards_left() const; //accessor
		card next_card(); 

		void discard_card(); //mutator
		void shuffle(); //mutator
};	
