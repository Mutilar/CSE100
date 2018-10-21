/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 10/20/2018
*    Description: Implementing a Binary Search Tree shit
*
******************************************************************/
#include <iostream> //I forget which of these includes matter...
#include <vector>
#include <algorithm>
#include <array>
#include <list>
#include <string>
using namespace std;
using std::cout;

struct Node
{
  Node *head;
  Node *left;
  Node *right;
  int val;
  Node()
  {
    val = 0;
    left = nullptr;
    right = nullptr;
  }
};

Node *head_of_tree;
bool running = true;

void insertKey(int key)
{
  if (head_of_tree == nullptr)
  {
    Node *new_input = new Node();
    new_input->val = key;
    head_of_tree = new_input;
  }
  else
  {
    Node *pointer = head_of_tree;
    while (
        (key < pointer->val && pointer->left != nullptr) ||
        (key > pointer->val && pointer->right != nullptr))
    {
      if (key < pointer->val)
        pointer = pointer->left;
      else
        pointer = pointer->right;
    }
    Node *new_input = new Node();
    new_input->val = key;
    new_input->head = pointer;
    if (key < pointer->val)
      pointer->left = new_input;
    else
      pointer->right = new_input;
  }
}

int *deleteKey(Node *ptr, int key)
{
  // bool is_changing_head = false;
  Node *pointer = ptr;
  if (pointer == nullptr)
  {
    return 0;
  }
  // if (pointer->val == key)
  // {
  //   is_changing_head = true;
  // }
  //navigate to target node
  while (
      (key != pointer->val) && ((key < pointer->val && pointer->left != nullptr) ||
                                (key > pointer->val && pointer->right != nullptr)))
  {
    // cout << pointer->val;
    if (key < pointer->val)
      pointer = pointer->left;
    else if (key > pointer->val)
      pointer = pointer->right;
    if (key == pointer->val)
    {
      // cout << "found";
      break;
    }
  }
  if (key != pointer->val)
  {
    return 0;
  }
  //check cases
  if (pointer->left == nullptr && pointer->right == nullptr)
  {
    // cout << "no kids: " << pointer->val << " with parent " << pointer->head->val;
    if (pointer->val < pointer->head->val)
      pointer->head->left = nullptr;
    else
      pointer->head->right = nullptr;
    delete pointer;
    pointer = nullptr;
  }
  else if (pointer->left == nullptr)
  {
    if (pointer->head != nullptr)
    {
      // cout << "no left: " << pointer->val << " with parent " << pointer->head->val;
      if (pointer->val < pointer->head->val)
      {
        pointer->head->left = pointer->right;
        pointer->right->head = pointer->head;
      }
      else
      {
        pointer->head->right = pointer->right;
        pointer->right->head = pointer->head;
      }
    }
    else
    {
      head_of_tree = pointer->right;
    }
    delete pointer;
    pointer = nullptr;
  }
  else if (pointer->right == nullptr)
  {
    // cout << "no right: " << pointer->val << " with parent " << pointer->head->val;
    if (pointer->head != nullptr)
    {

      if (pointer->val < pointer->head->val)
      {
        pointer->head->left = pointer->left;
        pointer->left->head = pointer->head;
      }
      else
      {
        pointer->head->right = pointer->left;
        pointer->left->head = pointer->head;
      }
    }
    else
    {
      head_of_tree = pointer->left;
      //pointer->left->head = pointer->head;
    }
    delete pointer;
    pointer = nullptr;
  }
  else
  {
    //  cout << "multiple kids";
    Node *temp = pointer->right;
    int height = 0;
    while (temp->left != nullptr)
    {
      height++;
      temp = temp->left;
    }

    int temp_val = temp->val;
    // cout <<"suggested to remove" << temp_val;
    Node *temp_right = temp->right;
    if (temp->right == nullptr)
    {
      pointer->val = temp_val;
      //delete temp;
      //temp = nullptr;
      if (height == 0)
      {
        pointer->right = nullptr;
      }
      else
      {
        temp->head->left = nullptr;
      }
    }
    else
    {
      pointer->val = temp_val;
      if (height == 0)
      {
        pointer->right = temp_right;
        temp_right->head = pointer;
      }
      else
      {
        temp->head->left = temp_right;
        temp_right->head = temp;
      }
    }
  }
  // if (is_changing_head)
  // {
  //   head_of_tree = pointer;
  // }
}

void outputTree(Node *pointer, char cmd)
{
  if (pointer != nullptr)
  {
    if (cmd == 'p')
      cout << pointer->val << "\n"; //pre
    outputTree(pointer->left, cmd);
    if (cmd == 'i')
      cout << pointer->val << "\n"; //in
    outputTree(pointer->right, cmd);
    if (cmd == 's')
      cout << pointer->val << "\n"; //post
  }
}

int main()
{
  string command = "";
  while (running)
  {
    int key;
    cin >> command;
    if (command == "i")
    {
      cin >> key;
      insertKey(key);
    }
    if (command == "d")
    {
      cin >> key;
      deleteKey(head_of_tree, key);
    }
    if (command == "pre")
    {
      outputTree(head_of_tree, 'p');
      cout << "++++++++++++++++++++\n";
    }
    if (command == "in")
    {
      outputTree(head_of_tree, 'i');
      cout << "++++++++++++++++++++\n";
    }
    if (command == "post")
    {
      outputTree(head_of_tree, 's');
      cout << "++++++++++++++++++++\n";
    }
    if (command == "e")
    {
      running = false;
      break;
    }
  }
}
