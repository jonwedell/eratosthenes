#!/usr/bin/python

# This script was coded to get my brain started on python mode to allow me to jump into
#  the big re-write of the video generation script in python

from sys import argv

primes = [2]

if (len(argv) > 1) and argv[1] >= 2:
	ray = xrange(3,int(argv[1])+1,2)
	for number in ray:
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
			print number;
	#print "You want primes? You got'em: " + str(primes)[1:-1]

else:
	print "You lose, you lose, you lose!"

