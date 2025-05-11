class HashTable:
    def _init_(self, size):
        self.size = size
        self.table = [None] * size
        self.count_comparisons = 0

    def hash_function(self, key):
        # Simple hash function for demonstration purposes
        return len(key) % self.size

    def quadratic_probe(self, index, attempt):
        return (index + attempt ** 2) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        attempt = 0

        while self.table[index] is not None:
            self.count_comparisons += 1
            if self.table[index][0] == key:  # Key already exists, update value
                self.table[index] = (key, value)
                return
            attempt += 1
            index = self.quadratic_probe(index, attempt)

        self.table[index] = (key, value)

    def search(self, key):
        index = self.hash_function(key)
        attempt = 0

        while self.table[index] is not None:
            self.count_comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1]  # Return the value associated with the key
            attempt += 1
            index = self.quadratic_probe(index, attempt)

        return None  # Key not found

# Function to interactively add entries to the telephone book
def add_entries(phone_book):
    while True:
        name = input("Enter name (or 'exit' to stop): ")
        if name == 'exit':
            break
        number = input("Enter telephone number: ")
        phone_book.insert(name, number)
    print("Entries added successfully.")

# Function to search for a telephone number in the telephone book
def search_number(phone_book):
    name = input("Enter name to search: ")
    number = phone_book.search(name)
    if number:
        print("Telephone number:", number)
    else:
        print("Name not found in the telephone book.")

# Example usage:
phone_book = HashTable(11)  # Hash table size of 11 for demonstration
add_entries(phone_book)
search_number(phone_book)
print("Number of comparisons:", phone_book.count_comparisons)