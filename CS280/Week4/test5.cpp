#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>


using namespace std;
// Caleb Osorio CS280-004

bool checkCommand(string command, char *list[], int max){
    for(int i = 0; i < max; i++ ){
        string name(list[i]);
        if(name == command){
            return true;
        }
    }
    return false;
}

void mapLoop(map<char, int> mapA, string typeB){
    int highestNum = 0;
    char letter;
    for (std::map<char, int>::iterator i = mapA.begin(); i != mapA.end(); i++)
    {
        if(i->second > highestNum){
            highestNum = i->second;
            letter = i->first;
        }
    }

    cout << typeB << " of Largest number of occurrences: " << letter << " occurred " << highestNum<< " times\n";
}
void printMap(map<char, int> mapA, string type){
    cout<< "List of " << type << " seen in the file and their number of occurrences:" <<endl;
    for (std::map<char, int>::iterator i = mapA.begin(); i != mapA.end(); i++){
        cout<< i->first <<": " << i->second <<endl <<endl;
    }
}

int main(int argc, char* argv[]) {
    
    if(argc == 1){
        cerr << "NO SPECIFIED INPUT FILE NAME." <<endl;
        exit(1);
    }
    
    ifstream myFile;
    string filename(argv[1]);
    myFile.open(filename.c_str());
    
    if(!myFile){
        cerr << "CANNOT OPEN THE FILE: " << filename <<endl;
        exit(1);
    }
    else if(myFile.peek() == EOF){
        cout << "File is empty." <<endl;
        exit(1);
    }
    
    string text;
    map <char, int> letters;
    map <char, int> numbers;
    map <char, int> puncutation;

    while(getline(myFile, text) && !myFile.eof()){
        istringstream sloop(text);
        
        do{
            string word;
            sloop >> word;
           
            if(word.find_first_not_of(' ') != std::string::npos){
                for (auto &ch : word) { 
                    if(isalpha(ch)){
                        if(letters.find(toupper(ch)) == letters.end()){
                            letters[toupper(ch)] = 1;
                        }
                        else{
                            letters[toupper(ch)] += 1;
                        }
                    }
                    else if(isalnum(ch)){
                        if(numbers.find(ch) == numbers.end()){
                            numbers[ch] = 1;
                        }
                        else{
                            numbers[ch] += 1;
                        }
                    }
                    else if(ispunct(ch)){
                        if(puncutation.find(ch) == puncutation.end()){
                            puncutation[ch] = 1;
                        }
                        else{
                            puncutation[ch] += 1;
                        }
                    }
                } 
            }
        } while (sloop);
    }
    myFile.close();
    if(!letters.empty()){
        mapLoop(letters, "Letter");
    }
    if(!numbers.empty()){
        mapLoop(numbers, "Digits");
    }
    if(!puncutation.empty()){
        mapLoop(puncutation, "Punctuations");
    }

    if(argc > 2){
        if(checkCommand("-all", argv, argc)){
            printMap(letters, "Letters");
            printMap(numbers, "Digits");
            printMap(puncutation, "Punctuations");
        }
        if(checkCommand("-L", argv, argc) && !letters.empty()){
            printMap(letters, "Letters");
        }
        if(checkCommand("-D", argv, argc) && !numbers.empty()){
            printMap(numbers, "Digits");
        }
        if(checkCommand("-P", argv, argc) && !puncutation.empty()){
            printMap(puncutation, "Punctuations");
        }
    }
    exit(1);
    
}