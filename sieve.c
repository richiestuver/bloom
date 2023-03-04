#include <getopt.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

bool VERBOSE = false;
int parse_opts(int argc, char* argv[])
{

    int opt;
    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
        case ('v'):
            VERBOSE = true;
            break;
        default:
            break;
        }
    }

    if (optind >= argc) {
        printf("USAGE: sieve [N] (-v)\n");
        exit(EXIT_FAILURE);
    }

    return optind;
}

int main(int argc, char* argv[])
{
    int arg_idx = parse_opts(argc, argv);

    unsigned long long N = strtoull(argv[arg_idx], NULL, 10);
    unsigned long long sqrt_N = (unsigned long long)(floor(sqrt(N)));

    if (VERBOSE) {
        printf("N: %llu, sqrtN: %llu\n", N, sqrt_N);
    }

    unsigned long long* arr = calloc(N, sizeof(unsigned long long));
    if (arr == NULL) {
        perror("calloc");
        return EXIT_FAILURE;
    }
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

    if (VERBOSE) {
        for (unsigned long long i = 0; i < N; i++) {
            if (arr[i] == 0) {
                printf("%llu ", i);
            }
        }
    }
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
