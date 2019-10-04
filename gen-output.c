#include "stdlib.h"
#include "stdio.h"

int main(void) {
    int size = 0;
    scanf("%d",&size);
    int* intervals = malloc(sizeof(int)*size*2);
    if(intervals == NULL) {
        printf("error: cannot allocate memory\n");
        exit(1);
    }

    int i = 0;
    int* ptr = intervals;
    int start_max = 0;
    for(i=0;i<size;i++,ptr+=2) {
        scanf("%d",ptr);
        scanf("%d",ptr+1);
        if( *ptr <= start_max ) {
            printf("error: starts of intervals should increase strictly\n");
            exit(1);
        }
        if( *(ptr+1) < *ptr ) {
            printf("error: end of the interval should be no less than its start\n");
            exit(1);
        }
    }

    int prev_start = 0,
        prev_end = -1;
    for(i = 0;i < size*2; i+=2) {
        int curr_start = intervals[i],
            curr_end = intervals[i+1];

        if( curr_start > prev_end ) {
            prev_start = curr_start;
            prev_end = curr_end;
            printf("%d\t%d\n",prev_start,prev_end);
        }
    }
}
