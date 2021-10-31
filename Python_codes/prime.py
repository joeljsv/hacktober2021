#Program to find prime numbers upto a Given number
N = int(input("Enter the limit : "))

print("Prime numbers are: ")

for num in range(2, N + 1):

    i = 2

    for i in range(2, num):
        if(num % i == 0):
            i = num
            break;
    if(i != num):
        print(num, end=" ")