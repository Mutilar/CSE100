/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 9/12/2018
*    Description: Sorting an inputted array using merge sort
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int len;

void merge(int arr[], int low, int mid, int high)
{
  int arr2[len];

  int new_low = low;
  int second_low = new_low;
  int new_mid = mid + 1;
  int new_high = high;
  
  /*Select smallest value between the two subarrays*/
  while (new_low <= mid && new_mid <= new_high)
  {
    if (arr[new_low] <= arr[new_mid])
    {
      arr2[second_low++] = arr[new_low++];
    }
    else
    {
      arr2[second_low++] = arr[new_mid++];
    }
  }
  /*Add the rest of the values in the array if they weren't selected*/
  while (new_low <= mid)
  {
    arr2[second_low++] = arr[new_low++];
  }
  while (new_mid <= new_high)
  {
    arr2[second_low++] = arr[new_mid++];
  }
  /*Copy results to final array*/
  for (int i = low; i <= high; i++)
  {
    arr[i] = arr2[i];
  }
}
void sort(int arr[], int low, int high)
{
  int mid = 0;
  if (high > low)
  {
    mid = (low + high) / 2;
    sort(arr, low, mid);
    sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int main()
{
  /*First Input: Length of Array*/
  cin >> len;
  int values[len];
  /*Take in Array Values*/
  for (int i = 0; i < len; i++)
  {
    cin >> values[i];
  }
  /*Sort Array*/
  sort(values, 0, len-1);
  /*Print Sorted Array*/
  for (int i = 0; i < len; i++)
  {
    cout << values[i] << ";";
  }
  return 0;
}