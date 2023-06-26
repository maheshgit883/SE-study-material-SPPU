# # Python program for implementation of Quicksort Sort 
# # This function takes last element as pivot, places 
# # the pivot element at its correct position in sorted 
# # array, and places all smaller (smaller than pivot) 
# # to left of pivot and all greater elements to right 
# # of pivot 
def partition(arr,low,high):
    i =(low-1)   # index of smaller element 
    pivot=arr[high] # pivot 
  
    for j in range(low , high):
  
        # If current element is smaller than the pivot 
        if   arr[j] < pivot:
          
            # increment index of smaller element
            i = i+1
            arr[i],arr[j] = arr[j],arr[i]
  
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return (i+1)

def quickSort(arr,low,high):   
    if low < high:
            pi=partition(arr,low,high)   # pi is partitioning index, arr[p] is now at right place 
            quickSort(arr, low, pi-1)   
            quickSort(arr, pi+1, high)
  
arr = []
n =int(input("ENTER THE TOTAL NUMBER OF STUDENTS : "))
print("ENTER PERCENTAGES :")
for i in range(0,n):
    element=float(input())
    arr.append(element)
print("\n LIST OF PERCENTEGES OF FE STUDENTS IS :\n",arr)
quickSort(arr,0,n-1)
print("PERCENTAGE OF STUDENTS IN ASCENDING ORDER IS :\n",arr)
print("\nTOP 5 SCORES ARE :")
k=n-1
while (k>=(n-5)):
    print(arr[k])
    k=k-1
  
