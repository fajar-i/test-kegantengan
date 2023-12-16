#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "executable/ApelJelek.h"
// #include "Sortir.h"

struct To_Do{
    char jam[250];
    char hari[250];
    char kegiatan[250];
    int tanggal;
    int bulan;
    int tahun;
    char selesai[20];
};

int  Tambah_Jadwal(int size, struct To_Do *list);
int  read_db(struct To_Do *list, const char *filename, int size);
void Jadwal(struct To_Do *list, int size);
void cek_db(const char *filename);
void cari (struct To_Do *list, int size);
void overwrite(struct To_Do *list, int size, const char *aksinya);
void update (struct To_Do *list, int size);
const char* daftar_hari();
const char* daftar_bulan(int no);

int main(){
    int size;
    char menu;
    struct To_Do list[255];

    cek_db("db.txt");
    size = read_db(list, "db.txt", size);

    system("CLS");
    // system("start \"\" music\\1.mp3");

    do{
        size = read_db(list, "db.txt", size);
        system("type menu\\1.txt");
        scanf("%s", &menu);
        printf("\n");

        if(menu==0){
            printf("dadah"); 
            exit(0);}

        switch (menu) {
        case '1':
            size = read_db(list, "db.txt", size);
            Jadwal(list, size);
            break;

        case '2':
            system("CLS");
            size = read_db(list, "db.txt", size);
            Tambah_Jadwal(size, list);
            break;

        case '3':
            system("CLS");
            size = read_db(list, "db.txt", size);
            cari(list, size);
            break;
        case 'b': bjari();

        default: 
            printf("input tidak valid");
            Sleep(2000); 
            break;
        }    
    } while (menu!='0');
    return 0;
}

void cek_db(const char *filename){
    FILE *db = fopen(filename, "r");

    if (db == NULL) {
        printf("database tidak ditemukan sehingga list di reset");
        system("type nul > db.txt");
        return;
    }

    fclose(db);
}

int read_db(struct To_Do *list, const char *filename, int size){
    FILE *db = fopen(filename, "r");
    size = 0;

    while (fgets(list[size].kegiatan, sizeof(list[size].kegiatan), db) != NULL){
        list[size].kegiatan[strcspn(list[size].kegiatan, "\n")] = 0;

        fgets(list[size].hari, sizeof(list[size].hari), db);
        list[size].hari[strcspn(list[size].hari, "\n")] = 0;
        
        fscanf(db, "%d\n", &list[size].tanggal);
        fscanf(db, "%d\n", &list[size].bulan);
        fscanf(db, "%d\n", &list[size].tahun);

        fgets(list[size].jam, sizeof(list[size].jam), db);
        list[size].jam[strcspn(list[size].jam, "\n")] = 0;

        fgets(list[size].selesai, sizeof(list[size].selesai), db);
        list[size].selesai[strcspn(list[size].selesai, "\n")] = 0;

        size++;
    }
    fclose(db);
    return size;
}

void Jadwal(struct To_Do *list, int size) {
    const char *bulannya;

    if (size == 0){
        printf("Jadwalmu kosong bang, mending bobo aja\n");
    } else {
    system("CLS");
    printf("                    LIST KEGIATAN\n");
    printf("=======================================================\n");

    for (int i = 0; i < size; i++){
        bulannya = daftar_bulan(list[i].bulan);

        printf("Kegiatan %d  : %s\n", i+1, list[i].kegiatan);
        printf("Hari        : %s\n", list[i].hari);
        printf("Tanggal     : %d %s %d\n", list[i].tanggal, bulannya, list[i].tahun);
        printf("Jam         : %s\n", list[i].jam);
        printf("Keterangan  : %s\n", list[i].selesai);
        printf("=======================================================\n");
    }
    update(list, size);
    }
    getchar();
    printf("Tekan enter untuk melanjutkan...");
    getchar();
}

