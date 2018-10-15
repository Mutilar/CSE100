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

bool running = true;

void sort(double values[], int length)
{
  for (int i = 1; i < length; i++)
  {
    double key = values[i];
    int j = i - 1;
    while (j >= 0 && key < values[j])
    {
      values[j + 1] = values[j];
      j--;
    }
    values[j + 1] = key;
  }
}

int main()
{

  char command;
  while (running)
  {

    cin >> command;
    switch (command)
    {
    case 'i':
      insert();
      break;
    case 'd':
      insert();
      break;
    case 'i':
      insert();
      break;
    case 'e':
      running = false;
      break;
    }
  }

  /*First Input: Length of Array*/
  int length;
  //cout << "Input\n";
  cin >> length;
  double values[length];
  /*Take in Array Values*/
  for (int i = 0; i < length; i++)
  {
    cin >> values[i];
  }
  /*Sort Array*/
  sort(values, length);
  /*Print Sorted Array*/
  //cout << "Output\n";
  for (int i = 0; i < length; i++)
  {
    cout << values[i] << "\n";
  }
  return 0;
}