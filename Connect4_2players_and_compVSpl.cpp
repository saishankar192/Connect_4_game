#include<bits/stdc++.h>
using namespace std;

char board[6][7];
/*Function to print the board status */
void printing_board()
{
    cout<<"Current status of board: "<<endl;
	int i,j;
	for(i=0;i<6;i++)
	{
		cout<<"---------------"<<endl<<"|";
		for(j=0;j<7;j++)
		{
			cout<<board[i][j]<<"|";
		}
		cout<<endl;
	}
	cout<<"---------------"<<endl;
	return;
}
/*Creating empty board*/
void create_emptyboard()
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			board[i][j] = ' ';
		}
	}
	cout<<endl;
	return;
}
/* Check if the player chosen column has free cells to fill */
bool check_empty(int block)
{

	if(block<1 || block>7)
	{
		cout<<"Chosen block is not in range. Please choose between 1 and 7"<<endl;
		return false;
	}
	if(board[0][block-1]!=' ')
	{
		cout<<"Chosen column is completely filled. Please choose another column"<<endl;
		return false;
	}
	return true;
}
/*Execute the choice of a player */
void fill_block(int block,char c, int &r)
{
	int i;
	for(i=5;i>=0;i--)
	{
		if(board[i][block-1]==' ')
		{
			board[i][block-1]= c;
			r = i;
			break;
		}
	}
	printing_board();
	return;

}
/*Function to check winning criteria */
bool check_winning(int c,char ch,int r)
{
    c = c-1;
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

int main()
{
    loc:
	create_emptyboard();
	printing_board();
	int player1,player2,cnt=0,r=0,win=0,choice,gametype,CPU;
	char chr,cpu_chr;
	cout<<endl<<"Enter 1--->CPU vs Player  **********  2--->Player1 vs Player2: ";
	cin>>gametype;
	if(gametype==1)
	{
		rev:
		cout<<"Choose whether you want to play first(Enter 1) or second(Enter 2): ";
		cin>>choice;
		int alt;
		if(choice==1)
		{
			alt=0;
			chr = 'X';
			cpu_chr = 'O';
		}
		else if(choice==2)
		{
			alt=1;
			chr='O';
			cpu_chr = 'X';
		}
		else
		{
			cout<<"Entered number is out of range"<<endl;
			goto rev;
		}
		while(cnt<=41)
		{
			if(!alt)
			{
				cout<<"Player choose your input block: ";
				cin>>player1;
				if(check_empty(player1))
				{
					fill_block(player1,chr,r);
					if(cnt>=6)
					{
						if(check_winning(player1,chr,r))
						{
							cout<<"Player won the game"<<endl;
							win=1;
							break;
						}
					}
					r=0;
				}
				else
				{
					continue;
				}
				cnt++;
				alt=1;
			}
			else
			{
				CPU = (rand()%6)+1;
				if(check_empty(CPU))
				{
					fill_block(CPU,cpu_chr,r);
					if(cnt>=7)
					{
						if(check_winning(CPU,cpu_chr,r))
						{
							cout<<"CPU won the game"<<endl;
							win=1;
							break;
						}
					}
					r=0;
				}
				else
				{
					continue;
				}
				cnt++;
				alt=0;
			}
		}
		if(!win)
		{
		    cout<<"Complete board filled!\nMatch draw neither CPU nor Player won the game"<<endl;
		}
	}
	else if(gametype==2)
	{
		while(cnt<=41)
		{
			if(!(cnt%2))
			{
				cout<<"Player 1 choose your input block: ";
				cin>>player1;
				if(check_empty(player1))
				{
					fill_block(player1,'X',r);
					if(cnt>=6)
					{
						if(check_winning(player1,'X',r))
						{
							cout<<"Player 1 won the game"<<endl;
							win=1;
							break;
						}
					}
					r=0;
				}
				else
				{
					continue;
				}
				cnt++;
			}
			else
			{
				cout<<"Player 2 choose your input block: ";
				cin>>player2;
				if(check_empty(player2))
				{
					fill_block(player2,'O',r);
					if(cnt>=7)
					{
						if(check_winning(player2,'O',r))
						{
							cout<<"Player 2 won the game"<<endl;
							win=1;
							break;
						}
					}
					r=0;
				}
				else
				{
					continue;
				}
				cnt++;
			}
		}
		if(!win)
		{
		    cout<<"Complete board filled!\nMatch draw neither of players won"<<endl;
		}
	}
	int opt;
	cout<<"If you wish to play another game press 1 , to exit press 0"<<endl;
	cin>>opt;
	if(opt){
        goto loc;
	}
	return 0;
}
