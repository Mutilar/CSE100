/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 9/22/2018
*    Description: Finding the largest Subarray
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maximize(int arr[], int len)
{
  int max_final = arr[0], max_current = arr[0];
  
  /* Instead of recursion, which is inherently less efficient memorize-wise,
     I've implemented Kadane's Algorithm, which is both faster [O(n) versus O(nlogn)] and more memory efficient
  */
  for (int i = 1; i < len; i++)
  {
    int val = arr[i];
    max_final = max(val, max_final + val);
    max_current = max(max_current, max_final);
  }
  return max_current;
}

int main()
{
  int len;
  /*First Input: Length of Array*/
  cin >> len;
  int values[len];
  /*Take in Array Values*/
  for (int i = 0; i < len; i++)
  {
    cin >> values[i];
  }
  /*Maximize Array*/
  cout << maximize(values, len);
  return 0;
}