#include "BinarySearchTree.h"

namespace BST_NS {




template<class T>
BST_NS::BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree &other){
        // copying nodes from other tree
        // making tree size equal to other tree 
        root = hardCopyTree(other.root); 
        tree_size = other.tree_size; 

      }


template<class T>
BinarySearchTree<T>::~BinarySearchTree(){
    // call helper function to delete the tree
    // make root null and size 0
    deleteTree(root); 
    root = nullptr; 
    tree_size = 0;

}
template<class T> 
void BinarySearchTree<T>::deleteTree(TreeNode<T>* node){

    if (node != nullptr){
        // delete left subtree, then right subtree
        deleteTree(node->leftLink);
        deleteTree(node->rightLink);
        delete node; 
    }
}
template<class T>
void BinarySearchTree<T>::makeEmpty(){

    // make size 0 and root null 
    root = nullptr;
    tree_size = 0; 
}

template<class T>
TreeNode<T>* BinarySearchTree<T>:: hardCopyTree(TreeNode<T>* node){

    // if the node is null return null
    if (node == nullptr){
        return nullptr; 
    }
    // otherwise declare node with the data of node ->data 
    // copy the left subtree
    // copy the right subtree
    else {
            TreeNode<T>* newNode = new TreeNode<T>(node -> data, nullptr, nullptr);
            newNode->leftLink = hardCopyTree(node->leftLink);
            newNode->rightLink = hardCopyTree(node->rightLink);
            return newNode;
    }   
}



template<class T>
void BinarySearchTree<T>::insert(T item){

    // initalize item into constructor and create pointers
    TreeNode<T> *tempNode = new TreeNode<T>(item, nullptr, nullptr); 
    TreeNode<T> *current; 
    TreeNode<T> *parent; 

        // if the root is pointing to nothing, point root to item
        if (root == nullptr){
            root = tempNode; 
            tree_size++; 
            return; 
        }
        // else root poiter is not null
        else {
            // set current pointer to root pointer 
            current = root; 
            parent = nullptr; 

            // find position to set the pointer of tempNode 
            while (true){
                parent = current; 

                // item less than data, link left 
                if (item < parent->data){
                    current = current -> leftLink; 

                    if (current == nullptr){
                        parent -> leftLink = tempNode;
                        tree_size++; 
                        return; 
                    }
                }
                // else bigger than data, link right
                else {
                    current = current ->rightLink; 

                    if (current == nullptr){
                        parent -> rightLink = tempNode;
                        tree_size++; 
                        return; 
                    }
                }
            }
        }
        
}


template<class T>
void BinarySearchTree<T>::remove(T item){


    // initalise pointers and boolean to check 
    TreeNode<T>* current = root;
    TreeNode<T>* parent = nullptr;
    bool isLeft = false;


     // look for the node to be removed, if current pointer is not null
        // and data is not the item, keep looping  
    while (current != nullptr && current ->data != item){
        parent = current; 
        
        // if the item is less than the current pointer's data
        // point left, else point right 
        if (item < current->data){
            current = current-> leftLink; 
            isLeft = true; // it is on the left of the tree
        }  
        else {
                current = current ->rightLink;
            isLeft = false; // item on the right, so isLeft false
        }
    
    }

    // couldn't find the item, so current would be null, return
    if (current == nullptr){
        return; 
    }

    // now that current is pointing to the item, check
    // which case it fits into, no children
    // 1 left child, 1 right child, 2 children 


    // case 1: no children 
     if ( current->leftLink == nullptr && current ->rightLink == nullptr){

            // if it's the root make it null 
            if ( current == root){
                root = nullptr; 
            }
            // if it's left of the parent, make it null
            else if (isLeft){
                parent->leftLink = nullptr;
            }
            // else make the parent's right pointer null
            else {
                parent-> rightLink = nullptr; 
            }
            // delete the node pointed to by current, and decrease size and return
            delete current;
            tree_size--;
            return;
     }

     // case2: only a left child
     if (current-> rightLink == nullptr && current->leftLink != nullptr){
            // root has a left child
            if (current == root ){
                root = current->leftLink; 
            }
            // node on the left with only one child
            // make grandparent point to left grandchild
            else if (isLeft){
                parent->leftLink = current->leftLink; 
            }
            // node on the right, but has one left child 
            // make grandparent point to left of their right child
            else {
                parent->rightLink = current->leftLink;
            }
            delete current;
            tree_size--;
            return; 
            
     }

     //case 3: only a right child 
     if (current-> rightLink != nullptr && current->leftLink == nullptr){
            // root has the left child 
             if (current == root ){
                root = current->rightLink; 
            }
            // node on the left has only one right child 
            // make parents left point to it's child's right
            else if (isLeft){
                parent->leftLink = current->rightLink;
            }
            // node is on the right and it has one right child
            // make the grandparent point to child's right pointer
            else {
                parent->rightLink = current->rightLink;
            }
            delete current;
            tree_size--; 
            return;
     }

     //case 4 the node has 2 children

     else {
        // initalize the parent of node to be deleted
        // initalize the right node of the node to be delete
        // because the nodes on the right subtree
        // will qualify as parent of the leftsubtree
        TreeNode<T>* successorParent = current; 
        TreeNode<T>* successor = current->rightLink; 

            // look for smallest possible node on the left of right subtree of current
            // and find it's appropriate parent 
            while(successor-> leftLink !=nullptr){
                successorParent = successor; 
                successor = successor->leftLink; 
            }
            // current-> data now copies the pointed value by successor->data
            current->data = successor->data; 

            // fix successorParent's links 
            // if successor was on the left
            if (successorParent->leftLink == successor) {
                successorParent->leftLink = successor->rightLink;
            } 
            // if successor was on the right 
            else 
            {
                successorParent->rightLink = successor->rightLink;
            }

        // delete the original node that is now copied to current 
        delete successor;
        tree_size--;
        return;
     }
}





