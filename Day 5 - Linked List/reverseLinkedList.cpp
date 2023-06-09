LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
  // Write your code here
  if (head == NULL)
  {
    return head;
  }
  LinkedListNode<int> *curr = head;
  LinkedListNode<int> *forward = curr->next;
  LinkedListNode<int> *prev = NULL;

  while (curr->next != NULL)
  {
    curr->next = prev;
    prev = curr;
    curr = forward;
    forward = curr->next;
  }
  curr->next = prev;
  return curr;
}

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
void solve(LinkedListNode<int> *&head, LinkedListNode<int> *curr,
           LinkedListNode<int> *prev)
{
  if (curr == NULL)
  {
    head = prev;
    return;
  }
  LinkedListNode<int> *forward = curr->next;
  solve(head, forward, curr);
  curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
  // Write your code here
  if (head == NULL)
  {
    return head;
  }
  solve(head, head, NULL);
  return head;
  //   if (head == NULL) {
  //     return head;
  //   }
  //   LinkedListNode<int>* curr = head;
  //   LinkedListNode<int>* forward = curr->next;
  //   LinkedListNode<int>* prev = NULL;

  //   while (curr->next != NULL) {
  //     curr->next = prev;
  //     prev = curr;
  //     curr = forward;
  //     forward = curr->next;
  //   }
  //   curr->next = prev;
  //   return curr;
}