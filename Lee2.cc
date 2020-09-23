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

void verwerkgetal(int number){
    cout << number * number;
}

   int main ( ) {
    ifstream invoer("invoer.txt", ios::in);
    ofstream uitvoer("uitvoer.txt", ios::out);

    char kar = invoer.get ( );
    int i = 0;
    int number = 0;
    int lastNumber = 0;
    char lastKar;
    int countDe = 0;
    while( !invoer.eof ( )){
        uitvoer.put(kar);
        if(lastKar == 'd'){
            if(kar == 'e'){
                countDe++;
            }
        }
        if(isdigit(kar)){
            number = kar - '0';
            if(lastNumber != 0){
                number = (lastNumber * 10) + number;
            }
            lastNumber = number;
        }else{
            cout << kar;
            if(lastNumber != 0){
                verwerkgetal(lastNumber);
            }
            lastNumber = 0;
        }
        lastKar = kar;
        kar = invoer.get();
        i++;
    }
    invoer.close();
    uitvoer.close();
    cout << endl << "Count total 'de': " << countDe << endl;
    cout << "Count characters: " << i;

     return 0;
   }//main
