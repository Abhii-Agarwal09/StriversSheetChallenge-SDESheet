class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *fast = head;
    ListNode *slow = head;

    while (slow != NULL && fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        fast = fast->next;
      }
      slow = slow->next;
      if (slow == fast)
      {
        break;
      }
    }

    if (fast == NULL)
      return NULL;

    fast = head;

    while (fast != slow)
    {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};