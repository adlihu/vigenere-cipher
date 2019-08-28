/*Simple Implementation of Vigenere Cipher*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <conio.h>
#include <cmath>

using namespace std;

const string oldAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void prompt(void);
bool checkString(string text);
int findShift(char c);
char encrypt(char inputWord, int shift);
char decrypt(char inputWord, int shift);
string genEncryption(string key, string inputWord);
string genDecryption(string key, string inputWord);

int main(){
	char choice;
	string key;
	string inputWord;
	cout <<"Select an option."<<endl;
	cout <<"1. Encrypt\n"<<"2. Decrypt\n"<<"3. Exit"<<endl;
	choice = getch();
	while(true){
		if (choice == '1' || choice == '2'){break;}
		else if (choice == '3'){exit(1);}
		choice = getch();
	}
	cout <<"Enter a word as a key (Ex: CHAIR)."<<endl;
	cout <<"Your key is: ";
	cin >> key;
	while(true){
		if (checkString(key)){
			break;
		} else {
			cin >> key;
		}
	}
	if (choice == '1'){ cout <<"Enter word to encrypt: ";}
	else {cout <<"Enter word to decrypt: ";}
	cin.get(); //remove \n from buffer
	getline(cin,inputWord);
	if (choice=='1'){cout << "Encrypted Text: "<< genEncryption(key, inputWord) << endl;}
	else {cout << "Decrypted Text: "<< genDecryption(key, inputWord) << endl;}
}

bool checkString(string text){
	for (int i=0;i<text.length();i++){
		if (!isalpha(text[i])){
			return false;
		}
	}
	return true;
}
//Returns the index of where the letter is from the original alphabet
int findShift(char c){
	if (islower(c)){
		c = toupper(c);
	}
	for (int i=0;i<oldAlphabet.length();i++){
		if (c == oldAlphabet[i]){
			return i;
		}
	}
	return 0;
}
//Encrypts a letter according to shift
char encrypt(char inputWord, int shift){
	char c;
	if (isupper(inputWord)){
		c = inputWord+shift;
		if (c > 'Z'){
			c = char(int(c % 90) + 64);
			return c;
		} else {return c;}
	}
	else {
		int temp = inputWord+shift;
		if (temp > 'z'){
			c = char(temp % 122 + 96);
			return c;
		} else {return char(temp);}
	}
}
//Decrypts a letter according to shift
char decrypt(char inputWord, int shift){
	char c;
	if (isupper(inputWord)){
		c = inputWord - shift;
		if (c < 'A'){
			int temp = 65 - int(c);
			c = char(int(91 - temp));
			return c;
		} else {return c;}
	}
	else {
		c = inputWord - shift;
		if (c < 'a'){
			int temp = 97 - int(c);
			c = char(int(123 - temp));
			return c;
		} else {return c;}
	}
}

//Generate vigenere encryption of the words
string genEncryption(string key, string inputWord){
	string res;
	while (true){
		int k = 0;
		for (int i=0;i<inputWord.length();i++){
			if (!isalpha(inputWord[i])){
				res += inputWord[i];
				continue;
			}
			//if k > length of key, go back to pos 0
			if (k > key.length()-1){k = 0;}

			int shift = findShift(key[k]);
			res += encrypt(inputWord[i], shift);
			k++;
		}
		break;
	}
	return res;

}
//Generate vigenere decryption of the words
string genDecryption(string key, string inputWord){
	string res;
	while (true){
		int k = 0;
		for (int i=0;i<inputWord.length();i++){
			if (!isalpha(inputWord[i])){
				res += inputWord[i];
				continue;
			}
			//if k > length of key, go back to pos 0
			if (k > key.length()-1){k = 0;}

			int shift = findShift(key[k]);
			res += decrypt(inputWord[i],shift);
			k++;
		}
		break;
	}
	return res;
}