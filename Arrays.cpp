#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n/2;i++)
    {
        swap(arr[i],arr[n-i-1]);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);   
    }
    reverse(arr);
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}