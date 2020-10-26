#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include<unordered_map>
using namespace std;
void inputArray(int &n, vector<int> &arr)
{
    cout << "Enter no. of elements in array: \n";
    cin >> n;
    if (n > 0)
    {
        cout << "Start entering array elements \n";
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }
    else 
    {
        cout<<"Array is empty\n";
    }
}
// Question 1 reverse an integer array.
// 'reverseArrayDemo' is the main function.
// 'reverse' is the helper function.
void Q1_helper1(vector<int> &arr)
{
    //for reversing the array.
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
}
void Q1_main()
{
    //For taking user inputs.
    int n;
    vector<int> arr;
    inputArray(n, arr);
    Q1_helper1(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
/*
Question 2 : Find the max and min element in an integer array.
'max_min_Demo' is the main function.
*/
void Q2_main()
{
    int n, max_val, min_val;
    vector<int> arr;
    inputArray(n, arr);
    if (n > 0)
    {
        min_val = arr[0];
        max_val = arr[0];
        for (int i : arr)
        {
            if (i > max_val)
                max_val = i;
            if (i < min_val)
                min_val = i;
        }
        cout << "Max value: " << max_val << endl
             << "Min value: " << min_val << endl;
    }
    else
    {
        cout << "Array is empty! \n";
    }
}
/*
Question 3: Kth max/ Kth min element in an integer array.
This question uses heaps. A min heap is used to find the Kth max element and a max heap for a Kth min element.
Heaps have been implemented using C++ standard template library.
*/
int Q3_helper1(vector<int> arr, int k)
{
    //Finding the kth min element in an array.
    priority_queue<int> pq;
    int n = arr.size();
    if (n <= k)
        return -1;
    for (int i : arr)
    {
        pq.push(i);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
int Q3_helper2(vector<int> arr, int k)
{
    //Finding the kth max element of the array.
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    if (n <= k)
        return -1;
    for (int i : arr)
    {
        pq.push(i);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
void Q3_main()
{
    int n;
    vector<int> arr;
   inputArray(n, arr);
    int k;
    cout << "Enter value of k";
    cin >> k;
    cout << "The kth min element is :" << Q3_helper1(arr, k) << endl
         << "The kth max element is: " << Q3_helper2(arr, k) << endl;
}
/*
Question 4: Sort an array of 0,1 and 2 without using any sorting algo.
*/
vector<int> Q4_helper1(vector<int> arr)
{
    //This function sorts an array of 0,1 and 2 without using any sorting algo.
    int zero = 0, one = 0, two = 0;
    vector<int> result;
    int n = arr.size();
    if (n == 0)
        return result;
    for (int i : arr)
    {
        if (i == 0)
            zero++;
        if (i == 1)
            one++;
        if (i == 2)
            two++;
    }
    while (zero--)
        result.push_back(0);
    while (one--)
        result.push_back(1);
    while (two--)
        result.push_back(2);
    return result;
}
void Q4_main()
{
    int n;
    vector<int> arr;
    inputArray(n, arr);
    vector<int> ans = Q4_helper1(arr);
    cout << "The sorted array is: \n";
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
/*
Question 5: Given an integer array move all negative numbers to left and positive numbers to the right. Order not important.
*/
void Q5_main()
{
    int n;
    vector<int> arr;
    inputArray(n, arr);
    if(n<=0) return;
    int left=0,right=arr.size()-1;
    while(left<right)
    {
        while(arr[left]<0&&left<right)
        {
            left++;
        } 
        if(left<right)
        {
            if(arr[right]<0)
            {
                swap(arr[left++],arr[right]);
            }
            right--;
        }
    }
    for(int i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
/*
Question 6: Given 2 arrays find its union and intersection.
This implementation uses a hashmap
*/
vector<int> Q6_helper1(vector<int> arr1,vector<int> arr2)
{
    //This function finds union of arr1 and arr2
    vector<int> result;
    int n=arr1.size(),m=arr2.size();
    if(n==0&&m==0) return result;
    unordered_map<int,int> hash;
    for(int i:arr1)
    {
        hash[i]++;
    }
    for(int i:arr2)
    {
        hash[i]++;
    }
    for(auto itr:hash)
    {
        result.push_back(itr.first);
    }
    return result;
}
vector<int> Q6_helper2(vector<int> arr1,vector<int> arr2)
{
    //This function finds the intersection of arr1 and arr2
    vector<int> result;
    int n=arr1.size(),m=arr2.size();
    if(n==0&&m==0) return result;
    unordered_map<int,int> hash;
    for(int i:arr1)
    {
        hash[i]++;
    }
    for(int i:arr2)
    {
        if(hash.find(i)!=hash.end()) result.push_back(i);
    }
    return result;
}
void Q6_main()
{
    int n,m;
    vector<int> arr1,arr2;
    inputArray(n,arr1);
    inputArray(m,arr2);
    vector<int> uni,intersect;
    uni=Q6_helper1(arr1,arr2);
    intersect=Q6_helper2(arr1,arr2);
    cout<<"Union of the given arays: \n";
    for(int i:uni)
    {
        cout<<i<<" ";
    }
    cout<<endl<<"Intersection of given arrays: \n";
    for(int i:intersect)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    Q6_main();
}