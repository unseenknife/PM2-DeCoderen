// Auteur: Rachel Dijkstra en Jennifer Lee
// File: DijkstraEnLee2.cc
// What does the program do:
// The programm lets you choose whether you want to encode or
// decode, when you've chosen which one you'd like you enter an input file and tell
// the programm how you want call your output file. After you did this your output
// file will be in your files.
// Compiler/programma: Code::Blocks
// Last edited: 11-10-2020

#include <iostream>
#include <fstream>

using namespace std;

/**
* Information block with the information of the makers
*/
 void informationBlock(){
    cout <<"Makers: Rachel Dijkstra and Jennifer Lee" << endl;
    cout <<"Year of arrival: 2020" << endl;
    cout <<"Field of study: Artificial intelligence" << endl;
    cout <<"Student number: s2882043 and s2972913" << endl;
    cout <<"Assignment 2: DeCoderen" << endl;
    cout <<"Date: 12-10-2020\n" << endl;
    cout <<"-----------------------------------------------------------" << endl;
}//informationBlock

/**
* Questions to the user
*/
void userQuestions(char & answer, string & inputName, string & outputName){
    cout << "Do you want to encode or decode?" << endl;
    cout << "1. encode" << endl;
    cout << "2. decode" << endl;
    cin >> answer;

    cout << "What is the name of your input file: ";
    cin >> inputName;

    cout << "What for name do you want for your output file: ";
    cin >> outputName;
}//userQuestions

/**
* Reverse the given number
*
* @param number, an integer argument
* @param error, an call by reference bool argument
* @return the reversed number
*/
int numberReverse(int number, bool & error){
    int reversedNumber = 0;

    while(number > 0){
        // looks if the reversedNumber is going above INT_MAX or under INT_MIN
        if(reversedNumber > (INT_MAX / 10) - (number %10) ||
           reversedNumber < INT_MIN / 10 - (number %10)){
            error = true;
            return 0;
        }//if
        reversedNumber = (reversedNumber * 10) + (number %10);
        number = number/10;
    }//while
    return reversedNumber;
}//numberReverse

/**
* Looks if a number is a palindrome
*
* @param number, an integer argument
* @param error, an call by reference bool argument
* @return bool if number is a palindrome
*/
bool isPalindrome(int number, bool & error){
    return (number == numberReverse(number, error));
}// isPalindrome

/**
* Get the numbers of the input file and checks if they're lychrel numbers
*
* @param input, an input file
* @return bool if number is a palindrome
*/
bool isLychrel(int number, int & iteration, bool & error){
    int temp = number;
    int reversedNumber;
    // for a sample of iterations till palindrome
    // highest record of iteration till palindrome is 261
    for(int i = 1; i < 500; i++){
        reversedNumber = numberReverse(temp, error);
        if(error){
            cout << number << ": reversing number error" << endl;
            return false;
        }//if
        if(reversedNumber == temp){
            iteration = 0;
            return false;
        }//if
        if((reversedNumber + temp < 0)){
            cout << number << ": reversing number OK, adding up error!" << endl;
            error = true;
            return false;
        }//if
        else{
            if(isPalindrome(reversedNumber + temp, error)){
                iteration = i;
                return false;
            }//if
        }//else
        temp = temp + reversedNumber;
    }//for
    return true;
}// isLychrel

/**
* Get the numbers of the input file and checks if they're lychrel numbers
*
* @param input, an input file
* @param lastNumber, an number that remembers the latest number
* @param iteration, an number that counts the iteration till palindrome
*/
void getNumbers(char kar, int & lastNumber, int & iteration){
    bool error = false;

    if('0' <= kar && kar <= '9'){
        int number = kar - '0';
        if(lastNumber != 0){
            lastNumber = (lastNumber * 10) + number;
        }//if
        else{
            lastNumber = number;
        }//else
    }//if
    else{
        if(lastNumber != 0){
            if(isLychrel(lastNumber, iteration, error)){
                cout << lastNumber << " is a Lychrel number" << endl;
            }//if
            else if(error == false){
                if(iteration == 0){
                    cout << lastNumber << " is a palindrome" << endl;
                }//if
                else{
                    cout << lastNumber << " has " << iteration;
                    cout << " iterations" << endl;
                }//else
            }//else if
        }//if
        lastNumber = 0;
    }//else
}// getNumbers

/**
* Counts backslashes and if backslash counter is higher then 0 puts a backslash
*
* @param k, a character from input file
* @param output, an ofstream argument
* @param backsl, an integer argument, counts number of backslashes
* @return count backslashes before next character
*/
int backSlash(char k, ofstream & output, int & backsl) {
    if(k == '\\'){
        backsl ++;
    }//if
    else {
        if(backsl != 0){
            output.put('\\');
        }//if
        backsl = 0;
    }//else
    return backsl;
}//backslash

