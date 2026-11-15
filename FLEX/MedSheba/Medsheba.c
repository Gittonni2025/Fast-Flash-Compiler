#include "medsheba.h"

Patient currentPatient;
int patientExists = 0;

void ShebaShuru() {
    printf("\n=====================================\n");
    printf("     MedShebaLang Medical System (C)\n");
    printf("=====================================\n");
}

void ShebaShesh() {
    printf("\n[INFO] Session Ended Successfully.\n");
}

void RogiNao(char* name) {
    strcpy(currentPatient.name, name);

    printf("Enter Age: ");
    scanf("%d", &currentPatient.age);

    printf("Enter Gender: ");
    scanf("%s", currentPatient.gender);

    strcpy(currentPatient.priority, "NORMAL");
    strcpy(currentPatient.status, "STABLE");
    currentPatient.medCount = 0;
    currentPatient.reportCount = 0;

    patientExists = 1;
    printf("[REGISTRY] Patient Added Successfully.\n");
}

void RogiDao(char* name) {
    if(patientExists) {
        printf("\n========== PATIENT INFO ==========\n");
        printf("Name: %s\n", currentPatient.name);
        printf("Age: %d\n", currentPatient.age);
        printf("Gender: %s\n", currentPatient.gender);
        printf("BP: %.2f\n", currentPatient.bp);
        printf("Temp: %.2f\n", currentPatient.temp);
        printf("Sugar: %.2f\n", currentPatient.sugar);
        printf("Oxygen: %.2f\n", currentPatient.oxygen);
        printf("Heart Rate: %d\n", currentPatient.heartRate);
        printf("Priority: %s\n", currentPatient.priority);
        printf("Status: %s\n", currentPatient.status);
    } else {
        printf("No patient found!\n");
    }
}

void RoktoChap(char* n) {
    printf("Enter BP: ");
    scanf("%lf", &currentPatient.bp);
}

void TapmatraMapo(char* n) {
    printf("Enter Temperature: ");
    scanf("%lf", &currentPatient.temp);
}

void SugarMapo(char* n) {
    printf("Enter Sugar Level: ");
    scanf("%lf", &currentPatient.sugar);
}

void OksijenMapo(char* n) {
    printf("Enter Oxygen Level: ");
    scanf("%lf", &currentPatient.oxygen);
}

void NariDekho(char* n) {
    printf("Enter Heart Rate: ");
    scanf("%d", &currentPatient.heartRate);
}

void OushodhLekho(char* n, char* m) {
    if(currentPatient.medCount < 10) {
        strcpy(currentPatient.medications[currentPatient.medCount], m);
        currentPatient.medCount++;
        printf("[MEDICINE] Added: %s\n", m);
    }
}

void ReportJog(char* n, char* report) {
    if(currentPatient.reportCount < 10) {
        strcpy(currentPatient.reports[currentPatient.reportCount], report);
        currentPatient.reportCount++;
        printf("[REPORT] Added Successfully.\n");
    }
}

void ReportDekho(char* n) {
    printf("\n--- Reports for %s ---\n", currentPatient.name);
    for(int i = 0; i < currentPatient.reportCount; i++) {
        printf("- %s\n", currentPatient.reports[i]);
    }
}

void BillBanano(char* n) {
    printf("[BILL GENERATED] for %s\n", n);
}

void TakaNao(double amount) {
    printf("Received: %.2f BDT\n", amount);
}

void CabinDao(char* n) {
    printf("%s assigned to Cabin.\n", n);
}

void AmbulanceDako() {
    printf("[EMS] Ambulance Called.\n");
}

void RogiBiday(char* n) {
    strcpy(currentPatient.status, "DISCHARGED");
    printf("%s discharged.\n", n);
}

void OperationShuru() {
    printf("[OT] Operation Started.\n");
}

void OperationShesh() {
    printf("[OT] Operation Finished.\n");
}

void Sotorko(char* msg) {
    printf("!!! ALERT: %s !!!\n", msg);
}

void Dhiro(int sec) {
    clock_t start_time = clock();
    while (clock() < start_time + (sec * CLOCKS_PER_SEC));
}

void DatabaseSave() {
    printf("[DATABASE] Saved Successfully.\n");
}

int main() {
    srand(time(0));

    ShebaShuru();

    char patientName[50];
    printf("\nEnter Patient Name: ");
    scanf("%s", patientName);

    RogiNao(patientName);

    int choice;

    while(1) {
        printf("\n========== MENU ==========\n");
        printf("1. Input BP\n");
        printf("2. Input Temperature\n");
        printf("3. Input Sugar\n");
        printf("4. Input Oxygen\n");
        printf("5. Add Medicine\n");
        printf("6. Add Report\n");
        printf("7. Show Patient\n");
        printf("8. Show Reports\n");
        printf("9. Emergency Alert\n");
        printf("10. Call Ambulance\n");
        printf("11. Start Operation\n");
        printf("12. Discharge Patient\n");
        printf("13. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            RoktoChap(patientName);
        }
        else if(choice == 2) {
            TapmatraMapo(patientName);
        }
        else if(choice == 3) {
            SugarMapo(patientName);
        }
        else if(choice == 4) {
            OksijenMapo(patientName);
        }
        else if(choice == 5) {
            char med[50];
            printf("Medicine Name: ");
            scanf("%s", med);
            OushodhLekho(patientName, med);
        }
        else if(choice == 6) {
            char report[100];
            printf("Report: ");
            scanf("%s", report);
            ReportJog(patientName, report);
        }
        else if(choice == 7) {
            RogiDao(patientName);
        }
        else if(choice == 8) {
            ReportDekho(patientName);
        }
        else if(choice == 9) {
            Sotorko("Critical Condition");
        }
        else if(choice == 10) {
            AmbulanceDako();
        }
        else if(choice == 11) {
            OperationShuru();
            Dhiro(2);
            OperationShesh();
        }
        else if(choice == 12) {
            RogiBiday(patientName);
        }
        else if(choice == 13) {
            DatabaseSave();
            ShebaShesh();
            break;
        }
        else {
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}
