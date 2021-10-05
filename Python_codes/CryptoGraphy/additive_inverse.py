n = int(input("Enter a value : "))

print("(0,0)")
for i in range(0,n):
    for j in range(n//2,n):
        if((j+i)%n==0):
            print("({0},{1})".format(i,j))

