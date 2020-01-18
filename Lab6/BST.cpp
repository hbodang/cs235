//
//  BST.cpp
//  Lab6
//
//  Created by Haley Dennis on 5/15/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//
#include "BST.h"

using namespace std;


NodeInterface * BST::getRootNode() const
{
    return root;
}

//add recursively calls insert
bool BST::add(int item)
{
    if (find(item))
    {
        return false;
    }
    return insert(this->root, item);
}

bool BST::insert(Node*& local_root, int item)
{
    if (local_root == NULL)
    {
        local_root = new Node(item);
        return true;
    }
    else
    {
        if (item < local_root->item)
        {
            return insert(local_root->left, item);
        }

        else if (local_root->item < item)
        {
            return insert(local_root->right, item);
        }
        else
        {
            return false;
        }
    }
}

//erase recursively calls erase
bool BST::remove(int item)
{
    return erase(this->root, item);
}

bool BST::erase(Node*& local_root,int item)
{
    if (local_root == NULL)
    {
        return false;
    }
    else
    {
        if (item < local_root->item)
        {
            return erase(local_root->left, item);
        }
        else if (item > local_root->item)
        {
            return erase(local_root->right, item);
        }
        // Found item: local_root is equal to item we want to delete
        else
        {
            Node* old_root = local_root;
            //Base Cases
            //1. If local root has no children
            //Then: just delete the local root
            if (local_root->left == NULL && local_root->right == NULL)
            {
                //cout << "deleting leaf: " << local_root->item <<endl;
                delete local_root;
                local_root = NULL;
                return true;
            }
            //2. if local root has a left subtree and local root no right subtree
            //Then: the top of the left subtree replaces local root
            else if (local_root->left != NULL && local_root->right == NULL)
            {
                //cout << "deleting left subtree: " << local_root->item <<endl;
                local_root = local_root->left;
                delete old_root;
                old_root = NULL;
                return true;
            }
            //3. if local root has no left subtree and has a right subtree with no left
            //Then: the top of the right subtree replaces local root
            //else if (local_root-> left == NULL && local_root->right != NULL)
            
            else if (local_root->right != NULL && local_root->left == NULL)
            {
                //cout << "deleting right subtree: " << local_root->item <<endl;
                local_root = local_root->right;
                delete old_root;
                old_root = NULL;
                return true;
            }
            //4. if local root has a left subtree with a right
            //Then: the right-most of the left subtree replaces the local root
            else// (local_root->left != NULL && local_root->right != NULL)
            {
                //cout << "deleting something: " << local_root->item <<endl;
                old_root = local_root->left;
                //cout << "local_root: " << local_root->item <<endl;
                while(old_root->right != NULL)
                {
                    old_root = old_root->right;
                }
                //cout << "old_root after while statement: " << old_root->item <<endl;
                local_root->item = old_root->item;
                //remove(old_root->item);
                erase(local_root->left, old_root->item);
                return true;
            }
            //return true;
        }
    }
}

void BST::clear()
{
    while (root != NULL)
    {
        remove(root->item);
    }
}

bool BST::find(int item)
{
    return search(this->root, item);
}

bool BST::search(Node*& local_root, int target)
{
    if (local_root == NULL)
        return false;
    if (target < local_root->item)
        return search(local_root->left, target);
    else if (local_root->item < target)
        return search(local_root->right, target);
    //found item
    else
        return true;
}

