#include <stdio.h>
#include <stdlib.h>
# Nama : Adro Anra Purnama
# NIM : 13220005

int A = 0;
int B = 0;
int perintah;

int main()
{
    while(B != 4){
        printf("Instruksi Main\n");
        printf("1. Mengisi Cangkir A\n");
        printf("2. Mengisi Cangkir B\n");
        printf("3. Membuang Air Cangkir A\n");
        printf("4. Membuang Air Cangkir B\n");
        printf("5. Menuangkan Cangkir A kepada Cangkir B\n");
        printf("6. Menuangkan Cangkir B kepada Cangkir A\n");
        printf("\n");
        printf("Masukkan Perintah: ");
        scanf("%d", &perintah);
        if (perintah == 1){
            perintah1();
        }
        else if (perintah == 2){
            perintah2();
        }
        else if (perintah == 3){
            perintah3();
        }
        else if (perintah == 4){
            perintah4();
        }
        else if (perintah == 5){
            perintah5();
        }
        else if (perintah == 6){
            perintah6();
        }
        printf("A = %d\n", A);
        printf("B = %d\n", B);
        printf("\n");
    }
    printf("B=4 Selamat anda memenangkan permainan ini.");
}
int max(int num1, int num2){
    int result;
    if (num1 >= num2){
        result = num1;
    }
    else{
        result = num2;
    }
    return result;
}

int min(int num1, int num2){
    int result;
    if (num1 >= num2){
        result = num2;
    }
    else{
        result = num1;
    }
    return result;
}

void perintah1(){
    A = 3;
}

void perintah2(){
    B = 5;
}

void perintah3(){
    A = 0;
}

void perintah4(){
    B = 0;
}

void perintah5(){
    int Atemp = A;
    int Btemp = B;
    B = min(5, (Atemp + Btemp));
    A = max(0, (Atemp + Btemp - 5));
}

void perintah6(){
    int Atemp = A;
    int Btemp = B;
    A = min(3, (A+B));
    B = max(0, (A+B-3));
}

