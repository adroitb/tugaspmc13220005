#include <stdio.h>

struct mhs{
    char nama[80];
    int nim;
    float hadir;
};

int main(){
    struct mhs pmc[100];
    int n, i; //Banyak mahasiswa
    int jmldata;
    printf("Masukkan jumlah data mahasiswa : ");
    scanf("%d", &n);
    jmldata = n;
    for(i = 0; i != jmldata; i++){
        printf("\nData Mahasiswa %d", i+1);
        printf("\nMasukkan Nama Mahasiswa : ");
        scanf("%s", &pmc[i].nama);
        printf("Masukkan NIM Mahasiswa : ");
        scanf("%d", &pmc[i].nim);
        printf("Masukkan Persentase Kehadiran Mahasiswa : ");
        scanf("%f", &pmc[i].hadir);
    }
    int count = 0;
    printf("\nMahasiswa yang kehadirannya dibawah 80% :");
    for(i = 0; i != jmldata; i++){
        if (pmc[i].hadir < 80.0){
            printf("\n%d  %s", pmc[i].nim, pmc[i].nama);
            count += 1;
        }
    }
    if (count == 0){
        printf("\nTidak ada mahasiswa yang kehadirannya kurang dari 80%");
    }
    return 0;
}

