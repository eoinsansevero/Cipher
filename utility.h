/**
 * utility.h
 *
 * EECS 183: Project 3
 *
 * Helper functions and constants
 */

#ifndef __UTILITY__
#define __UTILITY__

#include <string>
using namespace std;


const int SIZE = 6;
const string ALNUM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with all alphabetical
 *           characters converted to uppercase. All other characters (numbers,
 *           symbols, spaces, punctuation marks, etc.) are unchanged.
 */
string toUpperCase(string original);


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with all non-alphabetical
 *           characters (numbers, symbols, spaces, punctuation marks, etc.)
 *           removed.
 *
 *           Example: "EECS 183!" -> "EECS"
 */
string removeNonAlphas(string original);


/**
 * Requires: original contains only uppercase alphabet and/or digits from 0 to 9.
 * Modifies: Nothing.
 * Effects:  Returns a copy of original string with duplicate characters except
 *           for the first occurence removed.
 *
 *           Example: "AABBCAB" -> "ABC"
 */
string removeDuplicate(string original);


/**
 * Requires: original is a character representing numbers from 0 to 9.
 * Modifies: Nothing.
 * Effects:  Returns the integer representation of the correspondiong charcater.
 *
 *                    char  int
 *           Example: '1' -> 1
 */
int charToInt(char original);


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Prints the grid.
 */
void printGrid(const char grid[SIZE][SIZE]);


#endif
