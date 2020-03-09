import os
file = open('TempRoot.txt', 'r', encoding='utf-8')
file1 = open('Temp.txt', 'w', encoding='utf-8')
test=False
count=0
for i in file:
	if i[0]=='@':
		i=i[1:]
		temp=i.split()
		s=''
		s1=''
		k=True
		for j in temp:
			if j[0]=='/':
				s1=j+' '
				k=False
			else:
				if k:
					s+=j+' '
				else:
					s1+=j+' '
					if j.endswith('/'):
						break
		s=s.strip()
		if s.count('-')==0 and s.count(' ')==0 and s.count('.')==0:
			test=True
			count+=1
			file1.writelines('----\n'+s.capitalize()+'\n')
			file1.writelines('Phiên âm: '+s1+'\n'+'Ý nghĩa:\n')
		else:
			test=False
	else: 
		if i!='' and test:
			file1.writelines(i)
file.close()
file1.close()

file = open('Temp.txt', 'r', encoding='utf-8')
file1 = open('Finally.txt', 'w', encoding='utf-8')
file1.writelines(str(count)+'\n')
for i in file:
	file1.writelines(i)
file.close()
file1.close()
os.remove('Temp.txt')
