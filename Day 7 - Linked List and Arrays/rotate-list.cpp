class Solution
{
public:
  int getLength(ListNode *head)
  {
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
      len++;
      temp = temp->next;
    }
    return len;
  }

public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    int len = getLength(head);
    if (head == NULL || head->next == NULL || k == 0 || k == len)
    {
      return head;
    }
    int correctPos = k % len;
    int moveIndex = len - correctPos;
    int cnt = 1;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = head;
    temp = head;
    while (cnt <= moveIndex - 1)
    {
      cnt++;
      temp = temp->next;
    }
    ListNode *newHead = temp->next;
    temp->next = NULL;
    return newHead;
  }
};