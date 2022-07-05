//先序遍历
void RootFirst(CSNode *root)
{
    if(root != NULL)
    {
        Visit(root->data);
        RootFirst(root->first_child;
        RootFirst(root->next_bro);
    }
}
                  
//后序遍历
void RootLast(CSNode *root)
{
    if(root != NULL)
    {
        RootLast(root->first_child);
        Visit(root->data);
        RootLast(root->next_bro);
    }
}
                  
//层次遍历
void LevelOrder(CSNode *root)
{
    CSNode *p = NULL;
    PushQueue(Q, root);
    while (!IsEmptyQueue(Q))
    {
        p = PopQueue(Q);
        Visit(p->data);
        p = p->first_child;
        while (p != NULL)
        {
            PushQueue(Q, p);
            p = p->next_bro;
        }
    }
}  