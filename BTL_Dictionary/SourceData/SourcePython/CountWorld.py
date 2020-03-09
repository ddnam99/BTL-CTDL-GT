import os
k=0
x=0
while 1:
	file = open('DictEV1.txt', 'r', encoding='utf-8')
	file1 = open('EV.txt', 'w', encoding='utf-8')
	count=0
	for i in file:
		if i=='----\n':
			count+=1
	file1.writelines(str(count)+'\n')
	file.close()
	file = open('DictEV1.txt', 'r', encoding='utf-8')
	for i in file:
		file1.writelines(i)
	file.close()
	file1.close()
	#os.remove('File\\EV'+s+'.txt')
	break
