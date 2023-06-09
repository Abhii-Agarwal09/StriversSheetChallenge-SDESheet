int getLength(Node *&head)
{
  Node *temp = head;
  int len = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    len++;
  }
  return len;
}
Node *findMiddle(Node *head)
{
  // Write your code here
  int len = getLength(head);
  int midPos = (len / 2) + 1;
  Node *temp = head;
  int cnt = 1;
  while (cnt < midPos)
  {
    temp = temp->next;
    cnt++;
  }
  return temp;
}