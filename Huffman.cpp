#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Node
{
    int weight;
    char c;
    struct Node *left, *right;
};

Node *newNode(char c, int weight)
{
    Node *temp = new Node;
    temp->c = c;
    temp->weight = weight;
    temp->left = temp->right = NULL;
    return (temp);
}
Node *emptyNode(int w)
{
    Node *temp = new Node;
    temp->weight = w;
    temp->left = temp->right = NULL;
    return (temp);
}

void traverse(Node *root)
{
    if (root != NULL)
    {
        traverse(root->left);
        std::cout << root->c << " ";
        traverse(root->right);
    }
    /*     else { 
  
        // Making external nodes 
        root = newNode(-1); 
        std::cout << root->c << " "; 
    }  */
}

Node *MergeTrees(Node * t1, Node * t2) 
{ 
    int w = t1->weight + t2->weight; 
    Node *temp = emptyNode(w);
    if (!t1) 
        return t2; 
    if (!t2) 
        return t1; 
    //t1->weight += t2->weight; 
    t1->left = MergeTrees(t1->left, t2->left); 
    t1->right = MergeTrees(t1->right, t2->right); 
    return t1; 
} 

void printv(std::vector<char> c)
{
    for (auto e : c)
        std::cout << e << " ";
    std::cout << std::endl;
}

void printm(std::map<char, int> m)
{
    for (auto e : m)
        std::cout << e.first << " " << e.second << "\n";
    std::cout << std::endl;
}



int main()
{
    std::string word = "";
    //std::vector<char> data = std::vector<char>();
    std::vector<Node> data = std::vector<Node>();
    std::map<char, int> occurance;

    std::cout << "Please input text to compress:"
              << "\n";
    std::getline(std::cin, word);
    std::cout << "Calculating...."
              << "\n";

    for (int i = 0; i < word.size(); i++)
    {
        //data.push_back(word[i]);
        occurance.insert(std::pair<char, int>(word[i], 0));
    }

    for (int i = 0; i < word.size(); i++)
    {
        //int num = count(data.begin(), data.end(), word[i]);
        int num = count(word.begin(), word.end(), word[i]);
        std::map<char, int>::iterator it = occurance.find(word[i]);
        it->second = num;
    }

    for (auto e : occurance)
    {
        Node* root = newNode(e.first, e.second);
        data.push_back(*newNode(e.first, e.second));
    }

    //printv(data);
    printm(occurance);
    std::cout << word << "\n";

    return 0;
}
