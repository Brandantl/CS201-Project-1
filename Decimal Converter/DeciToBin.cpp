// Name: Brandan Tyler Lasley
// Date: 4/19/2014 23:36
// Desc: Converts Dedimal to binary (upto INT64 MAX).
#include "DeciToBin.h"
#include <cmath>
using namespace std;

int main()
{
	long long decimal = 0;
	while (true) { // Endless loop, except when the right answer is given.
		cout << "Enter a INT64: "; // Print to screen
		if (cin >> decimal) { // Test if cin is valid (and the type)
				cout << ToBinary(decimal); // Print the answer!
				break; // Exit the loop once a valid answer was given.
		}
		else { // Oh noes it wasn't valid :/
			cerr << "Input was not an INT64!" << endl; // Crap something went wrong :(
			cin.clear(); // Clear Invalid flags
			cin.sync();  // Resyncs buffer
		}
	}
}

string ToBinary(long long decimal = 0) {
	stringstream binary(stringstream::in | stringstream::out);
	bool negitive = false; // Negitive Hoxfix,not how I would have programmed it but I didn't have enough time to impliment them properly.

	if (decimal < 0) {
		decimal = abs(decimal); // Absolute ftw.
		negitive = true;
	}

	if (decimal == 0) {
		return "0";
	}
	else if (decimal == 1) {
		if (negitive = '-1') {
			return "-1";
		}
		else {
			return "1";
		}
	}

	while (decimal >= 1) {
		binary << (decimal % 2);
		decimal = (decimal >> 1);
	}

	if (negitive) {
		binary << ("-"); // Another hotfix.
	}

	string output = binary.str(); // output is the answer, but heres a problem, its reversed!
	std::reverse(output.begin(), output.end()); // reverse output, to see the issue that made me use a stringstream
	// instead of a normal long long comment out this line and run it.
	return output.c_str(); // Return the correct output.
}
