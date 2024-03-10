// FCAI _ Structured Programming _ 2024_Assignment2

// program name:CS112_A2_T2_S17&18_20230221_20230285_20230033.cpp

//Program Description: This program works to encrypt and decrypt text as well so that only these we want to understand can understand them

// Last Modification Date:9/3/2023

// Author1 and ID and Group:Abdelrahaman yasser _ 20230221 _ B 
 
// Author2 and ID and Group:Ahmed mohamed _ 20230033 _ B

// Author3 and ID and Group:Fatma Hashim Mohammed _ 20230285 _ B

// Teaching Assistant: Ahmed lotfy S 17&18

// Who did what  Abdelrahaman yasser created Route cipher_Ahmed mohamed created Vignere Cipher_fatma hashim created  Simple Substitution Cipher

#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <algorithm>
# include<limits>
using namespace std;
int choice;
int choice1;
string text,key,keyWord;
//Start of simple substitution cipher
string alphabet = "abcdefghijklmnopqrstuvwxyz";

//Funcion to build cipher alphabet using the given key
string CipherAlphabet(const string& key)
{
    string cipherAlphabet = key;

    // Loop through each character in the alphabet if it's not found in the key, add it to the cipher alphabet.
    for (char c : alphabet)
    {
        if (key.find(c) == string::npos)
        {
            cipherAlphabet += c;
        }
    }
    return cipherAlphabet;
}


// Function to encrypt a string using the given key
string encrypt(const string& text, const string& key)
{
    // Build the cipher alphabet using the given key
    string cipherAlphabet = CipherAlphabet(key);
    string encryptedText;

    // Loop through each character in the text
    for (char c : text)
    {
        if (isalpha(c))
        {
            char lowerC = isupper(c) ? tolower(c) : c;

            char encryptedChar = cipherAlphabet[alphabet.find(lowerC)];

            encryptedText += encryptedChar;
        }
        else {
            encryptedText += c;
        }
    }
    return encryptedText;
}


// Function to decrypt a string using the given key
string decrypt(const string& cipherText, const string& key)
{
    // Build the cipher alphabet using the given key
    string cipherAlphabet = CipherAlphabet(key);
    string decryptedText;

    // Loop through each character in the cipher text
    for (char c : cipherText)
    {
        if (isalpha(c))
        {
            char lowerC = isupper(c) ? tolower(c) : c;

            char decryptedChar = alphabet[cipherAlphabet.find(lowerC)];

            decryptedChar = isupper(c) ? toupper(decryptedChar) : decryptedChar;

            decryptedText += decryptedChar;
        }
        else {
            decryptedText += c;
        }
    }
    return decryptedText;
}

//end of simple substitution cipher

