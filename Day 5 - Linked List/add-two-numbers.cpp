/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
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
  ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {

    int carry = 0;

    ListNode *newList = NULL;
    ListNode *newListTail = NULL;

    if (l1->next == NULL && l2->next == NULL) {
      int sum = l1->val + l2->val;
      int carry = 0;
      int data;
      if (sum >= 10) {
        data = sum % 10;
        carry = 1;
      }
      insertAtTail(newList, newListTail, data);
      if (carry == 1) insertAtTail(newList, newListTail, 1);
      return newList;
    }

    while (l1 != NULL || l2 != NULL) {
      int val1 = 0;
      int val2 = 0;
      if (l1 != NULL) val1 = l1->val;
      if (l2 != NULL) val2 = l2->val;

      int sum = val1 + val2 + carry;
      carry = 0;

      int data = sum % 10;
      insertAtTail(newList, newListTail, data);

      if (sum >= 10) carry = 1;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (carry == 1) insertAtTail(newList, newListTail, 1);
    return newList;
  }
};