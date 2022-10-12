#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    typedef struct{
        char* name;
    } Biba_Boba;
    
    int num=2, i;
    Biba_Boba* data = malloc(num * sizeof *data);
    for (i = 0; i < num; i++){
        data[i].name=(char*)malloc(sizeof(char)*8);
        printf("Enter name: ");
        scanf("%s", data[i].name);
    }
    for ( i = 0; i < num; i++){
        printf("Name: %s\n", data[i].name);
    }
    return 0;
}
        
        
