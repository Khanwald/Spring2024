#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split_string(string line) {
    stringstream ss(line);

    vector<string> words;

    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main()
{
    string filename;
    cout << "Enter the name of a file to read from: \n";
    getline(cin, filename);

    fstream file(filename, ios::in);

    if (!file) {
        cerr << "\nFile cannot be opened " << filename << endl;
        return EXIT_FAILURE;
    }

    int line_count = 0;
    int commented_line_count = 0;
    int word_count = 0;
    string line;
    string max_line = "";
    string max_word = "";

    while (getline(file, line)) {

        if ((line.length() > 0 && line[0] == '#') || (line.length() > 1 && line[0] == '/' && line[1] == '/')) {
            ++commented_line_count;
        }
        else {
            if (line.length() > max_line.length()) {
                max_line = line;
            }
            vector<string> words = split_string(line);

            for (auto word : words) {
                if (word.length() > max_word.length()) {
                    max_word = word;
                }
            }

            word_count += words.size();
        }

        ++line_count;
    }

    file.close();

    cout << "\nTotal Number of Lines: " << line_count;
    cout << "\nNumber of non-commented lines: " << line_count - commented_line_count;
    cout << "\nLine of Maximum Length: \"" << max_line << "\"";
    cout << "\nNumber of words: " << word_count;
    cout << "\nWord of Maximum Length: \"" << max_word << "\"\n";
    

    return 0;
}