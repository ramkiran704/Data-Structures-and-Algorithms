def Quicksort(A,l,r):
    if r-l<=1:
        return ()
    yellow=l+1
    for green in range(l+1,r):
        if A[green]<=A[l]:
            (A[yellow],A[green])=(A[green],A[yellow])
            yellow=yellow+1
    (A[l],A[yellow-1])=(A[yellow-1],A[l])
    Quicksort(A,l,yellow-1)
    Quicksort(A,yellow,r)
A=[3, 4, 5, 2, 1, 7, 10, 9, 8]
Quicksort(A,0,len(A))
print(A)