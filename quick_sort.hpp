/*
  クイックソートの長所と短所
  長所：ソート処理が高速
  短所：分割処理の回数が多く必要になる場合には遅い
*/

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <iostream>

#define ARRAY_SIZE 10           // 配列の要素数
#define STACK_SIZE 32           // スタックの要素数

class QUICK_SORT {
public:
    QUICK_SORT() {};
    virtual ~QUICK_SORT() {};

    // 再帰を使う方法
    void search1(int numbers[], int left, int right) {
        //std::cout << "QUICK_SORT1" << std::endl;

        int i, j;
        int pivot;              // 枢軸
        int tmp;

        // 範囲の中央にある要素を枢軸とする
        pivot = median(numbers, left, right);
        //pivot = numbers[(left+right)/2];
        i = left;
        j = right;

        while(1) {
            // 枢軸以上の値が見つかるまで右方向へ進めていく
            while(numbers[i] < pivot) i++;
            // 枢軸以下の値が見つかるまで左方向へ進めていく
            while(numbers[j] > pivot) j--;
            // 左右から進めてきたiとjがぶつかったらループを終える
            if(i >= j) break;

            // 要素を交換
            tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;

            // 結果の表示
            print_array(numbers, ARRAY_SIZE);

            i++;
            j--;
        }

        // 枢軸の左側に要素が2つ以上あれば、クイックソートを再帰
        if(left < i-1) search1(numbers, left, i-1);
        // 枢軸の右側に要素が2つ以上あれば、クイックソートを再帰
        if(j+1 < right) search1(numbers, j+1, right);
    };

    // 再帰を使わない方法（大規模データ対策）
    void search2(int numbers[], int left, int right) {
        std::cout << "QUICK_SORT2" << std::endl;

        int i, j;
        int pivot;              // 枢軸
        int tmp;
        int left_stack[STACK_SIZE], right_stack[STACK_SIZE];
        int sp;                 // スタックポインタ

        // スタックの初期化
        left_stack[0] = left;
        right_stack[0] = right;
        sp = 1;

        // スタックが空になるまで繰り返す
        while(sp > 0) {
            sp--;
            left = left_stack[sp];
            right = right_stack[sp];

            if(left < right) {
                // 範囲の中央にある要素を枢軸とする
                pivot = median(numbers, left, right);
                //pivot = numbers[(left+right)/2];
                i = left;
                j = right;

                while(1) {
                    // 枢軸以上の値が見つかるまで右方向へ進めていく
                    while(numbers[i] < pivot) i++;
                    // 枢軸以下の値が見つかるまで左方向へ進めていく
                    while(numbers[j] > pivot) j--;
                    // 左右から進めてきたiとjがぶつかったらループを終える
                    if(i >= j) break;

                    // 要素を交換
                    tmp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = tmp;

                    // 結果の表示
                    print_array(numbers, ARRAY_SIZE);

                    i++;
                    j--;
                }

                // 左右の部分のうち、小さい方の範囲を先に処理するようにする
                if(i-left < right-i) {
                    // 左部分の方が小さいので、先に処理できるように、スタックには右部分から積む
                    left_stack[sp] = i+1;
                    right_stack[sp++] = right;
                    left_stack[sp] = left;
                    right_stack[sp++] = i-1;
                }
                else {
                    // 右部分の方が小さいので、先に処理できるように、スタックには左部分から積む
                    left_stack[sp] = left;
                    right_stack[sp++] = i-1;
                    left_stack[sp] = i+1;
                    right_stack[sp++] = right;
                }
            }
        }
    };

    // 3つの要素から中央値を求める
    int median(int numbers[], int left, int right) {
        int a, b, c;

        a = numbers[left];
        b = numbers[(left+right)/2];
        c = numbers[right];

        if(a < b) {
            if(b < c) return b;
            if(a < c) return c;
            return a;
        }
        else {
            if(a < c) return a;
            if(b < c) return c;
            return b;
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
