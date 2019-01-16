#include <iostream>
using namespace std;

int WinningMove(int pile, int nMaxMove)
{
	// If number of chips in pile is less than or equal the maximum allowed to be removed,
	// return this maximum winning move
	if (pile <= nMaxMove)
		return pile;

	// Try remove highest maximum to lowest minimum allowed number of chips one by one
	for (int n = nMaxMove; n > 0; n--)
	{
		// After removing "n" number of chips, there are only "pile - n" left in the pile,
		//and the oppenent is allowed to remove "n * 2" number of chips
		// If the oppenent cannot find a winning move, which is when returning 0, then'n' is the maximum winning move
		int oppwinningmove = WinningMove(pile - n, n * 2);
		if (oppwinningmove == 0)
			return n;
	}
	// If cannot find a winning move, return 0
	return 0;
}

int main()
{
	cout << "Single-pile Nim game\n";
	for (int i = 2; i <= 15; i++)
	{
		int winningmove = WinningMove(i, i - 1);
		cout << "For size = " << i << " has Maximum Winning Move = " << winningmove << "\n";
	}
	return 0;
}
