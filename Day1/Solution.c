#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,z = 0;    
    long int res = 1;
    int input[200];
    char name[5];
    FILE *fp;
    fp = fopen("input.txt","r");

    while(!feof(fp))
    { 
        fscanf(fp, "%s\n", name);
        // printf("%d, %s\n", i, name);
        input[i] = atoi(name);
        i++;
    }

    fclose(fp);

    // TRAVERSE 
    // for(i=0;i<200;i++){
    //     printf("%d \n",input[i]);
    // }

    // PART I
    // for(i=0;i<199;i++){
    //     for(j=i+1;j<200;j++){
    //         if(input[j] + input[i] == 2020){
    //             printf("i: %d\n", input[i]);
    //             printf("j: %d\n", input[j]);
    //             res = input[j] * input[i];
    //             break;
    //         }
    //     }
    // }

    // PART II
    int flag = 0;
    for(i=0;i<200;i++){
        for(j=0;j<200;j++){
            for(z=0;z<200;z++){
                if(input[i] + input[j] + input[z] == 2020 && (input[i] != input[j]) && (input[j] != input[z]) && (input[i] != input[z])){
                    printf("i: %d\n", input[i]);
                    printf("j: %d\n", input[j]);
                    printf("z: %d\n", input[z]);
                    res =  input[j] * input[i] * input[z];
                    flag = 1;
                    break;
                } 
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
    }

    printf("res: %ld\n", res);
    return 0;
}