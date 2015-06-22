from random import randint
def choosePivot(a):
    return randint(0,len(a)-1)
def partition(a):
    p=choosePivot(a)
    a[0],a[p]=a[p],a[0]
    j=1
    for i in range(1,len(a)):
        if a[i]<a[0]:
            a[i],a[j]=a[j],a[i]     #Swap the number less than the pivot
            j+=1
    a[0],a[j-1]=a[j-1],a[0]
    return j-1,a                #return index of pivot and the partitioned array
def quickSort(a):
    if len(a)>2:
        x,b=partition(a)        #Partition the array
        c=quickSort(b[:x])      #sort the left half
        d=quickSort(b[x+1:])    #sort the right half
        return c+[a[x]]+d       #stitch the results together to get answer
    else:
        return a                #Only one element. Already sorted, return as it is.
