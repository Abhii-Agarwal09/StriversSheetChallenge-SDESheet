#include <bits/stdc++.h>

Node<int> *findMid(Node<int> *head)
{
  Node<int> *slow = head;
  Node<int> *fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node<int> *merge(Node<int> *left, Node<int> *right)
{
  Node<int> *ans = new Node<int>(-1);
  if (left == NULL)
  {
    return right;
  }
  if (right == NULL)
  {
    return left;
  }
  Node<int> *temp = ans;

  while (left != NULL && right != NULL)
  {
    if (left->data < right->data)
    {
      temp->next = left;
      temp = left;
      left = left->next;
    }
    else
    {
      temp->next = right;
      temp = right;
      right = right->next;
    }
  }

  while (left != NULL)
  {
    temp->next = left;
    temp = left;
    left = left->next;
  }

  while (right != NULL)
  {
    temp->next = right;
    temp = right;
    right = right->next;
  }

  return ans->next;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
  // Write your code here.
  if (first == NULL)
    return second;
  if (second == NULL)
    return first;
  Node<int> *result = merge(first, second);
  return result;
}
