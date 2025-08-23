# Tree Data Structure  

A **tree** is a collection of `nodes` and `edges` and one of the node is selected as _**root node**_ and rest all the nodes are divided into disjoint subsets and each subset is a tree or sub-tree .  

![Tree Terminology](../assets/root_terminology.png)

### Terminology Of A Tree  

1   ***root***  : _The topmost node of the tree_ . 

-   _e.g `A` in the above tree_ .

2   ***parent*** : A parent node is a node in which one or more than one node is connected to it . 

-   _e.g `B` is the parent of node `E` and node `F`_

3   ***child*** : A child node is a node that is directly connected to another node, which is called it's parent .

-   _e.g node `E` is the child of `B` ._

4   ***siblings*** : _The siblings are the direct child of a parent node, or in other word the sibling node share same parent node_ . 

-   _e.g node `E` and node `F` are the siblings and both have same parent node `B`_ .

5   ***descendant*** : _A descendant of a node is any node that can be reached by repeatedly moving from a parent to a child . This include the node's children, it's grand-children or it's great grand-childrens_ . 

-   _e.g Descendant of `B` is [`N`, `J`, `K`, `F`]_ .

6   ***ancestors*** : _An ancestor of a node is any node on the path from that node to the root_ . 

-   _e.g from node `O` to root `A`, path = [`O`, `L`, `H`, `D`, `A`]_ .

7   ***degree of node*** : _Number of direct children of a node_ . 

-   _e.g deg(`B`) = 2, because node `B` having two direct children & deg(`D`) = 3, because node `D` having 3 direct children_ .

8   ***external node / leaf node*** : _All the node which have 0 nodes, means the last generation_ . 

-   _e.g nodes `E`, `N`, `K`, `C`, `G`, `O`, `P`, `M` & `I` are the leaf node or external node bacause they don't have any child or they are not parent_ .

9   ***internal node / non-leaf node*** : _A node which have one or more than one childre_ .

-   _e.g nodes `B`, `F`, `J` `L`, `H` & `D` are the internal node, because all the nodes have either one children node or more than one or in other word, they are the parent of one or more than one children_ .

10   ***levels*** : _The level of a node is nothing but it's distance from the root . The level concept is very closely related to depth of a node_ .

-   _e.g_
-   The **root node** is at **Level 0**.
-   The children of the root are at **Level 1**.
-   Their children are at **Level 2**, and so on.

11   ***height*** : _The height is the length of the **longest path** from the **root node** to a **leaf node**. It represent the overall tallness of the tree ._ 

-   **Height Of A Node :** The height of a specific node is the length of the longest path from that node down to a leaf node in its subtree.

-   **Height of a Tree:** The height of the entire tree is the height of its root node.

12   ***forest*** : **The collection of sub-trees are nothing but a forest.**