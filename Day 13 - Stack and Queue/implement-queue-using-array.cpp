#include <bits/stdc++.h>
class Queue
{
  int *arr;
  int size;
  int first;
  int rear;

public:
  Queue()
  {
    // Implement the Constructor
    size = 100001;
    arr = new int[size];
    first = 0;
    rear = 0;
  }

  /*----------------- Public Functions of Queue -----------------*/

  bool isEmpty()
  {
    // Implement the isEmpty() function
    return first == rear;
  }

  void enqueue(int data)
  {
    // Implement the enqueue() function
    if (rear == size)
    {
      return;
    }
    arr[rear++] = data;
  }

  int dequeue()
  {
    // Implement the dequeue() function
    if (first == rear)
    {
      return -1;
    }
    return arr[first++];
  }

  int front()
  {
    // Implement the front() function
    if (first == rear)
    {
      return -1;
    }
    return arr[first];
  }
};