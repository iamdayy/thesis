#include "inventory.h"
using namespace std;

Inventory::Inventory(const string &name) : inventoryDatabase(name)
{
}

void Inventory::readAll()
{
    InventoryItem item;
    int size = inventoryDatabase.getDataSize();
    if (size == 0)
    {
        cout << "No Data" << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= size; i++)
        {
            item = inventoryDatabase.readData(i);
            cout << "Item ke-" << i << endl;
            cout << "======================\n";
            item.displayItemInfo();
        }
    }
}

void Inventory::addInventory()
{
    InventoryItem inputInventory;

    int last = inventoryDatabase.getDataSize() + 1;
    inputInventory.id = last;

    cout << "Masukan nama item : " << endl;
    cin.getline(inputInventory.title, 20);
    cout << "Masukan banyak item : " << endl;
    cin >> inputInventory.quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan Kategori barang : " << endl;
    cin.getline(inputInventory.category, 20);

    inventoryDatabase.writeData(last, inputInventory);
}

void Inventory::readOne()
{
    InventoryItem item;
    string search;
    cout << "Masukan nama item yang akan di cari : " << endl;
    cin >> search;
    int size = inventoryDatabase.getDataSize();
    cout << "===============================\n";
    if (size == 0)
    {
        cout << "No Data" << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= size; i++)
        {
            item = inventoryDatabase.readData(i);
            if (item.title == search)
            {
                item.displayItemInfo();
                break;
            }
            if (i == size)
            {

                cout << "No Data" << endl;
                return;
            }
        }
    }
}

void Inventory::deleteInventory()
{
    int id, size;
    char is_continue;
    string name;
    InventoryItem Item;
    cout << "Masukan nama item yang ingin di hapus : ";
    cin >> name;
    size = inventoryDatabase.getDataSize();
    for (int i = 1; i <= size; i++)
    {
        Item = inventoryDatabase.readData(i);
        if (Item.title == name)
        {
            id = Item.id;
            break;
        }
    }
    cout << "Yakin ingin menghapus item ini : " << endl;
    Item.displayItemInfo();
    cout << "[y/n] : " << endl;
    cin >> is_continue;
label_confirm:
    if (is_continue == 'y' | is_continue == 'Y')
    {
        inventoryDatabase.deleteData(id);
    }
    else if (is_continue == 'n' | is_continue == 'N')
    {
        return;
    }
    else
    {
        goto label_confirm;
    }
}

void Inventory::updateInventory()
{
    int id, size;
    char is_continue;
    string name;
    InventoryItem Item, ItemToUpdate;
    cout << "Masukan nama item yang ingin di ubah : ";
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    size = inventoryDatabase.getDataSize();
    for (int i = 1; i <= size; i++)
    {
        Item = inventoryDatabase.readData(i);
        if (Item.title == name)
        {
            id = Item.id;
            Item.displayItemInfo();
            break;
        }
    }
    ItemToUpdate = inventoryDatabase.readData(id);

    cout << "===========================\n"
         << "Masukan nama baru : \n";
    cin.getline(ItemToUpdate.title, 20);
    cout << "Masukan banyak baru : \n";
    cin >> ItemToUpdate.quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukan kategori baru : \n";
    cin.getline(ItemToUpdate.category, 20);
    cout << "Yakin ingin mengubah item ini : " << endl;
    ItemToUpdate.displayItemInfo();
    cout << "[y/n] : " << endl;
    cin >> is_continue;
label_confirm:
    if (is_continue == 'y' | is_continue == 'Y')
    {
        inventoryDatabase.writeData(id, ItemToUpdate);
    }
    else if (is_continue == 'n' | is_continue == 'N')
    {
        return;
    }
    else
    {
        goto label_confirm;
    }
}