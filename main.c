#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void boarde(char x[9][9])
{
  for (int i=0;i<9;i++)
    {
      for (int j=0;j<9;j++)
        {
          x[i][j] = '?';
        }
    }
}

void print_board(char x[9][9])
{
  for (int i=0;i<9;i++)
    {
      for (int j=0;j<9;j++)
        {
          printf(" %c ", x[i][j]);
        }
      printf("\n");
    }
}

void minefield_generator(char y[9][9],char x[9][9])
{
  int k;
  srand(time(0));
  for (int i=0;i<9;i++)
    {
      for (int j=0;j<9;j++)
        {
          k=rand()%10+1;
          if (y[i][j]=='-')
            y[i][j]='-';
          else if (k>=2)
            y[i][j]='-';
          else
            y[i][j]='*';
        }
    }
}

int minefieldcounter(char y[9][9])
{
  int mine_nr=0,blank_nr=0;
  for (int i=0;i<9;i++)
    {
      for (int j=0;j<9;j++)
        {
          if (y[i][j]=='-')
            blank_nr++;
          else
            mine_nr++;
        }
    }
  return mine_nr;
}

void Starter_Area(char x[9][9],int r1,int r2,char y[9][9])
{
   if(r1-1==0 && r2-1==0)
   {
     for (int i=0;i<=1;i++)
       {
         for (int j=0;j<=1;j++)
           {
             y[r1-1+i][r2-1+j]='-';
           }
       }
   }
   else if(r2==9 && r1!=0 && r1!=9)
   {
     for (int i=-1;i<=1;i++)
       {
         for (int j=-1;j<=0;j++)
           {
             y[r1-1+i][r2-1+j]='-';
           }
       }
   }
   else if(r1==9 && r2==9)
   {
     for (int i=-1;i<=0;i++)
       {
         for (int j=-1;j<=0;j++)
           {
             y[r1-1+i][r2-1+j]='-';
           }
       }
   }
   else if(r2-1==0 && r1-1!=0 && r1-1!=9)
   {
    for (int i=-1;i<=1;i++)
      {
        for (int j=0;j<=1;j++)
          {
            y[r1-1+i][r2-1+j]='-';
          }
      }
  }
   else if(r1-1==0 && r2-1 != 0 && r2 !=9)
   {
    for (int i=0;i<=1;i++)
      {
        for (int j=-1;j<=1;j++)
          {
            y[r1-1+i][r2-1+j]='-';
          }
      }
  }
   else if (r1==9 && r2 != 0 && r2!=9)
   {
    for (int i=-1;i<=0;i++)
      {
        for (int j=-1;j<=1;j++)
          {
            y[r1-1+i][r2-1+j]='-';
          }
      }
  }
   else if(r1-1==0 && r2==9)
   {
    for (int i=0;i<=1;i++)
      {
        for (int j=-1;j<=0;j++)
          y[r1-1+i][r2-1+j]='-';
      }

  }
   else if (r1==9 && r2==0)
   {
     for (int i=-1;i<=0;i++)
       {
         for (int j=0;j<=1;j++)
            y[r1-1+i][r2-1+j] = '-';
       }
   }
   else if (r1-1!=0 && r1-1!=9 && r2-1!=0 && r2-1!=9)
   {  for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        y[r1 - 1 + i][r2 - 1 + j] = '-';
      }
    }
  }
}

void checker(char x[9][9],char y[9][9],int r1,int r2)
{
  char cnt=48;
  if(r1-1==0 && r2-1==0)
   {
     for (int i=0;i<=1;i++)
       {
         for (int j=0;j<=1;j++)
           {
             if(y[r1-1+i][r2-1+j]=='*')
              cnt++;
           }
       }
   }
   else if(r2==9 && r1!=0 && r1!=9)
   {
     for (int i=-1;i<=1;i++)
       {
         for (int j=-1;j<=0;j++)
           {
             if(y[r1-1+i][r2-1+j]=='*')
             cnt++;
           }
       }
   }
   else if(r1==9 && r2==9)
   {
     for (int i=-1;i<=0;i++)
       {
         for (int j=-1;j<=0;j++)
           {
             if(y[r1-1+i][r2-1+j]=='*')
               cnt++;
           }
       }
   }
   else if(r2-1==0 && r1-1!=0 && r1-1!=9)
   {
    for (int i=-1;i<=1;i++)
      {
        for (int j=0;j<=1;j++)
          {
            if(y[r1-1+i][r2-1+j]=='*')
              cnt++;
          }
      }
  }
   else if(r1-1==0 && r2-1 != 0 && r2 !=9)
   {
    for (int i=0;i<=1;i++)
      {
        for (int j=-1;j<=1;j++)
          {
            if(y[r1-1+i][r2-1+j]=='*')
              cnt++;
          }
      }
  }
   else if (r1==9 && r2 != 0 && r2!=9)
   {
    for (int i=-1;i<=0;i++)
      {
        for (int j=-1;j<=1;j++)
          {
            if(y[r1-1+i][r2-1+j]=='*')
              cnt++;
          }
      }
  }
   else if(r1-1==0 && r2==9)
   {
    for (int i=0;i<=1;i++)
      {
        for (int j=-1;j<=0;j++)
         if( y[r1-1+i][r2-1+j]=='*')
           cnt++;
      }
  }
   else if (r1==9 && r2==0)
   {
     for (int i=-1;i<=0;i++)
       {
         for (int j=0;j<=1;j++)
           if( y[r1-1+i][r2-1+j] == '*')
             cnt++;
       }
   }
   else if (r1-1!=0 && r1-1!=9 && r2-1!=0 && r2-1!=9)
   {  for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        if (y[r1 - 1 + i][r2 - 1 + j] == '*')
          cnt++;
      }
    }
  }
  x[r1-1][r2-1]=cnt;
}


int main(){

  char board[9][9];
  char mineboard[9][9];
  int r,c;
  printf("This is the board\n\n");
  boarde(board);
  print_board(board);
  printf("Enter wanted cell\n");
  scanf("%d %d", &r, &c);
  Starter_Area(board,r,c,mineboard);
  minefield_generator(mineboard,board);
  checker(board,mineboard,r,c);
  printf("\n\n");
  print_board(board);
  while(minefieldcounter(mineboard)<81-minefieldcounter(mineboard))
    {
      printf("Enter wanted cell\n");
      scanf("%d %d",&r,&c);
      if (mineboard[r-1][c-1]=='*')
      {
        printf("You Lost...\nThis is the mineboard\n");
        print_board(mineboard);
        break;
      }
      checker(board,mineboard,r,c);
      printf("\n\n");
      print_board(board);
    }
  if (minefieldcounter(mineboard)==81-minefieldcounter(mineboard))
    printf("You WIN");
  return 0;
 }
