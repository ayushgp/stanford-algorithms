def countArrayInv(a):
    if len(a)<2:
        return [a,0]
    mid=int(len(a)/2)
    x,X=countArrayInv(a[:mid])
    y,Y=countArrayInv(a[mid:])
    result=[]
    i=j=k=0
    numinv=X+Y
    while j<len(x) and i<len(y):
        if x[j]<=y[i]:
            result.append(x[j])
            j+=1
        else:
            result.append(y[i])
            numinv+=len(x[j:])
            i+=1
    result+=x[j:]
    result+=y[i:]
    return [result,numinv]
a=[1,5,4,3,2]
print a
print countArrayInv(a)
