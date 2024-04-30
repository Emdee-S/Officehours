#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "stdexcept"






int main(){

     BST_NS::BinarySearchTree<int> tree;
   /* std::cout << "Inserting 5 3 7 2 4 6 8" << std::endl;
    // Insert some values into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);


    std::cout << "preOrder: " << std::endl;
    // Print the tree using pre-order traversal
    tree.preOrderShow();
    std::cout << std::endl;

     std::cout << "inOrder: " << std::endl;
    // Print the tree using in-order traversal
    tree.inOrderShow();
    std::cout << std::endl;

    // Print the tree using post-order traversal
     std::cout << "postOrder: " << std::endl;
    tree.postOrderShow();
    std::cout << std::endl;

    // Print the size of the tree
    std::cout << "Size of the tree: " << tree.size() << std::endl;

    // Print the height of the tree
    std::cout << "Height of the tree: " << tree.height() << std::endl;


    // Test the inTree() function
    bool found = tree.inTree(5);
    std::cout << "5 is in the tree: " << (found ? "true" : "false") << std::endl;

    found = tree.inTree(1);
    std::cout << "1 is in the tree: " << (found ? "true" : "false") << std::endl;

    found = tree.inTree(9);
    std::cout << "9 is in the tree: " << (found ? "true" : "false") << std::endl;
    

    tree.makeEmpty(); 
     std::cout << "tree emptied: " << std::endl;
     std::cout << "inOrder: " << std::endl;
     tree.inOrderShow();
    std::cout << std::endl;
    // Print the size of the tree
    std::cout << "Size of the tree: " << tree.size() << std::endl;

    // Print the height of the tree
    std::cout << "Height of the tree: " << tree.height() << std::endl;


    std::cout << "Inserting 10 6 14 5 8 7 9 12 15 11 13 2" << std::endl;
    // Insert some values into the tree
    tree.insert(10);
    tree.insert(6);
    tree.insert(14);
    tree.insert(5);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    tree.insert(12);
    tree.insert(15);
    tree.insert(11);
    tree.insert(13);
    tree.insert(2); 

    std::cout << "inOrder: " << std::endl;
    // Print the tree using in-order traversal
    tree.inOrderShow();
    std::cout << std::endl;
    // Print the size of the tree
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;

    std::cout <<" " <<std::endl;





    std::cout <<"No children: Removing 2, 9, 13 " <<std::endl;
    tree.remove(2);
    tree.remove(9);
    tree.remove(13); 

    std::cout << "preOrder: " << std::endl;
    tree.preOrderShow();
    std::cout << std::endl;
     std::cout << "inOrder: " << std::endl;
    tree.inOrderShow();
    std::cout << std::endl;
     std::cout << "postOrder: " << std::endl;
    tree.postOrderShow();
    std::cout << std::endl;
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;

    tree.insert(2);
    tree.insert(9);
    tree.insert(13);


    std::cout <<"one left child: Removing 5" <<std::endl;
    
    tree.remove(5);

    std::cout << "preOrder: " << std::endl;
    tree.preOrderShow();
    std::cout << std::endl;
     std::cout << "inOrder: " << std::endl;
    tree.inOrderShow();
    std::cout << std::endl;
     std::cout << "postOrder: " << std::endl;
    tree.postOrderShow();
    std::cout << std::endl;
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;
    

    std::cout <<"one right child: Removing 9" <<std::endl;
    tree.remove(9); 

    std::cout << "preOrder: " << std::endl;
    tree.preOrderShow();
    std::cout << std::endl;
     std::cout << "inOrder: " << std::endl;
    tree.inOrderShow();
    std::cout << std::endl;
     std::cout << "postOrder: " << std::endl;
    tree.postOrderShow();
    std::cout << std::endl;
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;


    std::cout <<"two children child: Removing 14" <<std::endl;

    tree.remove(14); 

    std::cout << "preOrder: " << std::endl;
    tree.preOrderShow();
    std::cout << std::endl;
     std::cout << "inOrder: " << std::endl;
    tree.inOrderShow();
    std::cout << std::endl;
     std::cout << "postOrder: " << std::endl;
    tree.postOrderShow();
    std::cout << std::endl;
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;

    std::cout <<"Removing 12, 11" <<std::endl;

    tree.remove(12);
    tree.remove(11); 

    std::cout << "preOrder: " << std::endl;
    tree.preOrderShow();
    std::cout << std::endl;
     std::cout << "inOrder: " << std::endl;
    tree.inOrderShow();
    std::cout << std::endl;
     std::cout << "postOrder: " << std::endl;
    tree.postOrderShow();
    std::cout << std::endl;
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;

    std::cout <<"Removing 7: " <<std::endl;
    tree.remove(7); 
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;
    std::cout <<"Removing 2,8: " <<std::endl;
    tree.remove(2); 
    tree.remove(8); 
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;
    std::cout <<"Removing 13: " <<std::endl;
    tree.remove(13); 
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;
    std::cout <<"Removing 10: " <<std::endl;
    tree.remove(10); 
    std::cout << "Size of the tree: " << tree.size() << std::endl;
    std::cout << "Height of the tree: " << tree.height() << std::endl;
    */



    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);
    tree.insert(9);
    tree.insert(1);
    tree.insert(10);
    tree.insert(7);



    BST_NS::BinarySearchTree<int> otherTree(tree);
    
    otherTree.inOrderShow(); 

    std::cout << "Size of the tree: " << otherTree.size() << std::endl;
    std::cout << "Height of the tree: " << otherTree.height() << std::endl;
    otherTree.insert(90); 
    otherTree.insert(13); 
    otherTree.insert(40); 

    otherTree.inOrderShow(); 
    
    std::cout << "Size of the tree: " << otherTree.size() << std::endl;
    std::cout << "Height of the tree: " << otherTree.height() << std::endl;

return 0; 


}