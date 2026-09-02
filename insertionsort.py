def insertionsort(l):
    for i in range(len(l)):
        pos=i
        while( pos>0 and l[pos]<l[pos-1]):
            l[pos],l[pos-1]=l[pos-1],l[pos]
            pos=pos-1
    print(l)
l=[3,5,2,1,4,7]
insertionsort(l)