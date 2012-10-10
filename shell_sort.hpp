/*
  シェルソートの長所と短所
  長所：ソート処理が比較的に高速
  短所：不安定なソート
*/

#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <iostream>

class SHELL_SORT {
public:
    SHELL_SORT() {};
    virtual ~SHELL_SORT() {};

    void search(int numbers[], int array_size) {
        std::cout << "SHELL_SORT" << std::endl;

        int gap = 4;            // 交換処理の間隔
        int tmp;

        while(gap > 0) {
            for(int i = gap; i < array_size; i++) {
                int j = i;

                while(j >= gap && numbers[j-gap] > numbers[j]) {
                    // 目的の順番と逆になっていたら交換
                    tmp = numbers[j];
                    numbers[j] = numbers[j-gap];
                    numbers[j-gap] = tmp;

                    // 交換処理の間隔分だけ添字を後退させる
                    j -= gap;

                    // 結果の表示
                    print_array(numbers, array_size);
                }
            }

            // 交換処理の間隔を決める
            if(gap/2 != 0)
                gap = gap/2;
            else if(gap == 1)
                gap = 0;
            else
                gap = 1;
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
