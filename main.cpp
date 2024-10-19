#include <cstdlib>
#include <iostream>
using namespace std;
int random(int a) { return rand() % a; }
string coinflip() {
  int randomNum;
  string ans;
  randomNum = random(2);
  if (randomNum == 0)
    ans = "heads";
  else
    ans = "tails";
  return ans;
}
void rps() {
  char user, rps;
  string usero, rpso;
  int randomNum;

  cout << "\nThis is a rock paper scissors game\n";
  cout << "\n\tChoose rock paper or scissors by giving r, p, or s "
          "respectively: ";
  cin >> user;

  if (user != 'r' && user != 'p' && user != 's') {
    cout << "\n\t\tInvalid input. Choose from r, p, or s.";
  } else {
    randomNum = random(3);
    if (randomNum == 0)
      rps = 'r';
    else if (randomNum == 1)
      rps = 'p';
    else
      rps = 's';

    if (user == 'r')
      usero = "rock";
    else if (user == 'p')
      usero = "paper";
    else
      usero = "scissors";

    if (rps == 'r')
      rpso = "rock";
    else if (rps == 'p')
      rpso = "paper";
    else
      rpso = "scissors";

    cout << "\n\t\t\tUser = " << usero << "\n\t\t\tSystem = " << rpso;

    if (user == rps)
      cout << "\n\t\t\tDraw";
    else if ((user == 'r' && rps == 's') || (user == 'p' && rps == 'r') ||
             (user == 's' && rps == 'p'))
      cout << "\n\t\t\tYou win";
    else
      cout << "\n\t\t\tSystem wins";
  }
}
void coin() {
  char user;
  string system, guess;
  cout << "\nThis is a coin flip game\n";
  cout << "\n\tIf you want to guess give y if not give n: ";
  cin >> user;
  if (user == 'n') {
    cout << "\n\t\t\tThe coin fliped to " << coinflip();
  } else if (user == 'y') {
    cout << "\n\tChoose heads or tails (h/t): ";
    cin >> guess;
    if (guess == "h")
      guess = "heads";
    else if (guess == "t")
      guess = "tails";
    system = coinflip();
    if (guess == system)
      cout << "\n\t\t\tYou win";
    else
      cout << "\n\t\t\tYou chose " << guess << " and the coin flipped to "
           << system;
  } else
    cout << "\n\t\tInvalid input give h or t ";
}
void dice() {
  int guess = 0, systemNum;
  char user;
  cout << "\nThis is a dice game\n";
  cout << "\n\tIf you want to guess give y if not give n: ";
  cin >> user;
  systemNum = random(6) + 1;

  if (user == 'n') {
    cout << "\n\t\t\tThe dice has shown " << systemNum;
  } else if (user == 'y') {
    cout << "\n\tChoose numbers between 1 to 6 : ";
    cin >> guess;
    if (guess >= 1 && guess <= 6) {
      if (guess == systemNum) {
        cout << "\n\t\t\tYou win";
      } else {
        cout << "\n\t\t\tNot same, The dice has shown " << systemNum;
      }
    } else {
      cout << "\n\t\tInvalid guess. Choose numbers between 1 to 6 .";
    }
  } else {
    cout << "\n\t\tInvalid input. Please enter 1 or 0.";
  }
}
void encrypt() {
  string input, word = "";
  int randomint;
  cout << "\nThis is an encryptor\n";
  cout << "\n\tEnter the sentence to encrypt: ";
  cin.ignore();
  getline(cin, input);
  randomint = random(10) + 1;
  for (char &letter : input) {
    if (isalpha(letter)) {
      char changedletter = letter + randomint;
      if ((islower(letter) && changedletter > 'z') ||
          (isupper(letter) && changedletter > 'Z')) {
        changedletter -= 26;
      }
      word += changedletter;
    } else {
      word += letter;
    }
  }
  cout << "\n\t\tEncrypted sentence: " << word;
  cout << "\n\t\tKey: " << randomint;
}
void decrypt() {
  string input, word = "";
  int key;
  cout << "\nThis is the decryptor\n";
  cout << "\n\tEnter the sentence to decrypt: ";
  cin.ignore();
  getline(cin, input);
  cout << "\n\tKey: ";
  cin >> key;
  if (!isdigit(key)) {
    cout << "\n\t\tInvalid input. Key should be a number.";
  } else {
    for (char &letter : input) {
      if (isalpha(letter)) {
        char changedletter = letter - key;
        if ((islower(letter) && changedletter < 'a') ||
            (isupper(letter) && changedletter < 'A')) {
          changedletter += 26;
        }
        word += changedletter;
      } else {
        word += letter;
      }
    }
    cout << "\n\t\tDecrypted sentence: " << word;
  }
}
int main() {
  string choice;
  char replay;
  do {
    cout << "Welcome\n";
    cout << "\n\tYou want ecryption and decryption or game of chance(l/g) : ";

    cin >> choice;
    if (choice != "l" && choice != "g")
      cout << "\n\t\tInvalid input chose from l or g";
    else if (choice == "l") {
      cout << "\n\t\tYou want to encrypt or decrypt(e/d) : ";
      cin >> choice;
      if (choice == "e")
        encrypt();
      else if (choice == "d")
        decrypt();
      else
        cout << "\n\t\tInvalid input chose from e or d";
    } else {
      cout << "This is game of chance\n";
      cout << "\n\tChoose which you want (rps,coin,dice) : ";
      cin >> choice;
      if (choice != "rps" && choice != "coin" && choice != "dice")
        cout << "\n\t\tInvalid input. Choose from rps, coin, or dice.";
      else if (choice == "rps")
        rps();
      else if (choice == "coin")
        coin();
      else
        dice();
    }
    cout << "\n\n\tDo you want to continue? (y/n): ";
    cin >> replay;
    cout << "\n\n";

  } while (replay == 'y');
  return 0;
}