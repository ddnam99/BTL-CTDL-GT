import os
while os.path.isfile('Temp.txt')==False or os.path.isfile('Finally.txt')==False: pass
os.remove('Temp.txt')
os.remove('Finally.txt')