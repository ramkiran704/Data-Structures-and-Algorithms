def gcd(m,n):
    fn=[]
    fm=[]
    for i in range(1,m+1):
        if m%i==0:
            fm.append(i)
            
    for i in range(1,n+1):
        if n%i==0:
            fn.append(i)
    fresult=[]
    for i in fn:
        if i in fm:
            fresult.append(i)
    return(fresult[-1])
def gcd1(m,n):
    resultarr=[]
    for i in range(1,min(m,n)+1):
        if m%i==0 and n%i==0:
            resultarr.append(i)
    return resultarr[-1]
def withoutarr(m,n):
    for i in range(1,min(m,n)+1):
        if m%i==0 and n%i==0:
            mrcf=i
    return mrcf
def gcdeuclid(m,n):
    if m<n:
        (m,n)=(n,m)
    while (m%n) !=0:
        (m,n)=(n,m%n)
    return n
m=int(input())
n=int(input())
result=gcd(m,n)
result1=gcd1(m,n)
result2=withoutarr(m,n)
result3=gcdeuclid(m,n)
print(result)
print(result1)
print(result2)
print(result3)