#include <stdio.h>

int sum()
{
    int a, b;
    printf("Enter two numbers: \n");
    scanf("%d %d", &a, &b);
    int result = a + b;
}
int main()
{
    printf("The sum of two numbers is %d", sum()); //printf first calls the function sum() and then executes to print the string
    return 0;
}