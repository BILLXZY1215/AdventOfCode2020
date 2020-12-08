#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 626

struct data {
    int flag; // 0 --> not operated yet; 1 --> operated
    char operation[4]; //nop/jmp/acc
    int sign; // 1 --> +;  -1 --> -;
    int num; // + num / - num
};

struct data input[SIZE];


int main(){
    int i,j=0;
    // Initialize alpha
    for(i=0;i<SIZE;i++){
        input[i].flag = 0;
        input[i].sign = 0;
        input[i].num = 0;
    }

    i = 0;
    FILE *fp;
    fp = fopen("input.txt","r");
    while(!feof(fp)){
        fscanf(fp, "%[^ ]", input[i].operation);
        fgetc(fp); // " "
        int sign = fgetc(fp); // +(43) / -(45)
        input[i].sign = (sign == 43) ? 1 : -1;
        char num[4];
        fscanf(fp, "%s\n", num);
        input[i].num = atoi(num);
        i++;
    }
    fclose(fp);



    //TRAVERSE
    // printf("i: %d\n", i);
    // for(i=0;i<SIZE;i++){
    //     printf("%d: flag: %d, %s, %d %d \n", i,input[i].flag, input[i].operation, input[i].sign, input[i].num);
    // }


    //PART I
    // i = 0;
    // int acc = 0;
    // while(input[i].flag == 0){
    //     if(strcmp(input[i].operation,"nop")==0){
    //         input[i].flag = 1;
    //         i++;
    //         continue;
    //     }else if(strcmp(input[i].operation,"acc")==0){
    //         input[i].flag = 1;
    //         if(input[i].sign == 1){
    //             acc += input[i].num;
    //         }else if(input[i].sign == -1){
    //             acc -= input[i].num;
    //         }
    //         i++;
    //         continue;
    //     }else if(strcmp(input[i].operation,"jmp")==0){
    //         input[i].flag = 1;
    //         if(input[i].sign == 1){
    //             i += input[i].num;
    //         }else if(input[i].sign == -1){
    //             i -= input[i].num;
    //         }
    //         continue;
    //     }
    // }

    // printf("PART I acc: %d\n", acc);

    // PART II
    i = 0;
    j = 0;
    int acc = 0;
    int operate[94] = {0};
    while(input[i].flag == 0){
        if(strcmp(input[i].operation,"nop")==0){
            // printf("%d nop %d %d\n",i, input[i].sign, input[i].num);
            operate[j] = i;
            input[i].flag = 1;
            i++;
            j++;
            continue;
        }else if(strcmp(input[i].operation,"acc")==0){
            input[i].flag = 1;
            if(input[i].sign == 1){
                acc += input[i].num;
            }else if(input[i].sign == -1){
                acc -= input[i].num;
            }
            i++;
            continue;
        }else if(strcmp(input[i].operation,"jmp")==0){
            // printf("%d jmp %d %d\n",i, input[i].sign, input[i].num);
            input[i].flag = 1;
            operate[j] = i;
            j++;
            if(input[i].sign == 1){
                i += input[i].num;
            }else if(input[i].sign == -1){
                i -= input[i].num;
            }
            continue;
        }
    }


    int num = 0;
    int flag=0;
    for(num = 0; num < 94; num++){
        // printf("\n------ num: %d ------\n", num);
        if(flag){
            break;
        }
        //Clear Flag/Acc
        for(i=0;i<SIZE;i++){
            input[i].flag = 0;
        }
        acc = 0;


        printf("operate: %d\n",operate[num]);

        //Swap back nop/jmp
        if(strcmp(input[operate[num]].operation,"jmp")==0){
            strcpy(input[operate[num]].operation,"nop");
            // printf("jmp -> nop %s\n",input[num].operation);
        }else if(strcmp(input[operate[num]].operation,"nop")==0){
            strcpy(input[operate[num]].operation,"jmp");
            // printf("nop -> jmp %s\n",input[num].operation);
        }

        i = 0;
        while(input[i].flag == 0){ // if flag-->1, then infinite loop
            if(i == 625){
                printf("jmp/nop: %d\n", num);
                flag=1;
                break;
            }

            if(strcmp(input[i].operation,"nop")==0){
                // printf("%d nop %d %d\n",i, input[i].sign, input[i].num);
                input[i].flag = 1;
                i++;
                continue;
            }else if(strcmp(input[i].operation,"acc")==0){
                input[i].flag = 1;
                if(input[i].sign == 1){
                    acc += input[i].num;
                }else if(input[i].sign == -1){
                    acc -= input[i].num;
                }
                i++;
                continue;
            }else if(strcmp(input[i].operation,"jmp")==0){
                // printf("%d jmp %d %d\n",i, input[i].sign, input[i].num);
                input[i].flag = 1;
                if(input[i].sign == 1){
                    i += input[i].num;
                }else if(input[i].sign == -1){
                    i -= input[i].num;
                }
                continue;
            }
        }

        //Swap back nop/jmp
        if(strcmp(input[operate[num]].operation,"jmp")==0){
            strcpy(input[operate[num]].operation,"nop");
        }else if(strcmp(input[operate[num]].operation,"nop")==0){
            strcpy(input[operate[num]].operation,"jmp");
        }

    }



    printf("PART II acc: %d\n", acc);

    return 0;
}




        
    
