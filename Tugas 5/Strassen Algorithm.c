/*Strassen's Algorithm for Matrix Multiplication using Divide & Conquer Approach*/
/*Author: Sayak Bera*/

#include <stdio.h>
#include <math.h>

void randomArray(int N, int** A, int** B){
    for(int i = 0;i < N; i++){
        for(int j = 0; j< N; j++){
            A[i][j] = ((rand()%10) + 1);
            B[i][j] = ((rand()%10) + 1);
        }
    }
}

void Madd(int* A, int* B, int* C, int n, int x){
    int i,j, m=x>0?n/2:n;
    for (i=0;i<m;i++)
        for (j=0;j<m;j++)
            *(C+i*m+j) = *(A+i*n+j) + *(B+i*n+j);
}

void Msub(int* A, int* B, int* C, int n, int x){
    int i,j, m=x>0?n/2:n;
    for (i=0;i<m;i++)
        for (j=0;j<m;j++)
            *(C+i*m+j) = *(A+i*n+j) - *(B+i*n+j);
}

void strassen(int* A, int* B, int* C, int n){
    int i,j;
    if(n==2){
        int P=(*A+*(A+n+1))*(*B+*(B+n+1));  //P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])
        int Q=(*(A+n)+*(A+n+1))*(*B);   //Q=(A[1][0]+A[1][1])*B[0][0]
        int R=(*A)*(*(B+1)-*(B+n+1));   //R=A[0][0]*(B[0][1]-B[1][1])
        int S=(*(A+n+1))*(*(B+n)-*B);   //S=A[1][1]*(B[1][0]-B[0][0])
        int T=(*A+*(A+1))*(*(B+n+1));   //T=(A[0][0]+A[0][1])*B[1][1]
        int U=(*(A+n)-*A)*(*B+*(B+1));  //U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])
        int V=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1));  //V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1])

        *C=P+S-T+V;
        *(C+1)=R+T;
        *(C+n)=Q+S;
        *(C+n+1)=P+R-Q+U;
    }
    else{
        int m=n/2, x[m][m], y[m][m], o[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                o[i][j]=0;

        /*P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])*/
        int P[m][m];
        Madd(A, A+m*(n+1), x, n, 1);
        Madd(B, B+m*(n+1), y, n, 1);
        strassen(x, y, P, m);

        /*Q=(A[1][0]+A[1][1])*B[0][0]*/
        int Q[m][m];
        Madd(A+m*n, A+m*(n+1), x, n, 1);
        Madd(B, o, y, n, 1);
        strassen(x, y, Q, m);

        /*R=A[0][0]*(B[0][1]-B[1][1])*/
        int R[m][m];
        Madd(A, o, x, n, 1);
        Msub(B+m, B+m*(n+1), y, n, 1);
        strassen(x, y, R, m);

        /*S=A[1][1]*(B[1][0]-B[0][0])*/
        int S[m][m];
        Madd(A+m*(n+1), o, x, n, 1);
        Msub(B+m*n, B, y, n, 1);
        strassen(x, y, S, m);

        /*T=(A[0][0]+A[0][1])*B[1][1]*/
        int T[m][m];
        Madd(A, A+m, x, n, 1);
        Madd(B+m*(n+1), o, y, n, 1);
        strassen(x, y, T, m);

        /*U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])*/
        int U[m][m];
        Msub(A+m*n, A, x, n, 1);
        Madd(B, B+m, y, n, 1);
        strassen(x, y, U, m);

        /*V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1])*/
        int V[m][m];
        Msub(A+m, A+m*(n+1), x, n, 1);
        Madd(B+m*n, B+m*(n+1), y, n, 1);
        strassen(x, y, V, m);


        /*Calculating the 4 parts for the result matrix*/
        int W[m][m], X[m][m], Y[m][m], Z[m][m];
        Msub(V,T,x,m,0);
        Madd(S,x,y,m,0);
        Madd(P,y,W,m,0); // W=P+S-T+V
        Madd(R,T,X,m,0); // X==R+T
        Madd(Q,S,Y,m,0); // Y=Q+S
        Msub(U,Q,x,m,0);
        Madd(R,x,y,m,0);
        Madd(P,y,Z,m,0); // Z=P+R-Q+U

        /*Conquering 4 parts in the result matrix*/
        for (i=0;i<m;i++)
            for (j=0;j<m;j++){
                *(C+i*n+j) = W[i][j]; //C[0][0]=W
                *(C+i*n+j+m) = X[i][j]; //C[0][1]=X
                *(C+(i+m)*n+j) = Y[i][j]; //C[1][0]=Y
                *(C+(i+m)*n+j+m) = Z[i][j]; //C[1][1]=Z
            }
    }
}

void main()
{
    int i,j,k,m,N,o,n1,n2,n3,n,n4=0;

    printf("Masukkan ukuran matriks: ");
    scanf("%d", &N);

    int** A = (int**)malloc(N * sizeof(int*));
    int** B = (int**)malloc(N * sizeof(int*));

    for(int i = 0; i < N; ++i){
        A[i] = (int*)malloc(sizeof(int) * N);
        B[i] = (int*)malloc(sizeof(int) * N);
    }
    randomArray(N, A, B);
    n = N;
    n1 = N;
    n2 = N;
    n3 = N;
    n4 = N;

    /*Creating square matrix of order 2^n for all and initializing all elements to 0 except prefixed*/
    n4=n1>n2?n1:n2;
    n=n3>n4?n3:n4;

    m = pow(2, n);
    int a[m][m],b[m][m],C[m][m];
    for(i=0;i<m;i++)
        for(j=0;j<m;j++){
            a[i][j]=0;
            b[i][j]=0;
        }
    for(i=0;i<n1;i++)
        for(j=0;j<n2;j++)
            a[i][j]=A[i][j];
    for(i=0;i<n2;i++)
        for(j=0;j<n3;j++)
            b[i][j]=B[i][j];

    /*Printing first matrix*/
    printf("\nThis is the first matrix:");
    for(i=0;i<n1;i++){
        printf("\n\n\n");
        for(j=0;j<n2;j++)
            printf("\t%d",a[i][j]);
    }
    /*Printing second matrix*/
    printf("\n\n\nThis is the second matrix:");
    for(i=0;i<n2;i++){
        printf("\n\n\n");
        for(j=0;j<n3;j++)
            printf("\t%d",b[i][j]);
    }

    strassen(a,b,C,m);    //Calling the function.

    /*Printing the final matrix*/
    printf("\n\n\nThis is the final matrix:");
    for(i=0;i<n1;i++){
        printf("\n\n\n");
        for(j=0;j<n3;j++)
            printf("\t%d",C[i][j]);
    }
}
