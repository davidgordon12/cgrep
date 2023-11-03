#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#include "grep.h"
#include "help.h"

using namespace std;

void WriteLines(string path);
bool MatchLine(string line, string regex);
vector<string> ReadLines(string path);
vector<string> ReadDirectory(string path);

bool process(int argc, string argv[]) {
    switch (argc) {
    case 1:
        // If only one arg was provided, we will search the current directory
        break;
    default:
        break;
    }

    string output;

    return true;
}

vector<string> ReadDirectory(string path) {}

vector<string> ReadLines(string path) {
    using namespace std;

    string line;
    ifstream input;
    input.open("test.txt");

    if (!input.is_open()) {
      perror("Error open");
      exit(EXIT_FAILURE);
    }

    while (getline(input, line)) {
      cout << line << endl;
    }
}

bool MatchLine(string line, string regex) {}

void WriteLines(string path) {}