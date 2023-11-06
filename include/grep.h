#ifndef _GREP_H
#define _GREP_H

#include <vector>

class Grep {
  public:
    bool Process(int argc, std::string argv[]);

  private:
    void ProcessFile();
    void ProcessDir();
    std::vector<std::string> ReadDirectory(std::string path);
    std::vector<std::string> ReadLines(std::string path);
    bool MatchLine(std::string line, std::string regex);
    void WriteLines(std::string path);
};

#endif