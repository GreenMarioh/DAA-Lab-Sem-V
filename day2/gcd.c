#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "r");
    if (!f1)
    {
        printf("Error, no such input file.\n");
        return 1;
    }
    FILE *f2 = fopen(argv[2], "w");
    if (!f2)
    {
        printf("Error, cannot open output file.\n");
        fclose(f1);
        return 1;
    }

    int a, b;
    while (fscanf(f1, "%d %d", &a, &b) == 2)
    {
        int result = gcd(a, b);
        fprintf(f2, "The GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
