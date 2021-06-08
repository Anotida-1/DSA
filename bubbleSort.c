#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i,n,temp, arr[100];
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for ( i = 0; i < n; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
            
        }
        
    }
    printf("\nThe sorted array is: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    
    return 0;
}
