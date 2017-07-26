//
// Created by leonardo on 17/7/25.
//

#include <stdlib.h>
#include <stdio.h>
#include "QsortSLL.h"

sll_t* sll_create()
{
    sll_t* sll = malloc(sizeof(sll_t));
    sll->head = NULL;

    return sll;
}

void sll_add(sll_t* sll, int key)
{
    node_t* node = malloc(sizeof(node_t));
    node->key = key;
    node->next = NULL;

    if (sll->head == NULL) {
        sll->head = node;
    } else {
        node_t* tail = sll->head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = node;
    }
}

void sll_check(sll_t* sll) {
    printf("sll: ");

    char isOK = 1;
    int tmp = -1;

    for (node_t* node = sll->head; node != NULL; node = node->next) {
        printf("%d ", node->key);
        if (tmp > node->key) isOK = 0;
        tmp = node->key;
    }

    printf(" in order: %s\n", isOK ? "true": "false");
}

void sll_sort(sll_t* sll) {
    if (sll == NULL || sll->head->next == NULL) {
        return;
    }
    node_t node;
    node_t* head_prev = &node;
    sll_sort_work(head_prev, sll->head, NULL);
    sll->head = head_prev->next;
}


void sll_sort_work(node_t* head_prev, node_t* head, node_t* tail)
{
    if (head == tail || head->next == tail) return; // 检查顺序不能反

    node_t left_head;
    node_t right_head;
    node_t* left = &left_head;
    node_t* right = &right_head;

    int mid = head->key;
    node_t* node = head->next;

    while (node != tail) {
        if (node->key < mid) {
            left->next = node;
            left = node;
        } else {
            right->next = node;
            right = node;
        }
        node = node->next;
    }

    // 从右到左依次链接，顺序不能反
    right->next = tail;
    left->next = head;
    head->next = right_head.next;
    head_prev->next = left_head.next;

    sll_sort_work(head_prev, head_prev->next, head);
    sll_sort_work(head, head->next, tail);

}
