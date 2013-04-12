#include <iostream>

class GameState {
	private:
		int LBank[3];
		int RBank[3];
		
	public:
		GameState(int lm, int lc, int lb, int rm, int rc, int rb) { 
			LBank[0] = lm; LBank[1] = lc; LBank[2] = lb;
			RBank[0] = rm; RBank[1] = rc; RBank[2] = rb;
		}

		// Things to make this a full node:
		// Parent-Node
		// Action (is this a function?)
		// State
		// Path-Cost
		// Step-Cost (function)
		// Depth
		// Perhaps an Expand function?


		int *getLBank() { return LBank; }
		int *getRBank() { return RBank; }
}; 







int main(int argc, char *args[]) {

	GameState initial(0,0,0,0,0,1);




	return 0;

}


