#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct State {
	vector<State*> children;
	State* parent = nullptr;
	short int action[3] = {}; // [ # Cannibals, # Missionaries, Side Boat Moved]
	short int leftSide[2] = {3, 3}; // [# Cannibals, # Missionaries]
	short int rightSide[2] = {0, 0};
	bool boat = false; // Left = false, Right = true
};

class Game {
public:
	Game();
	void BFS(); // initiates solution search
	bool validState(short int left[], short int right[]); // checks for rules violations
	bool visited(State *state); // checks if state has already been seen
	void ACTIONS(State *node);
	State* fromRight(State* parent, short int cann, short int miss);
	State* fromLeft(State *parent, short int cann, short int miss);
	//State CHILDNODE(State curr, short int action);
	bool GOALTEST(State* current); // checks if state is goal state
	void SOLUTION(State* state); // prints solution
private:
	State *root = new State; // initial state
	stack<State*> path; // path to goal state
	vector<State*> explored; // keeps track of visited states
	queue<State*> frontier; // expanded states
};

