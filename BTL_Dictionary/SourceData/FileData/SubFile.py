k=0
file = open('Root\\Finally.txt', 'r', encoding='utf-8')
size=int(file.readline())
count=0
while 1:
	start=int(size*k/40)
	end=int(size*(k+1)/40)
	if start>=size:break
	if end>size: end=size
	print(start,end)
	file1 = open('DictEV'+str(k+1)+'.txt', 'w', encoding='utf-8')
	file1.writelines(str(end-start)+'\n')
	if k==0:
		count=0
	else:
		count=1
		file1.writelines('----\n')
	while 1:
		temp=file.readline()
		if temp=='----\n': count+=1
		if count>end-start: break
		file1.writelines(temp)
	file1.close()
	k+=1
file.close()
