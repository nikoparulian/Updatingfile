#include <stdio.h>
#include <string.h>

int main()
{
    // deklarasi konten baris
    struct {
        char prodi[5];
        char nama[20];
        char nilai[10];
    }x,y,z;

    FILE *arsipMatkul;
    FILE *arsipMatkulUpdate;

    arsipMatkul = fopen("ArsipMatKul.txt", "r");
    arsipMatkulUpdate = fopen("ArsipMatKulUpdate.txt", "w");

    fscanf(arsipMatkul, "%s %s %s\n", &x.prodi, &x.nama, &x.nilai);

    // flag first line
    int is_first = 1;

    do {
        if(is_first == 1) {
            fscanf(arsipMatkul, "%s %s %s\n", &y.prodi, &y.nama, &y.nilai);
            fscanf(arsipMatkul, "%s %s %s\n", &z.prodi, &z.nama, &z.nilai);
            is_first = 0;
        }
        else {
            // jika menemukan nilai selain 75 diantara 75
            if((strcmp(x.nilai,"75") == 0) && (strcmp(y.nilai,"75") != 0) && (strcmp(z.nilai,"75") == 0)) {
                fprintf(arsipMatkulUpdate, "%s %s %s\n", x.prodi, x.nama, x.nilai);
                strcpy(y.nilai,"-> 80");
            }
            else {
                fprintf(arsipMatkulUpdate, "%s %s %s\n", x.prodi, x.nama, x.nilai);
            }
            // geser baris
            x = y;
            y = z;

            fscanf(arsipMatkul, "%s %s %s\n", &z.prodi, &z.nama, &z.nilai);
        }
    }
    while(!feof(arsipMatkul));
    // menambahkan sisa scan
    fprintf(arsipMatkulUpdate, "%s %s %s\n", x.prodi, x.nama, x.nilai);
    fprintf(arsipMatkulUpdate, "%s %s %s\n", y.prodi, y.nama, y.nilai);

    fclose(arsipMatkul);
    fclose(arsipMatkulUpdate);
}
