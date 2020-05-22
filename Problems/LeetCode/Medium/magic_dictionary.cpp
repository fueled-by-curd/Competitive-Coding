class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> wrd_dict;
    MagicDictionary() 
    {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) 
    {
        for( string x:dict)
            wrd_dict[x] = 1;
        
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) 
    {
        char tmp;
        for(int i=0;i<word.size();i++)
        {
            tmp = word[i];
            for(int j=0;j<26;j++)
            {
                if( tmp == 'a' + j)
                    continue;
                
                word[i] = (char)('a' + j);
                if(wrd_dict.find(word) != wrd_dict.end() )
                    return true;
            }
            word[i] = tmp;
            
        }
        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
