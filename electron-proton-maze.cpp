#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <conio.h>

// ASCII 48=> 0, ASCII 49=> 1, ASCII 80=> P, ASCII 112=> p, ASCII 75=> K, ASCII 71=> G, ASCII 67=> C, ASCII 88=> X, ASCII 69=> E, ASCII 101=> e

// C is exit, G is starting point.
// 1 is walls and can not pass
// 0 is just a way. You can move on it but nothing happen.
// P is represents p+, E is represents e+, e is represents e-, p is represents p-,
// K ıs represents blackhole. If you go there the game finish with no points!

// The game's aim is collecting as many e+ and p- as you can. Afterwards, these will combine to form an antimatter.
// IMPORTANT NOTE: When you take one e-, one e+ is destroyed. When you take one p+, one p- is destroyed.

int main ()
{
	int N=6, M=10,i,j,A,B,C,k,l,a,b;//N is number of rows, M is number of columns
	static int puan[3];//puan[0]= represents points of e- ,puan[1]= represents points of e+ ,puan[2]= represents points of p- ,puan[3]= represents points of p+
	char hamle;
	
	
	 static char lab[6][10]={{48,48,49,48,80,48,112,48,112,48},
					{49,48,80,48,48,69,49,48,49,48},
					{49,71,49,48,49,48,49,48,48,75},
					{48,48,80,48,112,48,48,48,49,48},
					{48,49,49,48,75,67,49,48,49,48},
					{48,48,48,48,49,48,112,48,48,48}}; // Maze 
							
	

	for(i=0;i<N;i++) // find the starting point and put there the cursor which represents our location
		{
		for(j=0;j<M;j++)
			{
				if(lab[i][j]==71)
					{
					k=i;
					l=j;
					lab[k][l]=88;
					}
				
			}
			
		}
	
	i=k;
	j=l;
	while(lab[i][j]!=75&lab[i][j]!=67) // checking if the exit point has been reached and blackhole
	{
		for(a=0;a<N;a++)
		{
			for(b=0;b<M;b++)
			{
				printf("%4c",lab[a][b]);
			}
			printf("\n");
		}
		
		printf("Make move:\n"); // Take move
		hamle = getch();
		sleep(1);
		system("cls");
		
		if(hamle==27) // Press ESC, Quit from the game
		{
			printf("Cikis\n");
			break;
		}
		else
		{
		if(hamle==80) // move up
			{
				if(i+1<N&lab[i+1][j]!=49&lab[i+1][j]!=75&lab[i+1][j]!=67) //checking for walls and did cursor get out of the maze's border, also did you reach to exit
				{
					if(lab[i+1][j]==101)
					{
						puan[0]=puan[0]+1;
					}
					if(lab[i+1][j]==69)
					{
						puan[1]=puan[1]+1;
					}
					if(lab[i+1][j]==112)
					{
						puan[2]=puan[2]+1;
					}
					if(lab[i+1][j]==80)
					{
					puan[3]=puan[3]+1;
					};
					lab[i][j]=48;
					i=i+1;
					lab[i][j]=88;
				}
			
				else 
				{
					if(i+1>=N) // borders check
					{
					printf("You can not go outside the borders!\n");
					}
					else 
					{
						if(lab[i+1][j]==49) // wall check
						{
							printf("You hit the wall!\n");
						}
						else
						{
							if(lab[i+1][j]==75) // blackhole and exit game next while loop
							{
							lab[i][j]=75;
							
							}
							else // exit
							{
								lab[i][j]=67;
							}
						}
					
					}
				}
			}
		if(hamle==72) // move down
			{
				if(i-1>=0&lab[i-1][j]!=49&lab[i-1][j]!=75&lab[i-1][j]!=67)
					{
						if(lab[i-1][j]==101)
						{
							puan[0]=puan[0]+1;
						}
						if(lab[i-1][j]==69)
						{
							puan[1]=puan[1]+1;
						}
						if(lab[i-1][j]==112)
						{
							puan[2]=puan[2]+1;
						}
						if(lab[i-1][j]==80)
						{
							puan[3]=puan[3]+1;
						};
					lab[i][j]=48;
					i=i-1;
					lab[i][j]=88;
					}
				else
					{
					if(i-1<0)
						{
							printf("You can not go outside the borders!\n");
						}
					else
						{
							if(lab[i-1][j]==49)
						{
							printf("You hit the wall!\n");
						}
						else
						{
							if(lab[i-1][j]==75)
							{
							lab[i][j]=75;
							
							}
							else
							{
								lab[i][j]=67;
							}
						}
						}
					}
			}
		if(hamle==77) // move right
			{
				if(j+1<M&lab[i][j+1]!=49&lab[i][j+1]!=75&lab[i][j+1]!=67)
					{
						if(lab[i][j+1]==101)
						{
							puan[0]=puan[0]+1;
						}
						if(lab[i][j+1]==69)
						{
							puan[1]=puan[1]+1;
						}
						if(lab[i][j+1]==112)
						{
							puan[2]=puan[2]+1;
						}
						if(lab[i][j+1]==80)
						{
							puan[3]=puan[3]+1;
						};
					lab[i][j]=48;
					j=j+1;
					lab[i][j]=88;
					}
				else
					{
					if(j+1>=M)
						{
							printf("You can not go outside the borders\n");
						}
					else
						{
							if(lab[i][j+1]==49)
						{
							printf("You hit the wall!\n");
						}
						else
						{
							if(lab[i][j+1]==75)
							{
							lab[i][j]=75;
							
							}
							if(lab[i][j+1]==67)
							{
								lab[i][j]=67;
							}
						}
						}
					}
			}
		if(hamle==75) // move left
			{
				if(j-1>=0&lab[i][j-1]!=49&lab[i][j-1]!=75&lab[i][j-1]!=67)
					{
						if(lab[i][j-1]==101)
						{
							puan[0]=puan[0]+1;
						}
						if(lab[i][j-1]==69)
						{
							puan[1]=puan[1]+1;
						}
						if(lab[i][j-1]==112)
						{
							puan[2]=puan[2]+1;
						}
						if(lab[i][j-1]==80)
						{
							puan[3]=puan[3]+1;
						};
					lab[i][j]=48;
					j=j-1;
					lab[i][j]=88;
					}
				else
					{
					if(j-1<0)
						{
							printf("You can not go outside the borders\n");
						}
					else
						{
							if(lab[i][j-1]==49)
						{
							printf("You hit the wall!\n");
						}
						else
						{
							if(lab[i][j-1]==75)
							{
							lab[i][j]=75;
							
							}
							else
							{
								lab[i][j]=67;
							}
						}
						}
					}
			}
	
	}
}	
	if(lab[i][j]==67) 
	{
		if(puan[1]<puan[0]) // checking for enough e+
		{
			printf("Not enough e+ to produce antimatter!\n");
		}
		else
		{
			A=puan[1]-puan[0];
			if(puan[3]<puan[2]) // checking for enough p-
			{
				B=puan[2]-puan[3];
				if(A<B)
				{
					C=B/A;
				}
				else
				{
					C=A/B;
				}	
			}
			else
			{
				printf("Not enough p- to produce antimatter!\n");
			}
		}
	printf("You have reached the exit\n your score:%d",C);	
	}
	else
	{
		printf("GG Blackhole :D\n");
	}
	
	
	return 0;
}