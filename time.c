#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    for(int i=0; i < 100; i++)
    {
        struct timeval s, e;  
        gettimeofday(&s, NULL);

        usleep(15625);

        gettimeofday(&e, NULL);
        printf("time = %lf\n", (e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6);
    }
}