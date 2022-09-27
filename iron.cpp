
#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

int startRange(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end()) 
    {
        int index = it - v.begin();
       return index;
    }
    else {
       return -1;
    }
}

int endRange(vector<int> v, int K){

    auto last_max = max_element(rbegin(v), rend(v));
    auto last = distance(begin(v), last_max.base());
   return last;
}


int max_vector(vector<int> &a){
    return *max_element(a.begin(), a.end());
}

void addNumber(vector<int> &start,vector<int> &v){
    int max = max_vector(v);
    start[v[0]]+=max;
    start[v[1]-1]+=max;
}

vector <int> findTheRange(int n,vector<int> &v1,vector<int> &v2,vector<int> &v3){
    vector <int> start(n,0);
    vector <int> result;
    addNumber(start,v1);
    addNumber(start,v2);
    addNumber(start,v3);
    int max = max_vector(start);
    int s_range = startRange(start,max);
    int e_range = endRange(start,max);
    result.push_back(s_range);
    result.push_back(e_range);
    result.push_back(max);
    return result;
}
