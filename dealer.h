class dealer {
	hand d_hand;
	int card_total;
	
	public:
	dealer();
	~dealer();

	void d_get_card(card);
	void reset_d_hand();

	void dealer_turn(deck *);
	int d_hand_value(int) const;
	void show_hidden(bool) const;
};
