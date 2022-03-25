#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomArray(int N, int** A, int** B){
    for(int i = 0;i < N; i++){
        for(int j = 0; j< N; j++){
            A[i][j] = ((rand()%10) + 1);
            B[i][j] = ((rand()%10) + 1);
        }
    }
}

void kali_matriks(int N, int** A, int** B)
{
        int result[N][N];
        printf("\n\nPerkalian Matriks : \n");
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < N ; j++){
                result[i][j] = 0;

                for(int k = 0; k < N; k++){
                    result[i][j] += A[i][k] * B[k][j];
                }
                printf("%d ", result[i][j]);
            }
            printf("\n");
    }
}

int main(){
    int N;

    printf("Masukkan ukuran matriks\n");
    scanf("%d", &N);

    int** A = (int**)malloc(N * sizeof(int*));
    int** B = (int**)malloc(N * sizeof(int*));

    for(int i = 0; i < N; ++i){
        A[i] = (int*)malloc(sizeof(int) * N);
        B[i] = (int*)malloc(sizeof(int) * N);
    }
    randomArray(N, A, B);
    kali_matriks(N, A, B);
    getch();
    return 0;
}

