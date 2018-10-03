/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/3/2018
*    Description: Using Heap Sort
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int len;

void heapify(int val[], int length, int index)
{
    //Properties of a Heap:
    int left_index = (2 * index) + 1; 
    int right_index = (2 * index) + 2;

    //Assume parent is largest for now
    int largest_index = index;  
    
    if (left_index < length && val[left_index] > val[largest_index])
    {
        //If the left index is larger than parent, make it the parent
        largest_index = left_index;
    }
    if (right_index < length && val[right_index] > val[largest_index])
    {
        //If the right index is larger than parent, make it the parent
        largest_index = right_index;
    }

    if (largest_index != index)
    {
        //Move largest node up
        swap(val[index], val[largest_index]);
        heapify(val, length, largest_index);
    }
}

void heapSort(int val[], int shifting_length)
{
    for (int i = (shifting_length / 2) - 1; i >= 0; i--)
    {
        //Arrange array into form of a heap (fixing nodes that are larger than parents)
        heapify(val, shifting_length, i);
    }
    for (int i = (shifting_length - 1); i >= 0; i--)
    {
        //Find the next value to add to the sorted set
        swap(val[0], val[i]);
        heapify(val, i, 0);
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
    heapSort(values, len);
    for (int i = 0; i < len; i++)
    {
        cout << values[i] << ";";
    }
    return 0;
}