#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/**
 * parses the file to an array of winningPositions
 * @param {String} filePath
 * @param {vector<vector<int>>&} winningPositions : the array to put the positions on
 */
bool parseWinningPositions(char * filePath, vector<vector<int>> &winningPositions);



#endif
