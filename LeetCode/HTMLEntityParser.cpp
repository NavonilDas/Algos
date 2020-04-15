#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    //  ",  < , &gt; > ,&amp; &,&apos; ', &frasl; /
    string entityParser(string text) {
        map<string,string> items;
        items["&quot;"] = "\"";
        items["&lt;"] = "<";
        items["&gt;"] = ">";
        items["&amp;"] = "&";
        items["&apos;"] = "'";
        items["&frasl;"] = "/";
        string ans = "",tmp = "";
        bool started = false;
        int start_index = 0;
        
        for(int i=0;i<text.size();++i){
            char ch = text[i];
            if(ch == '&'){
                tmp += "&";
                started = true;
                start_index = i;
                continue;
            }
            if(started){
                if(tmp.size() > 7){
                    started = false;
                    ans += tmp+ch;
                    tmp = "";
                    continue;
                }
                if(ch == ';'){
                    tmp += ";";
                    if(items.find(tmp) != items.end())
                        ans += items[tmp];
                    else
                        ans += tmp;
                    tmp = "";
                    started = false;
                    continue;
                }
                tmp = tmp + ch;
                continue;
            }
            
            ans += text[i];
        }
        return ans;
    }
};