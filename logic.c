#include <stdio.h>
#define MONTHS 12 

int exit_menu(){
    char choice;
    printf("Are You Sure You Want To Exit?(Y/n)");
    scanf(" %c",&choice);
    getchar();
    if (choice =='Y' || choice == 'y')
    return 1;
    return 0;
}

void inputSales(double sales[][MONTHS],int branches){
    char branchNo_str[100];
    int branchNo,branchstart;  
    printf("How Many Of Your Branches Do You Want To Input Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchNo)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchstart)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }
    int end=branchstart+branchNo-1;
    
    if (branchNo<=0 || end>branches|| branchstart<=0){ 
            printf("Invalid Input Try Again!\n");
            return;
        }
    for (int i=branchstart-1;i<end;i++){  
        for (int j=0;j<MONTHS;j++){
            printf("Enter Sales For Branch No. %d , Month No. %d:",i+1,j+1);
            scanf("%lf",&sales[i][j]);
        }
    }
    getchar();
}

void printSales(double sales[][MONTHS],int branches){
    char branchNo_str[100];
    int branchNo,branchstart;

    printf("Enter How Many Of Your Branches Do You Want To Print The Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchNo)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }


    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchstart)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    int end=branchstart+branchNo-1;
        if (branchNo<=0||end>branches|| branchstart<=0){ 
        printf("Invalid Input Try Again!\n");
        return;
    }
    for(int i=branchstart-1;i<end;i++){
        for (int j=0;j<MONTHS;j++){
            printf("Branch No. %d Month %d : %f\n",i+1,j+1,sales[i][j]);
        }
    }
}

double totalSales(double sales[][MONTHS],int branches){
    double sum=0;
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++){
            sum+=sales[i][j];
        }
    }
    return sum;
}

void percentageSales(double sales[][MONTHS], int branches){
    char branchNo_str[100];
    int branchNo,branchstart;
    double percent;

    printf("Enter How Many Of Your Branches Do You Want To Print The Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchNo)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchstart)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    int end=branchstart+branchNo-1;
        if (branchNo<=0||end>branches|| branchstart<=0){ 
        printf("Invalid Input Try Again!\n");
        return;
    }
    double companyTotal=totalSales(sales,branches);
    for (int i=branchstart-1;i<end;i++){

        double branchTotal=0;//* Reset For Each Branch

        for (int j=0;j<MONTHS;j++){
            //* Calculate Branch Total Sales First In Inner Loop Alone
            branchTotal+=sales[i][j];
        }
        percent=(branchTotal/companyTotal)*100.0;
        printf("Percentage Of Branch No.%d: %.2f%\n",i+1,percent);
    }
}

int peakSales(double sales[][MONTHS],int branches){
    
    float max = -999999999.f;
    int peakMonth=0;
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++){
            double peak=sales[i][j];
            if (peak > max)
            {
                max = peak;
                peakMonth=j;
            }
        }

    }
    return peakMonth+1;
}