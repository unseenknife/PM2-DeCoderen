// Auteur: Rachel Dijkstra en Jennifer Lee
// Bestand: DijkstraEnLee2.cc
// Wat doet het programma:
//
// Compiler/programma: Code::Blocks
// Laatst bewerkt: 06-10-2020

#include <iostream>
#include <fstream>
#include <ctype.h>

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
    cout <<"Date: 05-10-2020\n" << endl;
    cout <<"-----------------------------------------------------------" << endl;
}

/**
* Questions to the user
*/
void userQuestions(char & answer, string & inputName, string & outputName){
    cout << "Do you want to encode or decode?" << endl;
    cout << "1. encode" << endl;
    cout << "2. decode" << endl;
    cin >> answer;

    cout << "What is the name of your input file (whole file name): ";
    cin >> inputName;

    cout << "What for name do you want for your output file: ";
    cin >> outputName;
}

/**
* Set an input file to the beginning
*
* @param input, an ifstream argument
*/
void startBeginningOfFile(ifstream & input){
    input.clear( );
    input.seekg( 0, std::ios::beg );
}

/**
* Reverse the given number
*
* @param number, an integer argument
* @return the reversed number
*/
int numberReverse(int number){
    int reversedNumber = 0;
    while(number > 0){
        reversedNumber = (reversedNumber * 10) + (number %10);
        number = number/10;
    }
    return reversedNumber;
}

/**
* Looks if a number is a palindrome
*
* @param number, an integer argument
* @return bool if number is a palindrome
*/
bool isPalindrome(int number){
    return (number == numberReverse(number));
}

/**
* Get the numbers of the input file and checks if they're lychrel numbers
*
* @param input, an input file
* @return bool if number is a palindrome
*/
bool isLychrel(int number){
    int temp = number;
    int reversedNumber;
    for(int i = 0; i < 500; i++){
        reversedNumber = numberReverse(temp);
        if(isPalindrome(reversedNumber + number)){
            return false;
        }
        temp = temp + reversedNumber;
    }
    return true;
}

/**
* Get the numbers of the input file and checks if they're lychrel numbers
*
* @param input, an input file
*/
void getNumbers(ifstream & input){
    startBeginningOfFile(input);

    char kar = input.get();
    int number = 0;
    int lastNumber = 0;

    while(!input.eof()){
        if('0' <= kar && kar <= '9'){
            number = kar - '0';
            if(lastNumber != 0){
                lastNumber = (lastNumber * 10) + number;
            }
            else{
                lastNumber = number;
            }
        }
        else{
            if(lastNumber != 0 && isLychrel(lastNumber)){
                cout << lastNumber << " is a Lychrel number" << endl;
            }
            lastNumber = 0;
        }
        kar = input.get();
    }
}

int main ( ) {
    char answer; string inputName; string outputName;
    informationBlock();

    userQuestions(answer, inputName, outputName);
    ifstream input(inputName, ios::in);
    ofstream output(outputName, ios::out);

    getNumbers(input);

    input.close();
    output.close();
    return 0;
}//main
