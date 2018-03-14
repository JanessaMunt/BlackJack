class game {
	private:
	deck cards;
	player *players;
	dealer game_dealer;
	int num_players;

	public:
	game(int);
	~game();
	void round();
	void get_player_bets();
	void deal_hand();
	void show_p_hands();
	void show_d_hand();
	void hit_pass();

	int dealer_turn();
	void calculate_winnings();
	void discard_hands();


};
