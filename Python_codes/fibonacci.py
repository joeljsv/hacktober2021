import numpy as np

#Making an empty list with 16 elements
n = 16
x = np.zeros(n)

#Setting x[0] and x[1] to their given values
x[0] = 1
x[1] = 1

#Printing out x[0] and x[1]
print(x[0])
print(x[1])

#Calculating the rest of the fiboncacci string using recursion
for i in range(2,n):
    x[i]= float(x[i-1]) + float(x[i-2])
    print(f"{x[i]}")

