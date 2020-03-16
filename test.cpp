/**
 * test.cpp
 *
 * <Eoin>
 * <eoins>
 *
 * EECS 183: Project 3 - Test Suite
 *
 * <This file is a test suite for the functions that will be implemented in caesar.cpp!>
 */

//Header files with function declarations

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
using namespace std;

//Test Function Declarations
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testVigenereCipher();
void testMixKey();
void testFillGrid();
void testFindInGrid(); 
void testPolybiusSquare();



int main(void) {

    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid(); 
    testPolybiusSquare();
    
    return 0;
}

//Function Definitions

void testToUpperCase() {

    cout << "Testing function toUpperCase()..." << endl << endl;

    cout << toUpperCase("hello") << " should be: HELLO" << endl;
    cout << toUpperCase("hElLo!!") << " should be: HELLO!!" << endl;
    cout << toUpperCase("a1s2d3f4") << " should be: A1S2D3F4" << endl;
    cout << toUpperCase("EOIN eoin *8@90  eoin") << " should be: EOIN EOIN *8@90  EOIN" << endl;

    cout << endl;
}

void testRemoveNonAlphas() {

    cout << "Testing function removeNonAlphas()..." << endl << endl;

    cout << removeNonAlphas("e1o2i3n4") << " should be: eoin" << endl;
    cout << removeNonAlphas("e129 0%68* *$ #o 90i 0@n!!") << " should be: eoin" << endl;
    cout << removeNonAlphas("e^5%E000o ?/Oi    [{!I }}n+-+_N") << " should be: eEoOiInN" << endl;

    cout << endl;
}

void testRemoveDuplicate() {
    cout << "Testing function removeDuplicate()..." << endl << endl;

    cout << removeDuplicate("EEOIN") << " should be: EOIN" << endl;
    cout << removeDuplicate("EOINEOINEOINEOINEOINEOINEOIN") << " should be: EOIN" << endl;
    cout << removeDuplicate("01234567890123456789") << " should be: 0123456789" << endl;
    cout << removeDuplicate("AKAKAKAKAKAAKAKAKAKAKA123") << " should be: AK123" << endl;
    cout << removeDuplicate("AA11BB22CC33") << " should be: A1B2C3" << endl;
    cout << removeDuplicate("MISSISSIPPI") << " should be: MISP" << endl;

    cout << endl;
}

void testCharToInt() {

    cout << "Testing funcion charToInt()..." << endl << endl;

    cout << charToInt('0') << " should be: " << 0 << endl;
    cout << charToInt('1') << " should be: " << 1 << endl;
    cout << charToInt('2') << " should be: " << 2 << endl;
    cout << charToInt('3') << " should be: " << 3 << endl;
    cout << charToInt('4') << " should be: " << 4 << endl;
    cout << charToInt('5') << " should be: " << 5 << endl;
    cout << charToInt('6') << " should be: " << 6 << endl;
    cout << charToInt('7') << " should be: " << 7 << endl;
    cout << charToInt('8') << " should be: " << 8 << endl;
    cout << charToInt('9') << " should be: " << 9 << endl;

    cout << endl;
}

