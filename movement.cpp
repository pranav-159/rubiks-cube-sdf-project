#include"opengl.h"

std::stack<std::function<void()>> movement_t::history;
movement_t* movement_t::Instance;

movement_t* movement_t::getInstance(){
	if(Instance == NULL) Instance = new movement_t;
	return Instance;
}



void movement_t::move(){
	for(unsigned i=0;i<9;i++){
		swapColors(peiceNumbers.at(i),peiceNumbers.at(i+3));
		printf("\n");
	}
	data::buildCube();
}

void movement_t::moveSide(){
	printf("Has sides to rotate");
	for(unsigned i=0;i<6;i++){
		swapColors(peiceNumbersSide.at(i),peiceNumbersSide.at(i+2));
		printf("\n");
	}
	data::buildCube();
}

void movement_t::swapColors(const unsigned x, const unsigned y){
	for(unsigned j=0;j<4;j++){
		std::swap(tempMoveObj.splitCube[data::choice-1][x][j].rCol,tempMoveObj.splitCube[data::choice-1][y][j].rCol);
		std::swap(tempMoveObj.splitCube[data::choice-1][x][j].gCol,tempMoveObj.splitCube[data::choice-1][y][j].gCol);
		std::swap(tempMoveObj.splitCube[data::choice-1][x][j].bCol,tempMoveObj.splitCube[data::choice-1][y][j].bCol);
	}
	std::cout<<"Swapped "<<x<<" and "<<y<<" ; ";
}

/*Check peiceNumbersSide and moveSide() properly*/
void movement_t::leftDown(){
	peiceNumbers = {0,3,6,36,39,42,26,23,20,45,48,51};
	peiceNumbersSide = {29,32,27,28,33,30,35,34};
	move();
	moveSide();
}

void movement_t::rightDown(){
	peiceNumbers = {2,5,8,38,41,44,24,21,18,47,50,53};
	peiceNumbersSide = {9,10,11,14,17,16,15,12};
	move();
	moveSide();
}

void movement_t::topLeft(){
	peiceNumbers = {0,1,2,27,28,29,18,19,20,9,10,11};
	peiceNumbersSide = {36,37,38,41,44,43,42,39};
	move();
	moveSide();
}

void movement_t::bottomLeft(){
	peiceNumbers = {6,7,8,15,16,17,24,25,26,33,34,35};
	peiceNumbersSide = {45,46,47,50,53,52,51,48};
	move();
}


void movement_t::verticalMiddleDown(){
	peiceNumbers = {1,4,7,37,40,43,25,22,19,46,49,52};
	move();
}

void movement_t::horizontalMiddleLeft(){
	peiceNumbers = {3,4,5,30,31,32,21,22,23,12,13,14};
	move();
}

void movement_t::frontClockwise(){
	peiceNumbers = {29,32,35,45,46,47,15,12,9,44,43,42};
	peiceNumbersSide = {0,1,6,3,8,7,2,5};
	move();
	moveSide();
}

void movement_t::backClockwise(){
	peiceNumbers = {38,37,36,27,30,33,51,52,53,17,14,11};
	peiceNumbersSide = {18,19,20,23,26,25,24,21};
	move();
	moveSide();
}

/*This function will call some rotate functions 20 times randomly each time  */
void movement_t::shuffle(){
	std::srand(time(0));
	for(unsigned i=0;i<20;i++){
	switch( rand() % NOMOVEMENTS){
		case 0 : leftDown();  break;
		case 1 : rightDown(); break;
		case 3 : topLeft(); break;
		case 4 : bottomLeft(); break;
		case 5 : verticalMiddleDown(); break;
		case 6 : horizontalMiddleLeft();break;
		case 7 : frontClockwise();break;
		case 8 : backClockwise();
	}
	}
}
