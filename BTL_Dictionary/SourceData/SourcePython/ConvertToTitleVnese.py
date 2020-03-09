import os
#import time
#cl=time.time()
while os.path.isfile('Temp.txt')==False: pass
file = open('Temp.txt', 'r', encoding='utf-8')
S2=[]
for i in file:
    temp=''
    for j in i:
        if j.isnumeric()==False:
            temp+=j
    S2.append(temp.lstrip(chr(65279)).capitalize())
file.close()
file = open('Finally.txt', 'w', encoding='utf-8')
file.writelines(''.join(S2))
file.close()
#print(round(time.time()-cl,4),'s',sep='')
#os.remove('Temp.txt')
