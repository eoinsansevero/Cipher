/**
 * caesar.cpp
 *
 * <Eoin Sansevero>
 * <eoins>
 *
 * EECS 183: Project 3
 *
 * <#description#!!!!!!!!!!!!!!!!!!!!!!!!!!>
 */

#include "caesar.h"
#include <iostream>


char shiftAlphaCharacter(char c, int n) {
    char cShift = c;

    //for positive n
    if (n >= 0) {

        //lower case letters
        if ((c >= 'a') && (c <= 'z')) {

            //shifted char must be between a - z, so updating n with % 26 will ensure that the int variable remainder will not exceed 26.
            while (n > 26) {
                n = n % 26;
            }

            if ((c + n) > 'z') {
                //remainder will not be larger than 26 because n cannot be larger than 26.
                int remainder = n - ('z' - c);
                //'`' is one unit behind 'a' in ASCII chart.
                cShift = '`' + remainder;
            }
            else {
                cShift = c + n;
            }
        }
        //uppercase letters
        if ((c >= 'A') && (c <= 'Z')) {

            //shifted char must be between A - Z, so updating n with % 26 will ensure that the int variable remainder will not exceed 26.
            while (n > 26) {
                n = n % 26;
            }

            if ((c + n) > 'Z') {
                //remainder will not be larger than 26 because n cannot be larger than 26.
                int remainder = n - ('Z' - c);
                //'@' is one unit behind 'A' in ASCII chart.
                cShift = '@' + remainder;
            }
            else {
                cShift = c + n;
            }
        }
    }

    //for negative n
    else if (n < 0) {
        //lower case letters
        if ((c >= 'a') && (c <= 'z')) {

            //shifted char must be between a - z, so updating n with % 26 will ensure that the int variable remainder will not exceed 26.
            while (abs(n) > 26) {
                n = n % 26;
            }

            if ((c + n) < 'a') {
                //remainder will not be larger than 26 because n cannot be larger than 26.
                int remainder = 'a' - (c + n);
                //'{' is one unit in front of 'z' in ASCII chart.
                cShift = '{' - remainder;
            }
            else {
                cShift = c + n;
            }
        }
        //uppercase letters
        if ((c >= 'A') && (c <= 'Z')) {

            //shifted char must be between A - Z, so updating n with % 26 will ensure that the int variable remainder will not exceed 26.
            while (abs(n) > 26) {
                n = n % 26;
            }

            if ((c + n) < 'A') {
                //remainder will not be larger than 26 because n cannot be larger than 26.
                int remainder = 'A' - (c + n);
                //'[' is one unit in front of 'Z' in ASCII chart.
                cShift = '[' - remainder;
            }
            else {
                cShift = c + n;
            }
        }
    }

    return cShift;
}


string caesarCipher(string original, int key, bool encrypt) {
    string encryptedMessage = "";
    string decyrptedMessage = "";
    
    if (encrypt == true) {

        //Encryption
        for (int i = 0; i < original.size(); i++) {

            //if char in string original is an alphabetical char.
            if ((original.at(i) >= 'A' && original.at(i) <= 'Z') || (original.at(i) >= 'a' && original.at(i) <= 'z')) {

                //add shifted char to string encryptedMessage.
                encryptedMessage += shiftAlphaCharacter(original.at(i), key);
            }
            else {

                //else (non-alphabetical char) --> simply add that char to string encryptedMessage.
                encryptedMessage += original.at(i);
            }
        }

        return encryptedMessage;
    }

    else if (encrypt == false) {

        //Decryption
        for (int i = 0; i < original.size(); i++) {

            //if char in string original is a capital alphabetical char.
            if (original.at(i) >= 'A' && original.at(i) <= 'Z') {

                //iterate over capital alphabet and call shiftAlphaCharacter on each with given key to find match.
                for (char letter = 'A'; letter <= 'Z'; letter++) {

                    //if match, add letter to decrypted message.
                    if (shiftAlphaCharacter(letter, key) == original.at(i)) {
                        decyrptedMessage += letter;
                    }
                    //else --> no match --> continue looping through capital alphabet to find match.
                }
            }

            //if char in string original is a lowercase alphabetical char.
            else if (original.at(i) >= 'a' && original.at(i) <= 'z') {

                //iterate over lowercase alphabet and call shiftAlphaCharacter on each with given key to find match.
                for (char letter = 'a'; letter <= 'z'; letter++) {

                    //if match, add letter to decrypted message.
                    if (shiftAlphaCharacter(letter, key) == original.at(i)) {
                        decyrptedMessage += letter;
                    }
                    //else --> no match --> continue looping through lowercase alphabet to find match.
                }
            }
            //if char in string original is a non-alphabetical char, simply add it to string decryptedMessage.
            else {
                decyrptedMessage += original.at(i);
            }
        }

        return decyrptedMessage;
    }
}
