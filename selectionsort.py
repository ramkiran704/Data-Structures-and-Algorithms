def selectionsort(l):
    for i in range(len(l)):
        min_value=i
        for j in range(i,len(l)):
            if l[j]<l[min_value]:
                min_value=j
        (l[i],l[min_value])=(l[min_value],l[i])
    print(l)
l=[8,9,2,5,6,7]
selectionsort(l)
