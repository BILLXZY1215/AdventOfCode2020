#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
// #define SIZE 3
#define SIZE 9
// #define SIZE 78

struct data{
    int bus;
    int index;
};

struct data bus[SIZE];

long long int head;

long long int rec(int i, long long int d);
int main(){
    int i = 0;

    //PART I
    // long int bus[SIZE];
    // bus[0] = 17;//16
    // bus[1] = 37;//
    // bus[2] = 449;
    // bus[3] = 23;
    // bus[4] = 13;
    // bus[5] = 19;
    // bus[6] = 607;
    // bus[7] = 41;
    // bus[8] = 29;
    // long int time = 1006401;
    // long int wait = 0 - time%bus[0] + bus[0];
    // long int res = wait * bus[0];
    // for(i=1;i<SIZE;i++){
    //     if(0 - time%bus[i] + bus[i] < wait){
    //         wait = 0 - time%bus[i] + bus[i];
    //         res = wait * bus[i];
    //     }
    // }
    // printf("PART I: %ld \n", res);

    //PART II

    int j = 0;
    i = 0;
    FILE *fp;
    fp = fopen("copy.txt","r");
    // fp = fopen("test.txt","r");
    while(!feof(fp)){
        char shit[10];
        fscanf(fp,"%s\n",shit);
        if(strcmp("x",shit) != 0){
            bus[j].bus = atof(shit);
            bus[j].index = i;
            j++;
        }
        i++;
    }
    fclose(fp);

    //TRAVERSE
    for(i=0;i<SIZE;i++){
        printf("bus: %d, index: %d\n", bus[i].bus, bus[i].index);
    }

    head = 14980153;

    i=0;

    // long long int k = rec(i, head);

    // while(1){
    //     if(head%17 == 0){
    //         printf("%lld\n",head);
    //         if((head+2)%13 == 0){
    //             if((head+3)%19 == 0){
    //                 printf("PART II: %lld\n", head);
    //                 break;
    //             }else{
    //                 head+=17;
    //                 continue;
    //             }
    //         }else{
    //             head+=17;
    //             continue;
    //         }
    //     }else{
    //         head+=17;
    //     }
    // }

    while(1){
        // 607 23 29 37都是质数
        // 求他们共同的因数即求607*23*29*37的质数
        if(head%14980153 == 0){
            if((head-31)%449 == 0){
                if((head+10)%41 == 0){
                    // if((head-37)%37 == 0){
                        // if((head+29)%29 == 0){
                            // if((head-23)%23 == 0){
                                if((head-12)%19 == 0){
                                    if((head-31)%17 == 0){
                                        if((head-18)%13 == 0){
                                            printf("PART II: %lld\n", head-48);
                                            break;
                                        }else{
                                            head+=14980153;
                                            continue;
                                        }
                                    }else{
                                        head+=14980153;
                                        continue;
                                    }
                                }else{
                                    head+=14980153;
                                    continue;
                                }
                            // }else{
                            //     head+=607;
                            //     continue;
                            // }
                        // }else{
                        //     head+=607;
                        //     continue;
                        // }
                    // }else{
                    //     head+=607;
                    //     continue;
                    // }
                }else{
                    head+=14980153;
                    continue;
                }
            }else{
                head+=14980153;
                continue;
            }
        }else{
            head+=14980153;
            continue;
        }
        printf("%lld\n",head);
    }

    return 0;
}

long long int rec(int i, long long int d){
    if(d % bus[i].bus == 0){
        if(i == SIZE-1){
            return d;
        }else{
            return rec(i+1, d+bus[i+1].index);
        }
    }else{
        return rec(0, head+bus[0].bus);
    }
}

