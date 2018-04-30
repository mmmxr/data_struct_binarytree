#pragma once 
#include <stddef.h>

typedef char TreeNodeType;

typedef struct TreeNode{
    TreeNodeType data;
    struct TreeNode* rchild;
    struct TreeNode* lchild;
}TreeNode;


void TreeInit(TreeNode** root); 

void PreOrder(TreeNode* root); 

void InOrder(TreeNode* root); 

void PostOrder(TreeNode* root); 

void LevelOrder(TreeNode* root); 

TreeNode* TreeCreate(TreeNodeType array[],size_t size ,size_t* index, TreeNodeType null_node);

void TreeDestroy(TreeNode* root); 

TreeNode* TreeClone(TreeNode* root); 

size_t TreeHeight(TreeNode* root); 

size_t TreeLeafSize(TreeNode* root); 

size_t TreeKLevelSize(TreeNode* root, int K); 

size_t TreeSize(TreeNode* root); 

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find); 

TreeNode* LChild(TreeNode* node); 

TreeNode* RChild(TreeNode* node); 

TreeNode* Parent(TreeNode* root, TreeNode* node); 

void PreOrderByLoop(TreeNode* root); 

void InOrderByLoop(TreeNode* root); 

void PostOrderByLoop(TreeNode* root); 

void TreeMirror(TreeNode* root); 

int IsCompleteTree(TreeNode* root); 
