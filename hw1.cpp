#include <iostream>
#include <stack>
#include <queue>
#include <set>

class GameState {
	public:

		static bool isValid(GameState *state, int *argAction) { // No negative numbers, m >= c everywhere
			bool valid = true;

			int leftMis = state->LBank[0];
			int leftCan = state->LBank[1];
			int rightMis= state->RBank[0];
			int rightCan= state->RBank[1];
			int boatMis = argAction[0];
			int boatCan = argAction[1];
			bool boatOnLeft  = state->LBank[2] == 1;
			bool boatOnRight = state->RBank[2] == 1;

			if (boatOnLeft) {
				if ((leftMis - boatMis < 0) || (leftCan - boatCan < 0)) {
					valid = false;
				}
				if ((leftMis - boatMis < leftCan - boatCan) && (leftMis - boatMis != 0)) {
					valid = false; 

				}
				if ((rightMis + boatMis < rightCan + boatCan) && (rightMis + boatMis != 0)) {
					valid = false;
				}
			}
			else {
				if ((rightMis - boatMis < 0) || (rightCan - boatCan < 0)) {
					valid = false;
				}
				if ((rightMis - boatMis < rightCan - boatCan) && (rightMis - boatMis != 0)) {
					valid = false;
				}
				if ((leftMis + boatMis < leftCan + boatCan) && (leftMis + boatMis != 0)) {
					valid = false;
				}
			}

			return valid;
		}


		static std::queue<GameState*> expand(GameState *node) { // Does this need the goal state or some other "problem" state thing?
			std::queue<GameState*> successors;
			int actions[5][2] = {{1,0},{2,0},{0,1},{1,1},{0,2}};
		
			for (int i = 0; i < 5; i++) {	
				if (isValid(node, actions[i])) {
					successors.push(new GameState(node,actions[i])); // Memory leak. Oh God memory leak. o_o
				}
			}			
			
			return successors;

		}



		int LBank[3]; //state
		int RBank[3]; //state
		int action[2];
		GameState *parent; //parentNode
		int pathCost; //pathcost of parent + stepcost
		int depth; //depth
		
		GameState(int lm, int lc, int lb, int rm, int rc, int rb) { 
			LBank[0] = lm; LBank[1] = lc; LBank[2] = lb;
			RBank[0] = rm; RBank[1] = rc; RBank[2] = rb;
			action[0] = 0; action[1] = 0;
			pathCost = 0;
			depth = 0;
		}
		GameState(GameState *argParent, int *argAction) {
			int stepCost = 1; // Or might this be a float? Probably not.
			if (argParent->LBank[2] == 1) {
				LBank[0] = argParent->LBank[0] - argAction[0];
				LBank[1] = argParent->LBank[1] - argAction[1];
				LBank[2] = 0;
				RBank[0] = argParent->RBank[0] + argAction[0];
				RBank[1] = argParent->RBank[1] + argAction[1];
				RBank[2] = 1;
				// Calculate stepCost here? Would we then need to pass in heuristics?
			}
			else {
				RBank[0] = argParent->RBank[0] - argAction[0];
				RBank[1] = argParent->RBank[1] - argAction[1];
				RBank[2] = 0;
				LBank[0] = argParent->LBank[0] + argAction[0];
				LBank[1] = argParent->LBank[1] + argAction[1];
				LBank[2] = 1;
			}

			parent = argParent;
			action[0] = argAction[0];
			action[1] = argAction[1];
			depth = argParent->depth + 1;
			pathCost = argParent->pathCost + stepCost;
		}

		// Things to make this a full node:
		// Step-Cost (function)

		// A show or print function might be useful as well.
		// Need a better show function...
		// Also, we need a close list and heuristic stuffs, and other things of the sort. IE: graphSearch ^_^

		void showStuffs() {
			// Note: this is temporary.
			
			std::cout << "\n\nAction: Move " << action[0] << " missionaries and " << action[1] << " cannibals." << std::endl;
			std::cout << "\tLeft Bank: \nMissionaries: " << LBank[0] << "\nCannibals: " << LBank[1] << "\nBoat: " << LBank[2] << std::endl;
			std::cout << "\tRight Bank: \nMissionaries: " << RBank[0] << "\nCannibals: " << RBank[1] << "\nBoat: " << RBank[2] << std::endl << std::endl;

		}

}; 



GameState *GraphSearch(GameState *goal) {

	GameState *solution;

	std::set<GameState*> close; // Is this one to one?


	return solution;

}




int main(int argc, char *args[]) {

	GameState initial(0,0,0,3,3,1);
	initial.showStuffs();

	std::queue<GameState*> childrens = GameState::expand(&initial);


	while (childrens.empty() == false) {


		childrens.front()->showStuffs();
		
		std::queue<GameState*> grandchildrens = GameState::expand(childrens.front());
	
		while (grandchildrens.empty() == false) {
			grandchildrens.front()->showStuffs();
			grandchildrens.pop();
		}

		childrens.pop();
	} 


	return 0;

}


