class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        const int totalWords = words.size()-1;
        for (int begin=0, moreWords=0; begin<=totalWords; begin=moreWords) {
            string currentBlock(maxWidth, ' ');
            
            currentBlock.replace(0, words[begin].size(), words[begin]);
           
            int remainingSpace = maxWidth - words[begin].size();
            for (moreWords=begin+1; moreWords <=totalWords && words[moreWords].size() < remainingSpace; moreWords++) {
               
                remainingSpace -= words[moreWords].size()+1;
            }
            
            int wordJoints = moreWords - begin -1;
            if (wordJoints) {
                
                int evenlyDistributedSpace = 1;
                int unEvenSpace = 0;
                if (moreWords <= totalWords) {
               
                    evenlyDistributedSpace += remainingSpace / wordJoints;
                    unEvenSpace = remainingSpace % wordJoints;
                }
                for (int i=begin+1, index=words[begin].size(); i < moreWords; i++) {
                    index += evenlyDistributedSpace + (unEvenSpace-- > 0);
                    currentBlock.replace(index, words[i].size(), words[i]);
                    index += words[i].size();
                }
            }
            result.push_back(currentBlock);
        }
        return result;
    }
};
