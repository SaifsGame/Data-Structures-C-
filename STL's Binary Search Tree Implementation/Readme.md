# BST (Set) Implementation in C++ 

A high-performance, template-based **Binary Search Tree (BST)** implementation that mimics the `std::set` interface. This project utilizes a **Sentinel (Dummy Head) Node** architecture to manage tree boundaries and iterator transitions efficiently.

## 🚀 Features

- **Generic Implementation**: Uses C++ Templates to support any data type that implements comparison operators.
- **Sentinel Node Architecture**: A dummy head node acts as a sentinel, simplifying logic for root deletion and `end()` iterator representation.
- **STL-like Interface**: Includes `iterator`, `insert()`, `erase()`, and `find()` methods.
- **Strict Exception Handling**: Prevents duplicate keys by throwing clear, descriptive errors.

---

## 🏗 Architecture Overview

This implementation uses a circular-style Sentinel Node logic:
- `head->parent` points to the actual **Root** of the tree.
- `head->left` points to the **Minimum** element.
- `head->right` points to the **Maximum** element.
- Any "null" child in the tree points back to the `head` node.



---

## 📊 Time Complexity

| Operation | Average Case | Worst Case (Skewed) |
| :--- | :--- | :--- |
| **Insert** | $O(\log n)$ | $O(n)$ |
| **Search** | $O(\log n)$ | $O(n)$ |
| **Delete** | $O(\log n)$ | $O(n)$ |
| **Space** | $O(n)$        | $O(n)$ |

---

## 🛠 Usage Example

```cpp
#include "set.h"
#include <iostream>

int main() {
    set<int> myTree;

    try {
        myTree.insert(50);
        myTree.insert(30);
        myTree.insert(70);
        
        auto it = myTree.find(30);
        if (it != myTree.end()) {
            std::cout << "Found: " << *it << std::endl;
        }

        myTree.erase(it);
        std::cout << "New size: " << myTree.size() << std::endl;

    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}
