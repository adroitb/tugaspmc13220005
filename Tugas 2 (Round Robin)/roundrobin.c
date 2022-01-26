#include<stdio.h>
#include <stdbool.h>

int main(){
    int i, proses, totalwaktu = 0, x, kuantum, flag;
    int waktu_datang[10], waktu_proses[10], temp[10], waktu_beres[10];
    printf("\nMasukkan Jumlah Proses:\t");
    scanf("%d", &proses);
    x = proses;
    for(i = 0; i < proses; i++)
    {
        printf("\nMasukkan Waktu Kedatangan Proses[%d]:\t", i);
        scanf("%d", &waktu_datang[i]);
    }
    for(i = 0; i < proses; i++)
    {
        printf("\nMasukkan Waktu Eksekusi Proses[%d]:\t", i);
        scanf("%d", &waktu_proses[i]);
        temp[i] = waktu_proses[i];
    }

    printf("\nMasukkan Waktu Kuantum:\t");
    scanf("%d", &kuantum);

    for(totalwaktu = 0, i = 0; x != 0;){
        if(temp[i] <= kuantum && temp[i] > 0){
            totalwaktu += temp[i];
            temp[i] = 0;
            flag = 1;
        }
        else if (temp[i] > 0){
            totalwaktu += kuantum;
            temp[i] -= kuantum;
        }
        if(temp[i] ==0 && flag == 1){
            x--;
            waktu_beres[i] = totalwaktu;
            flag = 0;
        }
        if(i == proses-1){
            i = 0;
        }
        else if(waktu_datang[i+1] <= totalwaktu){
            i = i +1;
        }
        else{
            i = 0;
        }
    }
    printf("\n\nProcess\t|Waktu Kedatangan|Waktu Eksekusi |Waktu Beres|\n\n");
    for (int i=0; i<proses; i++) {
      printf("P[%d]\t| \t %d \t | \t %d \t | \t %d \t |\n",i,waktu_datang[i], waktu_proses[i], waktu_beres[i]);
   }
}
