#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *build_tree(Node *root)
{
    cout << "enter data" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data for left of " << data << endl;
    root->left = build_tree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = build_tree(root->right);
    return root;
}

Node * createParentMapping (Node * root,int target,map<Node * , Node *> &nodeToParentMapping) // does both, finding the parent node as well as finding the target node
{
    Node * targetNode=NULL;

    queue<Node *> q1;
    q1.push(root);
    nodeToParentMapping[root]=NULL;

    while(! q1.empty())
    {
        Node * frontNode=q1.front();
        q1.pop();

        if(frontNode->data==target)
        {
            targetNode=frontNode;
        }

        if(frontNode->left)
        {
            nodeToParentMapping[frontNode->left]=frontNode;
            q1.push(frontNode->left);
        }
        if(frontNode->right)
        {
            nodeToParentMapping[frontNode->right]=frontNode;
            q1.push(frontNode->right);
        }
    }

    return targetNode;
}

int burnTree(Node * targetNode, map<Node *,Node *> nodeToParentMapping,int &totalTime)
{
    map<Node *,bool> visited;
    queue<Node *> q1;

    q1.push(targetNode);
    visited[targetNode]=true;

    int answer=0;

    while(! q1.empty())
    {
        bool flag=false;

        int size=q1.size();
        for(int i=0;i<size;i++)
        {
            //process neighbouring nodes
            Node * frontNode=q1.front();
            q1.pop();

            if(frontNode->left && !visited[frontNode->left])
            {
                flag=true;
                q1.push(frontNode->left);
                visited[frontNode->left]=true;
            }
            if(frontNode->right && !visited[frontNode->right])
            {
                flag=true;
                q1.push(frontNode->right);
                visited[frontNode->right]=true;
            }
            if(nodeToParentMapping[frontNode] && !visited[nodeToParentMapping[frontNode]])
            {
                flag=true;
                q1.push(nodeToParentMapping[frontNode]);
                visited[nodeToParentMapping[frontNode]]=true;
            }
        }
        if(flag==true)
        {
            answer++;
        }
    }

    return answer;
}

int minTime(Node * root,int target)
{
    
    map<Node *,Node *> nodeToParentMapping;
    Node * targetNode = createParentMapping(root,target,nodeToParentMapping);

    int totalTime=burnTree(targetNode,nodeToParentMapping,totalTime);

    return totalTime;
}

int main()
{
    vector<int>v1;
    
    return 0;
}