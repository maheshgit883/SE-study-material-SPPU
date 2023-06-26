
# MAHESH JAGTAP ROLL NO. 21027  SE A
# GRP B 11.a) Write a Python program to store roll numbers of student in array
# who attended training program in random order. 
# Write function for searching whether particular student attended training program or not, 
# using Linear search and Sentinel search.

def linearsearch(arr, n, x):
    i = flag = 0
    while (i < len(arr)):
        if (arr[i] == x):
            flag = 1
            break
        i = i + 1

    if flag == 1:
        print("ROLL NO.", x, "Was Present for the Prgram...")
    else:
        print("ROLL NO.", x, "Was Absent for the Prgram...")


def sentinelsearch(arr, n, x):
    last = arr[n - 1]
    arr[n - 1] = x
    i = 0
    while (arr[i] != x):
        i += 1
    arr[n - 1] = last

    if ((i < n - 1) or (x == arr[n - 1])):
        print("ROLL NO.", x, "Was Present for the Program...")
    else:
        print("ROLL NO.", x, "Was Absent for the Program...")

arr=[]
n=int(input("ENTER THE NUMBER OF STUDENTS ATTENDED THE PROGRAM  :"))
for i in range(0,n):
  roll = int(input("Enter roll no : "))   
  arr.append(roll) 
print("THIS IS THE LIST OF ROLL NUMBERS : ",arr) 

print("Which search method do u want to use:")
print("1.Linear search")
print("2.sentinel search")
c = int(input("ENTER YOUR CHOICE (1,2)  : "))
if (c == 1):
    print("OK,WE WILL USE LINEAR SEARCH METHOD")
    x = int(input("Enter roll no to be search :"))
    linearsearch(arr, n, x)
elif (c == 2):
    print("OK,WE WILL USE SENTINEL SEARCH METHOD")
    x = int(input("Enter roll no to be search :"))
    sentinelsearch(arr, n, x)
else:
    print("INVALID")

