A=[3,4,5,2,1,7,10,9,8]
def merge(A,B):
    (C,m,n)=([],len(A),len(B))
    (i,j)=(0,0)
    while i+j<m+n:
        if i==m:
            C.append(B[j])
            j+=1
        elif j==n:
            C.append(A[i])
            i+=1
        elif A[i]<=B[j]:
            C.append(A[i])
            i+=1
        elif A[i]>B[j]:
            C.append(B[j])
            j+=1
    return (C)
def mergesort (A,left,right):
    if  right-left<=1:
        return (A[left:right])
    if right-left>1:
        mid=(left+right)//2
        l=mergesort(A,left,mid)
        r=mergesort(A,mid,right)
        return (merge(l,r))
sorted_A=mergesort(A,0,len(A))
print(sorted_A)