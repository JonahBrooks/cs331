#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <vector>

class MooCow {
	public:
		int moo;

		MooCow(int argMoo) { moo = argMoo; }

};


class PrioComp {

	public:
		PrioComp() { } // Use an argument to change how this works between A* anf others in order to use a normal queue instead for those.

		bool operator() (MooCow cowOne, MooCow cowTwo) {
			return (cowOne.moo < cowTwo.moo);
		}

};

class Fringe {

	public:
		std::queue<MooCow> mooqueue;
		std::stack<MooCow> moostack;
		std::priority_queue<MooCow, std::vector<MooCow>, PrioComp>  mooprioq;
		std::string key;
	Fringe(std::string argKey) {
		key = argKey;
	}

	int head() {
		if(key.compare("queue")==0) {
			return mooqueue.front().moo;
		}
		if(key.compare("stack")==0) {
			return moostack.top().moo;
		}
		if(key.compare("priority_queue")==0) {
			return mooprioq.top().moo;
		}

	}

	void pop() {

		if(key.compare("queue")==0) {
			mooqueue.pop();
		}
		if(key.compare("stack")==0) {
			moostack.pop();
		}
		if(key.compare("priority_queue")==0) {
			mooprioq.pop();
		}

	}

	void push(MooCow toPush) {

		if(key.compare("queue")==0) {
			mooqueue.push(toPush);
		}
		if(key.compare("stack")==0) {
			moostack.push(toPush);
		}
		if(key.compare("priority_queue")==0) {
			mooprioq.push(toPush);
		}

		std::cout << toPush.moo << std::endl;
		std::cout << mooprioq.size() << std::endl;
	}

};


void moo(Fringe *cow) {
	std::cout << cow->head() << std::endl;
} 



int main(int argc, char *argv[]) {

	//Fringe mooqueue("queue");
	//Fringe moostack("stack");
	Fringe mooprioq("priority_queue");


	//mooqueue.push(MooCow(2));
	//moostack.push(MooCow(2));
	mooprioq.push(MooCow(2));
	mooprioq.push(MooCow(1));
	//moo(&mooqueue);
	//moo(&moostack);
	moo(&mooprioq);
	return 0;
}
