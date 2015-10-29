
#include <iostream>   // contains cout and cin
#include <cstdlib>    // contains the random number generator rand()
#include <ctime>      // contains time() to seed random number

using namespace std;

class Alice{
	public:
		void movewest();
	   void moveeast();
	   void movesouth();
		void movenorth();
	   void errorcheck();
	   int getX() const;
	   int getY() const;
	   void setX(int xpos);
	   void setY(int ypos);
	private:
		int posx, posy;
};

int Alice::getX() const{
	return posx;
}

int Alice::getY() const{
	return posy;
}

void Alice::setX(int xpos){
	posx = xpos;
}

void Alice::setY(int ypos){
	posy = ypos;
}
void Alice::movewest(){
	posx--;
}

void Alice::moveeast(){
	posx++;
}

void Alice::movesouth(){
	posy++;
}

void Alice::movenorth(){
	posy--;
}

void Alice::errorcheck(){
	if(posx < 0){
		posx = 0;
	}
	if(posx > 9){
		posx = 9;
	}
	if(posy < 0){
		posy = 0;
	}
	if(posy > 4){
		posy = 4;
	}
}
	
class Monster{
	public:
		void move();
	   int getX() const;
	   int getY() const;
	   bool errorcheck1();
	   bool errorcheck2();
	   void setX(int xpos);
	   void setY(int ypos);
	private:
		int posx, posy;
};

int Monster::getX() const{
	return posx;
}

int Monster::getY() const{
	return posy;
}

void Monster::setX(int xpos){
	posx = xpos;
}

void Monster::setY(int ypos){
	posy = ypos;
}
void Monster::move(){
	int r;
	r = rand() % 5;
	switch(r){
		case 0: posx++; posy++; break;
		case 1: posx++; posy--; break;
		case 2: posx--; posy++; break;
		case 3: posx--; posy--; break;
		case 4: break;
	}
}

bool Monster::errorcheck1(){
	if((posx == 0)&&(posy == 0)){
		return false;
	}
	if((posx == 9)&&(posy == 4)){
		return false;
	}
	return true;
}

bool Monster::errorcheck2(){
	if((posx < 0)||(posx > 9)||(posy < 0)||(posy > 4)){
		return true;
	}
	return false;
}

int main() {
	displayInfo();
	Alice A;
	Monster M[3];
	A.setX(0);
	A.setY(0);
	srand(time(NULL));
	int rx,ry,i,j,k;
	char move;
	for(i = 0; i < 3; ++i){
		while(true){
	      rx = rand() % 10;
	      ry = rand() % 5;
	      M[i].setX(rx);
		   M[i].setY(ry);
			if(M[i].errorcheck1()){
				break;
			}
		}
	}
	i = 15;
	//error check!!!!!
	while(true){
		cout << "\n";
		cout << "Moves remaining: " << i <<endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+" <<endl;
		for(j = 0;j < 5; ++j){
			for(k = 0;k < 10; ++k){
				cout<<"|";
				if((k == 9)&&(j == 4)){
					cout<<"E";
					break;
				}
				if((M[0].getX()==k)&&(M[0].getY()==j)){
					cout<<"M";
					continue;
				}
				if((M[1].getX()==k)&&(M[1].getY()==j)){
				   cout<<"M";
					continue;
				}
				if((M[2].getX()==k)&&(M[2].getY()==j)){
					cout<<"M";
				   continue;
				}
				if((A.getX()==k)&&(A.getY()==j)){
					cout<<"A";
					continue;
				}
				cout<<" ";
			}
			cout<<"|"<<endl;
			cout << "+-+-+-+-+-+-+-+-+-+-+" <<endl;
		}
		--i;
		if((A.getX()==9)&&(A.getY()==4)){
			cout<<"Well done! Alice found the exit."<<endl;
			break;
		}
		bool temp = false;
		for(j = 0; j < 3; ++j){
			if((A.getX() == M[j].getX())&&(A.getY() == M[j].getY())){
				temp = true;
			}
		}
		if(temp){
			cout<<"GameOver!"<<endl;
			break;
		}
		if(i == -1){
			cout<<"Run out of moves!"<<endl;
			break;
		}
		cout<<"q: NW,  w: N,    e: NE"<<endl;
		cout<<"a: W,   s: stop, d: E "<<endl;
		cout<<"z: SW,  x: S,    c: SE"<<endl;
		cout<<"Which way to move? ";
		cin>>move;
		switch(move){
			case 'q':
				A.movenorth();
				A.movewest();
			   A.errorcheck();
				break;
			case 'w':
				A.movenorth();
			   A.errorcheck();
				break;
			case 'e':
				A.movenorth();
			   A.moveeast();
			   A.errorcheck();
			   break;
			case 'a':
				A.movewest();
			   A.errorcheck();
			   break;
			case 's':
				break;
			case 'd':
				A.moveeast();
			   A.errorcheck();
			   break;
			case 'z':
				A.movesouth();
			   A.movewest();
			   A.errorcheck();
			   break;
			case 'x':
				A.movesouth();
			   A.errorcheck();
			   break;
			case 'c':
				A.movesouth();
			   A.moveeast();
			   A.errorcheck();
			   break;
		}
		//cout<<"A: ("<<A.getX()<< " "<<A.getY()<<")"<<endl;
		srand(time(NULL));
		for(j = 0; j < 3; ++j){
			int x = M[j].getX();
			int y = M[j].getY();
				M[j].move();
				if(M[j].errorcheck2()){
					M[j].setX(x);
					M[j].setY(y);
				}
			//cout<<"M"<<j<<" :("<<M[j].getX()<< " "<<M[j].getY()<<")"<<endl;
		}
		
	}
	
}
