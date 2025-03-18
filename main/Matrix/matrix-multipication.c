#include<stdio.h>
#include<stdlib.h>

void create_matrix(int a[][3], int row, int col)
    {
        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                a[i][j]=rand()%5;
    }

void display_matrix(int a [][3], int row , int col)
    {
        for (int i=0;i<row;i++)
            {
            for (int j=0;j<col;j++)
            printf("%d ", a[i][j]);
        printf("\n");
            }
            printf("\n");



    }

void matrix_multipication (int a[][3], int b[][3], int c[][3], int rA, int cB)
{
    for (int i=0;i<rA;i++)
       {
            for(int j=0;j<cB;j++)
            {
              c[i][j] =0;
               for (int k=0; k<3;k++)
                    c[i][j]+=a[i][k]*b[k][j];
            }
       }




}

int main()
{
    int a[3][3], b[3][3], c[3][3];
    create_matrix(a, 3, 3);
    display_matrix(a, 3, 3);
    create_matrix(b, 3, 3);
    display_matrix(b, 3, 3);
    matrix_multipication(a, b,c, 3, 3);
    display_matrix(c, 3, 3);
    return 0;
}
