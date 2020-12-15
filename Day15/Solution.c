#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 2020
// #define SIZE 30000000

int input[SIZE];

int main(){
    input[0] = 1;
    input[1] = 0;
    input[2] = 18;
    input[3] = 10;
    input[4] = 19;
    input[5] = 6;
    // input[6] = 0;
    int i,j, temp, preIndex, flag = 0;

    //PART I
    // for(i=0;i<6;i++){
    //     printf("%d\n", input[i]);
    // }
    // for(i = 6; i< SIZE; i++){
    //     flag = 0;
    //     temp = input[i-1];
    //     for(j=0;j<i-1;j++){
    //         if(input[j] == temp){
    //             preIndex = j+1;
    //             flag = 1;
    //         }
    //     }
    //     if(flag){
    //         input[i] = i-preIndex;
    //     }else{
    //         input[i] = 0;
    //     }
    //     printf("%d\n", input[i]);
    // }
    // printf("PART I: %d\n", input[SIZE-1]);

    int index[30000];
    for(i = 0; i<30000; i++){
        index[i] = -1;
    }
    index[1] = 0;
    index[0] = 1;
    index[18] = 2;
    index[10] = 3;
    index[19] = 4;
    index[6] = 5;

    //PART II
    for(i = 6; i< SIZE; i++){
        temp = input[i-1];
        // for(j=i-2;j>=0;j--){
        //     if(input[j] == temp){
        //         preIndex = j+1;
        //         flag = 1;
        //         break;
        //     }
        // }
        if(index[temp] == -1 || index[temp] == i-1){
            flag = 0;
        }else{
            preIndex = index[temp]+1;
            flag = 1;
        }

        if(flag){
            input[i] = i-preIndex;
        }else{
            input[i] = 0;
        }
        index[input[i]] = i;
        // printf("%d\n", input[i]);
    }
    printf("PART II: %d\n", input[SIZE-1]);
    return 0;
}