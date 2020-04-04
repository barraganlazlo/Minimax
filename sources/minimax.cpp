#include "minimax.h"
#include <iostream>

using namespace std;

#define INFINITY 2147483647
#define INFINITY_NEGATIVE -2147483648

Action minimax_decision(State s, vector<vector<bool>> &winningPositions)
{
  int action_id=-1;
  vector<Action> actions_state=get_actions(s);
  int max_action_value=INFINITY_NEGATIVE;
  for(unsigned int a=0; a<actions_state.size(); ++a){
    int v = min_value(result(s, actions_state[a]), winningPositions);
    if(v>max_action_value){
      max_action_value=v;
      action_id=a;
    }
  }
  if(action_id == -1) cout << "Warzazat" << endl;
  return actions_state[action_id];
}

int max_value(State s, vector<vector<bool>> &winningPositions)
{
  if(is_terminal_test(s, winningPositions)) return utility(s, player(s), winningPositions);
  int v = INFINITY_NEGATIVE;
  vector<Action> actions_state=get_actions(s);
  for(unsigned int a=0; a<actions_state.size(); ++a){
    v = max(v, min_value( result(s, actions_state[a]) ,winningPositions));
  }
  return v;
}

int min_value(State s, vector<vector<bool>> &winningPositions)
{
  if(is_terminal_test(s, winningPositions)) return utility(s, player(s), winningPositions);
  int v = INFINITY;
  vector<Action> actions_state=get_actions(s);
  for(unsigned int a=0; a<actions_state.size(); ++a){
    v = min(v, max_value( result(s, actions_state[a]) ,winningPositions));
  }
  return v;
}
