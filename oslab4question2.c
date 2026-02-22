//   This question is for increasing compilation time by 2 .

#include <stdio.h>


int main() {
    int n = 5;

    int AT[5] = {0, 1, 2, 3, 4};
    int BT[5] = {8, 7, 6, 2, 4};

    int CT[5], TAT[5], WT[5];

    // First process
    CT[0] = AT[0] + BT[0];

    // Remaining processes
    for(int i = 1; i < n; i++) {
        if(CT[i-1] < AT[i])
            CT[i] = AT[i] + BT[i];
        else
            CT[i] = CT[i-1] + BT[i];
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    float avgTAT = 0, avgWT = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        avgTAT += TAT[i];
        avgWT += WT[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    avgTAT /= n;
    avgWT /= n;

    printf("\nAverage Turnaround Time = %.2f", avgTAT);
    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    return 0;
}

