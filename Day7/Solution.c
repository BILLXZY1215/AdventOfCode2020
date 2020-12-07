#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 594

struct data {
    int alpha[SIZE];
    char name[100];
};

struct data a[SIZE];

int rec(int index);
int main(){
    int i,flag,num,k = 0;
    // for(i=0;i<SIZE;i++){
    //     for(k=0;k<SIZE;k++){
    //         a[i].alpha[k] = 0;
    //     }
    // }

    FILE *fp;
    fp = fopen("input_copy.txt","r");

    char input[100];
    while(!feof(fp)){
        flag = 0;
        fscanf(fp, "%s\n", input);
        for(i=0;i<100;i++){
            if(input[i]>='1'&&input[i]<='9'){
                num =input[i] - '0';
                // printf("num: %d\n",num);
                fscanf(fp, "%s\n", input);
                break;
            }
            if(input[i] == '*'){
                fscanf(fp, "%s\n", a[k].name);
                k++;
                break;
            }
        }
    }
    fclose(fp);

    // printf("k:%d\n",k);
    // printf("bag: %s\n",a[521].name); //shinygold


    //TRAVERSE
    // for(i=0;i<SIZE;i++){
    //     printf("name: %s\n",a[i].name);
    // }

    //-----------------------------------------------

    fp = fopen("input_copy.txt","r");
    while(!feof(fp)){
        flag = 0;
        fscanf(fp, "%s\n", input);
        for(i=0;i<100;i++){
            if(input[i]>='1'&&input[i]<='9'){
                num =input[i] - '0';
                // printf("num: %d\n",num);
                fscanf(fp, "%s\n", input);
                for(k=0;k<SIZE;k++){
                    if(strcmp(input,a[k].name)==0){
                        a[i].alpha[k] = num;
                        break;
                    }
                }
                break;
            }
            if(input[i] == '*'){
                fscanf(fp, "%s\n", input);
                k++;
                break;
            }
        }
    }
    fclose(fp);

printf("%s\n",a[521].name);
    int res = rec(521);
    printf("res: %d\n", res);


    return 0;
}


//PART I
int rec(int index){
    int res,i = 0;
    //base case
    //recursive steps
    for(i=0;i<SIZE;i++){
        if(a[i].alpha[index] != 0){
            printf("num: %d\n",a[i].alpha[index]);
            printf("name: %s, index: %d\n",a[index].name, i);
            res = res + 1 + rec(i);
        }
    }

    return res;
}