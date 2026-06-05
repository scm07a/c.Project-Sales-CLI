# Sales Management System (C)

## Overview
A console-based Sales Management System built in C for managing and tracking sales data across multiple branches.  
The system allows users to input, store, and analyze monthly sales using a structured menu-driven interface.

This project demonstrates procedural programming, file handling, and data processing in C.

---

## Features
- Add sales data for multiple branches
- Input monthly sales values
- View branch-wise sales reports
- Compare performance between branches
- Display all stored sales data
- Persistent data storage using files
- Input validation for safer user interaction

---

## Concepts Used
- Arrays (including 2D arrays for monthly data)
- Functions and modular programming
- File handling (reading and writing data)
- Input validation
- Basic sorting and comparison logic
- Menu-driven CLI system

---

## Project Structure
The program is organized into separate functional parts:
- Input handling functions
- Data processing and calculations
- File saving and loading functions
- Reporting and display functions

---

## Data Storage
All sales data is stored locally in a file to ensure persistence between sessions.

File used:
sales_data.txt

---

## How to Run

### Compile
```bash
gcc main.c -o sales
```

### Run (Linux / macOS)
```bash
./sales
```

### Run (Windows)
```bash
sales.exe
```

---

## Example Menu
```
---------- Sales Management System ----------

1. Add Branch Sales Data
2. View Branch Report
3. Compare Branch Performance
4. View All Data
0. Exit
```