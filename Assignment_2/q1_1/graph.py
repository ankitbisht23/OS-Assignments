import matplotlib.pyplot as plt
import numpy as np;


other = [9,9,9,8,8]
rr = [9,9,8,9,8]
fifo = [19,19,18,17,17]

fig = plt.subplots(figsize =(14, 8))
 

b1 = [2,8,14,20,26]
b2 = [x + 1 for x in b1]
b3 = [x + 1 for x in b2]
 

plt.bar(b1, other, color ='r', width = 1, edgecolor ='black', label ='other')
plt.bar(b2, rr, color ='g', width = 1, edgecolor ='black', label ='rr')
plt.bar(b3, fifo, color ='b', width = 1, edgecolor ='black', label ='fifo')
 
plt.xlabel('Priority', fontweight ='bold', fontsize = 12)
plt.ylabel('Time', fontweight ='bold', fontsize = 12)
 
plt.legend()
plt.show()
