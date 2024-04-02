// Nama : Alqan Nazra (231511068)
// Nama : Muhammad Wildan Gumilang (231511087)

#include "header.h"

void EntryData(namaKota P[], int kt) { // Nama : Muhammad Wildan Gumilang (231511087)
    address pNew;
    int i, pos;
    infousia inputusia{50};
    infotype inputNama[50];
    char ulang = 'Y';
    char pilihan;

    while (ulang == 'Y') {
        system("cls");
        
        DisplayDataKota(P, kt);

        /*input nama*/
        printf("Input ke dalam kota %s\n", P[kt - 1].kt);
        printf("Masukkan nama : ");
        fflush(stdin);
        scanf("%[^\n]s", inputNama);
        printf("Masukkan Usia : ");
        scanf("%d",inputusia);

        /*pembuatan elemen list baru*/
        CreateList(&pNew);
        Isi_Node(&pNew, inputNama);

        printf("\nPilih posisi untuk insert data:\n");
        printf("1. Awal\n");
        printf("2. Akhir\n");
        printf("3. Tengah\n");
        printf("Pilihan : ");
        fflush(stdin);
        scanf("%c", &pilihan);

        switch (pilihan) {
            case '1':
                Ins_Awal(&(P[kt - 1].p), pNew);
                break;
            case '2':
                Ins_Akhir(&(P[kt - 1].p), pNew);
                break;
            case '3':
                printf("Masukkan posisi untuk insert data: ");
                scanf("%d", &pos);
                InsertTengah(inputNama, pos, &(P[kt - 1].p));
                break;
            default:
                printf("Pilihan tidak valid.\n");
                free(pNew);
                continue;
        }

        /*ulang entry data?*/
        printf("\nApakah anda ingin entry data lagi? (Y/T) : ");
        ulang = toupper(_getch());
    }
}

void deleteData(namaKota P[], int nKota) { // Nama : Alqan Nazra (231511068)
    int pilKota, pos;
    address pDel;
    infotype nmDel[50];

    system("cls");
    menuKota(P, nKota, &pilKota);

    system("cls");
    DisplayDataKota(P, pilKota);

    printf("\nMasukkan posisi data yang ingin dihapus:\n");
    printf("1. Awal\n");
    printf("2. Akhir\n");
    printf("3. Tengah\n");
    printf("Pilihan : ");
    scanf("%d", &pos);

    switch (pos) {
        case 1:
            Del_Awal(&(P[pilKota - 1].p), nmDel);
            printf("%s berhasil dihapus.\n", nmDel);
            break;
        case 2:
            Del_Akhir(&(P[pilKota - 1].p), nmDel);
            printf("%s berhasil dihapus.\n", nmDel);
            break;
        case 3:
            printf("Masukkan posisi untuk delete data: ");
            scanf("%d", &pos);
            if (pos <= 0 || pos > Elmt(P[pilKota - 1].p) + 1) {
                printf("Posisi tidak valid.\n");
                return;
            }
            pDel = P[pilKota - 1].p;
            for (int i = 1; i < pos - 1; i++) {
                if (pDel == NULL) {
                    printf("Posisi tidak valid.\n");
                    return;
                }
                pDel = pDel->q;
            }
            Del_After(&pDel, nmDel);
            printf("%s berhasil dihapus.\n", nmDel);
            break;
        default:
            printf("Pilihan tidak valid.\n");
            return;
    }
    printf("\nTekan apa saja untuk kembali ke menu");
    _getch();
}

void deleteKota(namaKota P[], int *nKota) { // Nama : Muhammad Wildan Gumilang (231511087)
    int pilKota;
    
    // Validasi jumlah kota minimal 5
    if (*nKota <= 5) {
        printf("Jumlah kota sudah mencapai minimal 5. Operasi delete tidak dapat dilakukan.\n");
        printf("\nTekan apa saja untuk kembali ke menu");
        _getch();
        return;
    }

    system("cls");
    menuKota(P, *nKota, &pilKota);
    printf("Kota %s", P[pilKota - 1].kt);

    // Hapus data mahasiswa di kota yang dipilih
    address p = P[pilKota - 1].p;
    address temp;
    while (p != NULL) {
        temp = p;
        p = p->q;
        free(temp);
    }
    P[pilKota - 1].p = NULL;

    // Geser semua data kota setelah kota yang dihapus
    for (int i = pilKota - 1; i < *nKota - 1; i++) {
        strcpy(P[i].kt, P[i + 1].kt);
        P[i].p = P[i + 1].p;
    }

    // Dealokasi indeks terakhir
    free(P[*nKota - 1].p);
    P[*nKota - 1].p = NULL;
    P[*nKota - 1].kt[0] = '\0'; // Mengatur string menjadi kosong

    // Update jumlah kota
    (*nKota)--;

    printf(" berhasil dihapus dengan semua data mahasiswanya.");
    printf("\nTekan apa saja untuk kembali ke menu");
    _getch();
}

