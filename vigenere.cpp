/**
 * vigenere.cpp
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 3
 *
 * <#description#>
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>


string vigenereCipher(string original, string keyword, bool encrypt) {    
    //convert keyword to uppercase with only alphabetical characters.
    string upperKeyword = "";

    for (int i = 0; i < keyword.size(); i++) {

        //if char in keyword is alphabetical char.
        if ((keyword.at(i) >= 'a' && keyword.at(i) <= 'z') || (keyword.at(i) >= 'A' && keyword.at(i) <= 'Z')) {
            upperKeyword += toupper(keyword.at(i)); //adds only capital, alphabetical chars to upperKeyword.
        }
    }
    //keyword in all capital letters allows to calculate the distance for which to offset each alphabetical char in original, whether lowercase or uppercase.

    //Encrpyt
    if (encrypt == true) {

        string encryptedMessage = "";
        int j = 0;

        for (int i = 0; i < original.size(); i++) {

            //check if char is an alphabetical char.
            if ((original.at(i) >= 'a' && original.at(i) <= 'z') || (original.at(i) >= 'A' && original.at(i) <= 'Z')) {

                int distance;
                int remainder;

                if (j < upperKeyword.size()) {
                    distance = upperKeyword.at(j) - 'A';
                }
                else if (j >= upperKeyword.size()) {
                    remainder = j % upperKeyword.size();
                    distance = upperKeyword.at(remainder) - 'A';
                }

                char letter = shiftAlphaCharacter(original.at(i), distance);

                encryptedMessage += letter;
                j++;
            }

            //if char is not alphabetical, just add char to encryptedMessage.
            else {
                encryptedMessage += original.at(i);
            }
        }
        //After looped through each char in original and added encrypted char to encryptedMessage, return encrypted message.
        return encryptedMessage;        
    }
    
    //Decrypt
    if (encrypt == false) {

        string decryptedMessage = "";

        //iterate over original and for each character, go through the alphabet and shift the alphabetical letter by each amount in key
        //compare testLetter to original, if match --> add to final string, else don't

        //j is counter in order to increment to next char in keyword.
        int j = 0;

        for (int p = 0; p < original.size(); p++) {

            //if char in original is a non-alphabetical char, then add it to final string
            if ( (original.at(p) < 'A') || ( (original.at(p) > 'Z') && (original.at(p) < 'a') ) || (original.at(p) > 'z') ) {
                decryptedMessage += original.at(p);
            }
            
            //else, it is an alphabetical char
            else {

                int distance; //distance between char in upperkeyword and A, which is the amount to shift the testletter.
                int remainder; //remainder is the same^ except when the value goes past char 'A'.

                if (j < upperKeyword.size()) {
                    distance = upperKeyword.at(j) - 'A';
                }
                else if (j >= upperKeyword.size()) {
                    remainder = j % upperKeyword.size();
                    distance = upperKeyword.at(remainder) - 'A';
                }

                char letter; //letter of the alphabet
                char testLetter; //letter of the alphabet shifted by the amount in key

                //iterates over alphabet and checks if testLetter is == to char in original
                for ( letter = 'a'; letter <= 'z'; letter++) {

                    testLetter = shiftAlphaCharacter(letter, distance);

                    //uppercase
                    if (original.at(p) >= 'A' && original.at(p) <= 'Z') {
                        testLetter = toupper(testLetter);
                        
                        //if match
                        if (testLetter == original.at(p)) {
                            decryptedMessage += toupper(letter);
                        }
                    }

                    //lowercase
                    else {
                        //if match
                        if (testLetter == original.at(p)) {
                            decryptedMessage += letter;
                        }
                    }
                }

                j++; //increment j to get next value to shift with key
            }
        }

        //returns string with which ever chars were concatenating throughout the testing process.
        return decryptedMessage;
    }
}
