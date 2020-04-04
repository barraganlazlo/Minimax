#include "game.h"

using namespace std;

/**
 * STATE PART
 */

State::State()
{
  this->turn = 0;
  for(int i = 0; i <= 9; i++){
    this->tiles.push_back(-1);
  }
}

State::State(int n)
{
  this->turn = 0;
  for(int i = 0; i <= n; i++){
    this->tiles.push_back(-1);
  }
}
// 
// State::State(State &s)
// {
//   this->turn = s.turn;
//   //Copy values of tiles from s
//   for(unsigned int i = 0; i < s.tiles.size(); i++){
//     this->tiles.push_back(s.tiles[i]);
//   }
// }

/**
 * STATE PART
 */

vector<Action> get_actions(State &s)
{
 vector<Action> actions;
 for(unsigned int i=0;i<s.tiles.size();++i){
   if(s.tiles[i] == EMPTY){
     actions.push_back(Action(i));
   }
 }
 return actions;
}

State result(State s, const Action &a)
{
  s.tiles[a.tile_id] = player(s);
  return s;
}

bool is_terminal_test(State &s, vector<vector<bool>> &winningPositions)
{
  //EQUALITY
  if(s.turn >= s.tiles.size()) return true;
  //SOMEONE WIN
  for(unsigned int p = 0; p < PLAYERS; p++){
    if(playerHaveWinPosition(s, p, winningPositions)) return true;
  }

  return false;
}

bool playerHaveWinPosition(State &s, int p, vector<vector<bool>> &winningPositions)
{
  for(unsigned int c = 0; c < winningPositions.size(); c++){
    if(playerWin(s, p, winningPositions[c])) return true;
  }
  return false;
}

bool playerWin(State &s, int p, vector<bool> &winningPosition)
{
  for(unsigned int i = 0; i < winningPosition.size(); i++){
    if(winningPosition[i] && s.tiles[i] != p) return false;
  }
  return true;
}

int utility(State &s, int p, vector<vector<bool>> &winningPositions)
{
  // -> if equality : 0
  // -> if p win : 1
  // -> if p loose : -1

  bool p1_win = playerHaveWinPosition(s, PLAYER_1, winningPositions);
  bool p2_win = playerHaveWinPosition(s, PLAYER_2, winningPositions);

  if(!p1_win && !p2_win) return EQUALITY_VALUE;
  //P1 case
  if(p == PLAYER_1 && p1_win) return WIN_VALUE;
  //P2 case
  if(p == PLAYER_2 && p2_win) return WIN_VALUE;

  return LOSE_VALUE;
}
