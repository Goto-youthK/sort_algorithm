/*
  選択ソートの長所と短所
  長所：バブルソートに比べて交換処理の回数が少ない
  短所：ソート処理が遅い、不安定なソート
*/

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <iostream>

class SELECTION_SORT {
public:
    SELECTION_SORT() {};
    virtual ~SELECTION_SORT() {};

    void search(int numbers[], int array_size) {
        std::cout << "SELECTION_SORT" << std::endl;

        int min;                // 最小値を持つ要素のインデックス
        int tmp;

        for (int i = 0; i < array_size-1; i++) { // 配列の先頭を指す
            min = i;            // 配列の先頭を最小値の要素とする

            // 比較のループ
            for (int j = i+1; j < array_size; j++) { // 残りの要素を指す
                if (numbers[j] < numbers[min])
                    min = j;    // 最小値を持つ要素を更新
            }

            // 最小値を持つ要素と先頭の要素を交換
            tmp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = tmp;

            // 結果の表示
            print_array(numbers, array_size);
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
