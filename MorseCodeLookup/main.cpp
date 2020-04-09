/**********************************************************
* Programmer: Garett Pascual-Folster					  *
* Class: CptS 122, Spring, 2020; Lab Section 4			  *
* Programming Assignment: PA6							  *
* Date: January 20, 2020								  *
* Description: Using Binary Search Tree data structure	  *
*				for ciphering morse code				  *
**********************************************************/

#include "BST.h"

int main() {

	ifstream morsecode("MorseTable.txt");
	BST lookup(morsecode);
	morsecode.close();

	// balance tree for more efficiency
	lookup.balance();
	lookup.print();
	cout << endl << endl;

	string code;
	char character;
	ifstream text("Convert.txt");

	cout << "Converting text: " << endl;
	while (!text.eof()) {
		character = text.get();
		character = (character > 96) ? character - 32 : character;
		if (lookup.search(character, code))
			cout << code << " ";
		else if (character == ' ')
			cout << "  ";
		else
			cout << character;
	}
	text.close();

	return 0;
}