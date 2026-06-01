#include <stdio.h>
#define MONTHS 12 
#define MAXBRANCHES 100

int checkBranchInp(int* branchCount){
    char buff[100];
    fgets(buff,sizeof(buff),stdin);
    if (sscanf(buff,"%d",branchCount)!=1){
        return 0;
    }
    return 1;
}

int branchRange(int* branchStart,int* end,int* branchCount){
    char buff[100];
    fgets(buff,sizeof(buff),stdin);
    if(sscanf(buff,"%d",branchStart)!=1){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    *end=*branchStart+*branchCount-1;
    return 1;
}

int rangeValid(int* branchStart,int* branchCount,int* end, int branches){
    if (*branchCount<=0 || *end>branches|| *branchStart<=0){ 
        return 0;
        }
    return 1;
}

int checkInput(int *branchStart,int* branchCount, int* end,int branches){
    printf("Enter Number Of Branches To Process (1-%d):",branches);
    if(!checkBranchInp(branchCount)){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    printf("Enter Which Branch To Start From:");
    if(!branchRange(branchStart,end,branchCount)){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    if(!rangeValid(branchStart,branchCount,end,branches)){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    return 1;
}


void inputSales(double sales[][MONTHS],int branches){
    int branchCount,branchStart,end;
    if(!checkInput(&branchStart,&branchCount,&end,branches)){
        return;
    }
    for (int i=branchStart-1;i<end;i++){  
        for (int j=0;j<MONTHS;j++){
            printf("Enter Sales For Branch No. %d , Month No. %d:",i+1,j+1);
            scanf("%lf",&sales[i][j]);
            getchar();
        }
    }
}

void printSales(double sales[][MONTHS],int branches){
    int branchCount,branchStart,end;
    if(!checkInput(&branchStart,&branchCount,&end,branches)){
        return;
    }
    for(int i=branchStart-1;i<end;i++){
        for (int j=0;j<MONTHS;j++){
            printf("Branch No. %d Month %d : %.2f\n",i+1,j+1,sales[i][j]);
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
    int branchCount,branchStart,end;
    double percent;
    if(!checkInput(&branchStart,&branchCount,&end,branches)){
        return;
    }
    double companyTotal=totalSales(sales,branches);
    for (int i=branchStart-1;i<end;i++){

        double branchTotal=0;//* Reset For Each Branch

        for (int j=0;j<MONTHS;j++){
            //* Calculate Branch Total Sales First In Inner Loop Alone
            branchTotal+=sales[i][j];
        }
        percent=(branchTotal/companyTotal)*100.0;
        printf("Percentage Of Branch No.%d: %.2f%%\n",i+1,percent);
    }
}

int peakSales(double sales[][MONTHS],int branches){
    
    double max = -999999999;
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

void BranchesByMonth(double sales[][MONTHS],int branches){
    char new_month[50];
    int int_month,branchID[MAXBRANCHES];
    double sortedBranches[branches][MONTHS];

    //* Branch ID Initialization  
    for (int i=0;i<branches;i++)
        branchID[i]=i+1;

    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
        sortedBranches[i][j]=sales[i][j];
    }

    printf("Choose The Month You Want To Sort Each Branch By (1-12):");
    fgets(new_month,sizeof(new_month),stdin);
    if(sscanf(new_month,"%d",&int_month)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    if (int_month<1||int_month>MONTHS){
        printf("Invalid Input Try Again!\n");
        return;
    }
    for (int i=0;i<branches;i++){
        for(int j=0;j<branches-i-1;j++){
            if (sortedBranches[j][int_month-1]<sortedBranches[j+1][int_month-1]){

                double temp = sortedBranches[j][int_month-1];
                sortedBranches[j][int_month-1]=sortedBranches[j+1][int_month-1];
                sortedBranches[j+1][int_month-1]=temp;

                int tempid=branchID[j];
                branchID[j]=branchID[j+1];
                branchID[j+1]=tempid;
            }
        }
    }
    printf("The Sorted Branches For Month %d Are:\n",int_month);
    for (int i=0;i<branches;i++)
    printf("Branch No.%d: %.2f\n",branchID[i],sortedBranches[i][int_month-1]);
}

void MonthsByBranch(double sales[][MONTHS],int branches){
    char choice_chr[50];
    int branch_choice;
    double sortedMonths[branches][MONTHS];

    //? Copying Array Into Seperate Array So It Doesn't modify original 
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
        sortedMonths[i][j]=sales[i][j];
    }
    printf("Choose The Branch You Want To Sort Each Month(1-%d)",branches);
    fgets(choice_chr,sizeof(choice_chr),stdin);
    if (sscanf(choice_chr,"%d",&branch_choice)!=1){
        printf("Invalid Input Try Again\n");
        return;
    }
    if (branch_choice<1||branch_choice>branches){
        printf("Invalid Input Try Again\n");
        return;
    }
    for (int i=0;i<MONTHS;i++){
        for (int j=0;j<MONTHS-i-1;j++){
            if(sortedMonths[branch_choice-1][j]<sortedMonths[branch_choice-1][j+1]){
                double temp=sortedMonths[branch_choice-1][j];
                sortedMonths[branch_choice-1][j]=sortedMonths[branch_choice-1][j+1];
                sortedMonths[branch_choice-1][j+1]=temp;
            }
        }
    }
    printf("The Sorted Months Of Branch No.%d Are:\n",branch_choice);
    for (int i=0;i<MONTHS;i++)
    printf("Month No.%d: %.2f\n",i+1,sortedMonths[branch_choice-1][i]);
}

void savedata(double sales[][MONTHS],int branches){
    FILE *file=fopen("salesData.txt","w");

    if (file==NULL){
        printf("Error Opening File...\n");
        return;
    }

    fprintf(file,"%d\n",branches);
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
            fprintf(file,"%f ",sales[i][j]);

        fprintf(file,"\n");
    }
    fclose(file);
}
void loaddata(double sales[][MONTHS],int *branches){
    FILE*file=fopen("salesData.txt","r");
    if (file==NULL){
        printf("No Saved Data Found...\n");
        return;
    }
    fscanf(file,"%d",branches);
    for (int i=0;i<*branches;i++){
        for (int j=0;j<MONTHS;j++)
            fscanf(file,"%lf",&sales[i][j]);
    }
    fclose(file);
}

void resetdata(double sales[][MONTHS],int *branches){
    char resetChoice;
    printf("Are You Sure You Want To Reset All Data? This Action Is Irreversible(Y/n):");
    scanf(" %c",&resetChoice);
    getchar();
    if (resetChoice == 'N' || resetChoice == 'n')
    return;

    else if (resetChoice == 'Y' || resetChoice == 'y'){
    FILE *file=fopen("salesData.txt","w");
    if(file==NULL){
        printf("Error Resetting Data...\n");
        return;
    }
    fclose(file);
    for (int i=0;i<*branches;i++){
        for(int j=0;j<MONTHS;j++)
        sales[i][j]=0;
    }
    *branches=0;
    printf("Data Reset...\n");
    }
}

void checkNoBranch(int* branches){
    char branch_chrs[100];
    while (*branches<=0){
        printf("Enter The Number Of Branches(1-%d):", MAXBRANCHES);
        fgets(branch_chrs,sizeof(branch_chrs),stdin);

        if (sscanf(branch_chrs,"%d",branches)!=1)
            printf("Invalid Input Try Again\n");
        
        if (*branches<=0 || *branches>MAXBRANCHES){
            printf("Invalid Input Try Again\n");
            *branches=0;
        }
    }
}
void inputbranch(int* branches){
    *branches=0;
    checkNoBranch(branches);
}