#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


char FILE_NAME[] = "bacatext.txt";
FILE *myfile;

int main(){
    myfile = fopen(FILE_NAME, "r");
    const char *get_filename_ext(const char *FILE_NAME) {
        const char *dot = strrchr(FILE_NAME, '.');
        if(!dot || dot == FILE_NAME) return "";
        return dot + 1;
    }

    printf("Tipe File : %s\n", get_filename_ext(FILE_NAME));
}
