def factors(n):
    nlist=[]
    for i in range(1,n+1):
        if n%i==0:
            nlist.append(i)
    return nlist
def is_prime(n):
    return(factors(n)==[1,n])
n=int (input())
if is_prime(n):
    print(f"{n} is prime number")
else:
    print("Not a prime number")