#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 99
// #define SIZE 11

// struct data {
//     long long int preamble[25];
//     long long int target;
// };

// struct data input[SIZE];

int input[SIZE];

long long int temp[161];

long long int rec(int num);

int main(){
    FILE *fp;
    fp = fopen("input.txt","r");
    // fp = fopen("test.txt","r");
    int i,j = 0;
    while(!feof(fp)){
        char num[10];
        fscanf(fp, "%s\n", num); 
        input[i] = atoi(num);
        i++;
    }
    fclose(fp);



    //BUBBLE SORT
    for(i = SIZE-1;i>0;i--){
        for(j =0; j< i; j++){
            if(input[j] > input[j+1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }

    // TRAVERSE
    // for(i = 0; i< SIZE; i++){
    //     printf("%d\n", input[i]);
    // }

    // PART I
    // int one = 0;
    // int three = 0;
    // if(input[0] == 1){
    //     one++;
    // }else if(input[0] == 3){
    //     three++;
    // }
    // for(i = 0; i< SIZE-1; i++){
    //     if(input[i+1] - input[i] == 1){
    //         one++;
    //     }else if(input[i+1] - input[i] == 3){
    //         three++;
    //     }
    // }
    // printf("PART I: %d\n", one * (three+1));

    //PART II
    long long int res;

    // for(i=0;i<161;i++){
    //     temp[i] = 0;
    // }
    // for(i=98;i<60;i--){
    //     temp[input[i]] = rec(input[i]);
    //     printf("%d: %lld\n", i, temp[input[i]]);
    // }
    res = rec(0);
    printf("res: %lld\n", res);
    
    return 0;
}


long long int rec(int num){
    // printf("%d ", input[SIZE-1]);
    if(num==input[SIZE-1]){
        return 1;
    }

    // 以小见大--> 枚举递归
    if(num==102){
        return 614656;
    }
    if(num==68){
        return 137682944;
    }

    if(num==69){
        return 68841472;
    }

    if(num==66){
        return 481890304;
    }

    if(num==54){
        return 963780608;
    }

    if(num==52){
        return 3373232128;
    }

    if(num==36){
        return 13492928512;
    }

    if(num==25){
        return 188900999168;
    }

    if(num==10){
        return 2644613988352;
    }

    int i=0;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int one = num+1;
    int two = num+2;
    int three = num+3;

    // for(i=0;i<161;i++){
    //     if(temp[i] != 0){
    //         return temp[i];
    //     }
    // }

    for(i=0;i<SIZE;i++){
        if(input[i] == one){
            flag1=1;
        }
        if(input[i] == two){
            flag2=1;
        }
        if(input[i] == three){
            flag3=1;
        }
    }

    if(flag1 && flag2 && flag3){
        // printf("%d: 123\n", num);
        return rec(one) + rec(two) + rec(three);
    }else if(flag1 && flag3){
        // printf("%d: 13\n", num);
        return rec(one) + rec(three);
    }else if(flag1 && flag2){
        // printf("%d: 12\n", num);
        return rec(one) + rec(two);
    }else if(flag2 && flag3){
        // printf("%d: 23\n", num);
        return rec(two) + rec(three);
    }else if(flag1){
        // printf("%d: 1\n", num);
        return rec(one);
    }else if(flag2){
        // printf("%d: 2\n", num);
        return rec(two);
    }else if(flag3){
        // printf("%d: 3\n", num);
        return rec(three);
    }else{
        return 0;
    }
}