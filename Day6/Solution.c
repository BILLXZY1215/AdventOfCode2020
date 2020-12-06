#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 454

struct data {
    int alpha[26];
    int count;
};

struct data input[SIZE];

int main()
{
    int i,j,flag = 0;
    // Initialize alpha
    for(i=0;i<SIZE;i++){
        for(j=0;j<26;j++){
            input[i].alpha[j] = 0;
        }
        input[i].count = 0;
    }

    i = 0;
    FILE *fp;
    fp = fopen("input.txt","r");
    
    //Part I
    // while(!feof(fp))
    // { 
    //     flag = fgetc(fp);
    //     if(flag == 10){
    //         printf("\n");
    //         flag = fgetc(fp);
    //         if(flag == 10){
    //             printf("\n");
    //            i++;
    //            continue;
    //         }else{
    //             if(flag>=97 && flag <=122){
    //                 if(input[i].alpha[flag-97] == 0){
    //                     input[i].alpha[flag-97] = 1;
    //                     input[i].count++;
    //                 }
    //                 printf("%c",flag);
    //             }
    //         }
    //     }else{
    //         if(flag>=97 && flag <=122){
    //             if(input[i].alpha[flag-97] == 0){
    //                 input[i].alpha[flag-97] = 1;
    //                 input[i].count++;
    //             }
    //             printf("%c",flag);
    //         }
    //     }
    // }

    // fclose(fp);

    // //TRAVERSE

    // int res = 0;
    // for(i=0;i<SIZE;i++){
    //     res += input[i].count;
    // }
    // printf("\nPART I: %d\n", res);

    //Part II

    int people,z = 0;
    while(!feof(fp))
    { 
        flag = fgetc(fp);
        if(flag == -1){
            people++; 
            //遇到EOF
            for(z=0;z<26;z++){
                if(input[i].alpha[z] == people){
                    input[i].count++;
                }
            }
        }
        if(flag == 10){
            people++; 
            flag = fgetc(fp);
            if(flag == 10){
                //换组没有人
                for(z=0;z<26;z++){
                    if(input[i].alpha[z] == people){
                        input[i].count++;
                    }
                }
                people = 0;
                i++;
                continue;
            }else{
                //换人不换组
                if(flag>=97 && flag <=122){
                    input[i].alpha[flag-97] ++;
                }
            }
        }else{
            if(flag>=97 && flag <=122){
                input[i].alpha[flag-97] ++;
            }
        }
    }

    fclose(fp);

    int res = 0;
    for(i=0;i<SIZE;i++){
        res += input[i].count;
    }
    printf("\nPART II: %d\n", res);


    return 0;
}
