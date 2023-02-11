/*
 *  Program2.c
 *
 *  Created on: 10 Feb 2023
 *  Author: Micah Borghese
 *  Description: Finds all possible combinations of football score plays with a given total score.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void score_combinations(int *score) {
    int touchdown = 6;  // initialisations for the value of scores
    int field_goal = 3;
    int safety = 2;
    int extra_point = 7;
    int two_point_conversion = 8;

    int td = 0;  // initialisations of score quantities for each individual combination
    int fg = 0;
    int saf = 0;
    int xp = 0;
    int two_pt = 0;

    // this is a non-recursive solution to finding all possible combinations
    for (int i = 0; i <= *score; i++) {  // td
        for (int j = 0; j <= *score; j++) {  // fg
            for (int k = 0; k <= *score; k++) {  // saf
                for (int l = 0; l <= *score; l++) {  // td + fg
                    for (int m = 0; m <= *score; m++) {  // td + 2pt
                        if (i * touchdown + j * field_goal + k * safety + l * extra_point + m * two_point_conversion == *score) {  // see if combination is equal to given score
                            printf("%d TD, %d 3PT FG, %d Safety, %d TD + FG, %d TD + 2PT\n", i, j, k, l, m);
    
                            td += i;  // increase the quantities since this combination works
                            fg += j;
                            saf += k;
                            xp += l;
                            two_pt += m;
                        }
                    }
                }
            }
        }
    }
}

int main() {

    int nfl_score;

    while(1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL Score: ");
        scanf("%d", &nfl_score);

        if (nfl_score == 0 || nfl_score == 1) {  // check if entry is 0 or 1
        	break;  // stop program
        }

        printf("Possible Combinations of Scoring Plays:\n");
        score_combinations(&nfl_score);
    }

    return 0;
}
