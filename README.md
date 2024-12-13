# Library Management System

## Overview

The Library Management System is a C++ application designed to manage books and members in a library. It allows users to add books, list available books, add members, and manage book borrowing and returning functionalities. The system supports both fiction and non-fiction books, providing a simple interface for library management.

## Features

- Add Books: Users can add new books to the library, specifying the title, author, ISBN, type (Fiction or Non-Fiction), and additional details (genre or subject).
- List Books: Users can view all the books currently in the library along with their details.
- Add Members: Users can register new members with a unique ID and name.
- List Members: Users can view all registered members and their borrowed books.
- Borrow Books: Members can borrow available books by providing their member ID and the book's ISBN.
- Return Books: Members can return borrowed books, updating their status to available.
- Data Persistence: The system saves books and members to text files, allowing data to persist between sessions.

## Technologies Used

- C++
- Standard Template Library (STL)
- File I/O for data persistence

## File Structure

library_management_system/
├── Book.cpp         # Implementation of Book and derived classes
├── Book.h           # Header file for Book and derived classes
├── Member.cpp       # Implementation of Member class
├── Member.h         # Header file for Member class
├── globals.h        # Global variables and includes
└── main.cpp         # Main application logic

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Basic knowledge of C++ programming

### Compilation

To compile the project, navigate to the 'library_management_system' directory and run the following command:

'g++ main.cpp Book.cpp Member.cpp -o LibraryManagementSystem'

### Running the Application

After compiling, run the application using the following command:

'./LibraryManagementSystem'

### Usage

1. Follow the on-screen menu to navigate through the options.
2. Enter the required information when prompted.
3. The application will save data to books.txt and members.txt for future sessions.

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

## Acknowledgements

Thanks to the contributors and the open-source community for their support and resources.