/**
* Prints number of repetitions of characters & puts backslash in front of number
*
* @param pv, previous character of input file
* @param k, character of input file
* @param output, an ofstream argument
* @param counter, integer argument, counts repetitions of characters
* @return counter of repetition characters
*/
int countKar(char pv, char k, ofstream & output, int & counter){
    if((pv == k) && (k != '\n')) {
        counter ++;
    }//if
    else {
        if(counter != 1){
            output << counter;
        }//if
        if(('0' <= k) && (k <= '9')) {
            output.put('\\');
        }//if
        counter = 1;
    }//else
    return counter;
}//countKar

/**
* Prints number of repetitions of characters & puts backslash in front of number
*
* @param pv, previous character of input file
* @param k, character of input file
* @param output, an ofstream argument
*/
void put(char pv, char k, ofstream & output){
    if((pv != k) || (k == '\n')) {
        output.put(k);
    }//if
}//uitvoer

/**
* the function decodes a file
*
* @param k, character from input file
* @param pv, previous character from input file
* @param output, an output file
* @param backsl, backslash count an integer argument
* @param lastnumber, integer argument, number behind character that isn't number
* @param lastslashes, a bool argument
*/
void decoding(char k, char pv, ofstream & output, int & backsl,
              int & lastnumber, bool & lastslashes){
    // saves character if character = digit and if previous character isn't digit
    char memory;
    //saves character if previous character is backslash & character is number
    char memorynumber;
    int number = 0;

    if (pv == '\\'){
        backsl ++;
    }//if

    if((pv == '\\') && (k != '\\')){
        lastslashes = true;
    }//if

    if(('0' <= k) && (k <= '9')){
        if(!(('0' <= pv) && (pv <= '9'))){
            memory = pv;
            if(pv == '\\'){
                memorynumber = k;
            }//if
        }//if

        number = k - '0';

        if(lastnumber != 0){
            lastnumber = (lastnumber * 10) + number;
        }//if
        else{
            lastnumber = number;
        }//else
    }//if
    else{
        if(lastslashes){
            if(backsl == 2){
                if(lastnumber == 0){
                    output.put('\\');
                }//if
                else{
                    for(int i = 0; i < lastnumber; i++){
                        output.put('\\');
                    }//for
                }//else
            }//if
            if(backsl == 3){
                output.put('\\');
            }//if
            if(backsl != 2){
                if(lastnumber < 10){
                    output.put(lastnumber + '0');
                }//if
                if((lastnumber > 10) && (lastnumber < 100)){
                    for(int i = 0; i < lastnumber % 10; i++){
                        output.put(memorynumber);
                    }//for
                }//if
                if((lastnumber > 100) && (lastnumber < 1000)){
                    for(int i = 0; i < lastnumber % 100; i++){
                        output.put(memorynumber);
                    }//for
                }//if
                if((lastnumber > 1000) && (lastnumber < 10000)){
                    for(int i = 0; i < lastnumber & 1000; i++){
                        output.put(memorynumber);
                    }//for
                }//if
            }//if
            backsl = 0;
            lastslashes = false;
        }//if

        if(lastnumber != 0){
            for(int i = 0;i < lastnumber - 1 ;i++){
                if(memory != '\\' && !('0' <= memory && memory <= 9)){
                output.put(memory);
                }//if
            }//for
        }//if
        lastnumber = 0;
    }//else

    if((k != '\\') && !(('0' <= k) && (k <= '9'))){
        output.put(k);
    }//if
}//decoding

/**
* Get characters of the input file and decodes or encodes it
*
* @param input, an input file
* @param output, an output file
* @param answer, option of user to encode or decode the file
*/
void getCharacters(ifstream & input, ofstream & output, char answer){

    char kar = input.get();
    char prevKar;

    int lastNumber = 0;
    int iteration = 0; //counts iteration till palindrome
    int counter = 1; //counts repetitions of characters
    int backsl = 0; //counts backslashes that come after each other
    bool lastSlashes = false;


    while(!input.eof()){
        // encode
        if(answer == '1'){
            getNumbers(kar, lastNumber, iteration);
            backSlash(kar,output,backsl);
            countKar(prevKar,kar,output,counter);
            put(prevKar,kar,output);
        }//if

        // decode
        if(answer == '2'){
            decoding(kar, prevKar,output,backsl,lastNumber,lastSlashes);
        }//if
        prevKar = kar;
        kar = input.get();
    }//while
}//getCharacter

int main ( ) {
    char answer; string inputName; string outputName;
    informationBlock();

    userQuestions(answer, inputName, outputName);
    ifstream input(inputName + ".txt", ios::in);
    ofstream output(outputName + ".txt", ios::out);

    getCharacters(input, output, answer);

    input.close();
    output.close();
    return 0;
}//main
