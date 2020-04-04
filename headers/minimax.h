#ifndef MINIMAX_H
#define MINIMAX_H
#include <vector>
#include "game.h"

using namespace std;

/**
 * MiniMax
 * @param {State&} s : the state to process the algorithm on
 * @return {Action} : the action to play
 */
Action miniMaxDecision(State s, vector<vector<bool>> &winningPositions);

/**
 *
 * @param {State&} s : the state to process on
 * @return {int} : the value corresponding to @TOCOMPLETE ???
 */
int max_value(State s, vector<vector<bool>> &winningPositions);

/**
 *
 * @param {State&} s : the state to process on
 * @return {int} : the value corresponding to @TOCOMPLETE ???
 */
int min_value(State s, vector<vector<bool>> &winningPositions);

#endif
