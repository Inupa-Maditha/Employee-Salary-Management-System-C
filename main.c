#include <stdio.h>
#include "functions.h"

#define EXIT_CODE 19091

int loopCount=0,size=0,option=0;

int main(){
    int count;
    struct employees EMP[100];
    menu();
    while(option!=19091||option==0){
        switch(option){
            case 1:
            printf("Enter Number Of Employees : ");
            scanf("%d",&count);
            if(size+count>100){
                printf("Limit Exceeded. Max = 100.\n\n");
            }else{
                size += count;
                printf("\n");
                addData(EMP,count);
            }
            break;
            case 2:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Edit.\n\n");
            }else{
                editRow(EMP);
            }
            break;
            case 3:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Delete.\n\n");
            }else{
                deleteRaw(EMP);
            }
            break;
            case 4:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Preview.\n\n");
            }else{
                previewChanges(EMP);
            }
            break;
            case 5:
            if(size == 0){
                printf("You have Not Any Unsaved Data To Save.\n\n");
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
            if(loopCount != 0 && size != 0){
                char answer[4];
                printf("Your Changes Have Not Been Saved.\nDo you want to Exit without saving changes? ('yes' / 'no') : ");
                scanf("%s", answer);
                (answer[0]=='y')?option = EXIT_CODE:(answer[0]=='n')?saveChanges(EMP):printf("Invalid Input\n");
            }else{
                option = EXIT_CODE;
            }
            break;
            default:
            printf("Invalid Input\n\n");
        }
        (option!=19091)?menu():printf("You Have Successfully Exited...\n");
    }
    return 0;
}