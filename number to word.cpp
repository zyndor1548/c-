#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string number(int num)
{
    switch (num)
    {

    case 0:
        return "Zero";
    case 1:
        return "one";
    case 2:
        return "two";
    case 3:
        return "three";
    case 4:
        return "four";
    case 5:
        return "five";
    case 6:
        return "six";
    case 7:
        return "seven";
    case 8:
        return "eight";
    case 9:
        return "nine";
    default:
        return "";
    }
}

string teens(int num)
{
    switch (num)
    {
    case 0:
        return "ten";
    case 1:
        return "eleven";
    case 2:
        return "twelve";
    case 3:
        return "thirteen";
    case 4:
        return "fourteen";
    case 5:
        return "fifteen";
    case 6:
        return "sixteen";
    case 7:
        return "seventeen";
    case 8:
        return "eighteen";
    case 9:
        return "nineteen";
    default:
        return "";
    }
}

string tens(int num)
{
    switch (num)
    {
    case 2:
        return "twenty";
    case 3:
        return "thirty";
    case 4:
        return "forty";
    case 5:
        return "fifty";
    case 6:
        return "sixty";
    case 7:
        return "seventy";
    case 8:
        return "eighty";
    case 9:
        return "ninety";
    default:
        return "";
    }
}

string getdigit(string digit)
{
    int num, pos;
    string position;
    for (size_t i = 0; i < digit.size(); i++)
    {
        num = digit.at(i) - '0';
        pos = digit.size() - i;
        if (pos == 3)
        {
            position += number(num) + " ";
            position += "hundred ";
        }
        else if (pos == 1)
        {
            position += number(num) + " ";
        }
        else
        {
            if (num == 1)
            {
                position += teens(digit.at(i + 1) - '0') + " ";
                break;
            }
            position += tens(num) + " ";
        }
    }
    return position;
}

int main()
{
    cout << "\t#########################################\n";
    cout << "\t#       Number to word converter        #\n";
    cout << "\t#########################################\n";
    cout << "\nThis program will convert any number you input into words.\n";
    cout << "##############################################################\n\n\n";
    long long number;
    int length, cut;
    string word, numberstr;
    do
    {
        cout << "Enter number to change to word (number must be under 1 trillion): ";
        cin >> number;
        numberstr = to_string(number);
    } while (numberstr.length() > 12);
    length = numberstr.size();
    cut = length % 3;
    int numgroups = (cut > 0) ? (length / 3 + 1) : (length / 3);
    string group[numgroups];
    int index = 0;
    if (cut > 0)
    {
        group[index++] = numberstr.substr(0, cut);
    }
    for (int i = cut; i < length; i += 3)
    {
        group[index++] = numberstr.substr(i, 3);
    }
    for (int i = 0; i < index; i++)
    {
        word += getdigit(group[i]);
        if (index == 4 && i == 0)
            word += "billion ";
        if ((index == 4 && i == 1) || (index == 3 && i == 0))
            word += "million ";
        if ((index == 4 && i == 2) || (index == 3 && i == 1) || (index == 2 && i == 0))
            word += "thousand  ";
    }
    if (!word.empty())
    {
        if (number < 0)
        {
            word = "Negative " + word.substr(1);
        }
        else
        {
            word[0] = toupper(word[0]);
        }
    }
    cout << "\nConverted Number: " << word << "\n";
    return 0;
}