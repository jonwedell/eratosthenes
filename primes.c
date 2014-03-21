#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



/*
 * TODO:
 *  3) Multithread? That's cheating... :)
 * 
 * */

// Use a linked list to keep track of our seed primes
struct prime {
  unsigned long val;
  struct prime *next;
};

// Eponymous main method
int main(int argc, char *argv[]){

    // Set to 1 to print primes rather than count them
    int talk = 0;

    // Variables that we will use
    unsigned long biggest,numprimes,i,m,start,upto,tsqrt,seed_primes;
    struct prime *root,*current;

    // We want to avoid cache misses AT ALL COSTS!!!!1111
    unsigned long page_size = 65536*8;

    // Verify the user input and convert it to a long
    if ((argc < 2) || (!sscanf (argv[1],"%lu",&biggest)) || (biggest<2)){
        printf("You lose, you lose, you lose!\n");
        return 2;
    }

    if (argc == 3){
        if (!sscanf(argv[2],"%lu",&page_size)){
		printf("You lose, you lose, you lose!\n");
		return 2;
	}
    }

    // Because we search up to one less than the input
    biggest++;
    // Figure out how many primes we need to know and calculate them
    tsqrt = sqrt(biggest);
    // We need this max value to be even so that we can skip numbers /2
    if (tsqrt % 2 == 1){ tsqrt++; }
    
    // Start the linked list
    root = malloc( sizeof(struct prime) );  
    root->next = 0; root->val = 2;
    seed_primes = 1;
    current = root; 
    
    // We'll keep a char array of numbers that we are currently checking
    static char *tmpsearch = NULL;
    if (!tmpsearch) { tmpsearch = calloc(tsqrt, sizeof(char)); }
    
    // Go through the possible primes (no need to look at multiples of 2)...
	for(i=3;i<tsqrt;i=i+2){
        
        // Check if we already know if this number is not prime
        if (tmpsearch[i] == '\0'){
            // Add a new prime node at the end of the linked list
            current->next = malloc( sizeof(struct prime) );
            current = current->next; 
            current->val = i; current->next = 0;
            seed_primes++;
            // Remove all numbers divisble by the new prime from the search pool
            for (m=i;m<tsqrt;m = m + i){ tmpsearch[m] = '1'; }
        }
	}
    // Free our temporary prime-checking array
    free(tmpsearch);
    
    // Variables that we won't use... just kidding!
    numprimes = (biggest-tsqrt)/2 + seed_primes;
    
    // We'll keep a char array of numbers that we are currently checking
    static char *search = NULL;
    if (!search) { search = calloc(page_size, sizeof(char)); }
    
    // For each page
    for (i=tsqrt; i<biggest; i += page_size){
        // Reset the ram
        memset(search, '\0', page_size*(sizeof(char)));
        // Figure out the largest prime we need to check for this page
        tsqrt = sqrt(i+page_size);
        
        // And each prime
        current = root->next;
        while ( current != NULL ) {
            
            // Don't check primes greater than the sqrt
            if (current->val > tsqrt){break;}
            
            // Figure out what the maximum number we need to iterate to is
            upto = i+page_size; if (upto > biggest){ upto = biggest;}
            
            // Likewise, figure out the start value
            if ((i % current->val) == 0){
                start = current->val*(i/current->val);
            } else {
                start = current->val*(i/current->val) + current->val;
            }
            
            // Mark out the numbers
            for (m=start; m < upto; m += current->val){
                // Way quicker to make sure we aren't messing with
                // the memory at all if it's divisble by 2
                if (m % 2 != 0){
                    if (search[m-i] == '\0'){
                        search[m-i] = '1';
                        numprimes--;
                    }
                }
            }
            
            // Move on to the next prime
            current = current->next;
        }
        
        // Actually print the primes if requested
        if (talk){
            for (m=i; m<i+page_size; m++){
                if (m>=biggest){break;}
                if (search[m-i] == '\0'){
                    printf("%lu\n",m);
                }
            }
        }
    }
    
    // If they don't want to know the actual primes, they probably
    //  want to know how many there are.
    if (!talk){ printf("%lu primes found.\n",numprimes);}
    free(search);
    // If we were to go on to do other things, we would probably want
    // to free the nodes of the linked list that we allocated
    return 0;
}
