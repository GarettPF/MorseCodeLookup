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

	// balance tree for more efficiency
	lookup.balance();
	lookup.print();

	string code;
	if (lookup.search('G', code)) {
		cout << "G: " << code << endl;
	}


	return 0;
}