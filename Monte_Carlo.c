//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "graphics.h"
#include "winbgim.h"
//#include <conio.h>
#include <time.h>

//gcc -o mc Monte_Carlo.c

//PUT DEFINITIONS HERE

//SQUARE IS 200X200

int numGeneratorX(){
  srand(time(0));
  int xCoor = rand() % 200;
  return xCoor;
}

int numGeneratorY(){
    int yCoor = rand() % 200;
    return yCoor;
}

int main() {
  int xCoor = numGeneratorX();
  int yCoor = numGeneratorY();

  int gd = DETECT, gm;

  //location of the left, top, right, and bottom of square
  int left = 0, top = 0;
  int right = 200, bottom = 200;
  //location of center and radius of circle
  int x = 100, y = 100, radius = 100;

  //initializes graph
  initgraph(&gd, &gm, "");

  //creates rectangle and cirle
  rectangle(left, top, right, bottom);
  circle(x, y, radius);

  getch();
  closegraph();

  return 0;



  //return pi = 4 x (number of points in the circle/total number of points)

}

//void function that grabs generated X and Y vals and return 2 coordinates

//function to check whether point is in cirlce or not
  //if point is greater than radius, it is outside the circle
