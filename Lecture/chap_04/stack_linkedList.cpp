struct Node
{
    string data;
    Node *next;
};

Node *top_node = nullptr;

void push(string item)
{
    Node *p = new Node;
    p->data = item;
    p->next = top_node;
    top_node = p;
}

void pop()
{
    if (empty())
        throw runtime_exception("stack empty");
    Node *tmp = top_node;
    top_node = top_node->next;
    delete tmp;
}

string top()
{
    if (empty())
        throw runtime_exception("stack empty");
    return top_node->data;
}
bool empty()
{
    return top_node == nullptr;
}