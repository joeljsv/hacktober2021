a = input("Enter input : ")
key = int(input("Enter key value : "))
choice = int(input("1 for enc, 2 for dec"))

out = []
if(choice==1):
    for c in a:
        out.append(chr((((ord(c)-97) + key)%26)+97)) 

elif(choice==2):
        for c in a:
            out.append(chr((((ord(c)-97) - key)%26)+97)) 



print(out)
