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

void shift_left(int** mat, int N) {
    int* temp_buffer = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++){
        temp_buffer[i] = mat[i][0];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            mat[i][j] = mat[i][j + 1];
        }
    }
    for(int i = 0; i < N; i++){
        mat[i][N - 1] = temp_buffer[i];
    }
    free(temp_buffer);
}

void shift_left_row(int* mat, int N, int n){
    int* temp_buffer = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        temp_buffer[i] = mat[i];
    }

    for(int i = 0; i < (N - n); i++){
        mat[i] = mat[i + n];
    }

    for(int i = (N - n); i < N; ++i){
        mat[i] = temp_buffer[i - (N - n)];
    }
    free(temp_buffer);
}

void shift_up(int **mat, int N)
{
    int* temp_buffer = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; ++i){
        temp_buffer[i] = mat[0][i];
    }

    for(int i = 0; i < N - 1; ++i){
        for(int j = 0; j < N; ++j){
            mat[i][j] = mat[i + 1][j];
        }
    }

    for(int i = 0; i < N; ++i){
        mat[N - 1][i] = temp_buffer[i];
    }
    free(temp_buffer);
}

void shift_up_row(int** mat, int N, int kol, int n){
    int* temp_buffer = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
        temp_buffer[i] = mat[i][kol];
    }

    for(int i = 0; i < N - n; ++i){
        mat[i][kol] = mat[i + n][kol];
    }

    for(int i = (N-n); i < N; ++i){
        mat[i][kol] = temp_buffer[i - (N - n)];
    }
    free(temp_buffer);
}

void strassenSum(int** A, int** B, int** C, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            C[i][j] += (A[i][j] * B[i][j]);
        }
    }
}

int main(void){
    int N, i, j;
    clock_t start, end;
    double dura;
    srand(time(0));

    printf("Ukuran matriks : ");
    scanf("%d", &N);

    int** A = (int**)malloc(N * sizeof(int*));
    int** B = (int**)malloc(N * sizeof(int*));
    int** C = (int**)calloc(N, sizeof(int*));

    for(i = 0; i < N; ++i){
        A[i] = (int*)malloc(sizeof(int) * N);
        B[i] = (int*)malloc(sizeof(int) * N);
        C[i] = (int*)calloc(N, sizeof(int));
    }
    randomArray(N, A, B);

    start = clock();
    // Inisialisasi posisi
    for(i = 0; i < N - 1; i++){
        shift_left_row(A[i + 1], N, i + 1);
        shift_up_row(B, N, i + 1, i + 1);
    }
    strassenSum(A, B, C, N);

    for(int i = 0; i < N - 1; i++){
        shift_left(A, N);
        shift_up(B, N);
        strassenSum(A, B, C, N);
    }
    end = clock();
    dura = (double)(end - start)/CLOCKS_PER_SEC;
    printf("%0.8f\n",dura);

    for(i = 0; i < N; ++i){
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

