// Nama : Alqan Nazra (231511068)
// Nama : Muhammad Wildan Gumilang (231511087)

#ifndef NRSLL_H
#define NRSLL_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


typedef char infotype; 
typedef int infousia;

typedef struct tElmtList *address;
typedef struct tElmtList {
    infousia usi[50];
    infotype nm[50];
    address q;
} ListNama; // Tipe data baru ListNama

typedef struct{
    infotype kt[50]; 
    address p;
} namaKota; // Tipe data baru namaKota

bool isEmpty(address p);


void CreateList (address *p);


void Isi_Node (address *p , infotype* nilai);


void Tampil_List (address p);


void Ins_Awal (address *p, address PNew);


void Ins_Akhir (address *p, address PNew);


address Search (address p, infotype* nilai);


void InsertTengah(infotype nilaiBaru[], int pos, address *awal);


void InsertAfter (address * pBef, address PNew);


void Del_Awal (address * p, infotype * X);


void Del_Akhir (address * p, infotype * X);


void Del_After (address * pBef, infotype * X);


void DeAlokasi (address * p);


int Elmt (address p);


void EntryData(namaKota P[],int kt);


void deleteData(namaKota P[], int nKota);


void deleteKota(namaKota P[], int *nKota);


void DisplayDataKota(namaKota P[], int pilKota);


void SearchData(namaKota P[], int nKota);


void DisplayData(namaKota P[], int nKota);


void menuKota(namaKota P[],int nKota, int* pil);


void menu(namaKota P[], int nKota);


void inputJumlahKota(int* nKota);


void inputNamaKota(namaKota P[], int nKota);

void searchusia (namaKota P[],int nkota);

#endif