 #include<iostream>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

// Function to check if a string represents an integer (i.e., each character is a digit)
bool isInteger(const string& word) {
    for(char ch : word) {
        if(!isdigit(ch))
            return false;
    }
    return true;
}

int main() {
    // Taking file name from the user
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename);

    if(!file.is_open()) {
        // If file doesn't exist or cannot be opened
        cout << "File cannot be opened.";
        return 1; // Exit the program indicating failure
    }
    else {
        int lines = 0, chars = 0, digits = 0, letters = 0, punctuations = 0, words = 0, integers = 0;

        char ch;

        // Reading character by character
        while(file.get(ch)) {
            // Characters
            chars++;

            // Lines 
            if(ch == '\n')
                lines++;

            // Digits
            if(isdigit(ch))
                digits++;

            // Letters
            if(isalpha(ch))
                letters++;

            // Punctuations
            if(ispunct(ch))
                punctuations++;
        }

        // Reset the file pointer to the beginning of the file for word count
        file.clear();
        file.seekg(0, ios::beg);

        string word;

        // Reading word by word
        while(file >> word) {
            // Words
            words++;

            // Integers
            if(isInteger(word))
                integers++;
        }
        
        // Printing final values
        cout << "LINES: " << lines << endl;
        cout << "CHARS: " << chars << endl;
        cout << "DIGITS: " << digits << endl;
        cout << "LETTERS: " << letters << endl;
        cout << "PUNCTUATIONS: " << punctuations << endl;
        cout << "WORDS: " << words << endl;
        cout << "INTEGERS: " << integers << endl;
        
        file.close(); // Close the file when done
    }

    return 0;
} 