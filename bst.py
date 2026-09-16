class Tree:
    def __init__(self, initval=None):
        self.value = initval

        if self.value:
            self.right = Tree()
            self.left = Tree()
        else:
            self.left = None
            self.right = None

    def isempty(self):
        return self.value == None

    def insert(self, value):
        if self.isempty():
            self.value = value
            self.left = Tree()
            self.right = Tree()

        elif value < self.value:
            self.left.insert(value)

        elif value > self.value:
            self.right.insert(value)

    def inorder(self):
        if not self.isempty():
            self.left.inorder()
            print(self.value, end=" ")
            self.right.inorder()

    def isleaf(self):
        return self.left.isempty() and self.right.isempty()

    def maxval(self):
        if self.right.isempty():
            return self.value
        else:
            return self.right.maxval()

    def makeempty(self):
        self.value = None
        self.left = None
        self.right = None

    def copyright(self):
        self.value = self.right.value
        self.left = self.right.left
        self.right = self.right.right

    def delete(self, v):
        if self.isempty():
            return

        if v < self.value:
            self.left.delete(v)
            return

        if v > self.value:
            self.right.delete(v)
            return

        # v == self.value
        if self.isleaf():
            self.makeempty()

        elif self.left.isempty():
            self.copyright()

        else:
            self.value = self.left.maxval()
            self.left.delete(self.left.maxval())


# Create BST
root = Tree()

# Insert values
root.insert(50)
root.insert(30)
root.insert(70)
root.insert(20)
root.insert(40)
root.insert(60)
root.insert(80)

print("Inorder before deletion:")
root.inorder()

# Delete 40
root.delete(40)

print("\nInorder after deleting 40:")
root.inorder()