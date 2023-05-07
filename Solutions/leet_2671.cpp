#include "bits/stdc++.h"

class FrequencyTracker {
public:
    map<int, int> hash;
    map<int, set<int>> freq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        freq[hash[number]].erase(number);
        hash[number]++;
        freq[hash[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if(hash.count(number)) {
          freq[hash[number]].erase(number);
          hash[number]--;
          if(hash[number] == 0) hash.erase(number);
          else freq[hash[number]].insert(number);
        }
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency].size() > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  return 0;
}