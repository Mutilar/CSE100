/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 9/12/2018
*    Description: Binarily searching an array of data
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int search(int values[], int length, int target)
{
  int high = length - 1, low = 0, mid = (low + high) / 2;
  while (low <= high)
  {
    // cout<<"at " << mid;
    if (target == values[mid])
    {
      return mid;
    }
    else if (target > values[mid])
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
    mid = (low + high) / 2;
  }
  return -1;
}

int main()
{
  /*First Input: Length of Array*/
  int length;
  cin >> length;
  int values[length];
  /*Take in Target Value*/
  int target = 0;
  cin >> target;
  /*Take in Array Values*/
  for (int i = 0; i < length; i++)
  {
    cin >> values[i];
  }
  /*Print Result*/
  cout << search(values, length, target);
  return 0;
}