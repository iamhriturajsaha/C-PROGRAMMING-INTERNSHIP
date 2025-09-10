# 🛒Inventory Management System

A **command-line inventory management solution** built in C, designed for small to medium-sized retail businesses to efficiently track and manage their product inventory.

## 📌 Overview

This project provides a comprehensive inventory management system that enables store owners and managers to handle essential inventory operations through an intuitive command-line interface. The system offers real-time inventory tracking with persistent file-based storage, making it ideal for small retail establishments, warehouses or personal inventory management.

## ✨ Features

- **Item Management**
  - Add new products with unique identification numbers.
  - Store comprehensive item details (ID, name, price, quantity).
  - Automated inventory updates with real-time stock tracking.

- **Stock Management**
  - Update stock quantities for existing items.
  - Real-time inventory level monitoring.
  - Low stock alerts and warnings.

- **Sales Processing**
  - Process item sales with automatic stock deduction.
  - Validate stock availability before sales completion.
  - Instant inventory updates post-transaction.

- **Data Management**
  - Binary file storage (`inventory.dat`) for reliable data retention.
  - Automatic file creation and management.
  - Data integrity across program sessions.
  - Quick data retrieval and updates.

## 🛠️ Technical Stack

- **Programming Language -** C (ANSI C compatible).
- **Compiler -** GCC (GNU Compiler Collection).
- **File Operations -** Standard C library (`fopen`, `fwrite`, `fread`, `fseek`, `fclose`).
- **Data Storage -** Optimized binary file format.
- **Platform -** Cross-platform (Linux, macOS, Windows).

## 🚀 Getting Started

### Prerequisites

- **GCC Compiler** installed on your system.
- **Terminal/Command Prompt** access.
- **Minimum System Requirements -**
  - 1MB free disk space.
  - Any modern operating system (Linux, macOS, Windows).

## 💻 User Guide

### Main Menu Interface
```
=======================================
     INVENTORY MANAGEMENT SYSTEM
=======================================
1. Add New Item
2. View All Items
3. Update Stock Quantity
4. Process Sale
5. Exit System
=======================================
Enter your choice (1-5): 
```

### Detailed Operations

#### **Adding New Items**
```
Enter choice: 1

=== ADD NEW ITEM ===
Enter Item ID: 101
Enter Item Name: Wireless Headphones
Enter Unit Price: $89.99
Enter Initial Quantity: 25
✅ Item 'Wireless Headphones' added successfully!
📦 Stock Level: 25 units
```

#### **Viewing Inventory**
```
Enter choice: 2

=== CURRENT INVENTORY ===
+------+-------------------+--------+-----------+
| ID   | Item Name         | Price  | Stock     |
+------+-------------------+--------+-----------+
| 101  | Wireless Headphones| $89.99 | 25        |
| 102  | USB Cables        | $12.50 | 100       |
| 103  | Phone Cases       | $24.99 | 15        |
+------+-------------------+--------+-----------+
Total Items: 3 | Total Value: $2,122.35
```

#### **Updating Stock**
```
Enter choice: 3

=== UPDATE STOCK ===
Enter Item ID: 101
Current Stock: 25 units
Enter New Quantity: 50
✅ Stock updated successfully!
📈 New Stock Level: 50 units
```

#### **Processing Sales**
```
Enter choice: 4

=== PROCESS SALE ===
Enter Item ID: 101
Item: Wireless Headphones | Price: $89.99 | Available: 50
Enter Quantity to Sell: 3

💰 Sale Summary:
   - Item: Wireless Headphones
   - Quantity: 3 units
   - Unit Price: $89.99
   - Total Amount: $269.97

✅ Sale completed successfully!
📦 Remaining Stock: 47 units
```

## 🗃️ Data Structure

The system utilizes the following item structure for efficient data management -

```c
struct Item {
    int id;           // Unique item identifier
    char name[50];    // Product name/description
    float price;      // Unit price in currency
    int quantity;     // Available stock quantity
};
```

## 🔧 Error Handling & Validation

### **Robust Input Validation**
- **Item ID Verification -** Prevents duplicate IDs and invalid entries.
- **Quantity Validation -** Ensures positive values and realistic limits.
- **Price Validation -** Validates monetary values and prevents negative prices.
- **Stock Availability -** Checks sufficient inventory before processing sales.

### **Error Management**
- **File Access Errors -** Graceful handling of file I/O issues.
- **Memory Management -** Proper allocation and deallocation.
- **Invalid Operations -** Clear error messages and recovery suggestions.
- **Data Corruption -** Built-in data integrity checks.

## 📊 Business Intelligence

### **Inventory Insights**
- Real-time stock level monitoring.
- Automatic low stock identification.
- Item valuation calculations.
- Sales impact on inventory levels.

### **Operational Benefits**
- **Time Efficiency -** Quick inventory operations and updates.
- **Accuracy -** Eliminates manual counting errors.
- **Reliability -** Persistent data storage prevents data loss.
- **Scalability -** Handles growing inventory needs.

## 🔮 Future Enhancements

  - Comprehensive sales tracking and history.
  - Revenue calculations and profit margins.
  - Generate detailed inventory reports.
  - Low stock alerts and notifications.
  - User authentication and access levels.
  - Concurrent access with file locking.

## 🎯 Use Cases

- Track product inventory in real-time.
- Process sales and update stock automatically.
- Monitor popular items and stock levels.
- Manage incoming and outgoing inventory.
- Track item locations and quantities.
- Generate stock reports for management.
