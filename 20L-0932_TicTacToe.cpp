#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int number(int i,int j);
int finalwin(char** ptr2);
class TicTacToe
{
private:
	int n;
	char** arr;
public:
	TicTacToe();
	TicTacToe(int n);
	TicTacToe(const TicTacToe& board);
	~TicTacToe();
	friend void operator<<(ostream& , const TicTacToe&);
	void GetMove(char move);
	void getarr(char **ptr);
	void setarr(char **ptr);
	int winner();
};

TicTacToe::TicTacToe()
{
	n=3;
	arr=new char*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new char[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]='\0';
		}
	}
}

TicTacToe::TicTacToe(int N)
{
	this->n=N;
	arr=new char*[N];
	for(int i=0;i<N;i++)
	{
		arr[i]=new char[N];
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			arr[i][j]='\0';
		}
	}
}

TicTacToe::TicTacToe(const TicTacToe& board)
{
	this->n=board.n;
	if(board.arr!=nullptr)
	{
		arr=new char*[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=new char[n];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j]=board.arr[i][j];
			}
		}
	}
}

TicTacToe::~TicTacToe()
{
	if(arr!=nullptr)
	{
		for(int i=0;i<n;i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr=nullptr;
	}
}

void TicTacToe::getarr(char **ptr)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ptr[i][j]=arr[i][j];
		}
	}
}

void TicTacToe::setarr(char **ptr)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=ptr[i][j];
		}
	}
}

void operator << (ostream & out, const TicTacToe& board)
{
	int num;
	num=board.n;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(board.arr[i][j]!='\0')
			{
				out<<board.arr[i][j]<<" ";
			}
			else
			{
				out<<"- ";
			}
		}
		out<<endl;
	}
}

void TicTacToe:: GetMove(char move)
{
	int row,col;
	bool valid=false;
	while(valid==false)
	{
		cout<<"Enter row number : ";
		cin>>row;
		row=row-1;
		cout<<"Enter column number : ";
		cin>>col;
		col=col-1;
		if(row>=n || row<0)
		{
			cout<<"Row number is invalid...Enter row and column again"<<endl;
		}
		else if(col>=n || col<0)
		{
			cout<<"Column number is invalid...Enter row and column again"<<endl;
		}
		else
		{
			if(arr[row][col]=='\0')
			{
				arr[row][col]=move;
				valid=true;
			}
			else
			{
				cout<<"Invalid move,choose another space"<<endl;
			}
		}
	}
}

int TicTacToe::winner()
{
	int count=0;
	char prev,sign='f';
	bool finish=false,win=false;
	
	for(int a=0;a<n;a++)
	{
		count=1;
		prev=arr[a][0];
		for(int b=1;b<n;b++)
		{
			if(arr[a][b]==prev && arr[a][b]!='\0')
			{
				count++;
				prev=arr[a][b];
			}
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	for(int a=0;a<n;a++)
	{
		count=1;
		prev=arr[0][a];
		for(int b=1;b<n;b++)
		{
			if(arr[b][a]==prev && arr[b][a]!='\0')
			{
				count++;
				prev=arr[b][a];
			}
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	count=1;
	prev=arr[0][0];
	for(int a=1;a<n;a++)
	{
		if(arr[a][a]==prev && arr[a][a]!='\0')
		{
			count++;
			prev=arr[a][a];
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	count=1;
	prev=arr[0][n-1];
	for(int a=1,b=n-2;a<n;a++,b--)
	{
		if(arr[a][b]==prev && arr[a][b]!='\0')
		{
			count++;
			prev=arr[a][b];
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	if(win!=true)
	{
		finish=true;
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(arr[a][b]=='\0')
				{
					finish=false;
					b=n;
					a=n;
				}
			}
		}
	}

	if(finish==true)
	{
		sign='d';
	}

	if(sign=='x')
		return 1;
	else if(sign=='o')
		return 2;
	else if(sign=='d')
		return 3;
	else
		return 0;
}

class ultimateTicTacToe: TicTacToe
{
	TicTacToe** arr2;
	char** bigboard;
public:
	ultimateTicTacToe(int n);
	ultimateTicTacToe(const ultimateTicTacToe& board2);
	~ultimateTicTacToe();
	friend void operator<<(ostream& , const ultimateTicTacToe&);
	void getmove(char move,const ultimateTicTacToe&,int& boxrow,int& boxcol,int play[3][3]);
	void getboard(char** farr);
	void getthatarray(char** thatarr,const ultimateTicTacToe&,int a,int b);
	void setthatarray(char** thatarr,ultimateTicTacToe&,int a,int b);
};

ultimateTicTacToe::ultimateTicTacToe(int n)
{
	arr2=new TicTacToe*[3];
	for(int i=0;i<3;i++)
	{
		arr2[i]=new TicTacToe[3];
	}

	bigboard=new char*[3];
	for(int i=0;i<3;i++)
	{
		bigboard[i]=new char[3];
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			bigboard[i][j]='\0';
		}
	}
}

ultimateTicTacToe::ultimateTicTacToe(const ultimateTicTacToe& board2)
{
	arr2=new TicTacToe*[3];
	for(int i=0;i<3;i++)
	{
		arr2[i]=new TicTacToe[3];
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			arr2[i][j]=board2.arr2[i][j];
		}
	}
}

ultimateTicTacToe::~ultimateTicTacToe()
{
	if(arr2!=nullptr)
	{
		for(int i=0;i<3;i++)
		{
			delete[] arr2[i];
		}
		delete[] arr2;
		arr2=nullptr;
	}
}


void operator << (ostream & out, const ultimateTicTacToe& board2)
{
	char** ptr=new char*[3];
	for(int i=0;i<3;i++)
	{
		ptr[i]=new char[3];
	}

	out<<"---Board of ultimate tic tac toe without miniboards---"<<endl<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board2.bigboard[i][j]!='\0')
				out<<board2.bigboard[i][j]<<" ";
			else
				out<<"- ";
		}
		out<<endl;
	}

	out<<endl<<"---Board of ultimate tic tac toe with miniboards---"<<endl<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int a=0;a<3;a++)
			{
				board2.arr2[i][a].getarr(ptr);
				for(int b=0;b<3;b++)
				{
					if(ptr[j][b]!='\0')
						out<<ptr[j][b]<<" ";

					else
						out<<"- ";
				}
				out<<" ";
			}
			out<<endl;
		}
		out<<endl;
	}
}

