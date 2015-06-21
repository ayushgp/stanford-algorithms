from random import randint
def choosePivot(a):                                             #function to choose a random pivot
    return randint(0,len(a)-1)

def partition(a,pivot):                                         #function to partition the array
    a[0],a[pivot]=a[pivot],a[0]
    j=1

    for i in range(1,len(a)):
        if a[i]<a[0]:
            a[i],a[j]=a[j],a[i]                                 #Swap the number less than the pivot
            j+=1

    a[0],a[j-1]=a[j-1],a[0]                                     #swap the pivot to its rightful place
    return j-1,a                                                #return index of pivot and the partitioned array

def randomizedSelection(a,statistic):
    p=choosePivot(a)

    if statistic>len(a):
        print "Out of array index"
        return -1

    if len(a)>1:
        x,b=partition(a,p)                                      #Partition the array
        if x>statistic:
            c=randomizedSelection(b[:x],statistic)              #search the left half for the statistic
            return c
        elif x<statistic:
            d=randomizedSelection(b[x+1:],statistic-x-1)        #search the right half for the statistic
            return d
        else:
            return a[statistic]                                 #return the element if statistic is found

    else:
        return a[0]                                             #Only one element. Only solution, return as it is.
