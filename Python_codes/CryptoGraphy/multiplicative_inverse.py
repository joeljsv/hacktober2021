n = int(input("Enter a value : "))

print("(1,1)")
for i in range(0,n):
    for j in range(0,n):
        if((j*i)%n==1):
            print("({0},{1})".format(i,j))
