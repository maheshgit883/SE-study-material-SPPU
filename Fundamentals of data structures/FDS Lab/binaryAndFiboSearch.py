
# MAHESH JAGTAP ROLL NO. 21027  SE A
# GRP B 11. b) Write a Python program to store roll numbers of student array 
# who  attended training program in sorted order. 
# Write function for searching whether particular student attended training program or not, 
# using Binary search and Fibonacci search 

def binarysearch(arr, left, right, x): 
    while (left <= right) :
        mid = ((left + right) // 2)
        if (arr[mid] ==x):
            return mid
        elif arr[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def fibonaccisearch(arr,n,x):
    fm2 = 0
    fm1= 1
    fm= fm2 + fm1
    while (fm < n):
        fm2 = fm1
        fm1 = fm
        fm = fm2 + fm1
    offset = -1;
    while (fm > 1):
        i = min(offset+fm2, n-1)
        if (arr[i] < x): 
            fm = fm1
            fm1 = fm2
            fm2 = fm - fm1
            offset = i
        elif (arr[i] > x):
            fm = fm2
            fm1 = fm1 - fm2
            fm2 = fm - fm1
        else :
            return i
    if(fm1 and arr[offset+1] == x):
        return offset+1
    return -1

def printResult(result):
    if result != -1:
        print ("ROLL NO.", x, " Was Present for the Program And found at the index " ,result)
    else:
        print ("ROLL NO. ",x, " Was Absent for the Program...")

arr=[]
n=int(input("HOW MANY STUDENTS ATTENDED THE PROGRAM ?  :"))
print("ENTER ROLL NUMBERS IN SORTED ORDER :")
for i in range(0,n):
  roll = int(input("Enter roll no : "))   
  arr.append(roll) 
print("THIS IS THE LIST OF ROLL NUMBERS : ",arr) 

print("Which search method do u want to use:")
print("1.Binary search")
print("2.Fibonacci search")
c = int(input("ENTER YOUR CHOICE (1,2)  : "))
if (c == 1):
    print("OK,WE WILL USE BINARY SEARCH METHOD")
    x = int(input("Enter roll no to be search :"))
    result=binarysearch(arr,0, len(arr)-1, x)
    printResult(result)
elif (c == 2):
    print("OK,WE WILL USE FIBONACCI SEARCH METHOD")
    x = int(input("Enter roll no to be search :"))
    result=fibonaccisearch(arr, n, x)
    printResult(result)
else:
    print("INVALID")

