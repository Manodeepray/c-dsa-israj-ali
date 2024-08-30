#include <stdio.h>
#include <stdlib.h>


int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int main() {
    const char *inputFilename = "input2.txt";   
    const char *outputFilename = "output2.txt"; 

    FILE *inputFile = fopen(inputFilename, "r");
    

    FILE *outputFile = fopen(outputFilename, "w");
    
    
    
    
    
    

    int num1, num2, gcd;
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        gcd = findGCD(num1, num2);
        fprintf(outputFile, "GCD of %d and %d is %d\n", num1, num2, gcd);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("GCDs have been calculated and stored in %s.\n", outputFilename);

    return 0;
}

