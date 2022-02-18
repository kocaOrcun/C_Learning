#include <stdio.h>
#include <string.h>

int anagramFunc(char string1[], char string2[]){
    char temp;
    int i, j;
    int n  = strlen(string1);
    int n1 = strlen(string2);
    char st1[20],st2[20];
    strcpy(st1,string1);
    strcpy(st2,string2);
    // If both strings are of different length, then they are not anagrams

    if( n!= n1) {

        return 0;

    }

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (st1[i] > st1[j]) {
                temp = st1[i];
                st1[i] = st1[j];
                st1[j] = temp;
            }
            if (st2[i] > st2[j]) {
                temp = st2[i];
                st2[i] = st2[j];
                st2[j] = temp;
            }
        }
    }
    // Compare both strings character by character

    for(i = 0; i<n; i++) {
        if(st1[i] != st2[i]) {

            return 0;

        }
    }
    return 1;

}

void alphabeticalFunc(char strx[], char stry[] ){
    if(strcmp(strx,stry)<0){
        strcat(strx," ");
        strcat(strx,stry);
        printf("Alphabetical order of two strings:");
        puts(strx);
    }
    else if(strcmp(strx,stry)>0){
        strcat(stry," ");
        strcat(stry,strx);
        printf("Alphabetical order of two strings:");
        puts(stry);
    }
    else{
        strcat(strx," ");
        strcat(strx,stry);
        printf("Alphabetical order of two strings:");
        puts(strx);
    }

}


int main () {
    char str1[30], str2[30],choice[5]="yes";

    while(strcmp(choice,"yes") == 0){
        printf("Enter a firts string:");
        gets(str1);
        printf("Enter a second string:");
        gets(str2);
        if (anagramFunc(str1,str2)){
            printf("%s and %s are anagrams! \n", str1, str2);
            alphabeticalFunc(str1,str2);
        }
        else
            printf("%s and %s are not anagrams! \n", str1, str2);

        printf("Do you want to continue?");
        gets(choice);

        while(strcmp(choice,"yes") != 0 && strcmp(choice,"exit") != 0) {
            printf("Wrong input type again yes/exit:");
            gets(choice);
        }
    }

    return 0;
}



//
// Created by orcun on 16.02.2022.
//

