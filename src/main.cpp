#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
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