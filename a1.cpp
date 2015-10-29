#include <iostream>
#include <iomanip>

using namespace std;

void Print(int s, int r, int c);

int main(){
	int space, row, col;
	space = 9;
	row = 10;
	col = 19;
	Print(space, row, col);
	while(true){
	   cout << "Enter: 'a' move left, 'd' move rignt, '-' smaller, '+' larger, 'e' exit" << endl;
	   char instruct;
	   cin >> instruct;
	   if(instruct == 'a'){
			if(space > row -1){
				space --;
				Print(space, row, col);
			}else{
			   cout << "The triangle cannot go left any more." << endl;
			}
		}
		if(instruct == 'd'){
			space ++;
			Print(space, row, col);
		}
		if(instruct == '+'){
			space ++;
			row ++;
			col = col + 2;
			Print(space, row, col);
		}
		if(instruct == '-'){
			if(row > 2){
			   space --;
			   row --;
			   col = col -2;
				Print(space, row, col);
			}else{
				cout << "The triangle cannot be descreased any more." << endl;
			}
		}
		if(instruct == 'e'){
			exit (0);
		}
	}
}
	
void Print(int s, int r, int c){
	cout << setfill(' ') << setw(s+1) << '*' << endl;
	int j = 0;
	for(int i = r-2;i > 0; i--){
		j = j + 2;
		cout << setfill(' ') << setw(s) << '*' << setw(j) << '*' << endl;
		s --;
	}
	s --;
	if(s!=0){
		cout << setw(s) << " ";
	}
	cout << setfill('*') << setw(c) << '*' << endl;
}
