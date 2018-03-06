//#include <iostream.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>


//gcc -o sdk Sudoku_Checker.c

#define NUM_THREADS 9


typedef int bool;
#define true 1
#define false 0

int successBoard [9][9] = {
  {1, 4, 7, 2, 5, 8, 3, 6, 9},
  {2, 5, 8, 3, 6, 9, 4, 7, 1},
  {3, 6, 9, 4, 7, 1, 5, 8, 2},
  {4, 7, 1, 5, 8, 2, 6, 9, 3},
  {5, 8, 2, 6, 9, 3, 7, 1, 4},
  {6, 9, 3, 7, 1, 4, 8, 2, 5},
  {7, 1, 4, 8, 2, 5, 9, 3, 6},
  {8, 2, 5, 9, 3, 6, 1, 4, 7},
  {9, 3, 6, 1, 4, 7, 2, 5, 8},
};

int failBoard[9][9] ={
  {1, 4, 7, 2, 5, 8, 3, 6, 9},
  {2, 5, 3, 8, 6, 9, 4, 7, 1},
  {3, 6, 9, 4, 7, 1, 5, 8, 2},
  {4, 7, 1, 5, 8, 2, 6, 9, 3},
  {5, 8, 2, 6, 9, 3, 7, 1, 4},
  {6, 9, 3, 7, 1, 4, 8, 2, 5},
  {7, 1, 6, 8, 2, 5, 9, 3, 4},
  {8, 2, 5, 9, 3, 6, 1, 4, 7},
  {9, 3, 6, 1, 4, 1, 2, 5, 8},
};

//pthread_create (thread, attribute, start_routine, argument)
int colChecker(int array[9][9]);
int rowChecker(int array[9][9]);
int tbtchecker(int array[9][9], int x, int y);

//main process thread
int main(int argc, char const *argv[]) {

  /* the threads IDs */
  pthread_t thread_cols, thread_rows, thread_tbt1, thread_tbt2, thread_tbt3,
    thread_tbt4, thread_tbt5, thread_tbt6, thread_tbt7, thread_tbt8, thread_tbt9;

  /* Initializes the threads */
  pthread_create(&thread_cols, NULL, colChecker, );
  pthread_create(&thread_rows, NULL, rowChecker, );
  pthread_create(&thread_tbt1, NULL, tbtchecker, );
  pthread_create(&thread_tbt2, NULL, tbtchecker, );
  pthread_create(&thread_tbt3, NULL, tbtchecker, );
  pthread_create(&thread_tbt4, NULL, tbtchecker, );
  pthread_create(&thread_tbt5, NULL, tbtchecker, );
  pthread_create(&thread_tbt6, NULL, tbtchecker, );
  pthread_create(&thread_tbt7, NULL, tbtchecker, );
  pthread_create(&thread_tbt8, NULL, tbtchecker, );
  pthread_create(&thread_tbt9, NULL, tbtchecker, );


  /* Joins the threads and waits for them to finish executing */
  pthread_join(thread_cols, );
  pthread_join(thread_rows);
  pthread_join(thread_tbt1);
  pthread_join(thread_tbt2);
  pthread_join(thread_tbt3);
  pthread_join(thread_tbt4);
  pthread_join(thread_tbt5);
  pthread_join(thread_tbt6);
  pthread_join(thread_tbt7);
  pthread_join(thread_tbt8);
  pthread_join(thread_tbt9);


  /* code */
  int hi = rowChecker(successBoard);
  int x = tbtchecker(successBoard, 0, 0);
  int a = tbtchecker(successBoard, 3, 0);
  int b = tbtchecker(successBoard, 6, 0);
  int c = tbtchecker(successBoard, 0, 3);
  int d = tbtchecker(successBoard, 0, 6);
  int e = tbtchecker(successBoard, 3, 3);
  int f = tbtchecker(successBoard, 3, 6);
  int g = tbtchecker(successBoard, 6, 6);
  int h = tbtchecker(successBoard, 6, 3);

  return 0;
}

//checks columns for digits 1 through 9
int colChecker(int array[9][9]) {

    for(int i = 0; i < 9; i++)
    {
      int count = 0;
      int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      for(int j = 0; j < 9; j++)
      {
        for(int k = 0; k < 9; k++)
        {
          if(j == 8)
          {
            if(array[i][j] == num[k])
            {
              count++;
              num[k] = 0;
              if(count == 9)
              {
                continue;
              }
              else
              {
                return 0;
              }
            }
          }
          if(array[i][j] == num[k])
          {
            count++;
            num[k] = 0;
            break;
          }
      }
    }
}
    return 1;
}

int rowChecker(int array[9][9]) {
  for(int i = 0; i < 9; i++)
  {
    int count = 0;
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int j = 0; j < 9; j++)
    {
      for(int k = 0; k < 9; k++)
      {
        if(j == 8)
        {
          if(array[j][i] == num[k])
          {
            count++;
            num[k] = 0;
            if(count == 9)
            {
              continue;
            }
            else
            {
              return 0;
            }
          }
        }
        if(array[j][i] == num[k])
        {
          count++;
          num[k] = 0;
          break;
        }
    }
  }
}
  return 1;
}

int tbtchecker(int array[9][9], int x, int y){

  int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int count = 0;
  for (int i = x; i < x+3; i++) {
    for (int j = y; j < y+3; j++) {
      for(int k = 0; k < 9; k++)
      {
        if(array[i][j] == num[k])
        {
          num[k] = 0;
          break;
        }
      }
    }
  }
  for(int i = 0; i < 9; i++)
  {
    if(num[i] == 0)
    {
      count++;
    }
  }
  if(count == 9)
  {
    return 1;
  }

  return 0;
}
