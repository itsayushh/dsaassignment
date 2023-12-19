#include<bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<ll> &v,int low,int mid,int high){
    vector<ll> temp;
    int left = low;
    int right=mid+1;
    while (left<=mid && right<=high)
    {
        if(v[left]<v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        v[i]=temp[i-low];
    }
}

void mergeSort(vector<ll> &v,int low,int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1,high);
    merge(v,low,mid,high);
}


int main(){
    vector<ll> v = {5,51,3,10,21,9,1};
    mergeSort(v,0,v.size()-1);
    for(auto it:v) cout<<it<<" ";
}