void ultimateTicTacToe::getmove(char move,const ultimateTicTacToe& board2,int& boxrow,int& boxcol,int play[3][3])
{
	char** ptr=new char*[3];
	for(int i=0;i<3;i++)
	{
		ptr[i]=new char[3];
	}
	int row;
	int col;
	bool flag=true;
		while(flag==true)
		{
			row=-1;
			col=-1;
			while (row<1 || row>3)
			{
				cout<<"Enter the Row number: ";
				cin>>row;
				if (row<1 || row>3)
				{
					cout<<"Please enter a Row number in the range 1 to "<<3<<": "<<endl;
				}
			}
			while (col<1 || col>3)
			{
				cout<<"Enter the Column number: ";
				cin>>col;
				if(col<1 || col>3) 
				{
					cout<<"Please enter a Column number in the range 1 to "<<3<<": "<<endl;
				}
				cout<<endl;
			}
			row--;
			col--;
			board2.arr2[boxrow][boxcol].getarr(ptr);
			if (ptr[row][col]=='\0') 
			{
				ptr[row][col]=move;
				board2.arr2[boxrow][boxcol].setarr(ptr);

				if(play[row][col]==0)
				{
					boxrow=row;
					boxcol=col;
				}
				else
				{
					bool correct=false;
					while(correct==false)
					{
						bool flag2=false;
						cout<<"The player has taken a turn that points you to a board that is already complete"<<endl;
						cout<<"Before displaying board. Next player tell on which board do you want to take your next turn?"<<endl;
						while(flag2==false)
						{
							flag2=true;
							cout<<"Row: ";
							cin>>boxrow;
							if(boxrow<=0 || boxrow>3)
								flag2=false;
							boxrow--;
							cout<<"Column: ";
							cin>>boxcol;
							if(boxcol<=0 || boxcol>3)
								flag2=false;
							boxcol--;
							if(flag2==false)
								cout<<"Invalid Row/Column..Try Again"<<endl;
						}
						if(play[boxrow][boxcol]==0)
						{
							correct=true;
						}
						else
						{
							cout<<"Board can not be chosen..Try again"<<endl;
							correct=false;
						}
					}
				}
				flag=false;
			}
			else 
			{
				cout<<"The selected space is already occupied !"<<endl<<"Please enter a valid set of row and column !"<<endl<<endl;
			}
		}

		int win=0,num;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				win=board2.arr2[i][j].winner();
				num=number(i,j);
				if(win==1)
				{
					if(play[i][j]!=1)
					{
						cout<<"------ PLAYER 1 WINS ON MINIBOARD "<<num<<"! ------"<<endl;
					}
					play[i][j]=1;
					board2.bigboard[i][j]='x';
				}
				else if(win==2)
				{
					if(play[i][j]!=1)
					{
						cout<<"------ PLAYER 2 WINS ON MINIBOARD "<<num<<"! ------"<<endl;
					}
					play[i][j]=1;
					board2.bigboard[i][j]='o';
				}
				else if(win==3)
				{
					if(play[i][j]!=0)
					{
						cout<<"------ MATCH DRAWN ON MINIBOARD "<<num<<"! ------"<<endl;
					}
					play[i][j]=1;
					board2.bigboard[i][j]='D';
				}
			}
		}
}

