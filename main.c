#include <stdio.h>
#include "logic.h"

int main(){
    char choice[100];
    int branches=0,option;
    double sales[MAXBRANCHES][MONTHS]={0};
    loaddata(sales,&branches);
    checkNoBranch(&branches);

    while (1){
        printf("\n  = = = = = = = = = = = = = = = = = = = = = = RETAIL COMPANY DATABASE = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("  |     0.Exit                                                                             No. Of Branches:%d      |\n",branches);
        printf("  |            1.Input Sales Data.                                2.Show Sales Data.                              |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              3.Total Company Sales.                             4.Branch Percentages.                         |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              5.Peak Sales Month.                                6.Sort Each Branches By Month Sales.          |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              7.Sort Each Months By Branch Sales.                8.Change No. Of Branches.                     |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              9.Save Data.                                       10.Reset Data.                                |\n");
        printf("  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("  Enter Your Choice:");
        fgets(choice,sizeof(choice),stdin);
        if(sscanf(choice,"%d",&option)!=1){
            printf("Invalid Input Try Again\n");
            continue;
        }

        if (option == 0){
            char choice;
            printf("Are You Sure You Want To Exit?(Y/n)");
            scanf(" %c",&choice);
            getchar();
            if (choice == 'Y' || choice == 'y'){
                savedata(sales,branches);
                break;
            }
            else if (choice == 'N' || choice == 'n')
                continue;
            else 
                printf("Invalid Input...\n");
            
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
        
        else if (option == 8){
            inputbranch(&branches);
            savedata(sales,branches);
        }

        else if (option == 9)
            savedata(sales,branches);

        else if (option == 10){
            resetdata(sales,&branches);
            checkNoBranch(&branches);
        }

        else printf("Invalid Choice Try Again!\n");
    }
    return 0;
}