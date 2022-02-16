#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    printf("Enter the number of boxes: \n");
    scanf("%d", &n);

    int boxes[n];

    printf("For each box, enter 1 if it has a ball, 0 otherwise: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &boxes[i]);
    }

    int operations[n];
    int numOfOperation = 0;

    for(i = 0; i < n; i++) {

        for(j = 0; j < n; j++) {

            if(boxes[j] == 1) {
                numOfOperation += abs(i - j);
            }
        }

        operations[i] = numOfOperation;
        numOfOperation = 0;
    }

    printf("Operations needed for each box:");

    for(i = 0; i < n; i++) {

        printf("\nBox %d is: %d", i+1, operations[i] );
    }

    return 0;
}

//
// Created by orcun on 16.02.2022.
//