void DisplayDataKota(namaKota P[], int pilKota){ // Nama : Alqan Nazra (231511068)
    address p;
    p = P[pilKota-1].p;

    printf("===============================================\n");
    printf("Kota : %s\n", P[pilKota-1].kt);
    printf("===============================================\n");

    Tampil_List(p);

    printf("===============================================\n");
    printf("Jumlah Mahasiswa : %d\n", Elmt(P[pilKota-1].p));
    printf("===============================================\n\n");
}


// Fungsi untuk mencari data mahasiswa berdasarkan nama di seluruh kota
void SearchData(namaKota P[], int nKota){ // Nama : Alqan Nazra (231511068)
    address pSearch;
    char inputNama[50];

    system("cls");
    printf("Input nama mahasiswa yang ingin dicari: ");
	fflush(stdin);
    scanf("%[^\n]s", inputNama);

    system("cls");
    for(int i = 0; i<nKota; i++){
        pSearch = Search(P[i].p, inputNama);

        if(!isEmpty(pSearch)){
           printf("%s ditemukan di kota %s\n", inputNama, P[i].kt);
           DisplayDataKota(P,i+1);
           break;
        }
    }

    if(isEmpty(pSearch)){
        printf("%s tidak ditemukan\n", inputNama);
    }
    printf("\ntekan apa saja untuk kembali ke menu");
    _getch();

}

void searchusia (namaKota P[],int nkota)
{
    address uSearch;
    int inputUsia[50];

    system("cls");
    printf("Input Usia yang ingin dicari: ");
    scanf("%d", inputUsia);

    system("cls");
    for (int i = 0;i <nkota;i++)
    {
        uSearch = Searchusia(P[i].p, inputUsia);

        if(isEmpty(uSearch)){
            printf("%d ditemukan dikota %s\n", inputUsia,P[i].kt);
            DisplayDataKota(P,i+1);
            break;
        }
    }

    if(isEmpty(uSearch)){
        printf("%s tidak ditemukan\n", inputUsia);
    }
    printf("\ntekan apa saja untuk kembali ke menu");
    _getch();
}

void DisplayData(namaKota P[], int nKota){ // Nama : Alqan Nazra (231511068)
    system("cls");

    for(int i = 0; i<nKota; i++){
        DisplayDataKota(P, i+1);
    }
    printf("tekan apa saja untuk kembali ke menu");
    _getch();
}

void menuKota(namaKota P[],int nKota, int* pil){ // Nama : Alqan Nazra (231511068)
    system("cls");
    for(int i = 0; i<nKota; i++){
        printf("%d. %s\n", i+1, P[i].kt);
    }
    printf("Pilih angka kota: ");
    scanf("%d", pil);


}

void inputJumlahKota(int* nKota){ // Nama : Muhammad Wildan Gumilang (231511087)
    system("cls");
    do {
        printf("Masukkan jumlah kota (minimal 5): ");
        scanf("%d", nKota);

        if (*nKota < 5) {
            printf("Jumlah kota minimal harus 5.\n");
        }
    } while (*nKota < 5);
}


void inputNamaKota(namaKota P[], int nKota) { // Nama : Muhammad Wildan Gumilang (231511087)
    namaKota dtk;

    ulangi:
    system("cls");

    for (int i = 0; i < nKota; i++) {
        printf("Nama kota %d : ", i + 1);
        fflush(stdin);
        scanf("%[^\n]s", P[i].kt);
        P[i].p = NULL;
    }

    // Memeriksa duplikasi nama kota
    for (int i = 0; i < nKota - 1; i++) {
        for (int j = i + 1; j < nKota; j++) {
            int cek = strcmp(P[i].kt, P[j].kt);
            if (cek == 0) {
                printf("Nama kota tidak boleh duplikat.\n");
                printf("\nTekan apa saja untuk kembali ke menu");
                _getch();
                goto ulangi;
            }
        }
    }
}

bool isEmpty(address p){ // Nama : Alqan Nazra (231511068)

    if(p == NULL){ // jika p == null maka return true
        return true;
    }else{
        return false;
    }
}

void CreateList (address *p){ // Nama : Alqan Nazra (231511068)

    *p = (address) malloc(sizeof(ListNama));
}

void Isi_Node (address *p , infotype* nilai){ // Nama : Alqan Nazra (231511068)
    if(!isEmpty(*p)){
        strcpy((*p)->nm, nilai);
        (*p)->q = NULL;
    }
}
// Fungsi untuk menampilkan isi list
void Tampil_List (address p){ // Nama : Alqan Nazra (231511068)
    int nomor = 1;
    while(!isEmpty(p)){
        printf("%d. %s\n", nomor, (p)->nm);
        p = (p)->q;
        nomor++;
    }
}

void Ins_Awal (address *p, address PNew){ // Nama : Muhammad Wildan Gumilang (231511087)

    (PNew)->q = *p;
    *p = PNew;
}

