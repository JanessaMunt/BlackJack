class card{
	private:
		//int value; //1-13
		string suit; //4 each: club, spade, heards, diamonds
		string value; //stores the name of the card (Ace, one, two, ect)
		string location; //stores the "location" of the card - discard, deck, or hand
		int int_value; //stores the integer value of the card for calculating scores

	public:
		card(); //constructor
		~card(); //destructor
		void set_card(int, int); //mutator
		void move_card(string); //mutator

		string card_location() const; //accessor
		string get_value() const;
		int card_value() const;
		string get_suit() const;

};
