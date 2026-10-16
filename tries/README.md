# 🌳 Trie Data Structure (Prefix Tree)

A **Trie** (pronounced "try," derived from **retrieval**) is a tree-like data structure used to store a dynamic set of strings. It is also known as a **Prefix Tree** because the path from the root to any node represents a prefix of one or more words stored in the structure.

---

## ✨ Core Concepts

* **Tree-like Structure:** The trie organizes strings to allow for efficient prefix-based operations.
* **Node Representation:** Each node in the trie typically represents a **single character** of a string sequence.
* **Root Node:** The root node always represents an **empty string**.
* **Path as Prefix:** The path from the root to any node represents a **prefix** of a stored string (e.g., 'a', 'ap', 'app').
* **Efficient Retrieval:** The structure is excellent for **efficient retrieval of a key** from a large dataset of strings.

### 🏗️ TrieNode Structure

A basic `TrieNode` contains pointers to its children and a flag to mark the end of a word.

| Field | Description |
| :--- | :--- |
| `children` | An array (e.g., size 26 for 'a' through 'z') or a map to store pointers to the next `TrieNode`s, indexed by the character they represent. |
| `endOfWord` | A **Boolean flag** used to mark the end of a complete word in the trie. |

```cpp
class TrieNode {
public:
    // Using a map for sparse character sets or an array for fixed alphabets
    unordered_map<char, TrieNode*> children; 
    bool endOfWord = false; // Flag to denote the end of a word
    int freq; // if we're finding prefix of the given words
};
``` 

### ⚙️ Basic Operations and Time Complexity
The major operations are highly `efficient`. The time complexity depends only on the **length of the word** (*L*) being processed, not the total number of words (*N*) in the trie.  

| Operation | Description | Time Complexity ($L$ = Key Length) |
| :--- | :--- | :--- |
| **1. Insertion** | Insert a new word into the trie. | $O(L)$ |
| **2. Search** | Search for a complete word. | $O(L)$ |
| **3. Deletion** | Remove a word from the trie. | $O(L)$ |
| **4. StartsWith** | Check for a word that starts with a given prefix. | $O(L)$ |  

### ➕ 1. Insertion Operation (O(L))  
Insertion involves traversing the trie character-by-character and creating new nodes where paths do not yet exist.  

**Algorithm Steps:**  
1. **Start at Root:** Initialize a temporary pointer (`temp`) to the `root` node.
2. **Run Loop:** Iterate through each character (`key[i]`) of the word.  
3. **Check/Add Child:** Check if a child node for the current character exists in `temp->children`. 
    - **If Not Exists:** Create a **new** `TrieNode`, link it as the child for the character, and move `temp` to this new node.
    - **If Exists:** Simply move `temp` to the existing child node.
4. **Mark End:** Once the loop is complete, set `temp->endOfWord = true` to mark the end of the inserted word.  

### 🔍 2. Search Operation (O(L))  
Search validates the existence of a word by following its path from the root.  

**Algorithm Steps:**  
1. **Start at Root:** Initialize a temporary pointer (`temp`) to the root node.
2. **Run Loop:** Iterate through each character (`key[i]`) of the word.  
3. **Check Existiance:** Check if a child node for the current character exists in `temp->children`. 
    - **If Not Exists:** The word does not exist. `Return` false.
    - **If Exists:** Move `temp` to the next node
4. **Mark End:** After the loop, return `temp->endOfWord`. The word is only found if the entire path exists AND the last node is marked as the end of a word.  
```cpp
bool search(string key) {
    Node *temp = root;
    for (char ch : key) {
        if (temp->children.find(ch) == temp->children.end()) {
            return false;
        }
        temp = temp->children[ch];
    }
    
    return temp->eof;
}
```  

### 🗑️ 3. Deletion Operation (Advanced)  
Deletion is typically implemented recursively to handle the removal of unnecessary nodes while preserving shared prefixes.  

**Deletion Principle:**  
The key is to remove nodes only if they are no longer part of **any other** stored word.  
-   If the final node has children or marks the prefix of another word, only set `endOfWord = false`.
-   If the final node has no children and is not a prefix of other words, the node and any unique preceding nodes in the path can be safely deleted/removed while backtracking.  

### 🌍 Applications of Tries  
Tries are invaluable for high-speed string and prefix matching in real-world systems.  

-   **⚡ Auto-Complete / Search Suggestions:** Implementing auto-complete features in search bars and text editors.
-   **📚 Dictionaries & Spell Checkers:** Efficiently storing large dictionaries and quickly verifying word existence.  
-   **🌐 IP Routing Tables:** Used in networking (specifically **Radix Tries**) for efficient **Longest Prefix Match** lookups for routing packets.
-   **📂 Search Engine Indexing:** Used by search engines to index web pages by keywords for quick retrieval.
-   **📞 Contact/Directory Search:** Enabling fast, prefix-based searching for contacts in phone applications.  

