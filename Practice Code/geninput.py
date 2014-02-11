import random
f = open('input1000000.txt', 'w+')
# print "Generating input..."
for i in xrange(0,1000000):
	f.write(str(random.randint(-100000000,100000000)))
	f.write("\n")
	# print "In the loop."

f.close()
