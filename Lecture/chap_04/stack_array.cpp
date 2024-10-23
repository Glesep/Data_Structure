char mystack[MAX_CAPACITY];
int top_pos = -1;
bool full()
{
    return top_pos == MAX_CAPACITY - 1;
}
bool empty()
{
    return top_pos == -1;
}
void push(char c)
{
    if (full())
        throw runtime_error("stack_full");      // exception
    mystack[++top_pos] = c;
}
void pop()
{
    if (empty())
        throw runtime_error("stack_empty");
    top_pos--;
}
char top()
{
    if (empty())
        throw runtime_error("stack_empty");
    return mystack[top_pos];
}