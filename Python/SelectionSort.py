def selectionSort(a):
    mn=0
    for i in range(len(a)):
        for j in range(i+1,len(a)):
            if a[mn]>a[j]:
                mn=j
        a[mn],a[i]=a[i],a[mn]
    return a
