primes: prime.c primes.c
	gcc -o prime prime.c -O3 -std=gnu99 -lm
	gcc -o primes primes.c -O3 -std=gnu99 -lm

clean:
	rm prime primes
