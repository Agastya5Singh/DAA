/*
Huffman coding assigns variable length codewords to fixed length input characters
based on their frequencies/probabilities of occurrence. Given an array of characters
along with their frequency of occurrences. Write a menu driven programming to
perform the following functions.

HUFFMAN CODE GEBERATION MENU

0. Quit
1. Input n unique characters with their frequencies into an array
2. Display the Array
3. Generate Huffman Tree and Traverse the tree with pre-order.
4. Generate Huffman Codes for n characters and display the same.
5. Compare Huffman code with Fixed-Length Code
*/

#include<bits/stdc++.h>
using namespace std;

void menu()
{   
    cout<<"\n#--------------------------------------------------------------------#\n";
    cout<<"\n HUFFMAN CODE GEBERATION MENU \n";
    cout<<"0. Quit \n"; 
    cout<<"1. Input n unique characters with their frequencies into an array \n";
    cout<<"2. Display the Array \n";
    cout<<"3. Generate Huffman Tree and Traverse the tree with pre-order. \n";
    cout<<"4. Generate Huffman Codes for n characters and display the same. \n";
    cout<<"5. Compare Huffman code with Fixed-Length Code \n";
    cout<<"\n#--------------------------------------------------------------------#\n";



}



struct node
{
    char data;
    int freq;
    node *left,*right;
    node(char data,int freq)
    {
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

struct compare
{
    bool operator()(node *l,node *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct node *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << " ";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

//huffman tree min heap


void HuffmanTree(vector<char>data,vector<int>freq,int size)
{
    struct node *left, *right, *top;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new node(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

void HuffmanCodes(vector<char>data, vector<int>freq, int size)
{
    struct node *left, *right, *top;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new node(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

void compareCodes(vector<char>data, vector<int>freq, int size)
{
    struct node *left, *right, *top;
    priority_queue<node*, vector<node*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new node(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}



int main()
{   

    menu();
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;

    vector<int>freq;
    vector<char>ch;

    while(choice!=0)
    {
        switch(choice)
        {
            case 1:
            {
                int n;
                cout<<"Enter the number of characters: \n";
                cin>>n;
                // char ch[n];
                // int freq[n];
                char c;
                cout<<"Enter the characters: \n";
                for(int i=0;i<n;i++)
                {
                    cin>>c;
                    ch.push_back(c);
                }
                int f;
                cout<<"Enter the frequencies: \n";
                for(int i=0;i<n;i++)
                {
                    cin>>f;
                    freq.push_back(f);
                }
                break;
            }
            case 2:
            {   
                cout<<"The array is: \n";
                for(int i=0;i<freq.size();i++)
                {
                    cout<<ch[i]<<" "<<freq[i]<<endl;
                }
                break;
            }
            case 3:
            {   
                cout<<"The Huffman Tree is: \n";
                HuffmanTree(ch,freq,freq.size());
                

                break;
            }
            case 4:
            {   
                cout<<"The Huffman Codes are: \n";
                
                HuffmanCodes(ch,freq,freq.size());
                break;
            }
            case 5:
            {   
                cout<<"The comparison is: ";
                compareCodes(ch,freq,freq.size());

                break;
            }
            default:
            {
                cout<<"Invalid choice";
            }
        }
        menu();
        cout<<"Enter your choice: ";
        cin>>choice;
    }

    return 0;
}