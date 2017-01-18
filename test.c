#include <stdio.h>
#include <stdbool.h>
#include<time.h>

char board1[10][10];
int boat1[3][5];
int boat2[3][5];
int a_board1[10][10];
int boats_sunk=0;
int i;
int j;
int user_input;
int hit=0;
int miss=0;
int trials=0;

void create_boats(void)
{
	for(int boats=0;boats<3;boats++)
	{
		boat1[boats][2]=0;
		boat2[boats][2]=0;
		boat1[boats][5]=0;
		boat1[boats][3]=3;
		boat2[boats][3]=2;
		boat2[boats][5]=0;
	}
}
void create_board(void)
{
	for(int i=0;i<10;i++)
			{
				for(int j=0;j<10;j++)
				{
					board1[i][j]='0';
					a_board1[i][j]=0;
				}
			}	
}

void create_a_board(void)
{
	int i;
	int j;
	int h_or_v;
	int boat;
	srand(time(NULL));
		for(boat=0;boat<3;boat++)
		{
			h_or_v=rand()%2;
			if(h_or_v==1)
				{
					i=((rand()%7)+1);
					j=((rand()%7)+1);
					if(a_board1[i][j]<1&&a_board1[i+1][j]<1&&a_board1[i+2][j]<1)
					{
						boat1[boat][0]=i;
						boat1[boat][1]=j;
						boat1[boat][4]=h_or_v;
						a_board1[i][j]=1;
						a_board1[i+1][j]=1;
						a_board1[i+2][j]=1;
					}
					else
					{
						boat--;
					}
				}
			else 
				{
					i=((rand()%7)+1);
					j=((rand()%7)+1);
					if(a_board1[i][j]<1&&a_board1[i][j+1]<1&&a_board1[i][j+2]<1)
					{
						boat1[boat][0]=i;
						boat1[boat][1]=j;
						boat1[boat][4]=h_or_v;
						a_board1[i][j]=1;					
						a_board1[i][j+1]=1;
						a_board1[i][j+2]=1;
					}
					else
					{
						boat--;
					}
				}
		}
		for(boat=0;boat<3;boat++)
		{
			h_or_v=rand()%2;
			if(h_or_v==1)
				{
					i=((rand()%7)+1);
					j=((rand()%7)+1);
					if(a_board1[i][j]<1&&a_board1[i+1][j]<1)
					{
						boat2[boat][0]=i;
						boat2[boat][1]=j;
						boat2[boat][4]=h_or_v;
						a_board1[i][j]=1;
						a_board1[i+1][j]=1;
					}
					else
					{
						boat--;
					}
				}
			else 
				{
					i=((rand()%7)+1);
					j=((rand()%7)+1);
					if(a_board1[i][j]<1&&a_board1[i][j+1]<1)
					{
						boat2[boat][0]=i;
						boat2[boat][1]=j;
						boat2[boat][4]=h_or_v;
						a_board1[i][j]=1;
						a_board1[i][j+1]=1;
					}
					else
					{
						boat--;
					}
				}
		}
}

void print_board(user_input)
{
	int i,j;
	if(user_input==1)
		{
			for( i=0;i<10;i++)
			{
				for( j=0;j<10;j++)
				{
					printf("%c|",board1[i][j]);
				}
			printf("\n");
			}
		}
	else if(user_input==2)
		{
			printf("User's Board\n");
			for( i=0;i<10;i++)
			{
				for( j=0;j<10;j++)
				{
					printf("%c|",board1[i][j]);
				}
			printf("\n");
			}
		printf("\n\nAnswer Board\n");
			for( i=0;i<10;i++)
			{
				for( j=0;j<10;j++)
				{
					printf("%d|",a_board1[i][j]);
				}
			printf("\n");
			}
		}
}

int game_won(void)
{
	int boats;
	for (boats=0;boats<3;boats++)
	{
		if (boat1[boats][5]==1)
			{		
				boats_sunk+=1;
			}
		if (boat2[boats][5]==1)
			{		
				boats_sunk+=1;
			}
	}
	if (boats_sunk<6)
	{
	return 0;
	boats_sunk=0;
	}
	else
	{
	return 1;
	}
}
void check_boats(void)
{
	for(int boats=0;boats<3;boats++)
		{
			if (boat1[boats][2]==boat1[boats][3])
				{		
					boat1[boats][5]=1;
				}
			if (boat2[boats][2]==boat2[boats][3])
				{		
					boat2[boats][5]=1;
				}
		}
}

void hit_or_miss(void)
{
	int i;
	int j;	
	printf("Input a row and column to fire at!");
	scanf("%d %d",&i,&j);
	if (a_board1[i-1][j-1]>0)
	{
		board1[i-1][j-1]='X';
		print_board(user_input);
		printf("You hit a boat!");
		check_boats();
		hit+=1;
	}
	else
	{
		board1[i-1][j-1]='-';
		print_board(user_input);
		printf("You missed, try again.");
		miss+=1;
	}
	trials+=1;
	printf("Number of trials: %i\tNumber of hits: %i\tNumber of misses: %i\n",trials,hit,miss);
}
int main(void)
{
	printf("Choose a mode:\n1) Normal mode\n2)Test mode\n");
	scanf("%i",&user_input);
	create_board();
	create_a_board();
	printf("\n\n");
	print_board(user_input);
	while(game_won()==0)
		{hit_or_miss();}
}
