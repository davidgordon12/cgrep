#ifndef _GREP_H
#define _GREP_H

#include <vector>

class Grep {
  public:
    bool process(int argc, std::string argv[]);

  private:
    void processFile();
    void processDir();
    std::vector<std::string> ReadDirectory(std::string path);
    std::vector<std::string> ReadLines(std::string path);
    bool MatchLine(std::string line, std::string regex);
    void WriteLines(std::string path);
};

#endif