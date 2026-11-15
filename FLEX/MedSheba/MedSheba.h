#ifndef MEDSHEBA_H
#define MEDSHEBA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// রোগীর তথ্য সংরক্ষণের জন্য C Struct
typedef struct {
    char name[50];
    int age;
    char gender[20];
    double bp;
    double temp;
    double sugar;
    double oxygen;
    int heartRate;
    double weight;
    double height;
    char status[20];
    char priority[20];
    char medications[10][50];
    int medCount;
    char reports[10][100];
    int reportCount;
} Patient;

// ফাংশন ডিক্লোরেশন
void ShebaShuru();
void ShebaShesh();
void RogiNao(char* name);
void RogiDao(char* name);
void RoktoChap(char* n);
void TapmatraMapo(char* n);
void SugarMapo(char* n);
void OksijenMapo(char* n);
void NariDekho(char* n);
void OjonNao(char* n);
void UchotaNao(char* n);
void OushodhLekho(char* n, char* m);
void ReportJog(char* n, char* report);
void ReportDekho(char* n);
void BillBanano(char* n);
void TakaNao(double amount);
void CabinDao(char* n);
void AmbulanceDako();
void OperationShuru();
void OperationShesh();
void RogiBiday(char* n);
void Sotorko(char* msg);
void Dhiro(int sec);
void DatabaseSave();

#endif
