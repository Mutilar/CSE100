/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/6/2018
*    Description: Using Randomized Quicksort to avoid O(N^2) worst-case
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int len;

void quickSort(int *arr, int left, int right)
{
    if ((right - left) > 1)
    {
        //select a value from a random index
        int random_value = arr[(rand() % (right - left) + left)];
        int l = left;
        int r = right;
        r--; //this fixed a bug...
        while (l < r)
        {
            while (l < r && arr[r] > random_value) r--;
            while (l < r + 1 && arr[l] < random_value) l++;

            if (l < r) //swap (fancy way... assuming values aren't close to int.maxsize...)
            {
                arr[l] = arr[l] + arr[r];
                arr[r] = arr[l] - arr[r];
                arr[l] = arr[l] - arr[r];
                l++;
            }
        }
        quickSort(arr, left, l);
        quickSort(arr, r, right);
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
    /*Sorty Sort Sort*/
    quickSort(values, 0, len);
    for (int i = 0; i < len; i++)
    {
        cout << values[i] << ";";
    }
    return 0;
}