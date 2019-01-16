//c++ version
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int WinningMove(int pile, int nMaxMove)
{
	if (nMaxMove >= pile)
		return pile;

	// f stores fib numbers
	// need size of 7 for small piles up to 6 to prevent out of bounce
	// and use pile size for more than 6 in pile
	int fsize = pile;
	if (pile <= 6)
		fsize = 7;
	int* f = new int[fsize];
	for (int t = 0; t < fsize; t++)
		f[t] = 0;
	f[0] = 0;
	f[1] = 1;

	int n = 2; // next fib index
	f[n] = f[n - 1] + f[n - 2];
	while (pile >= f[n])
	{
		n++;
		f[n] = f[n - 1] + f[n - 2];
		if (pile == f[n])
			return 0;
	}

	// e.g. pile = 16
	// f = [0 1 1 2 3 5 8 13 21]
	// fi = 0 1 2 3 4 5 6 7  8
	// found f[n-1] <= pile < f[n]

	// i stores pile's a indexes of the fib number
	// e.g. pile = a1 + ... + ak
	// e.g. 17 = 13 + 3 + 1 => i  = [7 4 1]
	int* i = new int[pile];
	for (int t = 0; t < pile; t++)
		i[t] = 0;
	i[0] = f[n - 1]; // f[n-1] is the first fib decomposition # e.g. 7

	int remainpile = pile;
	int ii = 0; // first pile's a index to be stored
	int nn = n - 1; // first fib decomposition number index 
	// start from the last - 1 fib number to the beginning smaller fib number
	while (remainpile > 0 && nn > 0)
	{
		// e.g. 17 >= 13, and then 3 >= 3, and then 1 >= 1
		if (remainpile >= f[nn])
		{
			i[ii] = nn; // store this fib decompostion number index e.g. 7, and then 4, and then 1
			remainpile = remainpile - f[i[ii]]; // e.g. 4 = 17 - 13
			ii++; // next pile's a index to be stored
			nn = nn - 2; // next index cannot be 1 less
		}
		else
			nn--; // keep decreasing fib index to find next biggest fib for remainpile		
	}
	ii--; // exclude unnecessary last fib decomposition number 0
	// found i = [7 4 1]
	// ii = last fib number index index, e.g. 2, where i[2] = 1

	// find maximum sum of smallest fib decomposition numbers that is less than 1/3 of the next bigger fib decomposition number
	// so that we can find the maximum winning move without letting the opponent give us a fib number
	// e.g. 1 + 2 < 1/3 * (13) = 13/3 = 4.3333
	// and the sum must be less than nMaxMove
	// lets start from last smallest fib number in a, where a = [13 3 1], or i = [7 4 1]
	int maxsum = 0;
	int cursum = 0;
	while (ii > 0) // cannot consider f0, which is 0
	{
		cursum += f[i[ii]];
		// compare with 1/3 of 1 less ii, which is the next bigger fib decomposition number
		if (cursum <= nMaxMove && 2 * cursum < f[i[ii - 1]])
		{
			maxsum = cursum;
		}
		ii--;
	}
	// found max sum

	delete[] i;
	delete[] f;
	return maxsum; // max sum of smallest fib decomposition numbers as max winning move
}

int main()
{
	while (1)
	{
		cout << "Single-pile Nim game\n";
		cout << "Please enter integer for the pile size :\n";
		string input = "";
		getline(cin, input);
		int p = atoi(input.c_str());
		//int p = 10000;
		int j = p - 1;
		int winningmove = WinningMove(p, j);
		cout << "\nFor size = " << p << " has Maximum Winning Move = " << winningmove << "\n\n";
	}
	return 0;
}
