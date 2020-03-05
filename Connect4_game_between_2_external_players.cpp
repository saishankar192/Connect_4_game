#include<bits/stdc++.h>
#include<iostream>
using namespace std;

char board[6][7];
/*Function to print the state of board*/
void print_board(){
	int r,c,v=0;
	for(r=0;r<6;r++){
		cout<<"|";
		for(c=0;c<7;c++){
			cout<<board[r][c]<<"|";
		}
		cout<<endl;
		cout<<"---------------"<<endl;
	}
}
/*Function to execute the choice of a player based on the availability of that particular row & column space */
bool check_fill(int pl_ch,char ch,int &r,int &c){
	int i;
	if(pl_ch>7 ||pl_ch<1){
		return false;
	}
	for(i=5;i>=0;i--){
		if(board[i][pl_ch-1]==' '){
			board[i][pl_ch-1] = ch;
			r = i;
			c = pl_ch-1;
			print_board();
			return true;
		}
	}
	return false;
}
/*Function to check whether the player who just placed his symbol at r and c has any winning chance */
bool success_check(int r,int c,char ch){
	int cnt=1,i=c,j=r+1;
	/*Checking the line below */
	while(j<6){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		j++;
	}
	if(cnt>=4){
		return true;
	}
	/*Horizontal check */
	cnt=1,i=c-1,j=r;
	while(i>=0){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		i--;
	}
	i=c+1,j=r;
	while(i<=6){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		i++;
	}
	if(cnt>=4){
		return true;
	}
	/*LEFT DIAGONAL check i.e left UP and right DOWN check */
	cnt = 1;i=c-1;j=r-1;
	while(j>=0 && i>=0){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		i--;j--;
	}
	i=c+1;j=r+1;
	while(j<=5 && i<=6){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		i++;j++;
	}
	if(cnt>=4){
		return true;
	}
	/*RIGHT DIAGONAL check i.e left DOWN and right UP check */
	cnt = 1;i=c+1;j=r-1;
	while(j>=0 && i<=6){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		i++;j--;
	}
	i=c-1;j=r+1;
	while(j<=5 && i>=0){
		if(board[j][i]==ch){
			cnt++;
		}
		else{
			break;
		}
		i--;j++;
	}
	if(cnt>=4){
		return true;
	}
	return false;
}
int main(){
	int r,c;
	for(r=0;r<6;r++){
		for(c=0;c<7;c++){
			board[r][c]=' ';
		}
	}
	int chance=0,pl1_ch,pl2_ch;
	loc:
	print_board();
	while(chance<42){
	if(chance%2==0){
		cout<<"Player1 choose a column number between 1-7"<<endl;
		cin>>pl1_ch;
		while(!check_fill(pl1_ch,'X',r,c)){
			if(pl1_ch>7 ||pl1_ch<1){
			cout<<"Range Exceeded, Player1 choose a column number between 1-7"<<endl;
			}
			else{
			cout<<"Player1 chosen column is completely filled, choose another column"<<endl;
			}
			cin>>pl1_ch;
		}
		if(success_check(r,c,'X')){
			cout<<"Player1 is the winner"<<endl;
			break;
		}
	}
	else{
		cout<<"Player2 choose a column number between 1-7"<<endl;
		cin>>pl2_ch;
		while(!check_fill(pl2_ch,'O',r,c)){
			if(pl2_ch>7 ||pl2_ch<1){
			cout<<"Range Exceeded Player2 choose a column number between 1-7"<<endl;
			}
			else{
			cout<<"Player2 chosen column is completely filled, choose another column"<<endl;
			}
			cin>>pl2_ch;
		}
		if(success_check(r,c,'O')){
			cout<<"Player2 is the winner"<<endl;
			break;
		}

	}
	chance++;
	}
	int opt;
	cout<<"If you wish to play another game press 1 , to exit press 0"<<endl;
	cin>>opt;
	if(opt){
	chance=0;
	for(r=0;r<6;r++){
		for(c=0;c<7;c++){
			board[r][c]=' ';
		}
	}
	goto loc;
	}

}
