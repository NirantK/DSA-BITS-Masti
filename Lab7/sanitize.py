import string
put = open('clean.txt','w')
with open('input.txt') as f:
    for line in f:
        for ch in line: 
            if ch.isalpha() or ch==' ' or ch=='\n': 
            	if ch=='\n':
            		put.write(' ')
            	else:
		            put.write(ch.lower())