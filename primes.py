#!/usr/bin/python

# This script was coded to get my brain started on python mode to allow me to jump into
#  the big re-write of the video generation script in python

from sys import argv

if (len(argv) > 1) and argv[1] >= 2:
        tocheck = range(3,int(argv[1]),2)
        primes = [2]
        maxstore = int(float(argv[1])**.5+1);

	for number in tocheck:
		sqrt = number**.5;
		isprime = True
		for prime in primes:
			if prime > sqrt:
				break
			if ((number % prime) == 0):
				isprime = False
				break
		if (isprime == True):
			primes.append(number)
                        for loop in xrange(number,maxstore,number):
                                del tocheck[loop]
			print number;
	#print "You want primes? You got'em: " + str(primes)[1:-1]

else:
	print "You lose, you lose, you lose!"

