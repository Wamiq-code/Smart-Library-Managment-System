# Library Management System (C++)

A console-based Library Management System implemented in C++ that demonstrates core Object-Oriented Programming (OOP) concepts, dynamic memory management, exception handling, and file I/O operations.

## 🚀 Features

- **Student Management:** Add students to the system with unique Roll Numbers.
- **Book Inventory Management:** Add books with attributes like ID, Title, Author, and Quantity.
- **Issue & Return Tracking:** Keep records of which student borrowed which book. Tracks available inventory quantities dynamically.
- **File Handling:** Persists system states (Books, Students, and Active Records) into local `.txt` files.
- **Generic Search:** Utilizes a C++ Template function to locate item indexes dynamically.

---

## 🛠️ Object-Oriented Programming (OOP) Concepts Demonstrated

This project serves as an excellent reference for advanced C++ features:

1. **Inheritance & Abstraction:** 
   - Uses an abstract base class `Person` with a pure virtual function `display()`.
   - `Student` and `Librarian` inherit from `Person` and override the `display()` function.
2. **Polymorphism (Runtime):** 
   - Demonstrates dynamic binding through the virtual `display()` method overridden across the class hierarchy.
3. **Operator Overloading:** 
   - Overloads the prefix increment `++` and decrement `--` operators in the `Book` class to simplify increasing or decreasing inventory stock levels seamlessly.
4. **Dynamic Memory Management:** 
   - Allocates objects on the **Heap** using the `new` keyword to maintain data across different scopes.
   - Implements a custom **Destructor** (`~Library()`) utilizing `delete` to safely free heap memory and prevent memory leaks.
5. **Generic Programming (Templates):** 
   - Includes a generic search function `findIndex<T>` to look up elements within dynamic pointer arrays.
6. **Exception Handling:** 
   - Utilizes `try-catch` blocks to gracefully handle operational errors like full system limits, file streaming problems, and search failures.

---

## 📂 File Structure Overview

When you choose to save data within the program, it writes the current records out to three dedicated text files:
- `Text.txt` - Stores registered book data (ID, Title, Author, Quantity).
- `Text1.txt` - Stores student database details (Name, Roll Number).
- `Text2.txt` - Log of currently issued books matched to student roll numbers.
  
How to Use (Menu Navigation)
Upon launching the executable, you will interact with a text-driven menu interface:
Welcome to Library Management System
Following are the options you can choose from: 
1. Add Student
2. Add Book
3. Issue Book
4. Return Book
5. Display Students
6. Display Books
7. Display Records
8. Write Data to File
9. Find Book Index
10. Exit
Thankyou.
