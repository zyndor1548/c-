#include <iostream>
#include <string>
using namespace std;

string getdigit(int digit){
    switch(digit){
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
                break;
    }
}

string getposition(int digit,int pos){
    string position;
    switch(pos){
        case 12:
        case 11:
        case 10:
                position += getdigit(digit) + " ";
                position += "billion";
                break;
        case 9:
        case 8:
        case 7:
                position += getdigit(digit) + " ";
                position += "million";
                break;
        case 6:
        case 5:
        case 4:
                position += getdigit(digit) + " ";
                position += "thousand";
                break;
        case 3:
                position += getdigit(digit) + " ";
                position += "hundred";
                break;
        default:
            break;       
    }
    return position;
}

int main(){

    long long number = 9900000000,digit,pos;
    string numberStr = to_string(number),word;
    for( size_t i = 0; i < numberStr.size() ; i++){
        digit = numberStr.at(i) - '0';
        pos = numberStr.size() - i;
        if (digit != 0) {
            word += getposition(digit, pos) + " ";
        }
    }
    cout<<word;

    return 0;
}