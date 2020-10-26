#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
// Question 1 reverse an integer array. 
// 'reverseArrayDemo' is the main function. 
// 'reverse' is the helper function. 
void Q1_helper1(vector<int> &arr)
{
    //for reversing the array.
    int n=arr.size();
    for(int i=0;i<n/2;i++)
    {
        swap(arr[i],arr[n-i-1]);
    }
}
void Q1_main()
{
    //For taking user inputs.
    int n;
    cout<<"Enter no. of elements in array: \n";
    cin>>n;
    vector<int> arr;
    cout<<"Start entering array elements \n";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);   
    }
    Q1_helper1(arr);
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
/*
Question 2 : Find the max and min element in an integer array.
'max_min_Demo' is the main function.
*/
void Q2_main()
{
    int n,max_val,min_val;
    cout<<"Enter no. of elements in array: \n";
    cin>>n;
    vector<int> arr;
    if(n>0)
    {
        cout<<"Start entering array elements \n";
        for(int i=0;i<n;i++)
        {
        int x;
        cin>>x;
        arr.push_back(x);   
        }
        min_val=arr[0];
        max_val=arr[0];
        for(int i:arr)
        {
            if(i>max_val) max_val=i;
            if(i<min_val) min_val=i;
        }
        cout<<"Max value: "<<max_val<<endl<<"Min value: "<<min_val<<endl;
    }
    else
    {
        cout<<"Array is empty! \n";
    }
}
/*
Question 3: Kth max/ Kth min element in an integer array.
This question uses heaps. A min heap is used to find the Kth max element and a max heap for a Kth min element.
Heaps have been implemented using C++ standard template library.
*/
int Q3_helper1(vector<int> arr,int k)
{
    //Finding the kth min element in an array.
    priority_queue<int> pq;
    int n=arr.size();
    if(n<=k) return -1;
    for(int i:arr)
    {
        pq.push(i);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
int Q3_helper2(vector<int> arr,int k)
{
    //Finding the kth max element of the array.
    priority_queue<int,vector<int>,greater<int>> pq;
    int n=arr.size();
    if(n<=k) return -1;
    for(int i:arr)
    {
        pq.push(i);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
void Q3_main()
{
    int n;
    cout<<"Enter no. of elements in array: \n";
    cin>>n;
    vector<int> arr;
    cout<<"Start entering array elements \n";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);   
    }
   int k;
   cout<<"Enter value of k";
   cin>>k;
   cout<<"The kth min element is :"<<Q3_helper1(arr,k)<<endl<<"The kth max element is: "<<Q3_helper2(arr,k)<<endl;
}
int main()
{
   Q3_main();
}