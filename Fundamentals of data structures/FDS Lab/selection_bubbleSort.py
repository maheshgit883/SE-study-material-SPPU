'''Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.'''

def selectionSort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)): 
            if arr[min_idx] > arr[j]:
                min_idx=j
        arr[i],arr[min_idx] = arr[min_idx],arr[i]

def bubbleSort(arr):
    n=len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j] 

arr = []
n =int(input("ENTER THE TOTAL NUMBER OF STUDENTS : "))
print("ENTER PERCENTAGES :")
for i in range(0,n):
    element=float(input())
    arr.append(element)
print("\n LIST OF PERCENTEGES OF FE STUDENTS IS :\n",arr)
print("Which search method do u want to use:")
print("\n 1.SELECTION SORT \n 2.BUBBLE SORT")
c=int(input("ENTER YOUR CHOICE (1,2)  : "))

if(c==1):
    print("OK,WE WILL USE SELECTION SORT METHOD")
    selectionSort(arr)
elif(c==2):
    print("OK,WE WILL USE BUBBLE SORT METHOD")
    bubbleSort(arr)
else:
    print("INVALID")

print("PERCENTAGE OF STUDENTS IN ASCENDING ORDER IS :\n",arr)
print("\nTOP 5 SCORES ARE :")
k=n-1
while (k>=(n-5)):
    print(arr[k])
    k=k-1