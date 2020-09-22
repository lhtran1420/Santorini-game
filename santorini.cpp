#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int arr[7][7];
int markP[30][30];
int markA[30][30];
int col, row;
int colA, rowA;
int cnt = 0, ct = 0, ct1 = 0;

int dx[10]={-1,-1,0,1,1,1,0,-1};
int dy[10]={0,1,1,1,0,-1,-1,-1};

void change(int x, int y, int num) {	// The change of every square relating to the square (x,y) 
										// that player or AI comes into
	for(int i=0; i<=7; i++) {
		for(int j=1; j<=6; j++) {
		
			if(num==1) {  // if player goes into square(x,y)
				if( (x+j*dx[i])>6 || (x+j*dx[i]) <1 || (y+j*dy[i])>6 || (y+j*dy[i])<1 || markA[x+j*dx[i]][y+j*dy[i]]==1) break;	
				
				else {
					if(arr[x+j*dx[i]][y+j*dy[i]]<4) arr[x+j*dx[i]][y+j*dy[i]]++; // we have to increase every square relating
																				// to the square(x,y) that player is standing
					
				}
			}
			
			else if(num==-1) { // if AI goes into square(x,y)
				if((x+j*dx[i])>6 || (x+j*dx[i]) <1
				|| (y+j*dy[i])>6 || (y+j*dy[i])<1 || markP[x+j*dx[i]][y+j*dy[i]]==1) break;	
				
				else {
					if(arr[x+j*dx[i]][y+j*dy[i]]>0) arr[x+j*dx[i]][y+j*dy[i]]--; // we have to decrease every square relating
																				// to the square(x,y) that AI is standing
				}
			}
		}	
	}	
}

void check() { // check whether player or AI wins or not
	ct = 0; ct1 = 0;
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=6; j++) {
			if(arr[i][j] == 4) ct++; // count number of squares that are 4
			if(arr[i][j] == 0) ct1++; // count number of squares that are 0
		}
	}
}

void print() { //print the square matrix
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=6; j++) {
			if(markP[i][j] == 1) printf("P ");
			else if(markA[i][j] == 1) printf("A ");
			else printf("%d ",arr[i][j]);
		}
		
		printf("\n");
	}	
}

int main() {
	//initialize square matrix
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=6; j++) {
			arr[i][j] = 2; // all the square at starting point are equal to 2
			markP[i][j] = 0;
			markA[i][j] = 0;
		}
	}
	
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=6; j++) {
			printf("%d ",arr[i][j]);
		}
		
		printf("\n");
	}
	
	while(1) {
		if(cnt==0) {
			printf("Enter starting point with row: "); 
			scanf("%d", &row);
	
			printf("Enter starting point with column: "); 
			scanf("%d", &col);
			cnt++;
			markP[row][col] = 1; // mark the square that player is standing by 1
			
			// The way to choose AI's position that next to player's position
			if(col<6) {
				markA[row][col+1] = 1;
				rowA = row; colA=col+1;
			}	
			
			else {
				if(row<6) {
					markA[row+1][col] = 1;
					rowA = row+1; colA=col;
				}
				else {
					markA[row-1][col] = 1;
					rowA = row-1;
					colA=col;
				}
			}
		}
		
		
		else {
			int x,y;
			printf("Enter next move with row: ");
			scanf("%d", &x);
				
			printf("Enter next move with column: ");
			scanf("%d", &y);
			while(markP[x][y]==1 || markA[x][y]==1 || x>6 || x<1 || y>6 || y<1 
				|| abs(x-row)>1 || abs(y-col)>1) { // checking whether our move is available or not. 
												   // If it is not, we have to move again
				printf("Enter next move with row again: ");
				scanf("%d", &x);
				
				printf("Enter next move with column again: ");
				scanf("%d", &y);
			}
			
		
			markP[x][y] = 1;
			markP[row][col] = 0;
			row = x; col = y;
			
			change(x,y,1);
			check();
			
			if(ct>=10) { // if the square which is equal to 4 is equal or more than 10, player wins the game
				print();
				printf("Player wins");
				break;
			}
			
			int rd = rand() % 8; // randomly choose a square next to the square that AI is standing.
			int roa = rowA + dx[rd];
			int coa = colA + dy[rd];
			
			while(markP[roa][coa]==1 || markA[roa][coa]==1 || roa>6 || roa<1 
				|| coa>6 || coa<1 || abs(coa-colA)>1 || abs(roa-rowA)>1) { // checking whether AI's move is available or not. 
												                // If it is not, it will automatically move again
												                // until its move is correct.
					 
				rd = (rd+1) %8;
				roa = rowA + dx[rd];
				coa = colA + dy[rd];
			}
			
			markA[roa][coa] = 1; // marking the square that AI is standing by 1
			markA[rowA][colA] = 0;
			rowA = roa;colA = coa;
			change(roa,coa,-1);
			check();
			if(ct1>=10) { // if the square which is equal to 0 is equal or more than 10, AI wins the game
				print();
				printf("AI wins");
				break;
			}
		}
		
		// print the square matrix after each turn
		for(int i=1; i<=6; i++) {
			for(int j=1; j<=6; j++) {
				if(markP[i][j] == 1) printf("P ");
				else if(markA[i][j] == 1) printf("A ");
				else printf("%d ",arr[i][j]);
			}
			
			printf("\n");
		}			
		
	}
}

