#include <stdio.h>
#include <windows.h>
#include "logic.h"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    char choice[100],branch_chrs[100];
    int branches=0,option;
    double sales[MAXBRANCHES][MONTHS];
    loaddata(sales,branches);
    
    if (branches<=0){
        printf("Enter The Number Of Branches:");
        fgets(branch_chrs,sizeof(branch_chrs),stdin);
        if (sscanf(branch_chrs,"%d",&branches)!=1){
            printf("Invalid Input... Exiting Program\n");
            return 0;
        }
        if (branches<=0){
            printf("Invalid Input... Exiting Program\n");
            return 0;
        }
    }
    
    while (1){
        printf("\n  - - - - - - - - - - - - - - - - - - - - - - -RETAIL COMPANY DATABASE- - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("  ❘                                             No. Of Branches:%d                                                  ❘\n",branches);
        printf("  ❘              0.Exit                                             1.Input Sales Data.                            ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              2.Show Sales Data.                                 3.Total Company Sales.                         ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              4.Branch Percentages.                              5.Peak Sales Month.                            ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              6.Sort Each Branches By Month Sales.               7.Sort Each Months By Branch Sales.            ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘                                                  8.Save Data                                                   ❘\n");
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("  Enter Your Choice:");
        fgets(choice,sizeof(choice),stdin);
        if(sscanf(choice,"%d",&option)!=1){
            printf("Invalid Input Try Again\n");
            continue;
        }

        if (option == 0){
            if(exit_menu()){
                savedata(sales,branches);
                break;
            }
        }

        else if (option == 1){
            inputSales(sales,branches);
            savedata(sales,branches);
        }

        else if (option == 2)
            printSales(sales,branches);

        else if (option == 3)
            printf("Total Company Sales: $%.2f\n",totalSales(sales,branches));

        else if (option == 4)
            percentageSales(sales,branches);

        else if (option == 5)
            printf("Month No.%d Has The Peak Sales.\n",peakSales(sales,branches));

        else if (option == 6)
            BranchesByMonth(sales,branches);

        else if (option == 7)
            MonthsByBranch(sales,branches);
        
        else if (option==8)
            savedata(sales,branches);

        else printf("Invalid Choice Try Again!\n");
    }
    return 0;
}