# Employee Management System (C)

A simple command-line Employee Management System built using the C programming language. This application allows users to manage employee records, perform CRUD operations, and save data to a file.

## 🚀 Features

* Add employee records (ID, Name, Basic Salary)
* Edit existing employee data
* Delete employee records
* Preview unsaved changes in table format
* Save data to a file (`dataSheet.txt`)
* Automatic Gross Salary calculation
* Menu-driven user interface

## 🧮 Salary Calculation

Gross salary is calculated using:

* Transport Allowance = 10% of basic salary
* Attendance Allowance:

  * 8% if salary ≤ 35000
  * 5% if salary > 35000

```
Gross Salary = Basic Salary + Transport Allowance + Attendance Allowance
```

## 📂 Project Structure

```
.
├── main.c
├── functions.c
├── functions.h
├── dataSheet.txt (ignored in Git)
└── .gitignore
```

## ▶️ How to Run

1. Compile the program:

```
gcc main.c functions.c -o app
```

2. Run the executable:

```
./app
```

## 📌 Notes

* Maximum number of employees: 100
* Unsaved changes will be lost if not saved before exit
* Data is appended to the file (`dataSheet.txt`)

## 🛠️ Technologies Used

* C Programming
* File Handling
* Structures
* Arrays

## 👤 Author

Inupa Maditha — [GitHub](https://github.com/Inupa-Maditha)
