/////////////////////////////////
// 10196 - Check the Check
/////////////////////////////////
#include<cstdio>
#include<cctype>
char board[12][12],line[5],pc, *ans;
int i,j,bkx,bky,wkx,wky,gn;
bool bkc,wkc, valid;
bool check(char test, char c1, char c2){
	return (test == c1 || test == c2);
}
bool check(int x, int y, char c1, char c2, char c3, char c4, bool PEON){
	//Knight Check
	if(board[x-1][y-2] == c4 || board[x+1][y-2] == c4) return 1;
	if(board[x-1][y+2] == c4 || board[x+1][y+2] == c4) return 1;
	if(board[x-2][y-1] == c4 || board[x+2][y-1] == c4) return 1;
	if(board[x-2][y+1] == c4 || board[x+2][y+1] == c4) return 1;
	//Peon Check
	if(PEON){
		if(board[x+1][y+1] == 'P' || board[x+1][y-1] == 'P') return 1;
	} else {
		if(board[x-1][y+1] == 'p' || board[x-1][y-1] == 'p') return 1;
	}
	for(i = x+1; i < 10; i++){ //Vertical check below
		pc = board[i][y];
		if(pc != '.'){
			if(check(pc,c1,c2)) return 1;
			else break;
		}
	}
	for(i = x-1; i > 1; i--){ //Vertical check above
		pc = board[i][y];
		if(pc != '.'){
			if(check(pc,c1,c2)) return 1;
			else break;
		}
	}
	for(j = y+1; j < 10; j++){ //Horizontal check right
		pc = board[x][j];
		if(pc != '.'){ 
			if(check(pc,c1,c2)) return 1;
			else break;
		}
	}
	for(j = y-1; j > 1; j--){ //Horizontal check left
		pc  = board[x][j];
		if(pc != '.'){
			if(check(pc,c1,c2)) return 1;
			else break;
		}
	}
	for(i = 1; (x+i) < 10 && (y+i) < 10; i++){ //Diagonal check right-down
		pc = board[x+i][y+i];
		if(pc != '.'){
			if(check(pc,c1,c3)) return 1;
			else break;
		}
	}
	for(i = 1; (x+i) < 10 && (y-i) > 1; i++){ //Diagonal check left-down
		pc = board[x+i][y-i];
		if(pc != '.'){
			if(check(pc,c1,c3)) return 1;
			else break;
		}
	}
	for(i = 1; (x-i) > 1 && (y-i) > 1; i++){ //Diagonal check left-up
		pc = board[x-i][y-i];
		if(pc != '.'){
			if(check(pc,c1,c3)) return 1;
			else break;
		}
	}
	for(i = 1; (x-i) > 1 && (y+i) < 10; i++){ //Diagonal check right-up
		pc = board[x-i][y+i];
		if(pc != '.'){
			if(check(pc,c1,c3)) return 1;
			else break;
		}
	}
	return 0;
}
int main(void){
	for(i = 0; i < 12; i++) for(j = 0; j < 12; board[i][j] = '_',j++);
	while(true){
		gn++;
		for(i = 2; i < 10; getchar(),i++)
			for(j = 2; j < 10; j++)
				board[i][j] = getchar();
		gets(line);
		valid = bkc = wkc = 0;
		for(i = 2; i < 10; i++) 
			for(j = 2; j < 10; j++){
				if(board[i][j] != '.')	valid = 1;
				if(board[i][j] == 'k'){
					bkx = i; bky = j;
				} else if(board[i][j] == 'K'){
					wkx = i; wky = j;
				}
			}
		if(!valid) break;
		bkc = check(bkx,bky,'Q','R','B','N',true);		
		if(!bkc) wkc = check(wkx,wky,'q','r','b','n',false);
		if(bkc) ans = "black";
		else if(wkc) ans = "white";
		else ans = "no";
		printf("Game #%d: %s king is in check.\n",gn,ans);
		
	}
	return 0;
}