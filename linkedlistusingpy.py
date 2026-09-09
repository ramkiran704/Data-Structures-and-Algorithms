class Node:
    def __init__(self,data) :
        self.data=data
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None

    def append(self,data):
        newNode=Node(data)
        if not self.head:
            self.head=newNode
            return
        current=self.head
        while(current.next):
            current=current.next
        current.next=newNode
    def prepend(self,data):
        newNode=Node(data)
        newNode.next=self.head
        self.head=newNode

    def insert_after(self,target_data,data):

        current=self.head
        while current and current.data!=target_data:
            current=current.next
        if not current:
            print("Target data is not found")
            return
        newNode=Node(data)
        newNode.next=current.next
        current.next=newNode
    def delete_value(self,target_data):
        if not self.head:
            print("Empty Linked List")
            return
        if self.head.data==target_data:
            self.head=self.head.next
            return
        current=self.head
        while current.next and current.next.data!=target_data:
            current=current.next

        if not current.next:
            print("Target data is not found")
            return
        current.next=current.next.next

    def search(self,target_data):
        current=self.head
        while current:
            if current.data== target_data:
                print("Target data is found")
                return True
            current=current.next
        print("Target Data not found")
        return False
    def display(self):
        current=self.head
        while current:
            print(f'{current.data}')
            print("|")
            print("v")
            current=current.next
        

        


def main():
    sll =LinkedList()

    while True:
        print("\n=== SINGLY LINKED LIST MENU ===")
        print("1. Append (Add to End)")
        print("2. Prepend (Add to Beginning)")
        print("3. Insert After Value")
        print("4. Delete by Value")
        print("5. Search Value")
        print("6. Display List")
        print("7. Exit")

        choice = input("Enter your choice (1-7): ").strip()

        match choice:
            case "1":
                data = int(input("Enter value to append: "))
                sll.append(data)
            case "2":
                data = int(input("Enter value to prepend: "))
                sll.prepend(data)
            case "3":
                target_data = int(input("Enter target value to insert after: "))
                data = int(input("Enter new value to insert: "))
                sll.insert_after(target_data, data)
            case "4":
                data = int(input("Enter value to delete: "))
                sll.delete_value(data)
            case "5":
                data = int(input("Enter value to search: "))
                sll.search(data)
            case "6":
                sll.display()
            case "7":
                print("Exiting program.")
                break
            case _:
                print("Invalid choice. Please enter a number between 1 and 8.")


if __name__ == "__main__":
    main()