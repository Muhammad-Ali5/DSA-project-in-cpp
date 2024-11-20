# Inventory Management System

## Features
1. Add categories.
2. Display all categories with their sub-categories and products.
3. Add sub-categories under a category.
4. Add products to a specific sub-category.
5. Search and display details of a specific category.
6. View details of sold and remaining items.

## Classes Structure
### 1. **Product**
- Represents individual products in a sub-category.
- Attributes: `name`, `description`, `brand`, `price`.
- Methods: 
  - Constructor to initialize a product.

### 2. **subCategories**
- Represents sub-categories under a main category.
- Attributes: `name`, `item_Sold`, `item_Remaining`, `Product* p_head`.
- Methods:
  - Add products to a sub-category.
  - Display all products in a sub-category.

### 3. **Categories**
- Represents the main category (e.g., "Shoes").
- Attributes: `name`, `item_Sold`, `item_Remaining`, `subCategories* sub_head`.
- Methods:
  - Add sub-categories to a category.
  - Display all sub-categories and their products.

### 4. **inventrySystem**
- Represents the overall inventory system.
- Attributes: `Categories* cat_head`.
- Methods:
  - Add categories.
  - Search for categories by name.
  - Display all categories and their details.

## Usage Instructions
1. **Compile the Code**
   ```bash
   g++ inventory_system.cpp -o inventory_system
   ```
2. **Run the Program**
   ```bash
   ./inventory_system
   ```

3. **Menu Options**
   - **1. Add Category**: Input a category name to add a new category.
   - **2. Display Categories**: View all categories, sub-categories, and products.
   - **3. Add Sub-Category**: Input a category name and sub-category name to add a sub-category.
   - **4. Add Products in Sub-Category**: Input a category name, sub-category name, and product details to add a product.
   - **5. Search Category**: Input a category name to view its details.
   - **6. Exit Program**: Exit the application.

## Example Input/Output
**Adding a Category:**
```
Enter the Categorie name: Shoes
```

**Adding a Sub-Category:**
```
Enter the Categorie name to add Sub-Category to: Shoes
Enter the sub-Categorie name: Men
```

**Adding a Product:**
```
Enter the Category name to add Product to: Shoes
Enter the Sub-Category name: Men
Enter Product name: RunningShoes
Enter Description: Comfortable and lightweight
Enter Brand: Nike
Enter Price: 120.50
```

**Displaying All Categories:**
```
Categories are:
========================
Category Name: Shoes
Sold: 0
Remaining: 1
Sub Categories Product: Men
================================
=> Product in: Men
================================
Name: RunningShoes
Description: Comfortable and lightweight
Brand: Nike
Price: $120.50
--------------------------------
```

## Code Highlights
- **Dynamic Memory Management:** Uses pointers for linked lists to handle dynamic data.
- **Menu System:** Provides an intuitive interface for navigation and operation.
- **Extensible Design:** Easy to extend functionality by adding new methods or classes.

## Requirements
- **C++ Compiler**: Ensure you have a modern C++ compiler like GCC.
