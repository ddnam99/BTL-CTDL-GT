import os
while os.path.isfile('Temp.txt')==False: pass
file = open('Temp.txt', 'r', encoding='utf-8')
S1=''
S2=[]
for i in file:
    if S1=='':
    	S1=i
    else:
    	S2+=i.capitalize()
file.close()
s1=''
s2=''
for i in S1:
    if i.isalpha() or i==' ':
        s1+=i
for i in ''.join(S2):
    if i.isnumeric()==False:
        s2+=i
file = open('Finally.txt', 'w', encoding='utf-8')
file.writelines(s1.capitalize()+'\n')
file.writelines(s2)
file.close()
#os.remove('Temp.txt')