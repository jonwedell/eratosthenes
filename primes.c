#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	
        long biggest,psqrt,i,n,numprimes;
        sscanf (argv[1],"%lu",&biggest);
    
        static long *primes = NULL;

        if (!primes) {
                // allocate the buffer on the first use
                primes = calloc(biggest/5, sizeof(long));
        }
    
	primes[0] = 2;
	long where = 1;
	long prime = 0;
        numprimes = 1;
        
	// Initialize the primes array
	for(i=3;i<biggest+1;i=i+2){
		prime = 1;
		psqrt = sqrt(i) + 1;
		
		for (n=0;n<biggest/5;n++){
			if (primes[n] > psqrt){ break; }
			if (primes[n] == 0){ break; }
			if (i % primes[n] == 0){
				prime = 0;
				break;
			}
		}
		if (prime){
			primes[where] = i;
			where++;
			numprimes++;
		}
		
	}
        
        printf("%lu primes found.\n",numprimes);
        
	free(primes);

	return 0;
}
