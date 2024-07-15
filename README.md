My first C++ project in 5 years.

The goal is to learn again how to code in C++ with a little game named Detrak. 

1rst step: create a console app with the logic of the game.

2nd step: find a way to get an Android app with it. 

How it is played: 2 dice are rolled and each player has to draw these symbols into their sheet following very simple rules: 
- the two symbols have to be drawn in orthogonally adjacent fields. (Single fields previously surrounded with symbols will never be filled.) 
- as long as there are adjacent spaces, the symbols must be entered.
- The game ends when the sheets are filled or there are no legal adjacent spaces left.

Score:
  Each row and column are scored separately: 2, 3, 4 or 5 adjacent symbols of the same type score 2, 3, 4, 5 points PLUS 4/5 bonus points for 4/5 symbols, ie : 2 -> 2 points, 3 -> 3 points, 4 -> 8 points , 5 -> 10 points;
