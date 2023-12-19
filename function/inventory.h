
#ifndef INVENTORY_H
#define INVENTORY_H

#include "database.h"
#include <limits>
#include <string>
#include "../modules/structures.h"
class Inventory
{

private:

public:
    Database<InventoryItem> inventoryDatabase; // Menggunakan Database dengan template InventoryData
    void readAll();
    void readOne();
    void addInventory();
    void updateInventory();
    void deleteInventory();
    Inventory(const std::string& name);
};

#include "inventory.cpp"
#endif // INVENTORY_H