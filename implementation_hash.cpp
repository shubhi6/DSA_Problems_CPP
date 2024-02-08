#include <iostream>
#include <list> // Include the <list> header for using std::list
using namespace std;

struct myhash {
    int BUCKET;
    list<int>* table;

    myhash(int b) {
        BUCKET = b;
        table = new list<int>[b];
    }

    void insert(int key) {
        int i = key % BUCKET;
        table[i].push_back(key);
    }

    bool search(int key) {
    int i = key % BUCKET;
    for (std::list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
        if (*it == key)
            return true;
    }
    return false;
}



    void remove(int key) {
        int i = key % BUCKET;
        table[i].remove(key);
    }
};

int main() {
    myhash hashTable(7); // Create a hash table with 7 buckets

    // Insert some keys
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(15);
    hashTable.insert(7);

    // Search for keys
    cout << "Search 20: " << (hashTable.search(20) ? "Found" : "Not Found") << endl;
    cout << "Search 15: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (hashTable.search(25) ? "Found" : "Not Found") << endl;

    // Remove a key
    hashTable.remove(15);

    // Search again after removal
    cout << "Search 15 after removal: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}

