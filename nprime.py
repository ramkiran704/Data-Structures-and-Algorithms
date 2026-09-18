def factors(n):
    nlist=[]
    for i in range(1,n+1):
        if n%i==0:
            nlist.append(i)
    return nlist
def is_prime(n):
    return(factors(n)==[1,n])
n=int(input())
count=0
num=2
while(count<n):
    if is_prime(num):
        print(num,end=" ")
        count+=1
    num+=1