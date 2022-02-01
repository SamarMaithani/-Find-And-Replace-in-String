class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int j=0;
        map<int, pair<string, string>> maps;
        for(int i=0;i<indices.size();i++)
        {
            maps[indices[i]]=make_pair(sources[i], targets[i]);
        }
        
        for(auto itr=maps.begin();itr!=maps.end();itr++)
        {
            int i=itr->first+j;
            int l=(itr->second).first.size();
            string sub=s.substr(i,l);
            if(sub==(itr->second).first)
            {
                s.replace(i,l,(itr->second).second);
                j+=(itr->second).second.size()-l;
            }
        }
        return s;
    }
};
