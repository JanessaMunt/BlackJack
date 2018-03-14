blackjack: play_game.o game.o dealer.o player.o hand.o deck.o card.o
	g++ play_game.o game.o dealer.o player.o hand.o deck.o card.o -o blackjack
play_game.o: play_game.cpp
	g++ play_game.cpp -c
game.o: game.cpp
	g++ game.cpp -c
dealer.o: dealer.cpp
	g++ dealer.cpp -c
player.o: player.cpp
	g++ player.cpp -c
hand.o: hand.cpp
	g++ hand.cpp -c
deck.o: deck.cpp
	g++ deck.cpp -c
card.o: card.cpp
	g++ card.cpp -c
clean:
	rm -f a.out *.o blackjack
