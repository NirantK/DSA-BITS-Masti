# import random
# f = open('drivers.txt', 'w')
# # print "Generating input..."
# for i in xrange(9):
# 	f.write(str(random.randint(999999,10000000)));
# 	f.write(',');
# 	f.write(str(random.randint(999999,10000000)));
# 	# f.write(str(i))
# 	f.write("\n")
# 	# print "In the loop."
# f.close()

import random
f = open('owners.txt', 'w')
# print "Generating input..."
for i in xrange(9):
	f.write(str(random.randint(999999,10000000)));
	f.write(',');
	f.write(str(random.randint(999,10000)));
	# f.write(str(i))
	f.write("\n")
	# print "In the loop."
f.close()