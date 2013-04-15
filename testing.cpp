#include <iostream>
#include <queue>



class cow {

	public:
		int moo;

		cow(int mooarg) {
			moo = mooarg;
		}


};


void rawr(int *dinosaurs) {
	std::cout << dinosaurs[0] << dinosaurs[1] << std::endl;
}

std::queue<cow*> manycows() {
	std::queue<cow*> toReturn;

	toReturn.push(new cow(1));
	toReturn.push(new cow(2));

	return toReturn;
}


int main(int argc, char *args[]) {


	cow *goesmoo = new cow(2);

	//std::cout << manycows().front()->moo << std::endl;
	
	int dino[5][2] = {{0,1},{2,1},{1,1},{4,3},{0,0}};
	rawr(dino[1]);

	return 0;

}
