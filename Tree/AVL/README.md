# AVL Trees  

AVL Trees are the height balance binary search trees, means it balance the height of a binary search tree.  
AVL trees are balanced using balance factor .  

_for every node we are calculating the height_  
_Balance factor of a node always belong to {-1, 0 1}, It cannot be more then that, if any node having balance factor > 1 or < -1, means that, node is unbalanced ._  

_And for balancing that node we are performing rotations. There are four types of rotations in AVL Trees ._ 
-   **_LL Rotation_**
-   **_LR Rotation_**
-   **_RR Rotation_**
-   **_RL Rotation_**  

**_Note_** : For calculating the balance factor there is a simple formula : 
-   **balance_factor =** $height_left - height_right$ ∈ `{-1, 0, 1}`
-   if balance_factor = |height_left - height_right| <= 1 && >= -1 means that `Node is balance` . 
-   if balance_factor = |height_left - height_right| > 1 means that `Node is unballanced` .  

**_Note_** : Balance factor of a node cannot be more that > 2 or < -2 . The balance factor always lies between -2 to 2 and the rotation always berform between three nodes only, no matter, how big the tree is . If there is 10000 nodes, still the rotation is performing betwee three nodes .  


