#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Masukkan nama file: ");
    char array[100];
    scanf("%s", array);
    FILE *fileptr;
    char *bufferpdf;
    char *bufferjpg;
    long filelen;
    int i;
    int pdf, jpg;

    fileptr = fopen(array, "rb");
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    rewind(fileptr);
    bufferpdf = (char *)malloc((filelen+1)*sizeof(char));
    bufferjpg = (char *)malloc((filelen+1)*sizeof(char));
    for(i = 0; i < 5; i++) { //Mengambil Hex PDF
       fread(bufferpdf+i, 1, 1, fileptr);
    }
    for(i =-1 ; i < 4; i++) { //Mengambil Hex JPG
       fread(bufferjpg+i, 1, 1, fileptr);
    }

    printf("File len: %ld\n", filelen);
    printf("%s\n",*&bufferpdf);
    printf("%s\n",*&bufferjpg);
    pdf = strcmp(bufferpdf, "%PDF-"); //Membandingkan code PDF
    jpg = strcmp(bufferjpg, "JFIF"); //Membandingkan code JPG
    if (pdf == 0){
        printf("\nFile yang dipilih adalah file PDF");
    }
    else if (jpg == 0){
        printf("\nFile yang dipilih adalah file JPG");
    }
    else{
        printf("\nFile yang dipilih bukan file PDF maupun JPG.");
    }
    fclose(fileptr); // Close the file

    return 0;
}

