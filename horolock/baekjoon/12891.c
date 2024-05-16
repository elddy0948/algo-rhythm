#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int dna_length = 0, partial_length = 0, i = 0, lhs = 0, rhs = 0, answer = 0;
    char* dna = NULL;
    unsigned int minimum_counts[4];
    unsigned int current_counts[4] = {0, 0, 0, 0};

    scanf("%d %d", &dna_length, &partial_length);

    dna = (char*)malloc(sizeof(char) * dna_length);

    
    scanf("%s", dna);
    
    for(i = 0; i < 4; ++i)
    {
        scanf("%d", &minimum_counts[i]); 
    }

    lhs = 0;
    rhs = partial_length - 1;

    for(i = 0; i < partial_length; ++i)
    {
        if(dna[i] == 'A') { current_counts[0]++; }
        else if(dna[i] == 'C') { current_counts[1]++; }
        else if(dna[i] == 'G') { current_counts[2]++; }
        else if(dna[i] == 'T') { current_counts[3]++; }
    }

    while (rhs != dna_length)
    {
        if (current_counts[0] >= minimum_counts[0] && 
            current_counts[1] >= minimum_counts[1] &&
            current_counts[2] >= minimum_counts[2] &&
            current_counts[3] >= minimum_counts[3])
            {
                answer++;
            }
        
        if(dna[lhs] == 'A') { current_counts[0]--; }
        else if(dna[lhs] == 'C') { current_counts[1]--; }
        else if(dna[lhs] == 'G') { current_counts[2]--; }
        else if(dna[lhs] == 'T') { current_counts[3]--; }
        lhs++;

        rhs++;
        if (rhs == dna_length) { break; }
        if(dna[rhs] == 'A') { current_counts[0]++; }
        else if(dna[rhs] == 'C') { current_counts[1]++; }
        else if(dna[rhs] == 'G') { current_counts[2]++; }
        else if(dna[rhs] == 'T') { current_counts[3]++; }
    }

    printf("%d", answer);

    return 0;
}