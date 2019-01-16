# Single-pile-Nim-Game
COEN279 Project.

There are two players. The game starts out with pile of n chips. The players alternate in removing chips from the pile. 

Neither player is allowed to remove 0 chips.

The player who move first can remove at most n-1 chips.

After the first move, each player may remove, at most, twice the number of chips his opponent removed on the previous move.

The player who removes the last chip wins.
## Phase 0 : a recursive solution
Implement the following recursive function:
  * Return the maximum winning move if there is any
  * Otherwise return 0
  * Pile: number of Chips in the pile
  * nMaxMove: #chips allowed to move
## Phase 1: dynamic programing
* Formulas: Any status of the game can be described by using a pair of integers, namely 𝑝 be the number of chips in the   pile and 𝑟 the number of chips one is allowed to remove. Define
Any status of the game can be described by using a pair of integers, namely 𝑝 be the number of chips in the pile and 𝑟 the number of chips one is allowed to remove. Define 

  ```
  w[p, r] = the greatest number of chips of the optimal move, if exist; or 0, otherwise. 
  ```
  
* Write a program to calculate w[p, r].
* Print out all w[p, r], p = 1, ... , 100, r <= p as a triangular table by using p as the row index and r the column index.
## Phase 2 : Fibonacci Decomposition
* All the positive integers can be written into unique Fibonacci decomposition.
* Describe a strategy for Nim by using the hint.
* Hint: When can a player reduce the Fibonacci length of 𝑝, the size of the pile?

  
