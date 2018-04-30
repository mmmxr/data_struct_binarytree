#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"
#include "seqqueue.h"
#define TEST_HEADER printf("\n===================%s====================\n",__FUNCTION__)
TreeNode* CreatNode(TreeNodeType value)
{
    TreeNode* new_node=(TreeNode* )malloc(sizeof(TreeNode));
    new_node->data=value;
    new_node->lchild=NULL;
    new_node->rchild=NULL;
    return new_node;
}

void TreeDestroyNode(TreeNode**  root)
{
    if(root==NULL)
    {
        return;
    }
    free(*root);
    *root=NULL;
}

void TreeInit(TreeNode** root)
{
    if(root==NULL)
    {
        return;
    }
    *root=NULL;
}
void PreOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    //先访问根节点
    printf("%c ",root->data);
    //在递归的访问左子树
    PreOrder(root->lchild);
    //在递归的访问右子树
    PreOrder(root->rchild);
}
void InOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    //在递归的访问左子树
    InOrder(root->lchild);
    //先访问根节点
    printf("%c ",root->data);
    //在递归的访问右子树
    InOrder(root->rchild);
}
void PostOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    //在递归的访问左子树
    PostOrder(root->lchild);
    //在递归的访问右子树
    PostOrder(root->rchild);
    //先访问根节点
    printf("%c ",root->data);

}
void LevelOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    SeqQueue q;
    SeqQueueInit(&q);
    SeqQueuePush(&q,root);
    while(1)
    {
        SeqQueType front;
        int ret=SeqQueueTop(&q,&front);
        if(ret==0)
        {
            break;
        }
        //打印当前值
        printf("%c ",front->data);
        //出队列当前队首元素
        SeqQueuePop(&q);
        //分别入队列左右子树
        if(front->lchild!=NULL)
        {
            SeqQueuePush(&q,front->lchild);
        }
        if(front->rchild!=NULL)
        {
            SeqQueuePush(&q,front->rchild);
        }
    }
}
TreeNode* TreeCreate(TreeNodeType array[], size_t* index, TreeNodeType null_node)
{
    if(array==NULL||index==NULL)
    {
        return NULL;
    }
    TreeNode* root=NULL;
    if(array[*index]!=null_node)
    {
        root=CreatNode(array[*index]);
        ++(*index);
        root->lchild=TreeCreate(array,index,null_node);
        ++(*index);
        root->rchild=TreeCreate(array,index,null_node);
    }
    return root; 
}
void TreeDestroy(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    TreeDestroy(root->lchild);
    TreeDestroy(root->rchild);
    TreeDestroyNode(&root);
}
TreeNode* TreeClone(TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    TreeNode* dst=CreatNode(root->data);
    dst->data=root->data;
    dst->lchild=TreeClone(root->lchild);
    dst->rchild=TreeClone(root->rchild);
    return dst;

}
size_t TreeHeight(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(TreeHeight(root->lchild)>TreeHeight(root->rchild))
    {
        return TreeHeight(root->lchild)+1;
    }
    if(TreeHeight(root->lchild)<=TreeHeight(root->rchild))
    {
        return TreeHeight(root->rchild)+1;
    }
    return 0;
}
size_t TreeLeafSize(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->lchild==NULL&&root->rchild==NULL)
    {
        return 1;
    }
    return TreeLeafSize(root->lchild)+TreeLeafSize(root->rchild);
}
size_t TreeKLevelSize(TreeNode* root, int K)
{
    if(root==NULL||K<1)
    {
        return 0;
    }
    if(K==1)
    {
        return 1;
    }
    return TreeKLevelSize(root->lchild,K-1)+TreeKLevelSize(root->rchild,K-1);

}
size_t TreeSize(TreeNode* root)
{
    if(root==NULL)
    {
        return 0; 
    }
    return TreeSize(root->lchild)+TreeSize(root->rchild)+1;
}

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(to_find==root->data)
    {
        return root;
    }
    TreeNode* ret1 = TreeFind(root->lchild,to_find);
    TreeNode* ret2 = TreeFind(root->rchild,to_find);
    return ret1 != NULL ? ret1 : ret2;
}
TreeNode* LChild(TreeNode* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    return node->lchild;
}
TreeNode* RChild(TreeNode* node)
{
    if(node==NULL)
    {
        return NULL;
    }
    return node->rchild;
}
TreeNode* Parent(TreeNode* root, TreeNode* node)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->lchild==node||root->rchild==node)
    {
        return root;
    }
    TreeNode* lresult=Parent(root->lchild,node);
    TreeNode* rresult=Parent(root->rchild,node);

    return lresult!=NULL?lresult:rresult;
}
/////////////////////////////////////////////
//以下是测试函数
/////////////////////////////////////////////
void TestInit()
{
    TEST_HEADER;
    TreeNode* a; 
    TreeInit(&a);
}
void TestPreOrder()
{
    TEST_HEADER;
    TreeNode* root;
    root = CreatNode('a');
    TreeNode* b = CreatNode('b');
    TreeNode* c = CreatNode('c');
    TreeNode* d = CreatNode('d');
    TreeNode* e = CreatNode('e');
    TreeNode* f = CreatNode('f');
    TreeNode* g = CreatNode('g');
    root->lchild=b;
    b->lchild=d;
    b->rchild=e;
    e->lchild=g;
    root->rchild=c;
    c->rchild=f;

    PreOrder(root);
    printf("\n");
}
void TestInOrder()
{
    TEST_HEADER;
    TreeNode* root;
    root = CreatNode('a');
    TreeNode* b = CreatNode('b');
    TreeNode* c = CreatNode('c');
    TreeNode* d = CreatNode('d');
    TreeNode* e = CreatNode('e');
    TreeNode* f = CreatNode('f');
    TreeNode* g = CreatNode('g');
    root->lchild=b;
    b->lchild=d;
    b->rchild=e;
    e->lchild=g;
    root->rchild=c;
    c->rchild=f;

    InOrder(root);
    printf("\n");
}
void TestPostOrder()
{
    TEST_HEADER;
    TreeNode* root;
    root = CreatNode('a');
    TreeNode* b = CreatNode('b');
    TreeNode* c = CreatNode('c');
    TreeNode* d = CreatNode('d');
    TreeNode* e = CreatNode('e');
    TreeNode* f = CreatNode('f');
    TreeNode* g = CreatNode('g');
    root->lchild=b;
    b->lchild=d;
    b->rchild=e;
    e->lchild=g;
    root->rchild=c;
    c->rchild=f;

    PostOrder(root);
    printf("\n");
}
void TestLevelOrder()
{
    TEST_HEADER;
    TreeNode* root;
    root = CreatNode('a');
    TreeNode* b = CreatNode('b');
    TreeNode* c = CreatNode('c');
    TreeNode* d = CreatNode('d');
    TreeNode* e = CreatNode('e');
    TreeNode* f = CreatNode('f');
    TreeNode* g = CreatNode('g');
    root->lchild=b;
    b->lchild=d;
    b->rchild=e;
    e->lchild=g;
    root->rchild=c;
    c->rchild=f;

    LevelOrder(root);
    printf("\n");
}
void TestTreeCreate()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    PreOrder(root);
    printf("\n");
}
void TestTreeClone()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* src=TreeCreate(arr,&index,'#');
    TreeNode* dst=TreeClone(src);
    PreOrder(dst);
    printf("\n");
}
void TestTreeHeight()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    size_t size=TreeHeight(root);
    printf("size expext is 4,actual %lu\n",size);

}
void TestTreeLeafSize()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    size_t size=TreeLeafSize(root);
    printf("size expext is 3,actual %lu\n",size);

}
void TestTreeSize()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    size_t size=TreeSize(root);
    printf("size expext is 7,actual %lu\n",size);

}
void TestTreeKlevelSize()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    size_t size=TreeKLevelSize(root,1);
    printf("size expext is 1,actual %lu\n",size);
    size=TreeKLevelSize(root,3);
    printf("size expext is 3,actual %lu\n",size);
}
void TestTreeDestroy()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    TreeDestroy(root);
    printf("root expect NULL,actual %p\n",root);
    printf("root data  expect NULL,actual %c\n",root->data);

}
void TestTreeFind()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    TreeNode* ret=TreeFind(root,'b');
    printf("ret expect %p,actual %p\n",root->lchild,ret);
    ret=TreeFind(root,'x');
    printf("ret expect NULL,actual %p\n",ret);

}
void TestTreeLChild()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    TreeNode* ret=LChild(root->lchild);
    printf("ret expect d,actual %c\n",ret->data);

}
void TestTreeRChild()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    TreeNode* ret=RChild(root->lchild);
    printf("ret expect e,actual %c\n",ret->data);

}
void TestTreeParent()
{
    TEST_HEADER;
    TreeNodeType arr[]="abd##eg###c#f##";
    size_t index=0;
    TreeNode* root=TreeCreate(arr,&index,'#');
    TreeNode* ret=Parent(root,root->lchild->lchild);
    printf("ret expect b,actual %c\n",ret->data);

}
int main()
{
    TestInit();
    TestPreOrder();
    TestInOrder();
    TestPostOrder();
    TestLevelOrder();
    TestTreeCreate();
    TestTreeClone();
    TestTreeHeight();
    TestTreeLeafSize();
    TestTreeSize();
    TestTreeKlevelSize();
    TestTreeDestroy();
    TestTreeFind();
    TestTreeLChild();
    TestTreeRChild();
    TestTreeParent();
    
}
