
#ifndef AUTH_H
#define AUTH_H

#include "database.h"
#include "inventory.h"
#include "../modules/structures.h"
class Auth
{

private:
    Database<User> userDatabase; // Menggunakan Database dengan template UserData
    bool checkUserExists(const std::string &username);

public:
    Inventory inventoryData;
    User user;
    bool login();
    bool registerUser();
    Auth();
};

#include "auth.cpp"
#endif // AUTH_H
