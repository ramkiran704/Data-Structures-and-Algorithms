fibtable={}
def fib(n):
    
    try:
        value=fibtable[n]
    except KeyError:
        if n==0 or n==1:
            value=n
        else:
            value=fib(n-1)+fib(n-2)
        fibtable[n]=value

    return value
result=fib(5)
print(result)