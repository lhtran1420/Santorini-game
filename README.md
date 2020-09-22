The goal of this project is to implement the game Santorini using the C programming language. The game will be interactive and played between a human user and an AI (artificial intelligence). 

In this project, the rule is following: 
-  You only need to implement this game for two players and each only has 1 builder to play in this game. Please use ‘P’ as player’s builder and ‘A’ to represent the AI’s builder. 
-  Both builders can be moved into any adjacent space no matter what building levels are.
-  A builder cannot be moved into any adjacent space if the space is occupied by another builder.
-  When you move your builder into a space, your builder constructs a building level for each space (excludes the space the builder just moved in) that is located in a straight line of any octagonal direction if it is not blocked by another player.
-  When AI moves its builder into a space, AI’s builder destructs a building level for each space (excludes the space the builder just moved in) that is located in a straight line of any octagonal direction if it is not blocked by another player.
-  The building level ranges from 0 to  4. Your game should not contain any building with a building level more than 4 or less than 0 during the game play.
-  The game ends if there are at least 10 spaces with a building level of 4 or at least 10 spaces with a building level of 0 in the game board.
-  The human player wins if there are at least 10 spaces with a building level of 4 where the AI player wins if there are at least 10 spaces with a building level of 0 when the game ends.

After the player chooses a starting point, AI chooses a space adjacent to the player's starting point as its starting point. Notice that choosing starting points won’t change any building level in the game board. For example, Here the game states if the human player chooses (1,2) as the starting point, then AI chooses (1,3) as its  starting point. 

   1 2 3 4 5 6
1  2 P A 2 2 2
2  2 2 2 2 2 2
3  2 2 2 2 2 2
4  2 2 2 2 2 2
5  2 2 2 2 2 2
6  2 2 2 2 2 2