void ultimateTicTacToe::getboard(char** farr)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			farr[i][j]=bigboard[i][j];
		}
	}
}

void ultimateTicTacToe::getthatarray(char** thatarr,const ultimateTicTacToe& board2,int a,int b)
{
	board2.arr2[a][b].getarr(thatarr);
}

void ultimateTicTacToe::setthatarray(char** thatarr,ultimateTicTacToe& board2,int a,int b)
{
	board2.arr2[a][b].setarr(thatarr);
}
int main()
{
	int game;
	cout<<"Which game do you want to play?"<<endl;
	cout<<"Press 1 to play ultimate Tic Tac Toe"<<endl;
	cout<<"Press 2 to play simple Tic Tac Toe"<<endl;
	cin>>game;
	if(game==1)
	{
	int play[3][3]={0};
	ultimateTicTacToe board2(3);
	int boxrow,boxcol,win=0,count=1,fwin=0,s=0,gametype;
	char** finalarr=new char*[3];
	for(int i=0;i<3;i++)
	{
		finalarr[i]=new char[3];
	}

	char** thatarr=new char*[3];
	for(int i=0;i<3;i++)
	{
		thatarr[i]=new char[3];
	}

	cout<<"---Choose one of the following options---"<<endl;
	cout<<"1-To start a new game"<<endl;
	cout<<"2-To load previous game"<<endl;
	cin>>gametype;
	if(gametype==1)
	{
		while(win==0 && fwin==0)
		{
			if(count==1)
			{
				boxrow=1;
				boxcol=1;
			}
			if(count%2==1)
			{
				cout<<endl<<"---Player1 turn---"<<endl;
				board2.getmove('x',board2,boxrow,boxcol,play);
				board2.getboard(finalarr);
				fwin=finalwin(finalarr);
			}
			else
			{
				cout<<endl<<"---Player2 turn---"<<endl;
				board2.getmove('o',board2,boxrow,boxcol,play);
				board2.getboard(finalarr);
				fwin=finalwin(finalarr);
			}
			count++;
			cout<<board2;

			if(win==0)
			{
				cout<<"Enter 1 to save game or any other number to continue:" ;
				cin>>s;
				cout<<endl;
			}
			if(s==1)
			{
				ofstream MyWriteFile;
				MyWriteFile.open("SaveUltimategame.txt");
				for(int a=0;a<3;a++)
				{
					for(int b=0;b<3;b++)
					{
						board2.getthatarray(thatarr,board2,a,b);
						for(int i=0;i<3;i++)
						{
							for(int j=0;j<3;j++)
							{
								MyWriteFile<<thatarr[i][j]<<endl;
							}
						}
					}
				}
				MyWriteFile.close();
					
				MyWriteFile.open("Saveultimateboard.txt");
				board2.getboard(finalarr);
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						MyWriteFile<<finalarr[i][j]<<endl;
					}
				}
				MyWriteFile.close();
					
				MyWriteFile.open("SaveVariables.txt");
				MyWriteFile<<count<<endl;
				MyWriteFile<<boxrow<<endl;
				MyWriteFile<<boxcol<<endl;
				MyWriteFile.close();

				MyWriteFile.open("SaveBoxStatus.txt");
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						MyWriteFile<<play[i][j]<<endl;
					}
				}
				MyWriteFile.close();
			}
	
			if(fwin==1)
				cout<<"---- PLAYER 1 WINS ON BIG BOARD...CONGRATULATIONS!!!!! ----"<<endl;
			else if(fwin==2)
				cout<<"---- PLAYER 2 WINS ON BIG BOARD...CONGRATULATIONS!!!!! ----"<<endl;
			else if(fwin==3)
				cout<<"---MATCH DRAWN---"<<endl;
		}
	}
	else if(gametype==2)
	{
		ifstream MyReadFile;
		MyReadFile.open("SaveBoxStatus.txt");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				MyReadFile>>play[i][j];
			}
		}
		MyReadFile.close();

		MyReadFile.open("SaveVariables.txt");
		MyReadFile>>count;
		MyReadFile>>boxrow;
		MyReadFile>>boxcol;
		MyReadFile.close();

		MyReadFile.open("Saveultimateboard.txt");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				MyReadFile>>finalarr[i][j];
			}
		}
		MyReadFile.close();

		MyReadFile.open("SaveUltimategame.txt");
		for(int a=0;a<3;a++)
		{
			for(int b=0;b<3;b++)
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						MyReadFile>>thatarr[i][j];
					}
				}
				board2.setthatarray(thatarr,board2,a,b);
			}
		}
		MyReadFile.close();
		cout<<"Your Previous game board:"<<endl;
		cout<<board2;
		while(win==0 && fwin==0)
		{
			if(count==1)
			{
				boxrow=1;
				boxcol=1;
			}
			if(count%2==1)
			{
				cout<<endl<<"---Player1 turn---"<<endl;
				board2.getmove('x',board2,boxrow,boxcol,play);
				board2.getboard(finalarr);
				fwin=finalwin(finalarr);
			}
			else
			{
				cout<<endl<<"---Player2 turn---"<<endl;
				board2.getmove('o',board2,boxrow,boxcol,play);
				board2.getboard(finalarr);
				fwin=finalwin(finalarr);
			}
			count++;
			cout<<board2;

			if(win==0)
			{
				cout<<"Enter 1 to save game or any other number to continue:" ;
				cin>>s;
				cout<<endl;
			}
			if(s==1)
			{
				ofstream MyWriteFile;
				MyWriteFile.open("SaveUltimategame.txt");
				for(int a=0;a<3;a++)
				{
					for(int b=0;b<3;b++)
					{
						board2.getthatarray(thatarr,board2,a,b);
						for(int i=0;i<3;i++)
						{
							for(int j=0;j<3;j++)
							{
								MyWriteFile<<thatarr[i][j]<<endl;
							}
						}
					}
				}
				MyWriteFile.close();
					
				MyWriteFile.open("Saveultimateboard.txt");
				board2.getboard(finalarr);
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						MyWriteFile<<finalarr[i][j]<<endl;
					}
				}
				MyWriteFile.close();
					
				MyWriteFile.open("SaveVariables.txt");
				MyWriteFile<<count<<endl;
				MyWriteFile<<boxrow<<endl;
				MyWriteFile<<boxcol<<endl;
				MyWriteFile.close();

				MyWriteFile.open("SaveBoxStatus.txt");
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						MyWriteFile<<play[i][j]<<endl;
					}
				}
				MyWriteFile.close();
			}
	
			if(fwin==1)
				cout<<"---- PLAYER 1 WINS ON BIG BOARD...CONGRATULATIONS!!!!! ----"<<endl;
			else if(fwin==2)
				cout<<"---- PLAYER 2 WINS ON BIG BOARD...CONGRATULATIONS!!!!! ----"<<endl;
			else if(fwin==3)
				cout<<"---MATCH DRAWN---"<<endl;
		}
	}
	}
	else if(game==2)
	{
	int x;
	int win=0,count=1,s=0,gametype;
	cout<<"---Choose one of the following options---"<<endl;
	cout<<"1-To start a new game"<<endl;
	cout<<"2-To load previous game"<<endl;
	cin>>gametype;
	cout<<endl;
	if(gametype==1)
	{
		cout<<"Enter value of n to make n*n board"<<endl;
		cin>>x;
		char **ptr=new char*[x];
		for(int i=0;i<x;i++)
		{
			ptr[i]=new char[x];
		}
		TicTacToe board(x);
		while(win==0)
		{
			if(count%2==1)
			{
				cout<<"---PLayer 1 Turn---"<<endl;
				board.GetMove('x');
				cout<<board;
				win=board.winner();
			}
			else if(count%2==0)
			{
				cout<<"---PLayer 2 Turn---"<<endl;
				board.GetMove('o');
				cout<<board;
				win=board.winner();
			}
			count++;
			if(win==0)
			{
				cout<<"Enter 1 to save game or any other number to continue:" ;
				cin>>s;
				cout<<endl;
			}
			if(s==1)
			{
				board.getarr(ptr);
				ofstream MyWriteFile;
				MyWriteFile.open("Savegame.txt");
				MyWriteFile<<x<<endl;
				MyWriteFile<<count<<endl;
				for(int i=0;i<x;i++)
				{
					for(int j=0;j<x;j++)
					{
						MyWriteFile<<ptr[i][j]<<endl;
					}
				}
				MyWriteFile.close();
			}
		}
		if(win==1)
			cout<<"Player 1 wins"<<endl;
		else if(win==2)
			cout<<"Player 2 wins"<<endl;
		else if(win==3)
			cout<<"Match Draw"<<endl;
	}
	else if(gametype==2)
	{
		int size;
		ifstream MyReadFile;
		MyReadFile.open("Savegame.txt");
		MyReadFile>>size;
		MyReadFile>>count;
		char **ptr=new char*[size];
		for(int i=0;i<size;i++)
		{
			ptr[i]=new char[size];
		}

		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				MyReadFile>>ptr[i][j];
			}
		}
		MyReadFile.close();
		cout<<"Your Previous game board:"<<endl;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(ptr[i][j]=='\0')
				{
					cout<<"- ";
				}
				else
				{
					cout<<ptr[i][j]<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		TicTacToe board(size);
		board.setarr(ptr);
		while(win==0)
		{
			if(count%2==1)
			{
				cout<<"---PLayer 1 Turn---"<<endl;
				board.GetMove('x');
				cout<<board;
				win=board.winner();
			}
			else if(count%2==0)
			{
				cout<<"---PLayer 2 Turn---"<<endl;
				board.GetMove('o');
				cout<<board;
				win=board.winner();
			}
			count++;
			if(win==0)
			{
				cout<<"Enter 1 to save game or any other number to continue:" ;
				cin>>s;
				cout<<endl;
			}
			if(s==1)
			{
				board.getarr(ptr);
				ofstream MyWriteFile;
				MyWriteFile.open("Savegame.txt");
				MyWriteFile<<x<<endl;
				for(int i=0;i<x;i++)
				{
					for(int j=0;j<x;j++)
					{
						MyWriteFile<<ptr[i][j]<<endl;
					}
				}
				MyWriteFile.close();
			}
		}
		if(win==1)
			cout<<"Player 1 wins"<<endl;
		else if(win==2)
			cout<<"Player 2 wins"<<endl;
		else if(win==3)
			cout<<"Match Draw"<<endl;
	}
	
	system("pause");
}
}

