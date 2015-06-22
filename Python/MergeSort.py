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
