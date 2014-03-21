#!/usr/bin/python

# This script was coded to get my brain started on python mode to allow me to jump into
#  the big re-write of the video generation script in python

from sys import argv

if (len(argv) > 1) and argv[1] >= 2:
        biggest = int(argv[1]);
        tocheck = range(0,biggest,1)
        numprimes = 1;

	for number in xrange(3,biggest,2):
                if (tocheck[number] != 0):
                        numprimes += 1
                        for loop in xrange(number,biggest,number):
                                tocheck[loop] = 0
        
        print str(numprimes) + " primes found."

else:
	print "You lose, you lose, you lose!"

