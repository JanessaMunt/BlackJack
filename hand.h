class hand { 
	private:
		card * cards; //array holding the cards in hand
		int num_card; //number of cards in hand
	
	public:
		hand(); //constructor
		~hand(); //destructor	
			
		int size() const; //accessor
		int hand_val(int) const; //accessor
		void ascii_hand() const;
		void print_line(int, int) const;
		void ascii_hand_d() const;
		void print_line_d(int, int) const;

		void draw_card(card); //mutator
		void reset();
};
