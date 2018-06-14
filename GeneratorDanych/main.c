#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *f = fopen("in100_3.txt", "wt");
    fprintf(f, "1000 1000\n");
    fprintf(f, "100\n");
    srand(time(NULL));
    for (unsigned int i = 0; i < 100; i++) {
        fprintf(f, "%d %d %d\n", rand() % 1001, rand() % 1101, rand() % 1101);
    }
    fclose(f);
    return 0;
}
