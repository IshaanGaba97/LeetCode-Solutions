class Solution {
private:
    string findLine(int i, int j, int eachSlot, int extraSlots, vector<string>& words, int maxWidth){
        string s = "";
        for(int k = i; k < j; k++){
            s += words[k];
            if(k == j - 1) continue;
            for(int space = 1; space <= eachSlot; space++){
                s += " ";
            }
            if(extraSlots > 0){
                s += " ";
                extraSlots--;
            }
        }
        while(s.size() < maxWidth){
            s += " ";
        }
        return s;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int i = 0;
        while(i < n){
            int lettersCount = words[i].size();
            int spaceCount = 0;
            int j = i + 1;
            while(j < n && words[j].size() + 1 + lettersCount + spaceCount <= maxWidth){
                lettersCount += words[j].size();
                spaceCount++;
                j++;
            }
            int remainingSlots = maxWidth - lettersCount;
            int eachSlot = spaceCount == 0 ? 0 : remainingSlots / spaceCount;
            int extraSlots = spaceCount == 0 ? 0 : remainingSlots % spaceCount;

            if(j == n){
                eachSlot = 1;
                extraSlots = 0;
            }

            res.push_back(findLine(i, j, eachSlot, extraSlots, words, maxWidth));
            i = j;
        }
        return res;
    }
};