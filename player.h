class player {
	private:
	hand p_hand;
	int playing_total;
	int card_total;
	int bet;
	
	public:
	player(); //constructor
	~player(); //destructor

	void set_bet(); //mutator
	int card_total_amount() const; //accessors
	int bet_amount() const; //accessor
	void player_hand();
	void winnings(int);


	void blackjack_bust();	
	void update_card_total();
	void p_get_card(card);	

};
