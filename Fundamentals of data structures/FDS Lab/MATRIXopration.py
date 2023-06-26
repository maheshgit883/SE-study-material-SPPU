







mat1=[[]]
mat2=[]
mt3=[]
m=int(input("ENTER NO. OF ROWS OF MATRIX 1 :"))
n=int(input("ENTER NO. OF COLUMNS OF MATRIX 1 :"))
p=int(input("ENTER NO. OF ROWS OF MATRIX 2 :"))
q=int(input("ENTER NO. OF COLUMNS OF MATRIX 2 :"))
print("ENTER ELEMENTS OF MATRIX 1 :")
for i in range(0,m):
    for j in range(0,n):
        mat1[i][j]=int(input())
print(mat1)
print("1.ADDITION 2.SUBTRACTION  3.MULTIPLICATION  4.TRANSPOSE.")
print("ENTER YOUR CHOICE : ")
ch=int(input())
# if (ch==1):
#     add(mat1,mat2)
# elif (ch==2):
#     sub(mat1,mat2)
# elif (ch==3):
#     multi(mat1,mat2)
# elif (ch==4):
#     transpose(mat1,mat2)
# else:
#     print("INVALID")
