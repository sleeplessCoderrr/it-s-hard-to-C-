#include<bits/stdc++.h>
using namespace std;

#define HEIGHT 10
#define WIDTH 20

struct Tile{
	int x, y;
	char sym;
	bool isTouched;
	Tile* backtrack;
	
	Tile(int _x, int _y, char _sym){
		this->x = _x;
		this->y = _y;
		this->sym = _sym;
		this->isTouched = false;
		this->backtrack = NULL;
	}
};

Tile* maze[HEIGHT][WIDTH];
const int dirX[] = {0, 1, 0, -2};
const int dirY[] = {-1, 0, 1, 0};
int startX = 1, startY = 1;
int posX = startX, posY = startY ;
int finishX = WIDTH - 2, finishY = HEIGHT - 2;

void initMaze(){
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			if(i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1){
				maze[i][j] = new Tile(j, i, '#');
			} else {
				maze[i][j] = new Tile(j, i, ' ');
			}
			
		}
	}
	
	maze[startY][startX]->isTouched = true;
	maze[finishY][finishX]->sym = 'F';
	maze[posY][posX]->sym = 'P';
}

void printMaze(){
	for(int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

void getNeighbours(queue<Tile*> *q){
	for(int i=0; i<4; i++){
		int newX = posX + dirX[i];
		int newY = posY + dirY[i];
		
		if(newX < 0 || newY < 0 || newX > WIDTH -1 || newY > HEIGHT - 1 ||maze[newY][newX]->isTouched || maze[newY][newX]->sym == '#') continue;
		
		q->push(maze[newY][newX]);
		maze[newY][newX]->isTouched = true;
		maze[newY][newX]->sym = '?';
		maze[newY][newX]->backtrack = maze[posY][posX];
	}
}

void backTrack(Tile* back){
	if(back->x == startX && back->y == startY){
		return;
	}
	back->sym = '.';
	backTrack(back->)
}

void djikstra(){
	queue<Tile*> q;
	
	while(!q.empty() && !(posX == finishX && posY == finishY)){
		getNeighbours(&q);
		Tile* nextTile = q.top();
		q.pop();
		
		posY = nextTile->y;
		posX = nextTile->x;
		
		if(posX == finishY && posY == finishY){
			backTrack(maze[posY][posX])
		}
	}
}

int main(){
	
	
	return 0;
}
