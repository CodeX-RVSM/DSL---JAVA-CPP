s1 = []
s2 = []
def add(s):
   a= int(input("Enter number of elements you want to insert: "))
   for i in range (a):
      ele = int(input("Enter element: "))
      if ele not in s:
          s.append(ele)

def display(s):
   print(s)

def remove(s):
   ele = int(input("Enter element you want to remove: "))
   s.remove(ele)
   

def check(s):
   ele = int(input("Enter element to check in set: "))
   print(ele in s)

def size(s):
   print(len(s))

def union(a,b):
   result = []
   for i in (a):
       result.append(i)
   for i in (b):
        if i not in (result):
            result.append(i)
   return result

def intersection(a,b):
   result = []
   for i in (a):
       for j in (b):
           if(i == j):
               result.append(i)
   return result

def difference(a,b):
   result = []
   for i in (a):
        if i not in (b):
            result.append(i)
   return result

def subset(a,b):
    for i in (a):
        if i not in (b):
            return False
    return True
def propersubset(a,b):
    if (subset(a,b) == True and len(b)> len(a)):
        print("S2 is proper subset of s1")
    else:
        print("S2 is not proper subset of s1")

while True:
    print("""
      Menu:
      1. Add element to set s1
      2. Add element to set s2
      3. Display set s1
      4. Display set s2
      5. Remove from set s1
      6. Remove from set s2
      7. Check element in set s1
      8. Check element in set s2
      9. Size of set s1
      10. Size of set s2
      11. Union of sets 
      12. Intersection of sets s2 and s1
      13. Difference of sets s1 and s2
      14. Check if s2 is a subset of s1
      15. Check if s2 is proper subset of s1
      0. Exit
         """)
    choice = int(input("Enter your choice (0-15): "))
    if choice == 1:
        add(s1)
    elif choice == 2:
        add(s2)
    elif choice == 3:
        display(s1)
    elif choice == 4:
        display(s2)
    elif choice == 5:
        remove(s1)
        print("Remaining elements in Set 1 : ")
        display(s1)
    elif choice == 6:
        remove(s2)
        print("Remaining elements in Set 2 : ")
        display(s2)
    elif choice == 7:
        check(s1)
    elif choice == 8:
        check(s2)
    elif choice == 9:
        size(s1)
    elif choice == 10:
        size(s2)
    elif choice == 11:
        print(union(s1, s2))
    elif choice == 12:
        print(intersection(s2, s1))
    elif choice == 13:
        print(difference(s1, s2))
    elif choice == 14:
        print(subset(s2, s1))
    elif choice == 15:
        propersubset(s2,s1)
    elif choice == 0:
        break
    else:
        print("Invalid choice. Please enter a number between 0 and 15.")
