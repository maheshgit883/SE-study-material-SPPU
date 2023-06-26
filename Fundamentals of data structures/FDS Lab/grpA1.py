C=[2,3,5,7,13,15,17,19,20]
F=[1,4,5,8,9,12,13,15,18]
B=[2,6,9,10,13,16,17,19]
def crickANDbad():
    for i in range (0,len(C)):
        if (C[i]==B):
            flag==True
        if flag!=True:   
            B.append(C[i])
    return (B)
RESULT=crickANDbad()
print(RESULT)