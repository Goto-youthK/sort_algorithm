/* main.cpp */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>             // getpid()やgetppid()で必要
#include "bubble_sort.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "shell_sort.hpp"
#include "quick_sort.hpp"

#define ARRAY_SIZE 10           // 配列の要素数

void print_array(int numbers[], int array_size);

int main(int argc, char **argv) {
    BUBBLE_SORT bubble;
    SELECTION_SORT selection;
    INSERTION_SORT insertion;
    SHELL_SORT shell;
    QUICK_SORT quick;

    int numbers[ARRAY_SIZE];

    // 乱数の初期化(実行する度に異なる乱数が発生する)
    srand(getpid());

    for(int i = 0; i < ARRAY_SIZE; i++) {
        // 乱数の取得
        numbers[i] = rand()%10 + 1;
    }

    printf("Start:\n");
    print_array(numbers, ARRAY_SIZE);
    printf("\n");

    // 各種ソート処理
    bubble.search(numbers, ARRAY_SIZE);
    //quick.search1(numbers, 0, ARRAY_SIZE-1);

    printf("\n");
    printf("End:\n");
    print_array(numbers, ARRAY_SIZE);

    return 0;
}

void print_array(int numbers[], int array_size) {
    for(int i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