// start of route cipher
// Function to delete anything other than letters
string ignoreNunAlpha(string text)
{
    string newText;
    for (int i=0;i<text.size();i++){
        if (isalpha(text[i])){
            newText+=text[i];
        }
        else{
            continue;
        }
    }
    return newText;
}
// Function of converting lowercase letters to uppercase
string convertToUpper(string text){
    string newtext;
    for (int i=0;i<text.size();i++){
        if (islower(text[i])){
         newtext+=char(toupper(text[i]));
        }
        else{
            newtext+=text[i];
        }

    }
    return newtext;
}
// Function to avoid incorrect number of columns  Encryption
int validationColumns() {
    int  ncolumns;
    while (true) {
        cout << "=====================" << endl;
        cout << "Enter the key: ";

        cin >> ncolumns;

        if (cin.fail() ) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid number " << endl;
            continue;
        }
        string text1 = ignoreNunAlpha(convertToUpper(text));
        if (ncolumns>=1 && ncolumns <= int(0.5 * text1.size())) {
            break;
        } else {
            cout << "Invalid number. Please enter a valid number less than or equal to half the size of the text." << endl;
            continue;
        }
    }
    return ncolumns;
}
void Encryption(string text){
    int count =0;
    double nrows;
    count = text.size() ;
    int ncolumns= validationColumns();
    //calculate the number of rows
    nrows=double(count)/ncolumns;
    //Avoid getting a number that is less than the number of letters in the text
    nrows= ceil(nrows);
    //create a matrix
    char matrix[int(nrows)][ncolumns] ;
    int m = 0 ;
    //Enter text into the matrix
    for (int i=0;i<nrows;i++){
        for(int j=0;j<ncolumns;j++){
            if (m<text.size()){
                matrix[i][j]=text[m];
                m++;
            }
            else 
            {
                //If the number of letters in the word has expired and the number of rows is not full
                matrix[i][j] = 'X';
            }

        }
    }
    //Obtain the desired spiral shape
    string result;
    int left=0,bottom=int(nrows)-1;
    int top=0,right=ncolumns-1;
    while (top<=bottom&&left<=right){
        for (int i=top;i<=bottom;i++){
            result+=matrix[i][right];
        }
        right--;
        if (top<=bottom){
            for (int i=right;i>=left;i--){
                result+=matrix[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for (int i=bottom;i>=top;i--){
                result+=matrix[i][left];
            }
            left++;
        }
        for (int i=left;i<=right;i++){
            result+=matrix[top][i];
        }
        top++;
    }
    cout<<"====================="<<endl;
    cout <<"Encryption result  :"<<result<<endl;
    cout<<"====================="<<endl;
}
void Decryption(string text){
    int count =0;
    double rows;
    count = text.size() ;
    int colums= validationColumns();
    //calculate the number of rows
    rows=double(count)/colums;
    //Avoid getting a number that is less than the number of letters in the text
    rows= ceil(rows);
    //create a matrix
    char matrix[int(rows)][colums];
    int count1=0;
    // Fill the matrix
    string result;
    int left=0,bottom=int(rows)-1;
    int top=0,right=colums-1;
    while (top<=bottom&&left<=right){
        for (int i=top;i<=bottom;i++){
            matrix[i][right]=text[count1];
            count1++;
        }
        right--;
        if (top<=bottom){
            for (int i=right;i>=left;i--){
                matrix[bottom][i]=text[count1];
                count1++;
            }
            bottom--;
        }
        if(left<=right){
            for (int i=bottom;i>=top;i--){
                matrix[i][left]=text[count1];
                count1++;
            }
            left++;
        }
        for (int i=left;i<=right;i++){
            matrix[top][i]=text[count1];
            count1++;
        }
        top++;
        if (count1==text.size()){
            break;
        }
    }
    //Assemble the array so that the word is obtained before encryption
    for (int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
            result+=matrix[i][j];
        }
    }
    cout<<"====================="<<endl;
    cout <<"Decryption result  :"<<result<<endl;
    cout<<"====================="<<endl;
}
// end of route cipher
// start of vignere cipher
void encryption_vignere(string text , string keyWord)
{
   // Store Data
   string Result = "";
   // to check if message size 80 or more letters
   while (true)
   {
    
    if (text.length() < 81 )
    {
      break;
    }
    else
    {
      cout << "*Error* Please Enter 80 Characters at most : ";
    }
    getline(cin,text);
    
   }
   // to check if keyword size 8 or more letters
   while (true)
   {
    
    
    if (keyWord.length() < 9)
    {
      break;
    }
    else
    {
      cout << "*Error* Please Enter 8 Characters at most : ";
    }
    getline(cin,keyWord);
   }
   // to upper letters 
   for (int i = 0; i < text.length(); i++)
   {
    text[i] = toupper(text[i]);
   }
   for (int i = 0; i < keyWord.length(); i++)
   {
    keyWord[i] = toupper(keyWord[i]);
   }
   // to repeat the  key depends on message length
   string map_key = "";
   for (int i = 0 ,j =0 ; i < text.length(); i++)
   {
    if (j < keyWord.length())
    {
      map_key += keyWord[j];
      j++;
    }
    else
    {
      j = 0;
      map_key += keyWord[j];
      j++;
    }
    
   }
   // to check if char is digit , space , special character and calcaulate the new char 
   for (int i = 0 , j = 0; i < text.length(); i++)
   {
    if (isspace(text[i]) || isdigit(text[i]) || ispunct(text[i])) 
    {
      Result +=text[i];
      j++;
    }
    else
    {
      if (j < map_key.length())
      {
        int num = (abs(int(text[i]) + int(map_key[j]))) % 26;
        num +=65;
         char value = char(num);
         Result += value;
         j++;
      }
      
    }
    
   }
   cout << " your encrypted message is " << Result << endl;

}
void decryption_vignere(string text,string keyWord)
{
  // Store Data
  string Result = "";
  // to check if message size 80 or more letters
   while (true)
   {
    if (text.length() < 81 )
    {
      break;
    }
    else
    {
      cout << "*Error* Please Enter 80 Characters at most : ";
    }
    getline(cin,text);

   }
   cout << "Please Enter KeyWOrd Message((8 characters at most)) :\n";
   // to check if keyword size 8 or more letters
   while (true)
   {
    
    
    if (keyWord.length() < 9)
    {
      break;
    }
    else
    {
      cout << "*Error* Please Enter 8 Characters at most : ";
    }
    getline(cin,keyWord);
   }
    // to upper letters 
   for (int i = 0; i < text.length(); i++)
   {
    text[i] = toupper(text[i]);
   }
   for (int i = 0; i < keyWord.length(); i++)
   {
    keyWord[i] = toupper(keyWord[i]);
   }
   // to repeat the  key depends on message length
   string map_key = "";
   for (int i = 0 ,j =0 ; i < text.length(); i++)
   {
    if (j < keyWord.length())
    {
      map_key += keyWord[j];
      j++;
    }
    else
    {
      j = 0;
      map_key += keyWord[j];
      j++;
    }
    
   }
   // to check if char is digit , space , special character and calcaulate the maain char
   for (int i = 0 , j = 0; i < text.length(); i++)
   {
    if (isspace(text[i]) || isdigit(text[i]) || ispunct(text[i])) 
    {
      Result += text[i];
      j++;
    }
    else
    {
      if (j < map_key.length())
      {
        int num = abs(int(text[i])-65);
        int main_letter = 0;
        for (int x = 0; x < 26 ; x++)
        {
          if ((x+65+int(map_key[j])) % 26 == num)
          {
            main_letter = x + 65;
          }
        }
        main_letter = char(main_letter);
        Result += main_letter;
        j++;
        
      }
      
    }
   }  
   cout<<"your decrypted message is " <<Result<<endl;
}

void menu()
{
    do
    {
        cout << "Ahlan ya user ya habibi" << endl;
        cout << "What would you like to do today?" << "\n";
        cout << "1) Cipher a massage\n" << "2) Decipher a massage\n" << "3) End" << endl;
        cin >> choice;
        // Manually check if the input is an integer
        bool validInput = false;
        while (!validInput)
        {
            if (cin.fail())
            {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number: ";
                // Prompt the user to enter their choice again
                cin >> choice;
            }
            else
            {
                validInput = true;
            }
        }

        switch (choice)
        {
        case 1:
            cout << "please enter the message to cipher:" << endl;
            cin.ignore(); // Ignore the newline character from the previous input
            getline(cin, text);

            cout << "Which Cipher would you like to choose" << endl;
            cout << "1) Route Cipher\n" << "2) Vignere Cipher\n" << "3) Simple Substitution Cipher\n" << "4) Return\n";
            cin >> choice1;

            switch (choice1)
            {
            case 1:
                cout << "welcome to the Route Cipher " << endl;
                Encryption(ignoreNunAlpha(convertToUpper(text)));
                break;

            case 2:
                cout << "welcome to the Vignere Cipher " << endl;
                cout << "Please Enter KeyWOrd Message((8 characters at most)) :\n";
                cin>> keyWord;
                encryption_vignere(text,keyWord);
                break;

            case 3:
                cout << "welcome to the Simple Substitution Cipher " << endl;
                cout << "Please, enter the key: ";
                cin >> key;
                transform(key.begin(), key.end(), key.begin(), ::tolower);
                cout << "Your encrypted message is: " << encrypt(text, key) << endl;
                break;

            case 4:
                continue;
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
            }
        case 2:
            cout << "please enter the massage to Decipher:" << endl;
            cin.ignore(); // Ignore the newline character from the previous input
            getline(cin, text);

            cout << "Which Cipher would you like to choose" << endl;
            cout << "1) Route Cipher\n" << "2) Vignere Cipher\n" << "3) Simple Substitution Cipher\n" << "4) Return\n";
            cin >> choice1;

            switch (choice1)
            {
            case 1:
                cout << "welcome to the Route Cipher " << endl;
                Decryption(ignoreNunAlpha(convertToUpper(text)));
                break;

            case 2:
                cout << "welcome to the Vignere Cipher " << endl;
                cout << "Please Enter KeyWOrd Message((8 characters at most)) :\n";
                cin>> keyWord;
                decryption_vignere(text,keyWord);
                break;

            case 3:
                cout << "welcome to the Simple Substitution Cipher " << endl;
                cout << "Please, enter the key: ";
                cin >> key;
                transform(key.begin(), key.end(), key.begin(), ::tolower);
                cout << "Your decrypted message is: " << decrypt(text, key) << endl;
                break;

            case 4:
                continue;
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
            }
        }
    } while (choice != 3);

    cout << "Thanks you for using my program!" << endl;
}

int main()
{
    menu();
    return 0;
}