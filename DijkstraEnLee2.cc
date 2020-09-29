 #include <iostream>
 #include <fstream>
 #include <ctype.h>

using namespace std;

 void informationBlock(){
    cout <<"Makers: Jennifer Lee\n";
    cout <<"Year of arrival: 2020\n";
    cout <<"Field of study: Artificial intelligence\n";
    cout <<"Student number: s2972913\n";
    cout <<"Assignment 2: DeCoderen\n";
    cout <<"Date: 22-09-2020\n\n";
    cout <<"-----------------------------------------------------------\n";
}

int telDE (ifstream & invoer){
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

void test(ifstream & invoer, ofstream & uitvoer){
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
}


   int main ( ) {
    ifstream invoer("invoer.txt", ios::in);
    ofstream uitvoer("uitvoer.txt", ios::out);

    int countDe = telDE(invoer);
    test(invoer, uitvoer);

    invoer.close();
    uitvoer.close();
    cout << endl << "Count total 'de': " << countDe << endl;

     return 0;
   }//main
