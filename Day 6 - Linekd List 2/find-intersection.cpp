/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (headA->next == NULL && headB->next == NULL && headA == headB)
    {
      return headA;
    }

    stack<pair<int, ListNode *>> s1;
    stack<pair<int, ListNode *>> s2;

    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    while (temp1 != NULL)
    {
      s1.push({temp1->val, temp1});
      temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
      s2.push({temp2->val, temp2});
      temp2 = temp2->next;
    }
    cout << s1.size() << " " << s2.size() << endl;
    ListNode *prev = NULL;
    while (!s1.empty() || !s2.empty())
    {
      pair<int, ListNode *> front1;
      pair<int, ListNode *> front2;
      if (!s1.empty())
      {
        front1 = s1.top();
        s1.pop();
      }
      if (!s2.empty())
      {
        front2 = s2.top();
        s2.pop();
      }

      if (front1.second != front2.second)
      {
        return prev;
      }
      else
      {
        prev = front1.second;
      }
    }
    if (prev != NULL)
    {
      return prev;
    }
    return NULL;
  }
};