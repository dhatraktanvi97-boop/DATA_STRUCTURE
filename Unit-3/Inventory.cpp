#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

const int TABLE_SIZE = 10;

// Product Node
struct Product {
    int productID;
    string productName;
    float price;
    int quantity;
    Product* next;
};

// Hash Table Node
struct HashNode {
    Product* product;
    HashNode* next;
};

class ProductCatalog {
private:
    Product* head;
    HashNode* hashTable[TABLE_SIZE];

    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

    void insertIntoHashTable(Product* p) {
        int index = hashFunction(p->productID);

        HashNode* newNode = new HashNode;
        newNode->product = p;
        newNode->next = hashTable[index];

        hashTable[index] = newNode;
    }

    Product* searchByID(int id) {
        int index = hashFunction(id);
        HashNode* temp = hashTable[index];

        while (temp != nullptr) {
            if (temp->product->productID == id) {
                return temp->product;
            }
            temp = temp->next;
        }

        return nullptr;
    }

public:
    ProductCatalog() {
        head = nullptr;

        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }

    // Add Product
    void addProduct() {
        Product* newProduct = new Product;

        cout << "\nEnter Product ID: ";
        cin >> newProduct->productID;

        if (searchByID(newProduct->productID) != nullptr) {
            cout << "Product ID already exists!\n";
            delete newProduct;
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Product Name: ";
        getline(cin, newProduct->productName);

        cout << "Enter Price: ";
        cin >> newProduct->price;

        cout << "Enter Quantity: ";
        cin >> newProduct->quantity;

        if (newProduct->productID <= 0 ||
            newProduct->price < 0 ||
            newProduct->quantity < 0) {
            cout << "Invalid product details!\n";
            delete newProduct;
            return;
        }

        newProduct->next = head;
        head = newProduct;

        insertIntoHashTable(newProduct);

        cout << "\nProduct added successfully!\n";
    }

    // Update Product
    void updateProduct() {
        int id;

        cout << "\nEnter Product ID to update: ";
        cin >> id;

        Product* temp = searchByID(id);

        if (temp == nullptr) {
            cout << "Product not found!\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter New Product Name: ";
        getline(cin, temp->productName);

        cout << "Enter New Price: ";
        cin >> temp->price;

        cout << "Enter New Quantity: ";
        cin >> temp->quantity;

        if (temp->price < 0 || temp->quantity < 0) {
            cout << "Invalid details! Update rejected.\n";
            return;
        }

        cout << "\nProduct updated successfully!\n";
    }

    // Display All Products
    void displayProducts() {
        if (head == nullptr) {
            cout << "\nNo products available!\n";
            return;
        }

        Product* temp = head;

        cout << "\n========== PRODUCT CATALOG ==========\n";

        cout << left << setw(12) << "Product ID"
             << setw(22) << "Product Name"
             << setw(12) << "Price"
             << setw(10) << "Quantity" << endl;

        cout << "--------------------------------------------------------\n";

        while (temp != nullptr) {
            cout << left << setw(12) << temp->productID
                 << setw(22) << temp->productName
                 << setw(12) << fixed << setprecision(2) << temp->price
                 << setw(10) << temp->quantity << endl;

            temp = temp->next;
        }
    }

    // Search Product
    void searchProduct() {
        int id;

        cout << "\nEnter Product ID to search: ";
        cin >> id;

        Product* temp = searchByID(id);

        if (temp == nullptr) {
            cout << "Product not found!\n";
        }
        else {
            cout << "\nProduct Found!\n";
            cout << "Product ID: " << temp->productID << endl;
            cout << "Product Name: " << temp->productName << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Quantity: " << temp->quantity << endl;
        }
    }

    // Destructor
    ~ProductCatalog() {
        Product* temp = head;

        while (temp != nullptr) {
            Product* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* current = hashTable[i];

            while (current != nullptr) {
                HashNode* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
    }
};

// Main Function
int main() {
    ProductCatalog catalog;
    int choice;

    do {
        cout << "\n\n===== E-COMMERCE PRODUCT CATALOG =====\n";
        cout << "1. Add New Product\n";
        cout << "2. Update Product Details\n";
        cout << "3. Display All Products\n";
        cout << "4. Search Product by ID\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                catalog.addProduct();
                break;

            case 2:
                catalog.updateProduct();
                break;

            case 3:
                catalog.displayProducts();
                break;

            case 4:
                catalog.searchProduct();
                break;

            case 5:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
