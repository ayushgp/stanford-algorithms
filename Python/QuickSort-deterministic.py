def mergeSort(a):
    if len(a)<2:
        return a
    mid=int(len(a)/2)
    x=mergeSort(a[:mid])
    y=mergeSort(a[mid:])
    result=[]
    i=j=k=0
    while j<len(x) and i<len(y):
        if x[j]<y[i]:
            result.append(x[j])
            j+=1
        else:
            result.append(y[i])
            i+=1
    result+=x[j:]
    result+=y[i:]
    return result

def findMedian(a):
    return mergeSort(a)[len(a)/2]

def choosePivot(a):
    medians=[]
    j=0
    if len(a)==1:
        print a[0]
        return a[0]
    if 5<len(a):
        medians.append(findMedian(a[0:5]))
    else:
        medians.append(findMedian(a))
    for i in range(1,len(a)/5):
        if i*5<len(a):
            medians.append(findMedian(a[j*5:i*5]))
        else:
            medians.append(findMedian(a[j*5:len(a)]))
    return choosePivot(medians)

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
