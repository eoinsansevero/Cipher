/**
 * utility.cpp
 *
 * <Eoin Sansevero>
 * <eoins>
 *
 * EECS 183: Project 3
 *
 * <#description#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!>
 */

#include "utility.h"
#include <iostream>


string toUpperCase(string original) {
    
    //iterate over string
    for (int i = 0; i < original.size(); i++) {
        if (original.at(i) >= 'a' && original.at(i) <= 'z') {
            original.at(i) = toupper(original.at(i));
        }
    }
    string uppOriginal = original;
    
    return uppOriginal;
}

string removeNonAlphas(string original) {
    
    for (int i = 0; i < original.size(); i++) {
        if (original.at(i) < 'a' || original.at(i) > 'Z') {
            
        }
    }
    
    // returning a string to avoid compile error
    return "";
}

string removeDuplicate(string original) {
    // TODO: implement
    
    // returning a string to avoid compile error
    return "";
}

int charToInt(char original) {
    // TODO: implement
    
    // returning 0 to avoid compile error
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
