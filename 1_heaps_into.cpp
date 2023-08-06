#include <bits/stdc++.h>

using namespace std;

class heap
{
public:
    vector<int> v1;

    heap()
    {
        v1.push_back(0);
    }

    void insert(int data)
    {
        v1.push_back(data);
        int mc = v1.size() - 1;

        while (mc > 1)
        {
            if (v1[mc / 2] < v1[mc]) //parent is less than child then swap that parent & child
            {
                swap(v1[mc / 2], v1[mc]);
                mc = mc / 2;
            }
            else
            {
                return;
            }
        }

        return;
    }

    void print_karo()
    {
        for (int i = 1; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
    }

    void delete_karo()
    {
        if(v1.size()==1)
        {
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        else
        {
            //swap last and root element
            swap(v1[1],v1[v1.size()-1]);
            v1.pop_back();
            // now take root node to its correct position

            int i=1;
            while(i<=v1.size()-1)
            {
                int left_child=v1[2*i];
                int right_child=v1[(2*i)+1];
                
                if(2*i<v1.size() && v1[2*i]>=v1[i] && v1[2*i]>v1[(2*i)+1])
                {
                    swap(v1[2*i],v1[i]);
                    i=2*i;
                }
                else if( (i*2)+1<v1.size() && v1[(2*i)+1]>=v1[i] && v1[(2*i)+1]>v1[2*i])
                {
                    swap(right_child,v1[i]);
                    i=(i*2)+1;
                }
                else //when left & right child are both less than or equal to 
                {
                    return;
                }
            }
            return;
        }
    }
};

int main()
{
    heap *h1 = new heap();
    h1->insert(50);
    h1->insert(55);
    h1->insert(53);
    h1->insert(52);
    h1->insert(54);

    h1->print_karo();

    h1->delete_karo();

    h1->print_karo();
    return 0;
}