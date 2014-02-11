import random
f = open('input1.txt', 'w')
# print "Generating input..."
for i in xrange(99,50000,9):
	# f.write(str(random.randint(-100000000,100000000)))
	f.write(str(i))
	f.write("\n")
	# print "In the loop."

f.close()
