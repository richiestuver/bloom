#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{

    unsigned long long N = strtoull(argv[1], NULL, 10);
    unsigned long long sqrt_N = (unsigned long long)(floor(sqrt(N)));

    printf("N: %llu, sqrtN: %llu\n", N, sqrt_N);

    unsigned long long* arr = calloc(N, sizeof(unsigned long long));
    arr[0] = 1;
    arr[1] = 1;

    for (unsigned long long i = 2; i <= sqrt_N; i++) {
        if (arr[i] == 0) {

            unsigned long long k = 2;
            unsigned long long j = k * i;
            while (j < N) {
                arr[j] = 1;
                k += 1;
                j = k * i;
            }
        }
    }

    for (unsigned long long i = 0; i < N; i++) {
        if (arr[i] == 0) {
            printf("%llu ", i);
        }
    }
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
