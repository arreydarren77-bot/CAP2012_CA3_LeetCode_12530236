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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* current = &dummy;

        while (current->next != NULL) {
            if (current->next->val == val) {
                current->next = current->next->next;
            }
            else {
                current = current->next;
            }
        }

        return dummy.next;
    }
};

int main() {
    Solution obj;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(6);

    head = obj.removeElements(head, 6);

    cout << "Updated List: ";

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
