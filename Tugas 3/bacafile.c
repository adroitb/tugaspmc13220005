#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Masukkan nama file: ");
    char array[100];
    scanf("%s", array);

    FILE *dat = fopen (array, "rb");
    if (dat == NULL) return 1;
    int data_point;

    unsigned char head[8];
    fread(head, sizeof(head), 1, dat);

    unsigned char signaturepng[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    unsigned char signaturepdf[8] = {0x25, 0x50, 0x44, 0x46, 0x2D, 0x31, 0x2E, 0x37};
    unsigned char signaturejpg[8] = {0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46};

    if (!memcmp(signaturepng, head, 8))
    {
        printf("\n%s adalah file PNG", array);
    };
    if (!memcmp(signaturepdf, head, 8)){
        printf("\n%s adalah file PDF", array);
    }
    if (!memcmp(signaturejpg, head, 8)){
        printf("\n%s adalah file JPG", array);
    }
    else{
        printf("\n%s tidak diketahui jenis filenya", array);
    }

    fclose(dat);
    return 0;
}

