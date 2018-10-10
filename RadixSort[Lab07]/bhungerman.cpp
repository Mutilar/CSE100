/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/9/2018
*    Description: Using Radix Sort to sort "Vectors"
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int len;

//quick work-around for std:max not suppoorting longs
long maximum(long x, long y)
{
    if (x > y)
        return x;
    return y;
}

void countingSort(long arr[], long pos)
{
    long arr_new[len]; long current[10] = {0}; int i;
    for (i = 0; i < len; i++)
    {
        current[(arr[i] / pos) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        current[i] += current[i-1];
    }
    for (i = len - 1; i >= 0; i--)
    {
        arr_new[current[(arr[i] / pos) % 10] - 1] = arr[i];
        current[(arr[i] / pos) % 10]--;
    }
    for (i = 0; i < len; i++)
    {
        arr[i] = arr_new[i];
    }
}

void radixSort(long arr[])
{
    long max_val = -1000000;
    long pos = 1;
    long pass = 1;
    for (int i = 0; i < len; i++)
    {
        max_val = maximum(max_val, arr[i]);
    }
    while (max_val / pos > 0)
    {
        countingSort(arr, pos);
        pos *= 10; pass++;
    }
}

int main()
{
    /*First Input: Length of Array*/
    cin >> len;
    long values[len];
    /*Take in Array Values*/
    for (int i = 0; i < len; i++)
    {
        //ghetto form-into-one-number
        long new_val = 0;
        for (int j = 0; j < 10; j++)
        {
            int input;
            cin >> input;
            new_val += input * (long)pow(10, 9 - j);
        }
        values[i] = new_val;
    }
    /*Sorty Sort Sort*/
    radixSort(values);
    for (int i = 0; i < len; i++)
    {
        //Ghetto break-into-individual-numbers
        long new_val = values[i];
        long expon = 1000000000;
        while (expon > 0)
        {
            cout << (new_val - (new_val % expon)) / expon << ";";
            new_val -= (new_val - (new_val % expon));
            expon /= 10;
        }
        cout << "\n";
    }
    return 0;
}