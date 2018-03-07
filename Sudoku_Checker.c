//#include <iostream.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>


//gcc -o sdk Sudoku_Checker.c

//Global variables..
#define NUM_THREADS 9
int globalCount = 0;
//Just in case we need a mutex.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Might come in handy.
typedef int bool;
#define true 1
#define false 0

//The main array...
int array [9][9] = {
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
int arrayIncorrect [9][9] = {
  {1, 4, 7, 2, 5, 5, 3, 6, 9},
  {2, 5, 8, 3, 6, 9, 4, 7, 1},
  {3, 6, 9, 4, 7, 1, 5, 8, 2},
  {4, 7, 1, 5, 8, 3, 6, 9, 3},
  {5, 8, 2, 6, 9, 2, 7, 1, 4},
  {6, 9, 3, 7, 1, 4, 8, 2, 5},
  {7, 1, 4, 4, 2, 2, 9, 3, 6},
  {8, 2, 5, 9, 3, 6, 1, 4, 7},
  {9, 3, 6, 1, 4, 7, 2, 5, 8},
};

//These are the arrays that hold the key for the 3by3 checker...what to search for.
int globalArray0[2] = {0, 0};
int globalArray1[2] = {0, 3};
int globalArray2[2] = {0, 6};
int globalArray3[2] = {3, 0};
int globalArray4[2] = {3, 3};
int globalArray5[2] = {3, 6};
int globalArray6[2] = {6, 6};
int globalArray7[2] = {6, 3};
int globalArray8[2] = {6, 0};

//FUNCTION DELCARATIONS
void* colChecker();
void* rowChecker();
void* tbtchecker(void* params);
void* colCheckerIncorrect();
void* rowCheckerIncorrect();
void* tbtcheckerIncorrect(void* params);
//main process thread
int main(int argc, char const *argv[]) {

  /* the threads IDs */
  pthread_t threads[11];



if(strcmp(argv[1],"1")==0)
{
  /* Initializes the threads */
  pthread_create(&threads[0], NULL, colChecker, NULL);
  pthread_create(&threads[1], NULL, rowChecker, NULL);
  pthread_create(&threads[2], NULL, tbtchecker, globalArray0);
  pthread_create(&threads[3], NULL, tbtchecker, globalArray1);
  pthread_create(&threads[4], NULL, tbtchecker, globalArray2);
  pthread_create(&threads[5], NULL, tbtchecker, globalArray3);
  pthread_create(&threads[6], NULL, tbtchecker, globalArray4);
  pthread_create(&threads[7], NULL, tbtchecker, globalArray5);
  pthread_create(&threads[8], NULL, tbtchecker, globalArray6);
  pthread_create(&threads[9], NULL, tbtchecker, globalArray7);
  pthread_create(&threads[10], NULL, tbtchecker, globalArray8);

  /* Joins the threads and waits for them to finish executing */
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
  pthread_join(threads[3], NULL);
  pthread_join(threads[4], NULL);
  pthread_join(threads[5],NULL);
  pthread_join(threads[6], NULL);
  pthread_join(threads[7],NULL);
  pthread_join(threads[8],NULL);
  pthread_join(threads[9], NULL);
  pthread_join(threads[10], NULL);

  if(globalCount == 11) //globalcount keeps track of how many correct threads have occured...so 11 = all success
  {
    printf(" \n Global Count: %d \n This is a correct solution!", globalCount);
  }
}
else{
  /* Initializes the threads */
  pthread_create(&threads[0], NULL, colCheckerIncorrect, NULL);
  pthread_create(&threads[1], NULL, rowCheckerIncorrect, NULL);
  pthread_create(&threads[2], NULL, tbtcheckerIncorrect, globalArray0);
  pthread_create(&threads[3], NULL, tbtcheckerIncorrect, globalArray1);
  pthread_create(&threads[4], NULL, tbtcheckerIncorrect, globalArray2);
  pthread_create(&threads[5], NULL, tbtcheckerIncorrect, globalArray3);
  pthread_create(&threads[6], NULL, tbtcheckerIncorrect, globalArray4);
  pthread_create(&threads[7], NULL, tbtcheckerIncorrect, globalArray5);
  pthread_create(&threads[8], NULL, tbtcheckerIncorrect, globalArray6);
  pthread_create(&threads[9], NULL, tbtcheckerIncorrect, globalArray7);
  pthread_create(&threads[10], NULL, tbtcheckerIncorrect, globalArray8);

  /* Joins the threads and waits for them to finish executing */
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
  pthread_join(threads[3], NULL);
  pthread_join(threads[4], NULL);
  pthread_join(threads[5],NULL);
  pthread_join(threads[6], NULL);
  pthread_join(threads[7],NULL);
  pthread_join(threads[8],NULL);
  pthread_join(threads[9], NULL);
  pthread_join(threads[10], NULL);
  if(globalCount != 11) //globalcount keeps track of how many correct threads have occured...so 11 = all success
  {
    printf(" \n Global Count: %d \n This is not a solution!", globalCount);
  }
}

  /* exit */
  pthread_exit(NULL);
  return 0;
}

//checks columns for digits 1 through 9
void* colChecker() {

    for(int i = 0; i < 9; i++) //Outer loop for each column
    {
      //Local count keeps track of each individual column of how many numbers weve seen that are unique
      int count = 0;
      int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //Local array, to allow us to keep track of the numbers weve seen.
      for(int j = 0; j < 9; j++) //Inner loop for each number in the column
      {
        for(int k = 0; k < 9; k++)//Inner loop for checking every number in the column with the array
        {
          if(j == 8) //We are at the end of a column...so
          {
            if(array[j][i] == num[k]) //Check to see if it is the same as what is in the array
            {
              count++; //If it is, then add it to the count
              num[k] = 0; //Turn the array place to 0.
              if(count == 9) //if count = 9, then we have found all numbers in the column.
              {
                continue; //So we can continue onward in the check.
              }
              else
              {
                return NULL; //Otherwise, not all columns are correct, so we have to return.
              }
            }
            if(k == 8 && count != 9) //We need to make sure that we catch this...if we are on the last of the array, and j = 8
            //and the count is not 9...then we have a problem.
            {
              return NULL;
            }
            continue; //Continue onward with the k's
          }
          if(array[j][i] == num[k])//Normally...when j is not 8, we simply look through and add to count if they match.
          {
            //printf("%d ", k);
            count++;
            num[k] = 0;
            break;
          }
      }
    }
  }
    globalCount += 1; //IF WE GET THROUGH THE LOOP! ITS A SUCCESS! ADD TO THE COUNT
}

//LITERALLY DOES THE SAME EXACT THING AS THE COLUMN COUNTER BUT FLIPS THE I AND J VALUES
void* rowChecker() {
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
              return NULL;
            }
          }
          if(k == 8 && count != 9)
          {
            return NULL;
          }
          continue;
        }
        if(array[i][j] == num[k])
        {
          printf("%d", k);
          count++;
          num[k] = 0;
          break;
        }
    }
  }
}
  globalCount += 1; //IF WE GET THROUGH THE LOOP! ITS A SUCCESS! ADD TO THE COUNT
}

