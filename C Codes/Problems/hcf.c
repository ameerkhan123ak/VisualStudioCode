#include <stdio.h>

// Function to calculate the Highest Common Factor (HCF) of two numbers
int calculateHCF(int num1, int num2) {
    int smaller = (num1 < num2) ? num1 : num2;
    int hcf = 1;
    
    for (int i = 1; i <= smaller; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            hcf = i;
        }
    }
    
    return hcf;
}

int main() {
    int number1, number2;
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);

    int hcf = calculateHCF(number1, number2);
    printf("The HCF of %d and %d is: %d\n", number1, number2, hcf);

    return 0;
}
