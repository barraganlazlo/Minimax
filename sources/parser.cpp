#include "parser.h"

using namespace std;

inline void removeCharFromString( string &str, char charToremove)
{
  for(unsigned int i=0; i < str.size(); ++i){
    if(str[i]==charToremove){
      str.erase(i,1);
      i--;
    }
  }
}

bool parseWinningPositions(char * filePath, vector<vector<int>> &winningPositions)
{
  string line;
  ifstream myfile;
  myfile.open(filePath);

  if (myfile.is_open()) {

    vector<vector<bool>> winningPositions;
    int winingPosition_id=0;
    while (getline (myfile, line)) {
      removeCharFromString(line, ' ');
      cout << line << endl;
      winningPositions.push_back(vector<bool>());
      for(unsigned int i = 0; i < line.size(); i += 2){
        winningPositions[winingPosition_id].push_back(line[i] != '0');
      }
      winingPosition_id++;
    }
    myfile.close();
    return true;
  }

  return false;
}
