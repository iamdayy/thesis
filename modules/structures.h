// structures.h
#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <cstring>

const int MAX_NAME_LENGTH = 50; // Panjang maksimum nama item

struct User
{
    int id;
    char username[20];
    char password[20];
    char dbName[20];

    void displayUserInfo() const
    {
        std::cout << "Username : " << username << "\n";
    }
};

struct InventoryItem
{
    int id;
    char title[20];
    int quantity;
    char category[20];

    // Fungsi untuk menampilkan informasi item inventaris
    void displayItemInfo() const
    {
        std::cout << "Item: " << title << "\n"
                  << "Quantity: " << quantity << "\n"
                  << "Category: " << category << "\n"
                  << "Id: " << id << "\n"
                  << "==============================\n";
    }
};

// Tambahkan definisi struktur lainnya jika diperlukan

#endif // STRUCTURES_H