void* tbtchecker(void* params){ //CHECKS EVERY SINGLE 3 by 3 SQUARE

  //Pass in an array with two numbers in it...the indexes of what we are to search.
  int *thisArray = (int *) params;
  int x = thisArray[0]; //The rows...Comes from the arrays that are global.
  int y = thisArray[1];//The columns...from global array.
  //Pass in 2 indexes.....(0, 0)...(0, 3), and so on...and this loop will take those indexes are search a 3x3 grid inside of the
  //main array, and return the result.

  //The array to keep track of numbers
  int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //Local count to make sure we found all 9.
  int count = 0;
  //Outer loop -- Adding 3 to x allows us to get every single box in the sudoku puzzle.
  for (int i = x; i < x+3; i++) {
    //Inner Loop
    for (int j = y; j < y+3; j++) { //Add 3 to y, depending on the input allows us to get every box.
      //Inner Inner Loop for checking every thing in array against the local array.
      for(int k = 0; k < 9; k++)
      {
        if(array[i][j] == num[k]) //If they equal one another...
        {
          num[k] = 0; //Set local array to be 0 at that point.
          break;
        }
      }
    }
  }
  for(int i = 0; i < 9; i++) //If every single thing in the local array is 0...then every number has been found.
  {
    if(num[i] == 0)
    {
      count++;
    }
  }
  if(count == 9) //If count is 9..everything has been found.
  {
    globalCount += 1; //Add to the global count.
  }

  return NULL;
}




