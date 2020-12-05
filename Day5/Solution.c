#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

struct data {
    int front;
    int back;
    int row;
    int col;
    int id;
};

struct data input[814];

int main()
{
    FILE *fp;
    fp = fopen("input.txt","r");

    int i,j,freq = 0;

    while(!feof(fp))
    { 
        input[i].front = 0;
        input[i].back = 127;
        for(j=0;j<7;j++){
            if(fgetc(fp) == 70){  //“F” == 70
                input[i].back = (input[i].front + input[i].back - 1)/2;
            }else{
                input[i].front = (input[i].front + input[i].back + 1)/2;
            }
        }
        if(input[i].back == input[i].front){
            input[i].row = input[i].front;
        }
        j = 0;

        input[i].front = 0;
        input[i].back = 7;
        for(j=0;j<3;j++){
            if(fgetc(fp) == 76){  //“L” == 76
                input[i].back = (input[i].front + input[i].back - 1)/2;
            }else{
                input[i].front = (input[i].front + input[i].back + 1)/2;
            }
        }
        if(input[i].back == input[i].front){
            input[i].col = input[i].front;
        }
        j = 0;

        input[i].id = input[i].row *8 + input[i].col;

        if(fgetc(fp) == 10){   // "\n" == 10s
            i++;
        } 
    }

    fclose(fp);

    //TRAVERSE
    // for(i=0;i<814;i++){
    //     printf("%d id: %d\n", i, input[i].id);
    // }


    //Part I
    // int max = input[i].id;
    // for(i=1;i<814;i++){
    //     if(input[i].id > max){
    //         max = input[i].id;
    //     }
    // }
    // printf("max: %d\n", max);

    //Part II
    // SELECTION SORT
    // int max, temp = 0;
    // for(i=814;i>0;i--){
    //     max = 0;
    //     for(j=0; j<i; j++){
    //         if(input[j].id > input[max].id){
    //             max = j;
    //         }
    //     }
    //     //swap
    //     temp = input[i-1].id;
    //     input[i-1].id = input[max].id;
    //     input[max].id = temp;
    // }

    //BUBBLE SORT
    // int temp = 0;
    // for(i=813; i>0; i--){
    //     for(j=0;j<i;j++){
    //         if(input[j].id > input[j+1].id){
    //             temp = input[j].id;
    //             input[j].id = input[j+1].id;
    //             input[j+1].id = temp;
    //         }
    //     }
    // }

    //INSERTION SORT
    int temp = 0;
    for(i=1;i<814;i++){
        temp = input[i].id;
        j = i; // 0 -> i-1 are sorted
        while(j>=1 && input[j-1].id > temp){
            input[j].id = input[j-1].id; // move back for a position to insert
            j--;
        }
        input[j].id = temp;
    }

    for(i=0;i<814;i++){
        // printf("%d id: %d\n", i, input[i].id);
        if(input[i].id - i != 28){
            printf("Your Seat: %d\n", input[i].id-1);
            break;
        }
    }


    return 0;
}
