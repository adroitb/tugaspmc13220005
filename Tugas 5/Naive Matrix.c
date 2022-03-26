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

void kali_matriks(int N, int** A, int** B, int** C)
{
        printf("\n\nExecution Time : \n");
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < N ; j++){
                C[i][j] = 0;

                for(int k = 0; k < N; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
    }
}

int main(){
    int N;

    printf("Masukkan ukuran matriks: ");
    scanf("%d", &N);

    int** A = (int**)malloc(N * sizeof(int*));
    int** B = (int**)malloc(N * sizeof(int*));
    int** C = (int**)calloc(N, sizeof(int*));

    for(int i = 0; i < N; ++i){
        A[i] = (int*)malloc(sizeof(int) * N);
        B[i] = (int*)malloc(sizeof(int) * N);
        C[i] = (int*)calloc(N, sizeof(int));
    }
    randomArray(N, A, B);
    kali_matriks(N, A, B, C);
    free(A);
    free(B);
    free(C);
    return 0;
}

