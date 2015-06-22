#broken right now
#Return median index not the median.

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

def partition(a,pivot):                                         #function to partition the array
    a[0],a[pivot]=a[pivot],a[0]
    j=1

    for i in range(1,len(a)):
        if a[i]<a[0]:
            a[i],a[j]=a[j],a[i]                                 #Swap the number less than the pivot
            j+=1

    a[0],a[j-1]=a[j-1],a[0]                                     #swap the pivot to its rightful place
    return j-1,a                                                #return index of pivot and the partitioned array

def deterministicSelection(a,statistic):
    p=choosePivot(a)

    if statistic>len(a):
        print "Out of array index"
        return -1

    if len(a)>1:
        x,b=partition(a,p)                                      #Partition the array
        if x>statistic:
            c=deterministicSelection(b[:x],statistic)              #search the left half for the statistic
            return c
        elif x<statistic:
            d=deterministicSelection(b[x+1:],statistic-x-1)        #search the right half for the statistic
            return d
        else:
            return a[statistic]                                 #return the element if statistic is found

    else:
        return a[0]                                             #Only one element. Only solution, return as it is.
print deterministicSelection([5,1,48,6,2,4,8,7,5,63,2,1,4,8,99],13)
