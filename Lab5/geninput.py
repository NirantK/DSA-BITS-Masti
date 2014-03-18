import random
driver = open('Xdrivers.txt', 'w')
owner = open('Xowners.txt', 'w')
offense = open('Xoffenses.txt', 'w')
# print "Generating input..."
for i in xrange(10):
	uid = str(random.randint(999999,10000000));
	license = str(random.randint(999999,10000000));
	vehicleno = str(random.randint(999, 10000));
	penalty = str(random.randint(0,8));
	driver.write(uid+','+license+'\n');
	# driver.write(str(random.randint(999999,10000000))+','+str(random.randint(999999,10000000))+'\n');
	owner.write(uid+','+vehicleno+'\n');
	offense.write(license+','+penalty+'\n');
	offense.write(license+','+str(random.randint(0,8))+'\n');
	# f.write(str(random.randint(999999,10000000)));
	# f.write(str(i))
	# print "In the loop."

# import random
# f = open('owners.txt', 'w')
# # print "Generating input..."
# for i in xrange(9):
# 	f.write(str(random.randint(999999,10000000)));
# 	f.write(',');
# 	f.write(str(random.randint(999,10000)));
# 	# f.write(str(i))
# 	f.write("\n")
# 	# print "In the loop."
# f.close()