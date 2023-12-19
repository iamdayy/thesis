#include "auth.h"

using namespace std;

Auth::Auth() : userDatabase("auth"), inventoryData("")
{
    inventoryData.inventoryDatabase.deleteDatabase();
}

bool Auth::login()
{
    string username, password;

    cout << "=======Login========" << endl;
    cout << "====================" << endl;
    cout << "Username : " << endl;
    cin >> username;
    cout << "Password : " << endl;
    cin >> password;

    User readUser;
    bool access;
    string message;
    // Implementasi logika login menggunakan Database
    int dataSize = userDatabase.getDataSize();
    // checking user exists
    for (int i = 1; i <= dataSize; i++)
    {
        readUser = userDatabase.readData(i);
        if (readUser.username != username)
        {
            message = "Username not found";
            access = false;
        }
        else if (readUser.password != password)
        {
            message = "Password not match";
            access = false;
        }
        else
        {
            message = "Welcome back " + username;
            user = readUser;
            inventoryData = Inventory(user.dbName);
            // inventoryData.inventoryDatabase.deleteDatabase();
            access = true;
            break;
        }
    }

    cout << message << endl;
    return access;
}

bool Auth::registerUser()
{
    bool access;
    User userRead, inputUser;
    cout << "======Register======" << endl;
    cout << "====================" << endl;
    cout << "Username : " << endl;
    cin.getline(inputUser.username, 20);
    cout << "Password : " << endl;
    cin.getline(inputUser.password, 20);

    strcpy(inputUser.dbName, inputUser.username);
    strcat(inputUser.dbName, "_inventory");
    int last = userDatabase.getDataSize() + 1;
    inputUser.id = last;
    if (!checkUserExists(inputUser.username))
    {
        userDatabase.writeData(last, inputUser);
    }
    else
    {
        cout << "Username " << inputUser.username << " is found, logged in...." << endl;
    }

    access = login();

    return access;
}

bool Auth::checkUserExists(const std::string &username)
{

    User readUser;
    bool exists;
    // Implementasi logika login menggunakan Database
    int dataSize = userDatabase.getDataSize();
    if (dataSize != 0)
    {
        for (int i = 1; i <= dataSize; i++)
        {
            readUser = userDatabase.readData(i);
            if (readUser.username == username)
            {
                exists = true;
                break;
            }
            else
            {
                exists = false;
            }
        }
    }
    return exists;
}