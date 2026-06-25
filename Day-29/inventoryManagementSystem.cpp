#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

//function prototypes
void addProduct(vector<Product>& inventory);
void displayInventory(const vector<Product>& inventory);
void updateProduct(vector<Product>& inventory);
void deleteProduct(vector<Product>& inventory);

int main() {
    vector<Product> inventory;
    int choice;

    do {
        cout << "Inventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Delete Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                updateProduct(inventory);
                break;
            case 4:
                deleteProduct(inventory);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

void addProduct(vector<Product>& inventory) {
    Product newProduct;
    cout << "Enter Product ID: ";
    cin >> newProduct.id;
    cout << "Enter Product Name: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, newProduct.name);
    cout << "Enter Quantity: ";
    cin >> newProduct.quantity;
    cout << "Enter Price: ";
    cin >> newProduct.price;

    inventory.push_back(newProduct);
    cout << "Product added successfully!" << endl;
}

void displayInventory(const vector<Product>& inventory) {
    cout << "Inventory:" << endl;
    for (const auto& product : inventory) {
        cout << "ID: " << product.id << ", Name: " << product.name
             << ", Quantity: " << product.quantity << ", Price: $" << product.price << endl;
    }
}

void updateProduct(vector<Product>& inventory) {
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;

    for (auto& product : inventory) {
        if (product.id == id) {
            cout << "Enter new Product Name: ";
            cin.ignore(); // To ignore the newline character left in the buffer
            getline(cin, product.name);
            cout << "Enter new Quantity: ";
            cin >> product.quantity;
            cout << "Enter new Price: ";
            cin >> product.price;
            cout << "Product updated successfully!" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

void deleteProduct(vector<Product>& inventory) {
    int id;
    cout << "Enter Product ID to delete: ";
    cin >> id;

    auto it = find_if(inventory.begin(), inventory.end(), [id](const Product& p) {
        return p.id == id;
    });

    if (it != inventory.end()) {
        inventory.erase(it);
        cout << "Product deleted successfully!" << endl;
    } else {
        cout << "Product not found!" << endl;
    }
}