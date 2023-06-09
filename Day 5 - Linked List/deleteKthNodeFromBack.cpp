int getLen(Node *head)
{
  int len = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}
Node *removeKthNode(Node *head, int n)
{
  // Write your code here.
  if (head == NULL)
  {
    return head;
  }
  if (head->next == NULL)
  {
    return NULL;
  }
  int len = getLen(head);
  if (n == len)
  {
    return head->next;
  }
  int nodeToDelete = (len - n) + 1;
  Node *temp = head;
  int cnt = 1;
  while (cnt < nodeToDelete - 1)
  {
    cnt++;
    temp = temp->next;
  }
  temp->next = temp->next->next;
  return head;
}
