#include <stdio.h>
#include <windows.h>
#include "logic.h"
//todo Bubble sort for 6 and algorithm sort for 7


int main(){
    SetConsoleOutputCP(CP_UTF8);
    int branches,option;
    char choice[100];

    printf("Enter The Number Of Branches:");
    scanf("%d",&branches);//* Used For Loop Through Input and Output Of Array "sales[][]"
    getchar();
    if (branches<=0){
        printf("Invalid Input Exiting Program...\n");
        return 0;
    }
    double sales[branches][MONTHS];

    while (1){
        printf("\n  - - - - - - - - - - - - - - - - - - - - - - -RETAIL COMPANY DATABASE- - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("  ❘                                             No. Of Branches:%d                                                  ❘\n",branches);
        printf("  ❘              0.Exit                                             1.Input Sales Data.                            ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              2.Show Sales Data.                                 3.Total Company Sales.                         ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              4.Branch Percentages.                              5.Peak Sales Month.                            ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              6.Sort Each Branch By Month Sales.                 7.Sort Each Month By Branch Sales.             ❘\n");
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("  Enter Your Choice:");
        fgets(choice,sizeof(choice),stdin);
        sscanf(choice,"%d",&option);

        if (option == 0){
            if(exit_menu())
            break;
        continue;
        }

        else if (option == 1){
            inputSales(sales,branches);
        }

        else if (option == 2){
            printSales(sales,branches);
        }

        else if (option == 3){
            printf("Total Company Sales: $%.2f\n",totalSales(sales,branches));
        }
        
        else if (option == 4){
            continue;
        }
        
        else if (option == 5){
            continue;
        }
        
        else if (option == 6){
            continue;
        }
        
        else if (option == 7){
            continue;
        }

        else printf("Invalid Choice Try Again!\n");
    }
    return 0;
}