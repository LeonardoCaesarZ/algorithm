//
// Created by leonardo on 17/7/25.
//

#include <stdlib.h>
#include "QsortSLL.h"

int main() {
    sll_t* sll = sll_create();

    for (int i = 0; i < 10; i++) {
        sll_add(sll, rand() % 100);
    }

    sll_check(sll);
    sll_sort(sll);
    sll_check(sll);
}