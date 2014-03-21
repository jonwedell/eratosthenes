#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Eponymous main method
int main(int argc, char *argv[]){
	
    // Variables that we will use
    unsigned long biggest,psqrt,where,prime,numprimes,i,n,m;
    
    // Variables that we won't use... just kidding!
    where = 1;
	prime = 0;
    numprimes = 1; // Don't forget #2!
    
    // Verify the user input and convert it to a long
    if ((argc != 2) || (!sscanf (argv[1],"%lu",&biggest))){
        printf("You lose, you lose, you lose!\n");
        return 2;
    }
    
    // We only need to store the primes up to sqrt(largest number to check) so long as we print each prime as we find them
    unsigned long bigdiv = sqrt(biggest)+1;
    static unsigned long *primes = NULL;
    if (!primes) { primes = calloc(bigdiv/2, sizeof(long)); }
    
    // We'll keep a char array of numbers that are worth checking
    // As a minor optimization we won't bother checking numbers divisible by 2...
    static char *search = NULL;
    if (!search) { search = calloc(biggest+1, sizeof(char)); }
    for (i=1;i<biggest;i+=2){ search[i] = '1'; }
    
	// Go through the possible primes...
	for(i=3;i<biggest+1;i=i+2){
        
        // Check if we already know if this number is not prime
        if (search[i] == '1'){ 
            prime = 1;
            psqrt = sqrt(i);
            
            // Try dividing the number by all of our known primes
            for (n=0;n<where;n++){
                if ((primes[n] == 0) || (primes[n] > psqrt)){ break; }
                if (i % primes[n] == 0){
                    prime = 0;
                    break;
                }
            }
            
            // If the number is prime...
            if (prime){
                // Print the number
                //printf("%lu\n",i);
                numprimes++;
                // Store the number in our array of primes
                if (where<=bigdiv){
                    primes[where] = i;
                    where++;
                }

                // Remove all numbers divisble by the new prime from the search pool
                for (m=i;m<=(biggest);m = m + i){
                    search[m] = '0';
                }
            }
        }
	}

    printf("%lu primes found.\n",numprimes);

	//free(primes);
    //free(search);

	return 0;
}