void testShiftAlphaCharacter() {

    cout << "Testing function shiftAlphaCharacter() Part 1..." << endl << endl;

    cout << shiftAlphaCharacter('a', 3) << " should be: d" << endl;
    cout << shiftAlphaCharacter('b', 3) << " should be: e" << endl;
    cout << shiftAlphaCharacter('a', 24) << " should be: y" << endl;
    cout << shiftAlphaCharacter('a', 25) << " should be: z" << endl;
    cout << shiftAlphaCharacter('a', 26) << " should be: a" << endl;
    cout << shiftAlphaCharacter('a', 75) << " should be: x" << endl;
    cout << shiftAlphaCharacter('a', 100) << " should be: w" << endl;
    cout << shiftAlphaCharacter('a', 200) << " should be: s" << endl;
    cout << shiftAlphaCharacter('g', 42) << " should be: w" << endl;
    cout << shiftAlphaCharacter('v', 106) << " should be: x" << endl;
    cout << shiftAlphaCharacter('o', 111) << " should be: v" << endl;
    cout << shiftAlphaCharacter('d', -10) << " should be: T" << endl;
    cout << shiftAlphaCharacter('d', -234) << " should be: D" << endl;

    cout << endl << "Testing function shiftAlphaCharacter() Part 2..." << endl << endl;

    cout << shiftAlphaCharacter('A', 3) << " should be: D" << endl;
    cout << shiftAlphaCharacter('B', 3) << " should be: E" << endl;
    cout << shiftAlphaCharacter('A', 24) << " should be: Y" << endl;
    cout << shiftAlphaCharacter('A', 25) << " should be: Z" << endl;
    cout << shiftAlphaCharacter('A', 26) << " should be: A" << endl;
    cout << shiftAlphaCharacter('A', 75) << " should be: X" << endl;
    cout << shiftAlphaCharacter('A', 100) << " should be: W" << endl;
    cout << shiftAlphaCharacter('A', 200) << " should be: S" << endl;
    cout << shiftAlphaCharacter('G', 42) << " should be: W" << endl;
    cout << shiftAlphaCharacter('V', 106) << " should be: X" << endl;
    cout << shiftAlphaCharacter('V', -10) << " should be: L" << endl;
    cout << shiftAlphaCharacter('D', -10) << " should be: t" << endl;
    cout << shiftAlphaCharacter('D', -234) << " should be: d" << endl;

    cout << endl;
}

void testCaesarCipher() {
    
    cout << "Testing function caesarCipher()..." << endl << endl;

    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << " should be: Cuuj cu qj jxu Tyqw qj 11 f.c." << endl;
    cout << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << " should be: Meet me at the Diag at 11 p.m." << endl;

    cout << caesarCipher("Eoin is learning EECS 183!", 10, true) << " should be: Oysx sc vokbxsxq OOMC 183!" << endl;
    cout << caesarCipher("Oysx sc vokbxsxq OOMC 183!", 10, false) << " should be: Eoin is learning EECS 183!" << endl << endl;
}

void testVigenereCipher() {
    
    cout << "Testing function vigenereCipher()..." << endl << endl;

    cout << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << " should be: Euyb dv ee lxy Lzrk ll 11 f.g." << endl;
    cout << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << " should be: Meet me at the Diag at 11 p.m." << endl << endl;
}

void testMixKey() {

    cout << "Testing function mixKey()..." << endl << endl;

    cout << mixKey("POLYBIUS") << " should be: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789" << endl;
    cout << mixKey("183") << " should be: 183ABCDEFGHIJKLMNOPQRSTUVWXYZ0245679" << endl << endl;
}

void testFillGrid() {

    cout << "Testing function fillGrid() with no key (ALNUM)..." << endl << endl;

    char testArr1[SIZE][SIZE];
    fillGrid(testArr1, ALNUM);
    printGrid(testArr1);
    cout << endl;

    cout << "Testing function fillGrid() with key 'POLYBIUS'..." << endl << endl;

    fillGrid(testArr1, mixKey("POLYBIUS"));
    printGrid(testArr1);
    cout << endl;
}

void testFindInGrid() {

    cout << "Testing function findInGrid() with key 'POLYBIUS'..." << endl << endl;

    char testArr1[SIZE][SIZE];
    fillGrid(testArr1, mixKey("POLYBIUS"));
    
    cout << findInGrid('E', testArr1) << " should be: 15" << endl;
    cout << findInGrid('E', testArr1) << " should be: 15" << endl;
    cout << findInGrid('C', testArr1) << " should be: 13" << endl;
    cout << findInGrid('S', testArr1) << " should be: 11" << endl << endl;
}

void testPolybiusSquare() {

    cout << "Testing function polybiusSquare(grid, 183, EECS 183 IS THE BEST, true)..." << endl << endl;

    char testArr1[SIZE][SIZE];
    cout << polybiusSquare(testArr1, "183", "EECS 183 IS THE BEST", true) << " should be: 11110533 000102 1533 341411 04113334" << endl;
    cout << polybiusSquare(testArr1, "183", "11110533 000102 1533 341411 04113334", false) << " should be: EECS 183 IS THE BEST" << endl;
}