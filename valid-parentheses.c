char pair(char ch)
{
    if(ch == '(') return ')';
    if(ch == '{') return '}';
    if(ch == '[') return ']';
    return 0;
}
typedef struct 
{
    char data[5000];
    int top;
}Stack;
void initStack(Stack* stack)
{
    stack->top = -1;
}
void push(Stack* stack, char ch)
{
    if(stack->top == 4999)
    {
        return;
    }
    stack->data[++stack->top] = ch;
}
char pop(Stack* stack)
{
    if(stack->top == -1)
        return -1;
    return stack->data[stack->top--];
}
bool isValid(char* s) {
    int length = strlen(s);
    if(length % 2 == 1)
        return false;
    Stack stack; 
    initStack(&stack);
    for(int i = 0; i < length; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(&stack, s[i]);
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if(pair(pop(&stack)) != s[i])
            {
                return false;
            }
        }
    }
    return stack.top == -1;
}
