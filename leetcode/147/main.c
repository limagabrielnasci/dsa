#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode dummy = { .val = 0, .next = head };
    struct ListNode *prev = &dummy, *curr = head, *next = NULL;

    while (curr) {
        next = curr->next;

        if (prev->val >= curr->val)
            prev = &dummy;

        while (prev->next && prev->next->val < curr->val)
            prev = prev->next;

        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy.next;
}

int main() {
    return 0;
}
