class HashTable:
    def _init_(self, size):
        self.size = size
        self.table = [None] * size
        self.count_comparisons = 0

    def hash_function(self, key):
        # Simple hash function for demonstration purposes
        return len(key) % self.size

    def linear_probe(self, index):
        return (index + 1) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)

        while self.table[index] is not None:
            self.count_comparisons += 1
            index = self.linear_probe(index)

        self.table[index] = (key, value)

    def search(self, key):
        index = self.hash_function(key)
        initial_index = index

        while self.table[index] is not None:
            self.count_comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1]  # Return the value associated with the key
            index = self.linear_probe(index)
            if index == initial_index:
                break  # Reached the starting point, key not found

        return None  # Key not found

# Function to add entries to the telephone book
def add_entry(phone_book):
    name = input("Enter name: ")
    number = input("Enter telephone number: ")
    phone_book.insert(name, number)
    print("Entry added successfully.")

# Function to search for a telephone number in the telephone book
def search_number(phone_book):
    name = input("Enter name to search: ")
    number = phone_book.search(name)
    if number:
        print("Telephone number:", number)
    else:
        print("Name not found in the telephone book.")

# Example usage:
size = int(input("Enter the size of the hash table: "))
phone_book = HashTable(size)
while True:
    choice = input("Enter 'add' to add an entry, 'search' to search for a number, or 'exit' to quit: ")
    if choice == 'add':
        add_entry(phone_book)
    elif choice == 'search':
        search_number(phone_book)
    elif choice == 'exit':
        break
    else:
        print("Invalid choice.")
print("Number of comparisons:", phone_book.count_comparisons)