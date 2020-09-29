 #include <iostream>
 #include <fstream>
 #include <ctype.h>

using namespace std;

 void informationBlock(){
    cout <<"Makers: Jennifer Lee and Rachel Dijkstra" << endl;
    cout <<"Year of arrival: 2020" << endl;
    cout <<"Field of study: Artificial intelligence" << endl;
    cout <<"Student number: s2972913 and s2882043" << endl;
    cout <<"Assignment 2: DeCoderen" << endl;
    cout <<"Date: 29-09-2020\n" << endl;
    cout <<"-----------------------------------------------------------" << endl;
}

void startBeginningOfFile(ifstream & invoer){
    invoer.clear( );
    invoer.seekg( 0, std::ios::beg );
}

int countDe (ifstream & invoer){
    startBeginningOfFile(invoer);

    char kar = invoer.get ( );
    char prevKar = '\n';
    int i = 0; // locale teller

    while( !invoer.eof()){
        if(prevKar == 'd' && kar == 'e'){
            i++;
        }
        prevKar = kar;
        kar = invoer.get();
    }
    return i;
}

int countChar(ifstream & invoer, ofstream & uitvoer){
    startBeginningOfFile(invoer);

    char kar = invoer.get ( );
    int i = 0;
    int number = 0;
    int lastNumber = 0;
    while( !invoer.eof ( )){
        uitvoer.put(kar);
        if(isdigit(kar)){
            number = kar - '0';
            if(lastNumber != 0){
                number = (lastNumber * 10) + number;
            }
            lastNumber = number;
        }else{
            cout << kar;
            if(lastNumber != 0){
                cout << lastNumber * lastNumber;
            }
            lastNumber = 0;
        }
        kar = invoer.get();
        i++;
    }
    return i;
}

int numberReverse(int number){
    int reversedNumber = 0;
    while(number > 0){
        reversedNumber = (reversedNumber * 10) + (number %10);
        number = number/10;
    }
    return reversedNumber;
}


   int main ( ) {
    ifstream invoer("invoer.txt", ios::in);
    ofstream uitvoer("uitvoer.txt", ios::out);

    int totalChars = countChar(invoer, uitvoer);
    int totalDe = countDe(invoer);

    invoer.close();
    uitvoer.close();
    cout << endl << "Count total characters: " << totalChars << endl;
    cout << "Count total 'de': " << totalDe << endl;

    cout << numberReverse(5823);
     return 0;
   }//main
