#include <stdio.h>
#define N 9

void print(int board[N][N])
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
        	if((j+1)%3==0)
        	{
        		printf("%d| ", board[i][j]);
			}
			else if((i+1)%3==0)
        	{
        		printf("%d__", board[i][j]);
			}
			else
            printf("%d  ", board[i][j]);
        }
        printf("\n\n");
    }
}

int isSafe(int board[N][N], int row, int col, int i)
{
    int a;
    int k,l;
    for(a=0; a<9; a++)
    {
        if(board[row][a]==i)
        {
            return 0;
        }
    }
    for(a=0; a<9; a++)
    {
        if(board[a][col]==i)
            return 0;
    }
    int sr = row - row%3;
    int sc = col - col%3;

    for(k=0; k<3; k++)
    {
        for(l=0; l<3; l++)
        {
            if(board[k+sr][l+sc]==i)
                return 0;
        }
    }
    return 1;
}


int helper(int board[N][N], int row, int col)
{
    int i;
    if(row==N-1 && col==N)
    {
        return 1;
    }
    if (col == N)
    {
        row++;
        col = 0;
    }

    if(board[row][col]>0)
    {
        return helper(board, row, col+1);
    }
    for(i = 1; i<=9; i++)
    {
        if(isSafe(board, row, col, i)==1)
        {
            board[row][col] = i;
            if(helper(board, row, col+1)==1)
            return 1;
            board[row][col] = 0;
        }
    }
        
    return 0;
}

int main()
{
    int board[N][N] = { { 2, 0, 9, 0, 0, 0, 6, 0, 0 },
                       { 0, 4, 0, 8, 7, 0, 0, 1, 2 },
                       { 8, 0, 0, 0, 7, 9, 0, 4, 0 },
                       { 0, 3, 0, 7, 0, 0, 8, 0, 1 },
                       { 0, 6, 5, 0, 0, 8, 0, 3, 0 },
                       { 1, 0, 0, 0, 3, 0, 0, 0, 7 },
                       { 0, 0, 0, 6, 5, 0, 7, 0, 9 },
                       { 6, 0, 4, 0, 0, 0, 0, 2, 0 },
                       { 0, 8, 0, 3, 0, 1, 4, 5, 0 } };
                      
    print(board);
    printf("\n\n");
    if(helper(board, 0, 0)==1)
    {
    	printf("OUTPUT:-\n\n");
    	print(board);
	}
        
    else
        printf("No solution exists\n");

   return 0;
}
