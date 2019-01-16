#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string printspace(int r)
{
	if (r / 100)
		return " ";
	else if (r / 10)
		return "  ";
	else
		return "   ";
}

void printtable(int** w, int pile, const char* c)
{
	cout << endl;
	cout << c << endl;;
	// print table
	for (int p = 0; p <= pile; ++p)
	{
		for (int r = 0; r <= pile; ++r)
		{
			if (p == 0)
			{
				if (r == 0)
					cout << "p/r ";
				else
					cout << printspace(r).c_str() << r;
			}
			else
			{
				if (r == 0)
					cout << printspace(p).c_str() << p;
				else
					cout << printspace(w[p][r]).c_str() << w[p][r];
			}
		}
		cout << endl;
	}
}

int WinningMove(int pile, int nMaxMove)
{
	// dynamic allocation w[1..pile][1..pile]
	int** w = new int*[pile + 1];
	for (int i = 0; i <= pile; ++i)
	{
		w[i] = new int[pile + 1];
	}

	for (int p = 1; p <= pile; ++p)
	{
		for (int r = 1; r <= pile; ++r)
		{
			if (p <= r)
				w[p][r] = p;
			else
				w[p][r] = 0;
		}
	}

	//printtable(w, pile, "Initial w table");

	for (int p = 1; p <= pile; ++p)
	{
		for (int r = 1; r < p; ++r) // r <= p-1
		{
			int rr = 2 * r;
			if (rr > p)
				rr = p;

			if (w[p - r][rr] == 0)
				w[p][r] = r;
			else if (r > 1)
				w[p][r] = w[p][r - 1];
			else
				w[p][r] = 0;

			stringstream ssp; stringstream ssr;
			ssp << p; ssr << r;
			string sr = "p = " + ssp.str() + " r = " + ssr.str() + " w table";
			//printtable(w, pile, sr.c_str());
		}
		stringstream ssp;
		ssp << p;
		string sr = "p = " + ssp.str() + " w table";
		//printtable(w, pile, sr.c_str());
	}

	//printtable(w, pile, "Final w table");

	// return maximum winning move
	int wr = 0;
	if (pile <= nMaxMove)
		wr = w[pile][pile];
	else
		wr = w[pile][nMaxMove];

	// free
	for (int i = 0; i < pile; ++i)
		delete[] w[i];
	delete[] w;

	return wr;
}

int main()
{
	cout << "Single-pile Nim game\n";
	cout << "Please enter integer for the pile size :\n";
	string input = "";
	getline(cin, input);
	int i = atoi(input.c_str());
	//int i = 10000;
	int j = i - 1;
	int winningmove = WinningMove(i, j);
	cout << "\nFor size = " << i << " has Maximum Winning Move = " << winningmove << "\n";
	return 0;
}
