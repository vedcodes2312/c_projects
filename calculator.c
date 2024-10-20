#include <stdio.h>

int main() {
    int choice;
    int num1, num2, result, i;
    int flag = 0;
    long int factorial = 1;
    double base, exponent, power_result = 1.0;

    while(1) {
        // Display the menu
        printf("\n*** Advanced Calculator ***\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Factorial\n");
        printf("7. Check Prime\n");
        printf("8. Power\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user choice
        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            case 5:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 % num2;
                printf("Result: %d\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%d", &num1);
                factorial = 1;
                for(i = 1; i <= num1; i++) {
                    factorial *= i;
                }
                printf("Factorial of %d is %ld\n", num1, factorial);
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%d", &num1);
                flag = 0;
                if (num1 <= 1) {
                    flag = 1;
                }
                for(i = 2; i <= num1 / 2; i++) {
                    if(num1 % i == 0) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("%d is a prime number.\n", num1);
                } else {
                    printf("%d is not a prime number.\n", num1);
                }
                break;
            case 8:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &base, &exponent);
                power_result = 1.0;
                for(i = 1; i <= exponent; i++) {
                    power_result *= base;
                }
                printf("%.2lf raised to the power %.2lf is %.2lf\n", base, exponent, power_result);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose a valid operation.\n");
        }
    }

    return 0;
}