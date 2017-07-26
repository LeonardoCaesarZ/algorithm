//
// Created by leonardo on 17/7/25.
//

#ifndef ALGORITHM_QSORTSLL_H
#define ALGORITHM_QSORTSLL_H

typedef struct node_s {
    int key;
    struct node_s* next;
} node_t;

typedef struct sll_s {
    node_t* head;
} sll_t;

sll_t* sll_create();
void sll_add(sll_t* sll, int key);
void sll_sort(sll_t* sll);
void sll_sort_work(node_t* head_prev, node_t* head, node_t* tail);
void sll_check(sll_t* sll);

#endif //ALGORITHM_QSORTSLL_H
