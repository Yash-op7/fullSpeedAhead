int maxXOR(int n)
{
    Node *node = root;
    if (node == nullptr)
    {
        return -1;
    }
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int needed = !((n >> i) & 1);
        if (node->links[needed] != nullptr)
        {
            ans = ans | (1 << i);
            node = node->links[needed];
        }
        else
            node = node->links[!needed];
    }
    return ans;
}