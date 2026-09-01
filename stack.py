stack=[]
def push():
    if len(stack)==n:
        print("Stack is full")
    value=input("Enter the Value:")
    stack.append(value)
    print(stack)
def pop():
    if not stack:
        print("Stack is empty")
    else:
        e=stack.pop()
        print("removed Element:",e)
        print(stack)
n=int(input("Enter the size of stack"))
while True:
    print("enter the choice =>1:push,2:pop,3:quit")
    choice=int(input())
    if choice==1:
        push()
    elif choice==2:
        pop()
    elif choice==3:
        break
    else:
        print("incorrect input")