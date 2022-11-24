import matplotlib.pyplot as plt

f=open("time.txt","r")

de=float(f.readline())
p1=float(f.readline())
p2=float(f.readline())
p3=float(f.readline())

data={'default':de, "priority1":p1, "priority2":p2, "priority3":p3}

x=list(data.keys())
y=list(data.values())

fig=plt.figure(figsize=(10,5))

plt.bar(x, y, color="red", width=0.4)

plt.xlabel("PRIORITIES")
plt.ylabel("TIME TAKEN")
plt.title("For thread A")
plt.show()


#B
de=float(f.readline())
p1=float(f.readline())
p2=float(f.readline())
p3=float(f.readline())

data={'default':de, "priority1":p1, "priority2":p2, "priority3":p3}

x=list(data.keys())
y=list(data.values())

fig=plt.figure(figsize=(10,5))

plt.bar(x, y, color="blue", width=0.4)

plt.xlabel("PRIORITIES")
plt.ylabel("TIME TAKEN")
plt.title("For thread B")
plt.show()

#C
de=float(f.readline())
p1=float(f.readline())
p2=float(f.readline())
p3=float(f.readline())

data={'default':de, "priority1":p1, "priority2":p2, "priority3":p3}

x=list(data.keys())
y=list(data.values())

fig=plt.figure(figsize=(10,5))

plt.bar(x, y, color="green", width=0.4)

plt.xlabel("PRIORITIES")
plt.ylabel("TIME TAKEN")
plt.title("For thread C")
plt.show()
