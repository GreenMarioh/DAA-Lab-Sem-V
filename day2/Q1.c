#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getBinary(int n, char *res[32]){
    if (n == 0) return;
    res += to_string(n&1);
    getBinary(n>>1, res);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    
    int num = argv[1]; // is string type;

    char *inputFile = argv[2]; // Input file
    char *outputFile = argv[3]; // OutpuT file
    int n = atoi(num);
    for(int i = 0; i < n; i++){
        
    }

    return 0;
}
