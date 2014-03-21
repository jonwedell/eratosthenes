#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Eponymous main method
int main(int argc, char *argv[]){
	
    // Variables that we will use
    unsigned long long biggest,tsqrt,i;
    int prime = 1;
    int this_num = 0;
    
    // Verify the user input and convert it to a long
    if ((argc != 2) || (!sscanf (argv[1],"%llu",&biggest)) || (biggest < 2)){
        printf("You lose, you lose, you lose!\n");
        return 2;
    }
    tsqrt = sqrt(biggest);

	// Go through the possible primes (no need to look at multiples of 2)...
	for(i=2;i<tsqrt;i++){
        this_num = 0;
        while (biggest % i == 0){
            this_num++;
            biggest = biggest / i;
            tsqrt = sqrt(biggest);
            prime = 0;
        }
        if (this_num){
             printf("Divisor: %llu^%d\n",i,this_num);
        }
	}
    
    if (prime){
        printf("Prime\n");
    } else {
        printf("Divisor: %llu^1\n",biggest);
    }

	return 0;
}