int Tambah_Jadwal(int size, struct To_Do *list){
    FILE *db = fopen("db.txt", "a");
    const char* hari;

    printf("mau ngapain : ");
    getchar();
    fgets(list[size].kegiatan, 250, stdin);
    list[size].kegiatan[strcspn(list[size].kegiatan, "\n")] = 0;

    hari = daftar_hari();
    strcpy(list[size].hari, hari);

    printf("Tanggal (1-31) : ");
    scanf("%d", &list[size].tanggal);

    printf("Bulan (1-12) : ");
    scanf("%d", &list[size].bulan);

    printf("Tahun : ");
    scanf("%d", &list[size].tahun);

    printf("jam berapa (contoh : 09.00) : ");
    getchar();
    fgets(list[size].jam, 250, stdin);

    strcpy(list[size].selesai, "Belum selesai");
    size++;

    overwrite(list, size, "w");
    fclose(db);

    return size;    
}

void cari (struct To_Do *list, int size){
    const char* hari;
    hari = daftar_hari();
    const char *bulannya;

    system("CLS");
    printf("Jadwal di hari %s : \n", hari);
    printf("=======================================================\n");
    for (int i = 0; i < size; i++){
        if (strcmp(list[i].hari, hari)==0){
            bulannya = daftar_bulan(list[i].bulan);

            printf("kegiatan %d  : %s\n", i+1, list[i].kegiatan);
            printf("Tanggal     : %d %s %d\n", list[i].tanggal, bulannya, list[i].tahun);
            printf("jam         : %s\n", list[i].jam);
            printf("Keterangan  : %s\n", list[i].selesai);
            printf("=======================================================\n");
        }  
    }
    getchar();
    printf("Tekan enter untuk melanjutkan...");
    getchar();
}

const char* daftar_hari(){
    int menu;
    const char *hari;

    printf("[1] Senin\n");
    printf("[2] Selasa\n");
    printf("[3] Rabu\n");
    printf("[4] Kamis\n");
    printf("[5] Jum'at\n");
    printf("[6] Sabtu\n");
    printf("[7] Minggu\n");
    printf("Hari apa : ");
    scanf("%d", &menu);

    switch (menu){
    case 1: hari = "senin"; break;
    case 2: hari = "selasa"; break;
    case 3: hari = "rabu"; break;
    case 4: hari = "kamis"; break;
    case 5: hari = "jumat"; break;
    case 6: hari = "sabtu"; break;
    case 7: hari = "minggu"; break;
    default: break;
    }
    
    return hari;
}

const char* daftar_bulan(int no){
    const char *bulan;
    
    switch (no){
    case 1: bulan = "Januari"; break;
    case 2: bulan = "Februari"; break;
    case 3: bulan = "Maret"; break;
    case 4: bulan = "April"; break;
    case 5: bulan = "Mei"; break;
    case 6: bulan = "Juni"; break;
    case 7: bulan = "Juli"; break;
    case 8: bulan = "Agustus"; break;
    case 9: bulan = "September"; break;
    case 10: bulan = "Oktober"; break;
    case 11: bulan = "November"; break;
    case 12: bulan = "Desember"; break;
    default: break;
    }
    
    return bulan;
}

void update (struct To_Do *list, int size){
    char ubah[2];
    int menu, pilihan;
    printf("ingin merubah jadwal? (y/n) : ");
    scanf("%s", &ubah);
    if(strcmp(ubah, "y")==0){
        printf("[1] Tandai sudah selesai\n");
        printf("[2] Rubah jadwal\n");
        printf("[3] Hapus jadwal\n");
        printf("Masukkan pilihan jadwal : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Masukkan nomor kegiatan yang sudah selesai : ");
            scanf("%d", &pilihan);
            strcpy(list[pilihan-1].selesai, "\nselesai");
            overwrite(list, size, "w");
            printf("Kegiatan %d sudah ditandai selesai : ", pilihan);
            break;
        
        default:
            break;
        }

    }else{
        return;
    }
}

void overwrite(struct To_Do *list, int size, const char *aksinya){
    FILE *db = fopen("db.txt", aksinya);

    for (int i = 0; i < size; i++){
        fprintf(db, "%s\n", list[i].kegiatan);
        fprintf(db, "%s\n", list[i].hari);   
        fprintf(db, "%d\n", list[i].tanggal);
        fprintf(db, "%d\n", list[i].bulan);
        fprintf(db, "%d\n", list[i].tahun);
        fprintf(db, "%s", list[i].jam);
        fprintf(db, "%s\n", list[i].selesai);       
    }
    
    fclose(db);
}