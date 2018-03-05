//#include <iostream.h>
#include <stdlib.h>
#include <pthread.h>

//gcc -o sdk Sudoku_Checker.c

#define NUM_THREADS 9

typedef struct
{
  int col;
  int row;
  int(*board)[9];
} parameters;

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
void *colChecker(void *param);
void *rowChecker(void *param);
void remove_element(int array[], int index, int array_length);
int tbtChecker(int array[][], int x, int y);

//main process thread
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

//checks columns for digits 1 through 9
void *colChecker(void *param) {

}

void *rowChecker(void *param) {

  int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = 9;
  int count = 0;
  for(int i = 0; i < 9; i++)
  {
    for(int j = 0; j<9; j++)
    {

    }
  }

}

int tbtchecker(int array[][], int x, int y){
  int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = 9;
  int count = 0;
  for (int i = x; i < x+3; i++) {
    if(count == 9)
    {return 1;}
    for (int j = y; j < j+3; j++) {
      for(int k = 1; k < 10; k++)
      {
        if(array[i][j] == num[k])
        {
          remove_element(num, k , length);
          count++;
          break;
        }
      }
    }
  }
  return 0;
}

void remove_element(int array[], int index, int array_length)
{
  for(int i = index; i < array_length; i++)
  {
    array[i] = array[i+1];
  }
  int *tmp = realloc(array, (array_length - 1)* sizeof(array));
  if(tmp == NULL && array_length > 1)
  {
    exit(EXIT_FAILURE);
  }
array_length = array_length - 1;
array = tmp;

}

pthread_exit();
