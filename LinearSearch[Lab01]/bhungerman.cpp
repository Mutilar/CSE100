/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 9/12/2018
*    Description: Linearly searching an array of data
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int search(int values[], int length, int target) {
  for(int i = 0; i < length; i++) {    
    if (target == values[i])
    {
      return i;
    }
  }
  return -1;
}

int main() {
  /*First Input: Length of Array*/
  int length;
  cin >> length;
  int values[length];
  /*Take in Target Value*/
  int target = 0;
  cin >> target;
  /*Take in Array Values*/
  for (int i = 0; i < length; i++) {
      cin >> values[i];
  }
  /*Print Result*/
  cout << search(values, length, target) << "\n";
  return 0;
}