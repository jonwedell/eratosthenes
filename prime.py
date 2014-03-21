#!/usr/bin/python

from sys import argv

prime = True
num = int(argv[1]);
maxcheck = int(num**.5)
this_num = 0;

for n in range(2,maxcheck):
	if n > maxcheck:
		break
        this_num = 0
	while (num % n == 0):
		prime = False
                this_num += 1
                num = num / n
                maxcheck = num**.5
        if (this_num):
                print "Divisor: " + str(n) + "^" + str(this_num)

if prime:
        print "Prime"
else:
        print "Divisor: " + str(num) + "^1"
