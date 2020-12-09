#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000-26+1

struct data {
    long long int preamble[25];
    long long int target;
};

struct data input[SIZE];

int main(){
    int i = 0;
    for(i=0;i<1000-26+1;i++){
        FILE *fp;
        fp = fopen("input.txt","r");
        int j = 0;
        char num[50];
        // 
        if(i!=0){
            for(j=0;j<i;j++){
                fscanf(fp,"%s\n",num); //把前面的遍历完
            }
        }
        for(j=0;j<25;j++){
            fscanf(fp,"%s\n",num);
            input[i].preamble[j] = atof(num);
        }
        fscanf(fp,"%s\n",num);
        input[i].target = atof(num);
        // 
        fclose(fp);
    }

    //TRAVERSE
    // for(i=0;i<1000-26+1;i++){
    //     printf("target: %lld\n", input[i].target);
    // }

    int j,k,flag = 0;
    //PART I
    // for(i=0;i<SIZE;i++){
    //     for(j=0;j<24;j++){
    //         for(k=j+1;k<25;k++){
    //             if(input[i].preamble[j] + input[i].preamble[k] == input[i].target){
    //                 flag = 1;
    //                 break;
    //             }
    //         }

    //         if(flag){
    //             break;
    //         }
    //     }
    //     if(flag){
    //         flag = 0;
    //         continue;
    //     }else{
    //         printf("id: %d, target: %lld\n", i,input[i].target);
    //         break;
    //     }
    // }

    //PART II
    //index: 548 --> index_target: 523
    // printf("%lld\n", input[523].target); // 57195069
    long long int targets[548];
    FILE *fp;
    fp = fopen("input.txt","r");
    for(i = 0; i<548;i++){
        char num[50];
        fscanf(fp,"%s\n", num);
        targets[i] = atof(num);
        // printf("id: %d, %lld\n", i, targets[i]);
    }
    fclose(fp);

    int start, final = 0;

    flag = 0;
    for(i=0; i<547;i++){
        long long int sum = targets[i];
        for(j=i+1;j<548;j++){
            sum += targets[j];
            if(sum == 57195069){
                printf("start index: %d, final index: %d\n", i, j);
                start = i;
                final = j;
                flag = 1;
                break;
            }
            // printf("sum: %lld\n", sum);
        }
        if(flag){
            break;
        }
    }

    long long int min = targets[start];
    long long int max = targets[start];
    for(i = start+1; i < final; i++){
        if(targets[i] > max){
            max = targets[i];
        }
        if(targets[i] < min){
            min = targets[i];
        }
    }

    printf("min: %lld, max: %lld, res: %lld\n", min, max, min+max);
    
    return 0;
}