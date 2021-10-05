def inv(num):
    if num==1:
        return 1
    elif num==5:
        return 21
    elif num==21:
        return 5
    elif num==7:
        return 15
    elif num==15:
        return 7
    elif num==11:
        return 19
    elif num==17:
        return 23
    elif num==23:
        return 17
    elif num==25:
        return 25


a = input("Enter input : ")
key = int(input("Enter key value : "))
choice = int(input("1 for enc, 2 for dec"))

out = []
if(choice==1):
    for c in a:
        out.append(chr((((ord(c)-97) * key)%26)+97)) 

elif(choice==2):
        for c in a:
            out.append(chr((((ord(c)-97) * inv(key))%26)+97)) 



print(out)
