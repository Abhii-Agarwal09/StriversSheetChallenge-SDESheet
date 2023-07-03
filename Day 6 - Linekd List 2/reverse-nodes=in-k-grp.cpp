class Solution {
  public:
    ListNode* reverseKGroup(ListNode *head, int k) {
      if (head == NULL || k == 1) return head;
      ListNode *dummy = new ListNode(0);
      dummy->next = head;
      ListNode *curr = dummy;
      ListNode *pre = dummy;
      ListNode *nex = dummy;
      int count = 0;
      while (curr->next != NULL) {
        count++;
        curr = curr->next;
      }
      while (count >= k) {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; i++) {
          curr->next = nex->next;
          nex->next = pre->next;
          pre->next = nex;
          nex = curr->next;
        }
        count -= k;
        pre = curr;
      }
      return dummy->next;
    }
};