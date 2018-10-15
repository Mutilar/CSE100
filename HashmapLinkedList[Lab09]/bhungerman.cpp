/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/14/2018
*    Description: Implementing a Hash Table with Linking
*
******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <list>
using namespace std;
using std::cout;

bool running = true;
int hash_size;

std::list<int> *hash_table;

int hashKey(int val)
{
  return val % hash_size;
}

void insertKey(int key)
{
  hash_table[hashKey(key)].push_front(key);
}

void deleteKey(int key)
{
  int index = 0;
  for (std::list<int>::const_iterator iterator = hash_table[hashKey(key)].begin(), end = hash_table[hashKey(key)].end(); iterator != end; ++iterator)
  {
    if (*iterator == key)
    {
      iterator = hash_table[hashKey(key)].erase(iterator);
      cout << key << " : DELETED\n";
      return;
    }
    index++;
  }
  cout << key << " : DELETE FAILED\n";
}
void searchKey(int key)
{
  int index = 0;
  for (std::list<int>::const_iterator iterator = hash_table[hashKey(key)].begin(), end = hash_table[hashKey(key)].end(); iterator != end; ++iterator)
  {
    if (*iterator == key)
    {
      cout << key << " : FOUND AT " << hashKey(key) << "," << index << "\n";
      return;
    }
    index++;
  }
  cout << key << " : NOT FOUND\n";
}
void outputHashTable()
{
  for (int i = 0; i < hash_size; i++)
  {
    int index_list = 0;
    cout << i << " : ";
    for (std::list<int>::const_iterator iterator = hash_table[i].begin(), end = hash_table[i].end(); iterator != end; ++iterator)
    {
      index_list++;
      if (hash_table[i].size() == index_list)
      {
        cout << *iterator;
      }
      else cout << *iterator << "->";
    }
    cout << "\n";
  }
}

int main()
{
  cin >> hash_size;
  hash_table = new std::list<int>[hash_size];
  char command;
  while (running)
  {
    int key;
    cin >> command;
    switch (command)
    {
    case 'i':
      cin >> key;
      insertKey(key);
      break;
    case 'd':
      cin >> key;
      deleteKey(key);
      cout << "++++++++++++++++++++\n";
      break;
    case 's':
      cin >> key;
      searchKey(key);
      cout << "++++++++++++++++++++\n";
      break;
    case 'o':
      outputHashTable();
      cout << "++++++++++++++++++++\n";
      break;
    case 'e':
      running = false;
      break;
    }
  }
}