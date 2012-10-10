/*
  バブルソートの長所と短所
  長所：プログラムが単純、安定なソート
  短所：ソート処理が遅い
*/

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <iostream>

class BUBBLE_SORT {
public:
    BUBBLE_SORT() {};
    virtual ~BUBBLE_SORT() {};

    void search(int numbers[], int array_size) {
        std::cout << "BUBBLE SORT" << std::endl;

        int tmp;

        // 比較作業を止める位置を指す
        for(int i = 0; i < array_size-1; i++) {
            // 比較対象となる要素を指す
            for(int j = array_size-1; j > i; j--) {
                // 目的の順番に並んでいるか隣接する要素同士を比較する
                if(numbers[j-1] > numbers[j]) {
                    // 逆になっていたら交換
                    tmp = numbers[j-1];
                    numbers[j-1] = numbers[j];
                    numbers[j] = tmp;

                    // 結果の表示
                    print_array(numbers, array_size);
                }
            }
        }
    };

    void print_array(int numbers[], int array_size) {
        for(int i = 0; i < array_size; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    };
};

#endif
