class Solution {
  public:
    void insertAtTail(ListNode* &head, ListNode* &tail, int data) {
      ListNode *newNode = new ListNode(data);
      if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
      }
      tail->next = newNode;
      tail = newNode;
    }
  public:
    void reverse(ListNode* &head, ListNode *curr, ListNode *prev) {
      if (curr == NULL) {
        head = prev;
        return;
      }
      ListNode *forward = curr->next;
      reverse(head, forward, curr);
      curr->next = prev;
    }
  public:
    bool isPalindrome(ListNode *head) {
      ListNode *copy = NULL;
      ListNode *copyTail = NULL;
      ListNode *temp = head;
      while (temp != NULL) {
        insertAtTail(copy, copyTail, temp->val);
        temp = temp->next;
      }
      reverse(copy, copy, NULL);
      ListNode *copyTemp = copy;
      temp = head;
      while (copyTemp != NULL) {
        if (copyTemp->val != temp->val) return false;
        copyTemp = copyTemp->next;
        temp = temp->next;
      }
      return true;
    }
};

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
      ListNode *prev = NULL;
      ListNode *next = NULL;

      while (head != NULL)
      {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
      return prev;
    }

  public:
    bool isPalindrome(ListNode *head)
    {
      // find middle
      ListNode *slow = head;
      ListNode *fast = head;
      while (fast->next != NULL && fast->next->next != NULL)
      {
        fast = fast->next->next;
        slow = slow->next;
      }
      // reverse middle se end
      slow->next = reverseList(slow->next);
      slow = slow->next;
      // compare
      while (slow != NULL)
      {
        if (head->val != slow->val)
          return false;
        slow = slow->next;
        head = head->next;
      }
      return true;
    }
};