#include<bits/stdc++.h>
class LRUCache
{
    list<int>dq;
    map<int,pair<int,list<int>::iterator>>mpp;
    int sizee=0;
    
public:
    void recent(int key){
        dq.erase(mpp[key].second);
        dq.push_front(key);
        mpp[key].second=dq.begin();
    }
    
    LRUCache(int capacity) {sizee=capacity;}
    
    
    int get(int key){
       if(mpp.find(key)!=mpp.end()) 
       {
           recent(key);
           return mpp[key].first;
       }
      return -1;
    }


    void put(int key, int value)
    {
        if(mpp.find(key)==mpp.end()){
            dq.push_front(key);
            mpp[key]={value,dq.begin()};
            sizee--;
        }
        else{
            recent(key);
            mpp[key].first=value;
        }
        if(sizee<0){
            mpp.erase(dq.back());
            dq.pop_back();
            sizee++;
        }
    }
};