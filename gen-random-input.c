#include "stdlib.h"
#include "stdio.h"
#include "time.h"

//global const's
#define MIN_NUMBER_OF_INTERVALS 5
#define MAX_NUMBER_OF_INTERVALS 15
#define MIN_STEP 1
#define MAX_STEP 5
#define MIN_INTERVAL_SIZE 2
#define MAX_INTERVAL_SIZE 10
#if MIN_STEP <= 0
#error MIN_STEP should be >0
#endif

//main
int main(int argc,char *argv[]) {
    srand(time(NULL));

    int size = MIN_NUMBER_OF_INTERVALS + rand() % (MAX_NUMBER_OF_INTERVALS-MIN_NUMBER_OF_INTERVALS);
    printf("%d\n",size);

    int i = 0;
    int s = 0;
    for(; i < size; i++) {
        s += MIN_STEP + rand() % (MAX_STEP-MIN_STEP);
        int e = s + MIN_INTERVAL_SIZE + rand() % (MAX_INTERVAL_SIZE-MIN_INTERVAL_SIZE);
        printf("%d %d\n",s,e);
    }
}
