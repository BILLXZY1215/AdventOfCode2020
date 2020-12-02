#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct data {
    int least;
    int most;
    char target;
    char string[100];
};

struct data input[1000];


int main()
{
    int count = 0;
    char least[5];
    char most[5];
    char * target;
    FILE *fp;
    fp = fopen("input.txt","r");

    int i,j,freq = 0;

    while(!feof(fp))
    { 
        fscanf(fp, "%[^-]", least);
        fgetc(fp); // "-"
        fscanf(fp, "%[^ ]", most);
        fgetc(fp); // " "
        input[i].target = fgetc(fp);
        fgetc(fp); // ":"
        fgetc(fp); // " "
        fscanf(fp,"%s\n",input[i].string);
        input[i].least = atoi(least);
        input[i].most = atoi(most);
        i++;
    }

    fclose(fp);

    //TRAVERSE
    // for(i = 0; i< 1000; i++){
    //     printf("%d-%d %c: %s\n", input[i].least, input[i].most, input[i].target, input[i].string);
    // }

    //Part I
    // for(i=0;i<1000;i++){
    //     freq = 0;
    //     for(j=0;input[i].string[j] != '\0';j++){
    //         if(input[i].target==input[i].string[j]){
    //             freq++;
    //         }
    //         if(freq > input[i].most){
    //             break;
    //         }
    //     }
    //     if(freq <= input[i].most && freq >= input[i].least){
    //         count++;
    //     }
    // }

    //Part II
    for(i=0;i<1000;i++){
        freq=0;
        if(input[i].target==input[i].string[input[i].least-1]){
            freq++;
        }
        if(input[i].target==input[i].string[input[i].most-1]){
            freq++;
        }
        if(freq==1){
            count++;
        }
    }

    printf("count: %d\n", count);

    return 0;
}
