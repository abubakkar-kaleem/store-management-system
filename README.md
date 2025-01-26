
#### Super Store Management System

#### Description
This project is a **Super Store Management System** designed for a course on Programming Fundamentals. Built in C, it serves as a robust platform for managing a store’s inventory, handling administrative tasks, and supporting customer purchases. The system is easy to use and simulates real-world functionalities of a retail environment.

#### Features
1. **Admin Panel**:  
   - Add new products with details like name, quantity, and price.  
   - View all available products in the inventory.  
   - Edit product details, such as name, quantity, or price.  
   - Search for specific products by name.  
   - Delete products from the inventory.  

2. **Customer Interface**:  
   - Browse available products along with their details.  
   - Select items to purchase and view the total bill dynamically.  
   - Return to the main menu or exit after completing a purchase.  

3. **User-Friendly Design**:  
   - Simple text-based interface.  
   - Dynamic navigation between menus for smooth user experience.  
   - Intuitive prompts to guide users through various tasks.  

#### Technical Details
- **Programming Language**: C  
- **File Handling**: Data persistence is managed through text files (`database.txt`) to store product information.  
- **Dynamic Options**: Uses a switch-based menu system for streamlined user navigation.  
- **Error Handling**: Prevents duplicate product entries and alerts users when an action cannot be completed.

#### How It Works
1. **Launching the Application**:  
   Users are greeted with a welcome screen and can choose between the customer or administrator mode.

2. **Administrator Access**:  
   Upon successful login, the administrator gains access to various product management features, ensuring efficient inventory control.

3. **Customer Purchases**:  
   Customers can view the store's inventory, select items for purchase, and view the total bill dynamically.

4. **Data Storage**:  
   Product data is saved in `database.txt`, ensuring persistence across sessions.

#### Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/ImtiazStoreManager.git
   ```
2. Compile the code using a C compiler:
   ```bash
   gcc -o store_manager store_manager.c
   ```
3. Run the executable:
   ```bash
   ./store_manager
   ```

#### Future Enhancements
- Implement password hashing for enhanced security in administrator login.
- Introduce a graphical user interface (GUI) for improved usability.
- Add advanced reporting features to track sales and inventory trends.

#### Author
**Muhammad Abubakkar Kaleem**  
BSCS, FAST-NUCES (2018–2022)  
This project was created as part of the **Programming Fundamentals** course to demonstrate basic programming concepts like file handling, structures, and control statements.

Let me know if you'd like further refinements!
