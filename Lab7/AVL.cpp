//
//  AVL.cpp
//  Lab6
//
//  Created by Haley Dennis on 5/15/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//
#include "AVL.h"
#include "Node.h"
#include <iostream>

using namespace std;

NodeInterface * AVL::getRootNode() const
{
    return root;
}

//add recursively calls insert
bool AVL::add(int item)
{
    if (find(item))
    {
        return false;
    }
    return insert(this->root, item);
}

bool AVL::insert(Node*& local_root, int item)
{
    bool check = false;
    if (local_root == NULL)
    {
        local_root = new Node(item);
        check = true;
	}
    else
    {
        if (item < local_root->item)
        {
            check = insert(local_root->left, item);
        }
        else if (local_root->item < item)
        {
            check = insert(local_root->right, item);
        }
    }
	if (check == true)
	{
        balance(local_root);
		return check;
	}
	else
	{
		return false;
	}
}

//erase recursively calls erase
bool AVL::remove(int item)
{
    if (find(item) != true)
    {
        return false;
    }
    return erase(this->root, item);
}

bool AVL::erase(Node*& local_root,int item)
{
    bool check = false;
    if (local_root == NULL)
    {
        check = false;
    }
    else
    {
        if (item < local_root->item)
        {
            check = erase(local_root->left, item);
        }
        else if (item > local_root->item)
        {
            check = erase(local_root->right, item);
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
                delete local_root;
                local_root = NULL;
                check = true;
            }
            //2. if local root has a left subtree and local root no right subtree
            //Then: the top of the left subtree replaces local root
            else if (local_root->left != NULL && local_root->right == NULL)
            {
                local_root = local_root->left;
                delete old_root;
                old_root = NULL;
                check = true;
            }
            //3. if local root has no left subtree and has a right subtree with no left
            //Then: the top of the right subtree replaces local root
            else if (local_root->right != NULL && local_root->left == NULL)
            {
                local_root = local_root->right;
                delete old_root;
                old_root = NULL;
                check = true;
            }
            //4. if local root has a left subtree with a right
            //Then: the right-most of the left subtree replaces the local root
            else// (local_root->left != NULL && local_root->right != NULL)
            {
                old_root = local_root->left;
                while(old_root->right != NULL)
                {
                    old_root = old_root->right;
                }
                local_root->item = old_root->item;
                erase(local_root->left, old_root->item);
                check = true;
            }
        }
    }
	if (check == true)
	{
		balance(local_root);
		return check;
	}
	else
	{
		//If there is no node to remove it will get here
		return false;
	}
}

void AVL::clear()
{
    while (root != NULL)
    {
        remove(root->item);
    }
}

bool AVL::find(int item)
{
    return search(this->root, item);
}

bool AVL::search(Node*& local_root, int target)
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

void AVL::rotateLeft(Node*& n)
{
    Node* temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n = temp;
}

void AVL::rotateRight(Node*& n)
{
    Node* temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n = temp;
}

void AVL::balance(Node*& n)
{
	int leftBalance = 0;
	int rightBalance = 0;
	signed int balance = 0;
	
    if (n == NULL)
    {
        leftBalance = 0;
        rightBalance = 0;
    }
    if (n != NULL)
    {
        if (n->right == NULL)
        {
            rightBalance = 0;
        }
        else
        {
            rightBalance = n->right->getHeight();
        }
        if (n->left == NULL)
        {
            leftBalance = 0;
        }
        else
        {
            leftBalance = n->left->getHeight();
        }
        /*if (n->left != NULL && n->right != NULL)
        {
            leftBalance = n->left->getHeight();
            rightBalance = n->right->getHeight();
        }*/
    }
    
	balance = leftBalance - rightBalance;
	
	if (balance < -1)
	{
		balToLeft(n);
	}
	else if (balance > 1)
	{
		balToRight(n);
	}
	else
	{
		//it is balanced
	}
}

void AVL::balToLeft(Node*& n)
{
    if (n->right->right == NULL)
    {
        rotateRight(n->right);
    }
    if (n->right->left == NULL)
    {
        //do nothing
    }
    //Right-Left Imbalance
    else if (n->right->right->getHeight() < n->right->left->getHeight())
    {
        rotateRight(n->right);
    }
    //Right-Right Imbalance
    rotateLeft(n);
}

void AVL::balToRight(Node*& n)
{
    if (n->left->left == NULL)
    {
        rotateLeft(n->left);
    }
    if (n->left->right == NULL)
    {
        //do nothing
    }
    //Left-Right Imbalance
    else if (n->left->left->getHeight() < n->left->right->getHeight())
    {
        rotateLeft(n->left);
    }
    //Left-Left Imbalance
    rotateRight(n);
}
