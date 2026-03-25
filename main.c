#include <stdio.h>
#include "functions.h"

int loopCount=0;

struct employees{
    int id;
    char name[20];
    int salaryBasic;
    float salaryGross;
};

int main(){

    int count,option,size=0;
    menu();
    while(option!=99){
        switch(option){
            case 1:
            printf("Enter Number Of Employees : ");
            scanf("%d",&count);
            if(count>0){
                size += count;
                struct employees EMP[size];
                addData(EMP,size);
            }else{
                printf("Invalid Input.\n\n");
                menu();
            }
            break;
            case 2:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Edit.\n\n");
                menu();
            }else{
                editRow(EMP);
            }
            break;
            case 3:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Delete.\n\n");
                menu();
            }else{
                deleteRaw(EMP);
            }
            break;
            case 4:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Preview.\n\n");
                menu();
            }else{
                previewChanges(EMP);
            }
            break;
            case 5:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Save.\n\n");
                menu();
            }else{
                saveChanges(EMP);
            }
            break;
            case 6:
            viewDataTable();
            break;
            case 7:
            editDataTable();
            break;
            case 8:
            printf("You Are Exited..\n");
            option = 99;
            break;
            default:
            printf("Invalid Input\n\n");
            menu();
        }
    }
    return 0;
}