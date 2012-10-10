/*
  挿入ソートの長所と短所
  長所：ある程度ソート済みの状態であれば高速、安定なソート
  短所：ソート処理が遅い
*/

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iostream>

class INSERTION_SORT {
public:
    INSERTION_SORT() {};
    virtual ~INSERTION_SORT() {};

    void search(int numbers[], int array_size) {
        std::cout << "INSERTION_SORT" << std::endl;

        int tmp;

        for(int i = 1; i < array_size; i++) { // ソートされていない部分の先頭要素を指す
            // 比較のループ
            for(int j = i; j >= 1 && numbers[j-1] > numbers[j]; j--) { // ソート済み部分を後ろから進む
                // 目的の順番と逆になっていたら交換
                tmp = numbers[j-1];
                numbers[j-1] = numbers[j];
                numbers[j] = tmp;

                // 結果の表示
                print_array(numbers, array_size);
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