//INCORRECT METHODS

void* tbtcheckerIncorrect(void* params){ //CHECKS EVERY SINGLE 3 by 3 SQUARE

  //Pass in an array with two numbers in it...the indexes of what we are to search.
  int *thisArray = (int *) params;
  int x = thisArray[0]; //The rows...Comes from the arrays that are global.
  int y = thisArray[1];//The columns...from global array.
  //Pass in 2 indexes.....(0, 0)...(0, 3), and so on...and this loop will take those indexes are search a 3x3 grid inside of the
  //main array, and return the result.

  //The array to keep track of numbers
  int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //Local count to make sure we found all 9.
  int count = 0;
  //Outer loop -- Adding 3 to x allows us to get every single box in the sudoku puzzle.
  for (int i = x; i < x+3; i++) {
    //Inner Loop
    for (int j = y; j < y+3; j++) { //Add 3 to y, depending on the input allows us to get every box.
      //Inner Inner Loop for checking every thing in array against the local array.
      for(int k = 0; k < 9; k++)
      {
        if(arrayIncorrect[i][j] == num[k]) //If they equal one another...
        {
          num[k] = 0; //Set local array to be 0 at that point.
          break;
        }
      }
    }
  }
  for(int i = 0; i < 9; i++) //If every single thing in the local array is 0...then every number has been found.
  {
    if(num[i] == 0)
    {
      count++;
    }
  }
  if(count == 9) //If count is 9..everything has been found.
  {
    globalCount += 1; //Add to the global count.
  }

  return NULL;
}

void* colCheckerIncorrect() {

    for(int i = 0; i < 9; i++) //Outer loop for each column
    {
      //Local count keeps track of each individual column of how many numbers weve seen that are unique
      int count = 0;
      int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //Local array, to allow us to keep track of the numbers weve seen.
      for(int j = 0; j < 9; j++) //Inner loop for each number in the column
      {
        for(int k = 0; k < 9; k++)//Inner loop for checking every number in the column with the array
        {
          if(j == 8) //We are at the end of a column...so
          {
            if(arrayIncorrect[j][i] == num[k]) //Check to see if it is the same as what is in the array
            {
              count++; //If it is, then add it to the count
              num[k] = 0; //Turn the array place to 0.
              if(count == 9) //if count = 9, then we have found all numbers in the column.
              {
                continue; //So we can continue onward in the check.
              }
              else
              {
                return NULL; //Otherwise, not all columns are correct, so we have to return.
              }
            }
            if(k == 8 && count != 9) //We need to make sure that we catch this...if we are on the last of the array, and j = 8
            //and the count is not 9...then we have a problem.
            {
              return NULL;
            }
            continue; //Continue onward with the k's
          }
          if(arrayIncorrect[j][i] == num[k])//Normally...when j is not 8, we simply look through and add to count if they match.
          {
            count++;
            num[k] = 0;
            break;
          }
      }
    }
  }
    globalCount += 1; //IF WE GET THROUGH THE LOOP! ITS A SUCCESS! ADD TO THE COUNT
}

//LITERALLY DOES THE SAME EXACT THING AS THE COLUMN COUNTER BUT FLIPS THE I AND J VALUES
void* rowCheckerIncorrect() {
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
          if(arrayIncorrect[i][j] == num[k])
          {
            count++;
            num[k] = 0;

            if(count == 9)
            {
              continue;
            }
            else
            {
              return NULL;
            }
          }
          if(k == 8 && count != 9)
          {
            return NULL;
          }
          continue;
        }
        if(arrayIncorrect[i][j] == num[k])
        {
          count++;
          num[k] = 0;
          break;
        }
    }
  }
}
  globalCount += 1; //IF WE GET THROUGH THE LOOP! ITS A SUCCESS! ADD TO THE COUNT
}
