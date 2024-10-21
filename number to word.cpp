#include <iostream>
#include <string>
using namespace std;

string number(int num){
        switch(num){
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default:
                return "";
        }
}

string tens(int num){
    switch(num){
        case 1: return "fuck shit";
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "sixty";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninenty";
        default:
                return "";
    }
}

string getdigit(string digit){
    int num,pos;
    string position;
    for( size_t i = 0; i < digit.size() ; i++){
        num = digit.at(i) - '0';
        pos = digit.size() - i;
        if (pos == 3){
            position += number(num) + " ";
            position += "hundred ";
        }else if(pos == 1){
            position += number(num) + " ";
        }else{
            position += tens(num) + " ";
        }    
    }
    return position;
}

int main(){

    long long number = 888;
    int length,cut;
    string word;
    string numberstr = to_string(number);
    length = numberstr.size();
    cut = length % 3;
    int numgroups =( cut > 0 ) ? ( length / 3 + 1 ) : ( length / 3 );
    string group[numgroups];
    int index = 0;
    if ( cut > 0 ){
        group[index++] = numberstr.substr( 0 , cut );
    }
    for( int i = cut ; i < length ; i += 3){
        group[index++] = numberstr.substr( i , 3 );
    }
    for(int i = 0 ;i < index ;i++){
       word += getdigit(group[i]) + " ";  
    }
    cout<<word;

    return 0;
}