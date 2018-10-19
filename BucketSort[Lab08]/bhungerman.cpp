/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/13/2018
*    Description: Sorting an inputted array using bucket sort
*
******************************************************************/
//Bucket sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::cout;

void bucketSort(double arr[], int length){
    
    int index = 0;
    vector<double> arr_vec[length];

    for(int i = 0; i < length; i++)
    {
      arr_vec[(int)(arr[i]*length)].push_back(arr[i]);
    }

    for(int i = 0; i < length; i++)
    {
       // sort(arr_vec[i]);
    }

    for(int i = 0; i < length; i++) 
    {
        for(int j = 0; j < arr_vec[i].size(); j++) 
        {
            arr[index++] = arr_vec[i][arr_vec[i].size()-j-1];
        }
    }
}

void sort(double* values, int length) 
{
  for(int i = 1; i < length; i++) 
  {    
    double key = values[i];

    int j = i - 1;
    while(j >= 0 && key < values[j]) 
    {
      values[j + 1] = values[j];
      j--;
    }
    values[j + 1] = key;
  }
}

int main() {

  /*First Input: Length of Array*/
  int length;
  //cout << "Input\n";
  cin >> length;
  double values[length];
  /*Take in Array Values*/
  for (int i = 0; i < length; i++) {
      cin >> values[i];
  }
  /*Sort Array*/
  sort(values, length);
  /*Print Sorted Array*/
  //cout << "Output\n";
  for (int i = 0; i < length; i++) {
      cout << values[i] << "\n";
  }
  return 0;
}