#include <stdio.h>
#include <stdlib.h>

// Eponymous main method
int main(int argc, char *argv[]){
	
    // Variables that we will use
    unsigned long biggest,numprimes,i,m;
    
    // Variables that we won't use... just kidding!
    numprimes = 1; // Don't forget #2!
    
    // Verify the user input and convert it to a long
    if ((argc != 2) || (!sscanf (argv[1],"%lu",&biggest)) || (biggest < 2)){
        printf("You lose, you lose, you lose!\n");
        return 2;
    }
    
    //printf("2\n");
    
    // We'll keep a char array of numbers that are worth checking
    // and as a bonus use null as "could be prime" so we don't have
    // to actually initialize the array
    static char *search = NULL;
    if (!search) { search = calloc(biggest, sizeof(char)); }
    
	// Go through the possible primes (no need to look at multiples of 2)...
	for(i=3;i<biggest;i=i+2){
        
        // Check if we already know if this number is not prime
        if (search[i] == '\0'){ 
            // Either count the number or print it
            numprimes++; //printf("%lu\n",i);

            // Remove all numbers divisble by the new prime from the search pool
            for (m=i;m<biggest;m = m + i){ search[m] = '1'; }
        }
	}

    printf("%lu primes found.\n",numprimes);
    free(search);

	return 0;
}