int number(int i,int j)
{
	int num;
	if(i==0 && j==0)
		num=1;
	else if(i==0 && j==1)
		num=2;
	else if(i==0 && j==2)
		num=3;
	else if(i==1 && j==0)
		num=4;
	else if(i==1 && j==1)
		num=5;
	else if(i==1 && j==2)
		num=6;
	else if(i==2 && j==0)
		num=7;
	else if(i==2 && j==1)
		num=8;
	else if(i==2 && j==2)
		num=9;
	return num;
}

int finalwin(char** ptr2)
{
	int count=0,n=3;
	char prev,sign='f';
	bool finish=false,win=false;
	
	for(int a=0;a<n;a++)
	{
		count=1;
		prev=ptr2[a][0];
		for(int b=1;b<n;b++)
		{
			if(ptr2[a][b]==prev && ptr2[a][b]!='\0')
			{
				count++;
				prev=ptr2[a][b];
			}
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	for(int a=0;a<n;a++)
	{
		count=1;
		prev=ptr2[0][a];
		for(int b=1;b<n;b++)
		{
			if(ptr2[b][a]==prev && ptr2[b][a]!='\0')
			{
				count++;
				prev=ptr2[b][a];
			}
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	count=1;
	prev=ptr2[0][0];
	for(int a=1;a<n;a++)
	{
		if(ptr2[a][a]==prev && ptr2[a][a]!='\0')
		{
			count++;
			prev=ptr2[a][a];
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	count=1;
	prev=ptr2[0][n-1];
	for(int a=1,b=n-2;a<n;a++,b--)
	{
		if(ptr2[a][b]==prev && ptr2[a][b]!='\0')
		{
			count++;
			prev=ptr2[a][b];
		}
		if(count==n)
		{
			sign=prev;
			win=true;
			a=n;
		}
	}

	if(win!=true)
	{
		finish=true;
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(ptr2[a][b]=='\0')
				{
					finish=false;
					b=n;
					a=n;
				}
			}
		}
	}

	if(finish==true)
	{
		sign='d';
	}

	if(sign=='x')
		return 1;
	else if(sign=='o')
		return 2;
	else if(sign=='d')
		return 3;
	else
		return 0;
} 