template<class T>
bool BinarySearchTree<T>::inTree(T item) const{

        // if the tree is empty throw exception 
    if (tree_size == 0 ){
        throw std::runtime_error("tree is empty");
    }

    TreeNode<T> *current = root; 
    // if the current item pointer does not equal the input, proceed
    while ( current!= nullptr){
        // if item is found return true
        if ( current->data == item){
            return true;
        }
        // if item is less than current pointer's data point left
        if (current -> data > item){
            current = current -> leftLink;
        }
        // else bigger than current pointer's data point right
        else {
            current = current ->rightLink;
        }

    }
    // return false if not found 
    return false; 

}

 template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree other){
        
        // return the same tree if it's copying from itself
        // because it would delete itself otherwise
        if (this!= &other){
            return *this;

        }
        // delete tree to avoid memory leaks
        deleteTree(root); 

        root = hardCopyTree(other.root);
        tree_size = other.tree_size; 
}







template<class T>
void BinarySearchTree<T>::preOrderShow() const{
    // call helper function 
    preOrderHelper(root); 
        
}
template<class T>
void BinarySearchTree<T>::preOrderHelper(TreeNode<T>*node) const{
    if (node != nullptr){
        //preOrder traversal root, left tree, right tree
        std::cout << node -> data <<" "; 
        preOrderHelper(node -> leftLink);
        preOrderHelper(node -> rightLink);
    }
}
template<class T>
void BinarySearchTree<T>::inOrderShow() const{
    // call helper function 
    inOrderHelper(root);
    
}
template<class T>
void BinarySearchTree<T>::inOrderHelper(TreeNode<T>* node)const {
    if ( node != nullptr){
        // inOrdere traversal, left tree, root, right tree
        inOrderHelper(node ->leftLink);
        std::cout << node -> data <<" ";
        inOrderHelper(node ->rightLink);
    }
}



template<class T>
void BinarySearchTree<T>::postOrderShow() const{
    // call helper function 
    postOrderHelper(root); 
}
template<class T>
void BinarySearchTree<T>::postOrderHelper(TreeNode<T>*node) const{
    if ( node != nullptr){
        // postOrder traversal left tree, right tree, root 
        postOrderHelper(node -> leftLink);
        postOrderHelper(node -> rightLink);
        std:: cout << node -> data <<" "; 
    }
}



template<class T>
int BinarySearchTree<T>::size() const{
    // return size private variable
    return tree_size; 
}

template <class T>
int BinarySearchTree<T>::height(){
    // if the tree has less than 2 elements
    // then the tree is height 0
    if (tree_size < 2){
        return 0; 
    }
    // else find how many levels - 1 which
    // is the height 
    else {
    return getHeight(root) - 1; 
    }
}

template <class T>
int BinarySearchTree<T>::getHeight(TreeNode<T>*node) const{
        // check if node input is null
        if (node == nullptr){
            return 0; 
        }
        // recursively call getHeight to find the
        // height of right and left subtrees 
        int leftHeight = getHeight(node->leftLink);
        int rightHeight = getHeight(node->rightLink);
        
        // return the max of the two subtrees 
        return std::max(leftHeight, rightHeight) + 1;

}




} // namespace BST_NS