#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 755
// #define SIZE 5

struct data {
    int direction;  
        //0: forward; 
        //1: north; 
        //2: south; 
        //3: east; 
        //4: wast;
        //5: left;
        //6: right;
    int shit;
};

struct data input[SIZE];

int main(){
    FILE *fp;
    fp = fopen("input.txt","r");
    // fp = fopen("test.txt","r");
    int i,j = 0;
    while(!feof(fp)){
        int c=0;
        char fuck[10];
        c = fgetc(fp);
        if(c==70){  // 'F'
            input[i].direction = 0;
        }else if(c==78){ // 'N'
            input[i].direction = 1;
        }else if(c==83){ //'S'
            input[i].direction = 2;
        }else if(c==69){ //'E'
            input[i].direction = 3;
        }else if(c==87){ //'W'
            input[i].direction = 4;
        }else if(c==76){ //'L'
            input[i].direction = 5;
        }else if(c==82){ //'R'
            input[i].direction = 6;
        }
        fscanf(fp, "%s\n", fuck);
        input[i].shit = atoi(fuck);
        i++;
    }
    fclose(fp);

    //TRAVERSE
    // for(i=0;i<SIZE;i++){
    //     printf("%d %d\n", input[i].direction, input[i].shit);
    // }

    int e, n, d = 0;
    // PART I

    // //d==0 => east
    // //d==1 => west
    // //d==2 => north
    // //d==3 => south
    // for(i=0; i<SIZE;i++){
    //     if(input[i].direction == 0){
    //         if(d==0){ 
    //             e+= input[i].shit;
    //         }else if(d==1){
    //             e-= input[i].shit;
    //         }else if(d==2){
    //             n+= input[i].shit;
    //         }else if(d==3){
    //             n-= input[i].shit;
    //         }
    //     }else if(input[i].direction == 1){ //'N'
    //         n+= input[i].shit;
    //     }else if(input[i].direction == 2){ //'S'
    //         n-= input[i].shit;
    //     }else if(input[i].direction == 3){ //'E'
    //         e+= input[i].shit;
    //     }else if(input[i].direction == 4){ //'W'
    //         e-= input[i].shit;
    //     }else if(input[i].direction == 5){ //'L'
    //         if(input[i].shit == 180){
    //             //E->W; W->E; N->S; S->N
    //             //0->1; 1->0; 2->3; 3->2
    //             if(d==0){
    //                 d=1;
    //             }else if(d==1){
    //                 d=0;
    //             }else if(d==2){
    //                 d=3;
    //             }else if(d==3){
    //                 d=2;
    //             }
    //         }else if(input[i].shit == 90){
    //             //E->N; N->W; W->S; S->E
    //             //0->2; 2->1; 1->3; 3->0
    //             if(d==0){
    //                 d=2;
    //             }else if(d==1){
    //                 d=3;
    //             }else if(d==2){
    //                 d=1;
    //             }else if(d==3){
    //                 d=0;
    //             }
    //         }else if(input[i].shit == 270){
    //             //E->S; S->W; W->N; N->E
    //             //0->3; 3->1; 1->2; 2->0
    //             if(d==0){
    //                 d=3;
    //             }else if(d==1){
    //                 d=2;
    //             }else if(d==2){
    //                 d=0;
    //             }else if(d==3){
    //                 d=1;
    //             }
    //         }
    //     }else if(input[i].direction == 6){ //'R'
    //         if(input[i].shit == 180){
    //             if(d==0){
    //                 d=1;
    //             }else if(d==1){
    //                 d=0;
    //             }else if(d==2){
    //                 d=3;
    //             }else if(d==3){
    //                 d=2;
    //             }
    //         }else if(input[i].shit == 90){
    //             //E->S; S->W; W->N; N->E
    //             //0->3; 3->1; 1->2; 2->0
    //             if(d==0){
    //                 d=3;
    //             }else if(d==1){
    //                 d=2;
    //             }else if(d==2){
    //                 d=0;
    //             }else if(d==3){
    //                 d=1;
    //             }
    //         }else if(input[i].shit == 270){
    //             //E->N; N->W; W->S; S->E
    //             //0->2; 2->1; 1->3; 3->0
    //             if(d==0){
    //                 d=2;
    //             }else if(d==1){
    //                 d=3;
    //             }else if(d==2){
    //                 d=1;
    //             }else if(d==3){
    //                 d=0;
    //             }
    //         }
    //     }
    // }

    // if(e<0){
    //     e = 0-e;
    // }
    // if(n<0){
    //     n = 0-n;
    // }
    // printf("PART 1: %d\n", e+n);


    //PART II
    //d==0 => east
    //d==1 => west
    //d==2 => north
    //d==3 => south
    int wayPoint[2];
    wayPoint[0] = 10;
    wayPoint[1] = 1;
    e=0;n=0;
    
    for(i=0; i<SIZE;i++){
        if(input[i].direction == 0){
            e+= input[i].shit*wayPoint[0];
            n+= input[i].shit*wayPoint[1];
        }else if(input[i].direction == 1){ //'N'
            wayPoint[1] += input[i].shit;
        }else if(input[i].direction == 2){ //'S'
            wayPoint[1] -= input[i].shit;
        }else if(input[i].direction == 3){ //'E'
            wayPoint[0] += input[i].shit;
        }else if(input[i].direction == 4){ //'W'
            wayPoint[0] -= input[i].shit;
        }else if(input[i].direction == 5){ //'L'
            if(input[i].shit == 180){
                //E->W; W->E; N->S; S->N
                //0->1; 1->0; 2->3; 3->2
                if(d==0){
                    d=1;
                }else if(d==1){
                    d=0;
                }else if(d==2){
                    d=3;

                }else if(d==3){
                    d=2;
                }
                wayPoint[0] = 0 - wayPoint[0];
                wayPoint[1] = 0 - wayPoint[1];
            }else if(input[i].shit == 90){
                //E->N; N->W; W->S; S->E
                //0->2; 2->1; 1->3; 3->0
                if(d==0){
                    d=2;
                }else if(d==1){
                    d=3;
                }else if(d==2){
                    d=1;
                }else if(d==3){
                    d=0;
                }
                int temp = wayPoint[1];
                wayPoint[1] = wayPoint[0];
                wayPoint[0] = 0-temp;
            }else if(input[i].shit == 270){
                //E->S; S->W; W->N; N->E
                //0->3; 3->1; 1->2; 2->0
                if(d==0){
                    d=3;
                }else if(d==1){
                    d=2;
                }else if(d==2){
                    d=0;
                }else if(d==3){
                    d=1;
                }
                int temp = wayPoint[0];
                wayPoint[0] = wayPoint[1];
                wayPoint[1] = 0-temp;
            }
            
        }else if(input[i].direction == 6){ //'R'
            if(input[i].shit == 180){
                if(d==0){
                    d=1;
                }else if(d==1){
                    d=0;
                }else if(d==2){
                    d=3;
                }else if(d==3){
                    d=2;
                }
                wayPoint[0] = 0 - wayPoint[0];
                wayPoint[1] = 0 - wayPoint[1];
            }else if(input[i].shit == 90){
                //E->S; S->W; W->N; N->E
                //0->3; 3->1; 1->2; 2->0
                if(d==0){
                    d=3;
                }else if(d==1){
                    d=2;
                }else if(d==2){
                    d=0;

                }else if(d==3){
                    d=1;
                }
                int temp = wayPoint[0];
                wayPoint[0] = wayPoint[1];
                wayPoint[1] = 0-temp;
            }else if(input[i].shit == 270){
                //E->N; N->W; W->S; S->E
                //0->2; 2->1; 1->3; 3->0
                if(d==0){
                    d=2;
                }else if(d==1){
                    d=3;
                }else if(d==2){
                    d=1;
                }else if(d==3){
                    d=0;
                }
                int temp = wayPoint[1];
                wayPoint[1] = wayPoint[0];
                wayPoint[0] = 0-temp;
            }
        }
        printf("wayPoint East: %d, wayPoint North: %d, East: %d, North: %d\n", wayPoint[0], wayPoint[1], e, n);

    }

    if(e<0){
        e = 0-e;
    }
    if(n<0){
        n = 0-n;
    }
    printf("PART 1: %d\n", e+n);

    return 0;
}