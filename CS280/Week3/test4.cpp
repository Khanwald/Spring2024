#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool int_check(string word){
    for (auto &ch : word) { 
        if(!isdigit(ch)){return false;}
    } 
    return true;
}

bool name_check(string word){
    if(!isalpha(word[0])){return false;}
    for (auto &ch : word) { 
        if(!isalnum(ch) && ch != '@' && ch != '_')  {return false;}
    } 
    return true;
}
int main(int argc, char* argv[]) {
    
    
    ifstream myFile;
    string filename = "infile5";
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
    int total_lines = 0;
    int non_blank_lines = 0;
    int num_words = 0;
    int num_ints = 0;
    int num_names = 0;
    int less_five = 0;
    int greater_five = 0;
    
    
    while(getline(myFile, text) && !myFile.eof()){
        ++total_lines;
        istringstream sloop(text);
            
        do{
            string word;
            sloop >> word;
            if(word.find_first_not_of(' ') != std::string::npos){
                num_words += 1; 
                
                if(name_check(word)){
                    cout << word <<endl;
                    ++num_names;
                }
                else if(int_check(word)){
                    ++num_ints;
                }
                
                if(word.length() > 5){
                    ++greater_five;    
                }
                else{
                    ++less_five;
                }
 
            }

        } while (sloop);
    }
    cout << "Total Number of Lines: " << total_lines << endl;
    cout << "Number of non-blank lines: " << non_blank_lines << endl;
    cout << "Number of Words: " << num_words << endl;
    cout << "Number of Integers: " << num_ints << endl;
    cout << "Number of Names: " << num_names <<  endl;
    cout << "Number of Words Less Than or Equal to 5 Characters: " << less_five << endl;
    cout << "Number of Words Greater Than 5 Characters: " << greater_five <<endl;
    exit(1);
    
}