#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
} Node;

void reverse_list(Node **head)
{
    Node *prev = NULL;
    Node *tmp = NULL;
    Node *curr = *head;

    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;
        tmp->next = prev;
        prev = tmp;
    }
    *head = prev;
}

int main( void )
{
    Node fr = {
        .val = 1,
        .next = NULL
    };

    Node sc = {
        .val = 2,
        .next = NULL
    };

    Node th = {
        .val = 3,
        .next = NULL
    };

    Node fo = {
        .val = 4,
        .next = NULL
    };

    fr.next = &sc;
    sc.next = &th;
    th.next = &fo;

    Node *head = &fr;
    printf("before: %p\n", head);
    reverse_list(&head);
    printf("after: %p\n", head);
    while (head != NULL)
    {
        printf("%d\n", head->val);
        head = head->next;
    }
}
