#include <stdio.h>
#include <stdlib.h>
/* Nama : Adro Anra Purnama
   NIM : 13220005 */


int A = 0;
int B = 0;
int perintah = 0;
int rtn = 0;

int empty_stdin (void){
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}
int main()
{
    while(B != 4){
        for (;;){
            printf("\nA = %d\n", A);
            printf("B = %d\n", B);
            printf("\nInstruksi Main\n");
            printf("1. Mengisi Cangkir A\n");
            printf("2. Mengisi Cangkir B\n");
            printf("3. Membuang Air Cangkir A\n");
            printf("4. Membuang Air Cangkir B\n");
            printf("5. Menuangkan Cangkir A kepada Cangkir B\n");
            printf("6. Menuangkan Cangkir B kepada Cangkir A\n");
            printf("\n");

            printf("Masukkan Perintah: ");
            rtn = scanf("%d", &perintah);

            if (rtn == EOF){
                fputs ("\nUser canceled input.\n", stderr);
                return 1;
            }

            else if (rtn == 0){
                fputs ("\nError, Mohon masukkan Integer antara 1 - 6.\n", stderr);
                empty_stdin();
            }

            else if (perintah < 1 || perintah > 6){
                fputs ("\nError: Input perintah hanya diantara 1 - 6.\n", stderr);
                empty_stdin();
            }

            else{
                empty_stdin();
                break;
            }
        }
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
    }
    printf("\nB=4 Selamat anda memenangkan permainan ini.\n");
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
    A = min(3, (Atemp + Btemp));
    B = max(0, (Atemp + Btemp - 3));
}

