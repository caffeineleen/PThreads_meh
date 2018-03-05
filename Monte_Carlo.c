//#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <graphics.h>
#include <time.h>

void *numGenerator (void);

int main() {
  void *numGenerator (void);
  return 0;
}

void *numGenerator (void){
  int i,n;

  srand(time(0));

  for (int i; i < n; i++)  {
    printf("%d\n", rand() % 50);
  }
}
