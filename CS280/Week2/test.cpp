#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string filename;
    ifstream myFile;
    
    cout << "Enter the name of a file to read from: " << endl;
    cin >> filename;
    
    
    myFile.open(filename.c_str());
    
    if(!myFile){
        cerr << endl;
        cerr << "File cannot be opened " << filename << endl;
        exit(1);
    }
    
    cout << endl;
    
    string text;
    string max_word;
    string max_line;
        
    int total_lines = 0;
    int non_comm_lines = 0;
    int num_words = 0;
    
    while(getline(myFile, text) && !myFile.eof()){
        total_lines += 1;
        if(text.substr(0,2) != "//" && text.substr(0,1) != "#"){
            non_comm_lines += 1;
            if(text.length() > max_line.length()){
                max_line = text;
            }
            istringstream sloop(text);
            
            do{
                string word;
                sloop >> word;
                if(word.length() > max_word.length()){ max_word = word; }
                if(word.find_first_not_of(' ') != std::string::npos){ num_words += 1;}

            } while (sloop);

        }

        
    }
    
    cout << "Total Number of Lines: " << total_lines << endl;
    cout << "Number of non-commented lines: " << non_comm_lines << endl;
    cout << "Line of Maximum Length: \"" << max_line << "\"\n";
    cout << "Number of Words: " << num_words << endl;
    cout << "Word of Maximum Length: \"" << max_word <<  "\"\n";
    
    myFile.close();
    
    return 0;
}