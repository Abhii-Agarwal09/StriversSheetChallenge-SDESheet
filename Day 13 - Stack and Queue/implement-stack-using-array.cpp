#include <bits/stdc++.h>
// Stack class.
class Stack
{

  int size;
  int peek;
  int *arr;

public:
  Stack(int capacity)
  {
    // Write your code here.
    this->size = capacity;
    arr = new int[size];
    peek = -1;
  }

  void push(int num)
  {
    // Write your code here.
    if (peek != size)
    {
      peek++;
      arr[peek] = num;
    }
  }

  int pop()
  {
    // Write your code here.
    if (peek == -1)
    {
      return -1;
    }
    return arr[peek--];
  }

  int top()
  {
    // Write your code here.
    if (peek == -1)
    {
      return -1;
    }
    return arr[peek];
  }

  int isEmpty()
  {
    // Write your code here.
    if (peek == -1)
    {
      return 1;
    }
    return 0;
  }

  int isFull()
  {
    // Write your code here.
    if (peek == size - 1)
    {
      return 1;
    }
    return 0;
  }
};