/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/18/2018
*    Description: Implementing a Hash Table with Open Addressing
*
******************************************************************/
#include <iostream> //I forget which of these includes matter...
#include <vector>
#include <algorithm>
#include <array>
#include <list>
using namespace std;
using std::cout;

bool running = true;
int hash_size = 13;
int *hash_table;

int hashKey(int val)
{
  return val % hash_size;
}
int hashKey2(int val)
{
  return (1 + (val % 11));
}

void insertKey(int key)
{
  if (hash_table[hashKey(key)] != -10)
  {
    for (int i = 1; i < hash_size; i++)
    {
      if (hash_table[(hashKey(key) + i * hashKey2(key)) % hash_size] == -10)
      {
        hash_table[(hashKey(key) + i * hashKey2(key)) % hash_size] = key;
        break;
      }
    }
  }
  else
  {
    hash_table[hashKey(key)] = key;
  }
}

void deleteKey(int key)
{
  if (hash_table[hashKey(key)] == key)
  {
    hash_table[hashKey(key)] = -10;
  }
  else
  {
    for (int i = 1; i < hash_size; i++)
    {
      if (hash_table[(hashKey(key) + i * hashKey2(key)) % hash_size] == key)
      {
        hash_table[(hashKey(key) + i * hashKey2(key)) % hash_size] = -10;
        break;
      }
    }
  }
}
void searchKey(int key)
{
  bool found = false;
  if (hash_table[hashKey(key)] == key)
  {
    cout << hashKey(key) << "\n";
    found = true;
  }
  else
  {
    for (int i = 1; i < hash_size; i++)
    {
      if (hash_table[(hashKey(key) + i * hashKey2(key)) % hash_size] == key)
      {
        cout << (hashKey(key) + i * hashKey2(key)) % hash_size << "\n";
        found = true;
        break;
      }
    }
  }
  if (!found)
    cout << "NOT_FOUND\n";
}
void outputHashTable()
{
  for (int i = 0; i < hash_size; i++)
  {
    if (hash_table[i] >= 0)
    {
      cout << hash_table[i];
    }
    cout << "\n";
  }
}

int main()
{
  hash_table = new int[hash_size];
  for (int i = 0; i < hash_size; i++)
  {
    hash_table[i] = -10;
  }

  int val;
  char command = 'i'; //insert
  while (running)
  {
    cin >> val;
    switch (val)
    {
    case -1:
      outputHashTable();
      command = 's'; //search (index of)
      break;
    case -2:
      command = 'd'; //delete
      break;
    case -3:
      outputHashTable();
      running = false;
      break;
    default:
      switch (command)
      {
      case 'i':
        insertKey(val);
        break;
      case 's':
        searchKey(val);
        break;
      case 'd':
        deleteKey(val);
        break;
      }
    }
  }
}
