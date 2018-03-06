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
int totalCount = 1;
int insideCount = 0;
int circleX = 100;
int circleY = 100;

//SQUARE IS 200X200

double numGeneratorX(){
  srand(time(0));
  double xCoor = rand() % 200;
  return xCoor;
}

double numGeneratorY(){
    double yCoor = rand() % 200;
    return yCoor;
}

int main() {
  //double xCoor = numGeneratorX();
  //int yCoor = numGeneratorY();

  int square[200][200];
  int radius = 100;


  double pi = (4 * insideCount) / totalCount;
  printf("The estimated value of Pi is %f \n", pi);



  return 0;
}

void pointGenerator(){
  double xCoor = numGeneratorX();
  double yCoor = numGeneratorY();

  if (sqrt(((xCoor - circleX)*(xCoor - circleX) + ((yCoor - circleY)*(yCoor - circleY))) < 100)) {
    totalCount++;
    insideCount++;
  }
  else {
    totalCount++;
  }
  return;
}


//function to check whether point is in cirlce or not
  //if point is greater than radius, it is outside the circle
