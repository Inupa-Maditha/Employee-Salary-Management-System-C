#include <stdio.h>
#include <string.h>
#include "functions.h"

#define TABLE_WIDTH 69

void addData(struct employees EMP[],int count){

    printf("Enter Employee ID, Employee Name, Basic Salary :\n");
    for(int i=0; i<count; i++){
        printf("%02d : ",loopCount+1);
        getEmployeeDetails(EMP,loopCount);
        loopCount++;
    }
    printf("\n");
}

void editRow(struct employees EMP[]){

    int num;
    previewChanges(EMP);
    printf("Enter Row Number You Want Edit : ");
    scanf("%d",&num);
    if(num>0 && (num-1)<loopCount){
        printf("Enter Employee ID, Employee Name, Basic Salary : ");
        getEmployeeDetails(EMP,num-1);
    }else{
        printf("Invalid input\n\n");
    }
}

void deleteRaw(struct employees EMP[]){

    int num;
    previewChanges(EMP);
    printf("Enter Row Number You Want Delete : ");
    scanf("%d",&num);
    if(num>0 && (num-1)<loopCount){
        for(int i=num-1;i<loopCount;i++){
            EMP[i].id = EMP[i+1].id;
            strcpy(EMP[i].name,EMP[i+1].name);
            EMP[i].salaryBasic = EMP[i+1].salaryBasic;
            EMP[i].salaryGross = EMP[i+1].salaryGross;
        }
        EMP[loopCount].id = 0;
        EMP[loopCount].name[0] = '\0';
        EMP[loopCount].salaryBasic = 0;
        EMP[loopCount].salaryGross = 0.0;
        loopCount--; 
    }else{
        printf("Invalid input\n\n");
    }
}

void previewChanges(struct employees EMP[]){
    for(int i=0;i<TABLE_WIDTH;i++){
        printf("-");
    }
    printf("\n| %3s| %-5s| %-20s| %-15s| %-15s|\n","NO:","ID","Employee Name","Basic Salary","Gross Salary");
    for(int i=0;i<TABLE_WIDTH;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<loopCount;i++){
        printf("| %02d | %-5d| %-20s| %-15d| %-15.2f|\n",i+1,EMP[i].id,EMP[i].name,EMP[i].salaryBasic,EMP[i].salaryGross);
    }
    for(int i=0;i<TABLE_WIDTH;i++){
        printf("-");
    }
    printf("\n");
}

void saveChanges(struct employees EMP[]){

    FILE *fp;
    fp = fopen("dataSheet.txt","a");
    for(int i=0;i<loopCount;i++){
        fprintf(fp,"%-15s : %-5d\n%-15s : %-20s\n%-15s : %-15d\n%-15s : %-15.2f\n\n","Employee ID",EMP[i].id,"Employee Name",EMP[i].name,"Basic Salary",EMP[i].salaryBasic,"Gross Salary",EMP[i].salaryGross);
    }
    fclose(fp);
    loopCount = 0;
    size = 0;
    printf("Your changes saved..\n");
}

void viewDataTable(){
}

void editDataTable(){
}

void menu(){
    printf("\n(01) %-15s : 1\n(02) %-15s : 2\n(03) %-15s : 3\n(04) %-15s : 4\n(05) %-15s : 5\n(06) %-15s : 6\n(07) %-15s : 7\n(08) %-15s : 8\n\nEnter Your Option : ","Add Data","Edit Raw","Delete Raw","Preview Changes","Save Changes","View Data Table","Edit Data Table","Exit");
    scanf("%d",&option);
    printf("\n");
}

void getEmployeeDetails(struct employees EMP[],int num){

    scanf("%3d %19s %d",&EMP[num].id, EMP[num].name,&EMP[num].salaryBasic);
    EMP[num].salaryBasic=(EMP[num].salaryBasic<0)?0:EMP[num].salaryBasic;
    EMP[num].salaryGross = calculateSalaryGross(EMP[num].salaryBasic);
}

float calculateSalaryGross(int basicSalary){
    
    float grossSalary,transportAllowance = (float)basicSalary*10/100, attendanceAllowance = (basicSalary>35000)? (float)basicSalary*5/100:(float)basicSalary*8/100;
    grossSalary = transportAllowance + attendanceAllowance + basicSalary;
    return grossSalary;
}