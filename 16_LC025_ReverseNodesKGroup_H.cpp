#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            if (kth == NULL) {
                break;
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            // Reverse k nodes
            while (curr != groupNext) {
                ListNode* temp = curr->next;

                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};

int main() {
    Solution obj;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = obj.reverseKGroup(head, 2);

    cout << "Reversed List: ";

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
