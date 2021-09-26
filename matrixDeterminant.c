//
// Created by juode on 30/06/21.
//

#include "stdio.h"

int determinant(int mat1[100][100], int n) {

    int num, det, c1, c2, min[n][n], o=1;

    if(n == 2) {
        det = 0;
        det = (mat1[0][0]*mat1[1][1]) - (mat1[1][0]*mat1[0][1]);
        return det;
    } else {
        for (int i = 0; i < n; i++) {
            c1 = 0; c2=0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != 0 && k != i) {
                        min[c1][c2] = mat1[j][k];
                        c2++;
                        if (c2 > n-2) {
                            c2=0;
                            c1++;
                        }
                    }
                }
            }
            num = mat1[0][i];
            det += o*(num*(determinant(min, n-1)));
            o = -1*o;
        }
    }
    return det;
}

void main() {

    int n;
    int mat1[100][100];
    printf("Enter the size of matrix : ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Given matrix is \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Determinant of the matrix is = %d", determinant(mat1, n));

}