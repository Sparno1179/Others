#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#define MICRO_SEC 1000

int nanosleep(const struct timespec *req, struct timespec *rem);

int main()
{
    double total = 0;
    double waited_time = 0;
    for(int i=0; i < 500; i++)
    {
        struct timeval s, e;
        struct timespec req = {0, 15625 * MICRO_SEC};

        gettimeofday(&s, NULL);
        nanosleep(&req, NULL);
        gettimeofday(&e, NULL);

        waited_time = (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6;
        printf("time = %lf\n", waited_time);
        total += waited_time;
    }

    printf("AWT = %lf\n", total / 500.0);
    printf("difference between AWT and input = %lf", ((total / 500.0) / 0.015625));
}