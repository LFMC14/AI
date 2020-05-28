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
	short int leftSide[2] = { 3, 3 }; // [# Cannibals, # Missionaries]
	short int rightSide[2] = { 0, 0 };
	bool boat = false; // Left = false, Right = true
};

class Game {
public:
	Game();
	void BFS(); // initiates solution search
	bool validState(short int left[], short int right[]); // checks for rules violations
	bool visited(State* state); // checks if state has already been seen
	void ACTIONS(State* node);
	State* fromRight(State* parent, short int cann, short int miss);
	State* fromLeft(State* parent, short int cann, short int miss);
	//State CHILDNODE(State curr, short int action);
	bool GOALTEST(State* current); // checks if state is goal state
	void SOLUTION(State* state); // prints solution
private:
	State* root = new State; // initial state
	stack<State*> path; // path to goal state
	vector<State*> explored; // keeps track of visited states
	queue<State*> frontier; // expanded states
};

inline Game::Game()
{
}

inline void Game::BFS()
{
	if (GOALTEST(root))
		return SOLUTION(root);

	frontier.push(root);
	
	while (!frontier.empty()) {
		State *currState = frontier.front();
		frontier.pop();
		explored.push_back(currState);

		ACTIONS(currState);

		for (auto it = currState->children.begin(); it != currState->children.end(); it++) {
			if (!visited((*it))) {
				if (GOALTEST((*it)))
					return SOLUTION((*it));
				frontier.push(*it);
			}
		}
	}
}

inline bool Game::validState(short int left[], short int right[])
{
	// Check for cannibal majority or out of bounds numbers
	// on either side
	if ((left[0] > left[1] && left[1] != 0) || 
		(right[0] > right[1] && right[1] != 0) ||
		left[0] < 0 || left[0] > 3 || right[0] < 0 || right[0] > 3 ||
		left[1] < 0 || left[1] > 3 || right[1] < 0 || right[1] > 3)
		return false;

	return true;
}

inline bool Game::visited(State *state)
{
	queue<State*> copy = frontier;

	for (auto it = explored.begin(); it != explored.end(); it++) {
		if (state->boat == (*it)->boat &&
			state->leftSide[0] == (*it)->leftSide[0] &&
			state->leftSide[1] == (*it)->leftSide[1])
			return true;
	}
	while (!copy.empty()) {
		State *s = copy.front();
		if (state->boat == s->boat &&
			state->leftSide[0] == s->leftSide[0] &&
			state->leftSide[1] == s->leftSide[1]) {
			return true;
		}
		copy.pop();
	}
	return false;
}

inline void Game::ACTIONS(State* parent)
{
	State* child = nullptr;
	
	// checks to see which side boat is, then performs appropriate action
	for (int c = 0; c < 3; c++) {
		for (int m = 0; m < 3; m++) {
			if ((c + m) > 2 || (c + m) < 1)
				continue;
			else if (parent->boat)
				child = fromRight(parent, c, m);
			else
				child = fromLeft(parent, c, m);

			if (child)
				parent->children.push_back(child);
		}
	}
}

inline State* Game::fromRight(State* parent, short int cann, short int miss)
{
	State* child = new State;

	child->leftSide[0] = parent->leftSide[0] + cann;
	child->leftSide[1] = parent->leftSide[1] + miss;
	child->rightSide[0] = parent->rightSide[0] - cann;
	child->rightSide[1] = parent->rightSide[1] - miss;
	child->boat = false;

	if (validState(child->leftSide, child->rightSide)) {
		child->action[0] = cann;
		child->action[1] = miss;
		child->action[2] = false;
		child->parent = parent;
		return child;
	}
	else {
		delete child;
		return nullptr;
	}
}

inline State* Game::fromLeft(State* parent, short int cann, short int miss)
{
	State* child = new State;

	child->leftSide[0] = parent->leftSide[0] - cann;
	child->leftSide[1] = parent->leftSide[1] - miss;
	child->rightSide[0] = parent->rightSide[0] + cann;
	child->rightSide[1] = parent->rightSide[1] + miss;
	child->boat = true;

	if (validState(child->leftSide, child->rightSide)) {
		child->action[0] = cann;
		child->action[1] = miss;
		child->action[2] = true;
		child->parent = parent;
		return child;
	}
	else {
		delete child;
		return nullptr;
	}
}

inline bool Game::GOALTEST(State* current)
{
	if (current->rightSide[0] == 3 && current->rightSide[1] == 3)
		return true;

	return false;
}

inline void Game::SOLUTION(State* state)
{
	path.push(state);
	State* s = state;
	State* p = nullptr;

	while (s->parent) {
		path.push(s->parent);
		s = s->parent;
	}
	
	p = path.top();

	while (!path.empty()) {
		path.pop();

		cout << "Cannibals Left Side: " << p->leftSide[0] << "     "
			<< "Cannibals Right Side: " << p->rightSide[0] << endl
			<< "Missionaries Left Side: " << p->leftSide[1] << "     "
			<< "Missionaries Right Side: " << p->rightSide[1] << endl << endl;



		if (!path.empty()) {
			p = path.top();

			cout << "\nMove " << p->action[0]
				<< " cannibal/s and "
				<< p->action[1] << " missionary/ies" << " to the ";

			if (p->action[2] == true)
				cout << "right." << endl << endl;
			else
				cout << "left." << endl << endl;
		}
	}
}

int main()
{
	Game letsPlay;

	letsPlay.BFS();
}
