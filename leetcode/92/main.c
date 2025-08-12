#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;

    for (int i = 1; i < left; ++i) prev = prev->next;

    struct ListNode *curr = prev->next;
    for (int i = 0; i < right - left; ++i) {
        struct ListNode *tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }

    return dummy.next;
}

struct ListNode* newNode(int v) {
    struct ListNode* n = malloc(sizeof(*n));
    n->val = v; n->next = NULL;
    return n;
}

void printList(struct ListNode* h) {
    while (h) { printf("%d", h->val); if (h->next) printf(" -> "); h = h->next; }
    printf("\n");
}

int main(void) {
    return 0;
}
