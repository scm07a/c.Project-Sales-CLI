#ifndef LOGIC_H
#define LOGIC_H
#define MONTHS 12 

int exit_menu();
void inputSales(double sales[][MONTHS],int branches);
void printSales(double sales[][MONTHS],int branches);
double totalSales(double sales[][MONTHS],int branches);
void percentageSales(double sales[][MONTHS], int branches);
int peakSales(double sales[][MONTHS],int branches);



#endif