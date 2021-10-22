#include <stdio.h>
float average(float a[5])
{
    for (int i = 1; i <= 5; i++)
    {
        printf(" enter elements of array\n");
        scanf("%f", &a[i]);
    }
    float avg = (a[0] + a[1] + a[2] + a[3] + a[4]) / 5;
}
void main()
{
    float a[5];
    printf("average of five no. is %f ", average(a));
}