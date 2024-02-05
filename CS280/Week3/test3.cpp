#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <cstdio>
using namespace std;

bool int_check(string word){
    for (int i = 0; i < word.length(); ++i) { 
        if(!isdigit(word[i])){return false;}
    } 
    return true;
}

int main(int argc, char* argv[]) {
    ifstream myFile;
    string a = "23434";
    bool check = int_check(a);
    myFile.open("infile3");
    string text;
    int num_ints = 0;
    while(getline(myFile, text) && !myFile.eof()){

        istringstream sloop(text);
            
        do{
            string word;
            sloop >> word;
            cout <<word<<endl;
            if(int_check(word) && word.find_first_not_of(' ') != std::string::npos){
                cout << word << endl;
                num_ints += 1;
            }

        } while (sloop);
    }
    cout << num_ints <<endl;
    num_ints = 0;
    switch (num_ints){
        case 0 ... 1: cout << 23;
    }
}