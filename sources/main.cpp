#include <iostream>
#include <vector>
#include <string>
#include "minimax.h"
#include "parser.h"

#define BUFFER_SIZE 256

using namespace std;

int main(int argc, char* argv[]){

  int parser_arg = 1;
  if(argc !=2){
    cout << "Usage : " <<argv[0] << " filePath "<< endl;
    return -1;
  }
  char filePath[BUFFER_SIZE];
  sscanf (argv[parser_arg],"%s",filePath);

  vector<vector<int>> winningPositions;

  if (!parseWinningPositions(filePath, winningPositions)) cout << "can't open file : " << filePath<< endl;

  int size=winningPositions[0].size();

  State current_state(size);

  




  return 0;
}
