/**
 * bst function body
 * @version 0.1
 * @author forsilence
 */

# include"bst.h"
# include<stdlib.h>
# include<stdio.h>
# include<stddef.h> // define NULL

bst_t init_bst()
{
    bst_t T;
    T.root=NULL;
    return T;
}

bool bst_insert(bst_t *T,data_type data)
{
    bst_node *father=NULL;
    bst_node *cur_node=NULL;
    if (!T->root)//empty
    {
        cur_node=malloc(sizeof(bst_node));
        T->root = cur_node;
    }else//not empty
    {
        bst_node *temp = T->root;
        while (temp!=NULL)//find father node
        {
            father=temp;
            if (temp->data==data)
            {
                printf("data exist (bst_insert)\n");
                return false;
            }
            if (temp->data > data) temp = temp->lc;
            else temp = temp->rc;
        }
        // 分配内存
        cur_node=malloc(sizeof(bst_node));
        // 将分配的节点付给子节点
        if (data < father->data) father->lc = cur_node;
        else father->rc = cur_node;
    }
    // 分配内存失败
    if (!cur_node)
        return false;
    // 分配成功 并 将节点加入树中
    cur_node->data=data;
    cur_node->lc=NULL;
    cur_node->rc=NULL;
    // 是否是根节点
    if (cur_node==T->root)cur_node->father=NULL;
    else cur_node->father=father;
    return true;
}

// 中序遍历
void tree_walk(bst_t *T)
{
    if (T->root)
        m_walk(T->root);
    else printf("empty! (tree_walk)\n");
    printf("\n");
}

void m_walk(bst_node *node)
{
    if (node->lc) m_walk(node->lc);
    printf("%d ",node->data);
    if (node->rc) m_walk(node->rc);
}

// 查找
bst_node *bst_search(bst_t *T,data_type data)
{
    bst_node *temp = T->root;
    while(temp)
    {
        if (temp->data == data ) break;
        else if (temp->data > data) temp=temp->lc;
        else temp=temp->rc;
    }
    return temp;
}

// 删除
bool bst_remove(bst_t *T,data_type data)
{
    bst_node *cur_node = bst_search(T,data);
    if (!cur_node) return false;
    bst_node *replace_node = bst_minimum(cur_node);
    bst_transplant(T,replace_node,replace_node->rc);
    cur_node->data=replace_node->data;
    free(replace_node);
    return true;
}

// 用u代替v
void  bst_transplant(bst_t *T,bst_node *v,bst_node *u)
{
    if (v->father==NULL)
        T->root=u;
    else if (v->father->lc==v)
        v->father->lc=u;
    else v->father->rc=u;
    if (u) u->father=v->father; 
}

// 根节点下最小值点
bst_node *bst_minimum(bst_node *root)
{
    bst_node *temp=root;
    while(temp && temp->lc)
        temp=temp->lc;
    return temp;
}

// 根节点下最大值点
bst_node *bst_maximum(bst_node *root)
{
    bst_node *temp=root;
    while( temp && temp->rc )
        temp=temp->rc;
    return temp;
}