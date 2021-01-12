#include<iostream>
#include<string>
#include<cstdlib>
#include <ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int N = rand() %13 +1;
	return N;
}

int calScore(int x,int y,int z){
	int score;
	if(x>10){
	    x=10;
	}
	if(y>10){
	    y=10;
	}
	if(z>10){
	    z=10;
	}
	score = x+y+z;
	score = score%10;
	return score; 
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1;
	else{
		int act = rand()%100;
		if(act<69){
			return 1;
		}else{
			return 2;
		}
		}
		 
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if(p==y){
	cout <<   "|             Draw!!!           |"; // when p is equal to y
	}else if(p>y){
	cout <<   "|         Player wins!!!        |"; // when p is greater than y
	}else if(p<y){
	cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	}
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};
	int a = playerCards[0];
	int b = playerCards[1];
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[a] << " " << cardNames[b] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
		if(playerAction == 1 || playerAction == 2) break;
	}while(playerAction != 1 || playerAction != 2 ); 
	
	if(playerAction == 1){
		cout << "Player draws the 3rd card!!!" << "\n";
		playerCards[2] = drawCard();
		int c = playerCards[2];
		cout << "Your 3rd card: " << cardNames[c] << "\n";
		playerScore = calScore(playerCards[0], playerCards[1], playerCards[2]);
		cout << "Your new score: " << playerScore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	int d = yugiCards[0];
	int e = yugiCards[1];
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: "<< cardNames[d] << " " << cardNames[e] << "\n"; 
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);;
	cout << "Yugi's score: " << yugiScore << "\n";
	
	yugiAction = findYugiAction(yugiScore);
	
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		int f = yugiCards[2];
		cout << "Yugi's 3rd card: " << cardNames[f]<< "\n";
		yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
		cout << "Yugi's new score: " << yugiScore <<"\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	checkWinner(playerScore,yugiScore);
}
