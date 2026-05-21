#ifndef LOGIC_H
#define LOGIC_H
#define MONTHS 12 
#define MAXBRANCHES 100

int exit_menu();
void inputSales(double sales[][MONTHS],int branches);
void printSales(double sales[][MONTHS],int branches);
double totalSales(double sales[][MONTHS],int branches);
void percentageSales(double sales[][MONTHS], int branches);
int peakSales(double sales[][MONTHS],int branches);
void BranchesByMonth(double sales[][MONTHS],int branches);
void MonthsByBranch(double sales[][MONTHS],int branches);
void savedata(double sales[][MONTHS],int branches);
void loaddata(double sales[][MONTHS],int* branches);
void resetdata(double sales[][MONTHS],int* branches);
void checkNoBranch(int* branches);
void inputbranch(int* branches);
#endif