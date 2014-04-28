import random
x = open("input3.txt","w+");

for i in xrange(100000):
	x.write(str(random.randint(0,10000)));
	x.write('\n')