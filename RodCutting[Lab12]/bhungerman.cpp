/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 11/18/2018
*    Description: Cutting Rods Dynamically Programmingly
*
******************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lenRods;
int len;

int cutRod(int values[], int r[])
{
    int val[len + 1];
    int lastRod[len + 1];
    val[0] = 0;
    int i, j;
    for (i = 1; i <= len; i++) {
        int ideal = -1;
        int max = -10000000;
        for (j = 0; j < i; j++) {
            if (max < values[j] + val[i - j - 1]) {
                ideal = j;
                max = values[j] + val[i - j - 1];
            }
        }
        val[i] = max;
        lastRod[i] = ideal + 1;
    }
    i = len;
    j = 0;
    while (i > 0) {
        r[j++] = lastRod[i];
        i -= lastRod[i];
    }
    lenRods = j;
    return val[len];
}

int main()
{
    cin >> len;
    int values[len];
    /*Take in Array Values*/
    for (int i = 0; i < len; i++) {
        cin >> values[i];
    }
    int r[len + 1];
    int i;
    cout << cutRod(values, r) << "\n";
    cout << r[0];
    /*Print Sorted Array*/
    for (i = 1; i < lenRods; i++) {
        cout << " " << r[i];
    }
    cout << " -1\n";
    return 0;
}