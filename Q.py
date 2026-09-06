from collections import deque

class Queue:
    def __init__(self):
        self._item = deque()

    def enqueue(self, value):
        self._item.append(value)

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Dequeue from an Empty Q")
        return self._item.popleft()

    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from an Empty Q")
        return self._item[0]

    def is_empty(self):
        return len(self._item) == 0

    def size(self):
        return len(self._item)

    def display(self):
        return list(self._item)


if __name__ == '__main__':
    q = Queue()
    
    while True:
        print("\n1:Enqueue\t2:Dequeue\t3:Peek\t4:Display\t5:Exit")
        choice = input("Enter 1-5: ").strip()

        if choice == '1':
            try:
                value = int(input("Enter Element: "))
                q.enqueue(value)
                print(f"Added {value} to queue.")
            except ValueError:
                print("Error: Please enter a valid integer.")

        elif choice == '2':
            try:
                removed = q.dequeue()
                print("Deleted Element:", removed)
            except IndexError as e:
                print("Error: " + str(e))

        elif choice == '3':
            try:
                front = q.peek()
                print("Front Element:", str(front))
            except IndexError as e:
                print("Error: " + str(e))

        elif choice == '4':
            if q.is_empty():
                print("Queue is empty.")
            else:
                print("Queue elements (Front to Back): " + str(q.display()))

        elif choice == '5':
            print("Exiting menu. Goodbye!")
            break

        else:
            print("Invalid selection! Please enter a number from 1 to 5.")