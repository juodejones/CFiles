#include <stdio.h>

void sort(int[], int);

int main() {

    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array : \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    sort(array, n);
    return 0;
}

void sort(int array[], int n ) {

    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if( array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        printf("%d\t", array[i]);
    }
}