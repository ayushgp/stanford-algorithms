def InsertionSort(a):
    for i in range(len(a)):
        for j in range(i):
            if a[j]>a[i]:
                a[j],a[i]=a[i],a[j]
    return a