void Ins_Akhir (address *p, address PNew){ // Nama : Muhammad Wildan Gumilang (231511087)
    address pAkhir;
    if(isEmpty(*p)){
        (*p) = PNew;
    }else{
        pAkhir = (*p);
        while(!isEmpty((pAkhir)->q)){
            pAkhir = (pAkhir)->q;
        }
        (pAkhir)->q = PNew;
    }

}

// Fungsi untuk mencari node berdasarkan nilai
address Search (address p, infotype* nilai){ // Nama : Alqan Nazra (231511068)
    bool ketemu = false;
    address x = NULL ;

    while(!ketemu && !isEmpty(p)){
        if(strcmp((p)->nm,nilai) == 0){
            x = p;
            ketemu=true;
        }
        p = (p)->q;
    }
    return x;
}

address Searchusia (address p, infousia* nilai)
{
    bool selesai = false;
    address x = NULL ;

    while (!selesai && !isEmpty(p))
    {
        if((p)->usi,nilai == 0){
            x = p;
            selesai = true;
        }
        p = (p) ->q;
    }
    return x;
}

void InsertTengah(infotype nilaiBaru[], int pos, address *awal) { // Nama : Alqan Nazra (231511068)
    address p, q;
    int count = 1;

    p = (address)malloc(sizeof(ListNama));
    if (p == NULL) {
        printf("Alokasi memori gagal.\n");
        return;
    }

    Isi_Node(&p, nilaiBaru);

    if (pos == 1) {
        Ins_Awal(awal, p);
        return;
    }

    q = *awal;
    while (q != NULL && count < pos - 1) {
        q = q->q;
        count++;
    }

    if (q == NULL) {
        printf("Posisi tidak valid.\n");
        free(p);
        return;
    }

    InsertAfter(&q, p);
}

void InsertAfter (address * pBef, address PNew){ // Nama : Alqan Nazra (231511068)

    (PNew)->q = (*pBef)->q;
    (*pBef)->q = PNew;

}

void Del_Awal (address * p, infotype * X){ // Nama : Muhammad Wildan Gumilang (231511087)

    address q;
    strcpy(X,(*p)->nm);
    q = *p;
    *p = (*p)->q;
    (q)->q = NULL;
    DeAlokasi(&q);
}

void Del_Akhir (address * p, infotype * X){ // Nama : Muhammad Wildan Gumilang (231511087)

    address PDel, PBfr;
    PBfr = *p;
    while(((PBfr)->q)->q != NULL){
        PBfr = (PBfr)->q;
    }
    PDel = (PBfr)->q;
    strcpy(X,(PDel)->nm) ;
    (PBfr)->q = NULL;
    DeAlokasi(&PDel);
}

void Del_After (address * pBef, infotype * X){ // Nama : Alqan Nazra (231511068)

    address PDel,PNext;
    PDel = (*pBef)->q;
    strcpy(X, (PDel)->nm);
    PNext = (PDel)->q;
    (*pBef)->q = PNext;
    (PDel)->q = NULL;
    DeAlokasi(&PDel);
}

void DeAlokasi (address * p){ // Nama : Muhammad Wildan Gumilang (231511087)

    (*p)->q = NULL;
    free(*p);
}

// Fungsi untuk menghitung jumlah elemen dalam list
int Elmt (address p){  // Nama : Muhammad Wildan Gumilang (231511087)

    int n;
    n = 0;

    if(isEmpty(p)){
        return n;
    }else{
        n++;
    }

    while(!isEmpty((p)->q)){
        n++;
        p = (p)->q;
    }
    return n;
}

void menu(namaKota P[], int nKota){ // Nama : Muhammad Wildan Gumilang (231511087)
    system("cls");
    int pil, pilKota;
    printf("1. Entry Data Mahasiswa\n");
    printf("2. Cari Data\n");
    printf("3. Tampilkan Seluruh Data\n");
    printf("4. Tampilkan Data Kota\n");
    printf("5. Hapus Data Kota (Seluruh data mahasiswa di dalam kota akan terhapus)\n");
    printf("6. Hapus Data Nama Mahasiswa Dalam Kota\n");
    printf("0. Exit\n");
    printf("Pilih Menu : ");
    scanf("%d", &pil);

    switch(pil){
        case 1: menuKota(P, nKota, &pilKota);
                EntryData(P, pilKota);break;
        case 2: SearchData(P, nKota);break;
        case 3: DisplayData(P, nKota);break;
        case 4: menuKota(P, nKota, &pilKota);
                system("cls");
                DisplayDataKota(P, pilKota);
                printf("\nTekan apa saja untuk kembali ke menu");
                _getch();break;
        case 5: deleteKota(P, &nKota);break;
        case 6: deleteData(P, nKota);break;
        case 0: exit(1);break;
        default: printf("menu tidak tersedia");
		_getch();
    }
}