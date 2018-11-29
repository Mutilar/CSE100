/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 8/28/2018
*    Description: Sorting an inputted array using insertion sort
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;
   for (i = 0; i < n; i++)
      x[i] = 0.0;
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
   if (i < n)
      x[i] = u / weight[i]; 
   tp = tp + (x[i] * profit[i]);
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
   printf("\nMaximum profit is:- %f", tp);
}

int main() {
  float *w = new float[6] {2,2,4,3,6,5};
   float *p = new float[6] {2,3,7,5,11,6};
  knapsack(6, w , p, 5);
  return 0;
}