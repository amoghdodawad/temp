#include <iostream>
#include <vector>
#include<algorithm>
#include<string>

using namespace std;

void buildLPSTable(string pattern, vector<int>& lps){
    int n = pattern.size();
    lps[0] = 0;
    int i = 1, len = 0;
    while(i < n){
        if(pattern[i] == pattern[len]) lps[i++] = ++len;
        else {
            if(len != 0) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
}

vector<int> search(string text, string pattern, vector<int>& lps){
    int n = text.size(), m = lps.size();
    int i = 0, j = 0;
    vector<int> locations;
    while(i < n){
        if(text[i] == pattern[j]) {
            ++j;
            ++i;
            if(j == m) {
                locations.push_back(i-j);
                j = 0;
            }
        } else {
            if(j > 0) j = lps[j-1];
            else ++i;
        }
        
    }
    return locations;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;
    int n = text.length(), m = pattern.length();
    vector<int> lps(m,0);
    buildLPSTable(pattern, lps);
    vector<int> matchIndexes = search(text,pattern,lps);
    if(matchIndexes.size() == 0){
        cout << "No match found" << endl;
    } else {
        for(int i = 0; i < matchIndexes.size(); ++i){
            cout << "Match index has been found at location " << matchIndexes[i] << " " << endl;
        }
    }
}