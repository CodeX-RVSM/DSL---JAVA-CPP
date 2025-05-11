class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [-1] * size

    def Quadratic_probing_insert(self,data,table):
        index = data[0] % len(table)
        original_index = index
        i = 1

        while table[index] != -1:
            index = (index + (i*i)) % len(table)
            i = i + 1
            if index == original_index and all(item != -1 for item in table):
                print("Hash table is full. Cannot insert.")
                return

        table[index] = data
        print(f"{data} inserted in the table")
        
    def Quadratic_probing_search(self, key, table):
        index = key % len(table)
        original_index = index
        comparison = 1
        i = 1

        while table[index] != -1:
            if table[index][0] == key:
                print(f"Element found at index {index}")
                print(f"Number of comparisons: {comparison}")
                return table[index]
            index = (index + i*i) % len(table)
            i = i + 1
            comparison += 1
        if index == original_index and all(item != -1 for item in table):
            print("Key not found")
            return

    def display(self):
        print("INDEX\t\tNAME\t\tMOBILE NUMBER")
        print("---------------------------------------------")
        for index, item in enumerate(self.table):
            if item != -1:
                print(f"{index}\t\t{item[1]}\t\t{item[0]}")
            else:
                print(f"{index}\t\t-")
                
    def reset_table(self):
            self.table = [-1] * self.size
           
table_size = int(input("Enter the size of the table: "))
Hash_Table = HashTable(size=table_size)

while True:
            print("\nOperations:")
            print("1. Insert")
            print("2. Search")
            print("3. Display")
            print("4. Exit")

            operation_choice = int(input("Enter your choice (1/2/3/4): "))

            if operation_choice == 1:
                name = input("Enter the name: ")
                phone_no = int(input("Enter the phone number: "))
                data = (phone_no, name)
                Hash_Table.Quadratic_probing_insert(data, Hash_Table.table)
                
            elif operation_choice == 2:
                mobile_no = int(input("Enter the number you want to search: "))
                Hash_Table.Quadratic_probing_search(mobile_no, Hash_Table.table)
                
            elif operation_choice == 3:
                Hash_Table.display()
                
            elif operation_choice == 4:
                exit()
        
            else:
                print("Invalid choice,please enter a valid option")