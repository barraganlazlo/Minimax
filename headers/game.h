#ifndef GAME_H
#define GAME_H
#include <vector>

using namespace std;

#define EMPTY -1
#define PLAYER_1 0
#define PLAYER_2 1
#define PLAYERS 2 //number of players

#define LOSE_VALUE -1
#define EQUALITY_VALUE 0
#define WIN_VALUE 1

class State{
  public :
   //the set of squares of the games
    vector<int> tiles;

    // the number of turns since thje begining
    unsigned int turn;

    /*
    * creating a new state at turn 0
    * with tiles of size n filled with EMPTY (-1)
    */
    State(int n);

    // copying a state
    //State(State &s);
    State();
};

class Action{
  public :
    //id where the tile has to change to the current player value
    int tile_id;
    //creating an Action with tile_id
    Action(int tile_id): tile_id(tile_id){};
};


/**
 * calculate the player that has to move in this State
 *
 * @param  {State&} s : the State to calculate on
 * @return {int} : the value corresponding to the player that has to play in this state
 */
inline int player(State &s){
  return s.turn%PLAYERS;
}

/**
 * calculate and return the set of possible actions on a State
 *
 * @param {State&} s : the State to calculate on
 * @return  vector<Action> : the set of possibles actions
 */
vector<Action> get_actions(State &s);

/**
 * Result return the new state after a move
 *
 * @param  {State} s : the state before a move
 * @param  {Action&} a : the action to apply
 * @return {State} : the new State
 */
State result(State s, const Action &a);

/*
* A terminal test, which is true when the game is over and false otherwise.
*
* @param {State&} s : the state to check
* @param {vector<vector<bool>>&} winningPositions : the collection that defines wining positions
*/
bool is_terminal_test(State &s, vector<vector<bool>> &winningPositions);

/**
 * check if a player position corresponds to the winningPosition in the passed state
 *
 * @param  s : the state to check
 * @param  p : the player
 * @param  {vector<bool>&} winningPosition : a wining position
 * @return {bool} : true if player position corresponds to the winningPosition false otherwise
 */
bool playerWin(State &s, int p,  vector<bool> &winningPosition);

/**
 * check if a player win in the passed state
 *
 * @param  s : the state to check
 * @param  p : the player
 * @param  {vector<vector<bool>>} winningPositions :  the collection that defines wining positions
 * @return {bool} : true if the player wins false otherwise
 */
bool playerHaveWinPosition(State &s, int p, vector<vector<bool>> &winningPositions);


/**
 * Used to know who wins
 *
 * A utility function (also called an objective function or payoff function),
 * defines the final numeric value for a game that ends in terminal State s
 * for a player p (-1, 0 or 1 for example).
 *
 * @param {State&} s : the final state
 * @param {int} p : the player for who we want the value
 * @param {vector<vector<bool>>} winningPositions : the collection that defines wining positions
 * @return {int} : -1, 0 or 1 depending on the issue of the game
 */
int utility(State &s, int p, vector<vector<bool>> &winningPositions);


#endif
