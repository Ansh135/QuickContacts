# Quick Contacts

## Overview
The Contact Book is a console-based C++ application that allows users to efficiently manage their contacts. The application uses Binary Search Trees (BST) to store and retrieve contact records, ensuring optimal performance for insertion, search, and deletion operations. In addition, it provides features to mark contacts as favourites and saves all contact details to a text file for offline access.

## Features
- **Add Contacts:**  
  - Insert new contacts by entering a name, phone number, and email.
  - Choose whether to mark a contact as a favourite.
  - Contacts are inserted into two BSTs: one sorted by name and another by phone number.

- **Display Contacts:**  
  - Display all contacts using an in-order traversal of the BST to ensure records are listed in sorted order.

- **Search Contacts:**  
  - Search for contacts by name, phone number, or email.
  - Each search function traverses the BST to quickly locate the required contact details.

- **Edit Contacts:**  
  - Update an existing contact's name, phone number, or email.
  - The application searches for the contact based on the user’s input and allows for modification.

- **Delete Contacts:**  
  - Delete a specific contact by name.
  - Option to delete the entire contact directory.
  - The deletion operation handles cases with 0, 1, or 2 children in the BST.

- **Favourite Contacts:**  
  - Display only those contacts marked as favourites.
  - A stack is used in the traversal to filter and show favourite contacts.

- **Offline Save:**  
  - Save all contacts to a text file (`contactbook.txt`) using in-order traversal.
  - Ensures that contact data is persisted across sessions.

## Technical Details
- **Programming Language:** C++
- **Data Structures:**  
  - **Binary Search Tree (BST):** Used for storing and managing contacts for fast insertion, search, and deletion.
  - **Stack (STL):** Utilized during in-order traversal for both displaying and saving contacts.
- **Libraries Used:**  
  - `<iostream>` for console I/O.
  - `<fstream>` for file handling.
  - `<stack>` for iterative tree traversal.
  - `<string>` and `<stdlib.h>` for utility functions.
- **User Interface:**  
  - Console-based, menu-driven interface with clear prompts and options.
  - ASCII art in the main function to provide a visually appealing welcome screen.

