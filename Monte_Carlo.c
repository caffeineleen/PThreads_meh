//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <math.h>

//gcc -o mc Monte_Carlo.c

//PUT DEFINITIONS HERE
double numGeneratorX();
double numGeneratorY();
void pointGenerator();

//GLOBAL VARIABLE
double totalCount = 1;
double insideCount = 0;
int circleX = 100;
int circleY = 100;

//SQUARE IS 200X200


int main() {
  //double xCoor = numGeneratorX();
  //int yCoor = numGeneratorY();

  int square[200][200];
  int radius = 100;

  srand(time(NULL));

  pointGenerator();
  pointGenerator();
  pointGenerator();
  pointGenerator();
  pointGenerator();

  printf("The estimated value of insideCount is %f \n", insideCount);
  printf("The estimated value of totalCount is %f \n", totalCount);

  double pi = 0;
  if(totalCount != 0)
  {
     pi = (4 * insideCount) / totalCount;
  }
  else
  {
    printf("Nothing inside the circle.");
    return 0;
  }
  printf("Pi = (4 * %f) / %f \n", insideCount, totalCount);
  printf("The estimated value of Pi is %f \n", pi);

  return 0;
}

double numGeneratorX(){

  double xCoor = rand() % 200;
  return xCoor;
}

double numGeneratorY(){
      double yCoor = rand() % 200;
    return yCoor;
}

void pointGenerator(){
  double xCoor = numGeneratorX();
  double yCoor = numGeneratorY();

  printf("%f %f\n", xCoor, yCoor);

  printf("Point Generator: %f \n", sqrt(((xCoor - circleX)*(xCoor - circleX) + ((yCoor - circleY)*(yCoor - circleY)))));

  if (sqrt(((xCoor - circleX)*(xCoor - circleX) + ((yCoor - circleY)*(yCoor - circleY)))) < 100) {
    totalCount++;
    insideCount++;
  }
  else {
    totalCount++;
  }
  return;
}
