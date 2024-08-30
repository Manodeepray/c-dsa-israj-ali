#include <stdio.h>
#include <stdlib.h>

int convertToBinary(int n) {
    if (n == 0) {
        return 0;
    }

    return (n % 2) + 10 * convertToBinary(n / 2);
}

int* convertFileToBinary(const char *filename, int n) {
    FILE *file = fopen(filename, "r");
    int* binArray = (int*)malloc(n * sizeof(int));

    int number;
    for (int i = 0; i < n; i++) {
    
        fscanf(file, "%d", &number);
        printf("Decimal: %d -> Binary: ", number);
        
        if (number == 0) {
            printf("0");
            binArray[i] = 0;
        } else {
            binArray[i] = convertToBinary(number);
        }
        printf("\n");
    }
    

    fclose(file);
    return binArray;
}

void writebinarrayfile(const char *filename , int array[], int n){
    FILE *file = fopen(filename , "w");
    


    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", array[i]);
    }


    fclose(file);



}

int main() {
    const char *inputfilename = "numbers.txt";
    const char *outputfilename = "output.txt"; 
    int n;



    printf("Enter the number of decimal numbers to convert to binary: ");
    scanf("%d", &n);


    int *binArray = convertFileToBinary(inputfilename, n);
    writebinarrayfile(outputfilename , binArray , n);
    

    return 0;
}

