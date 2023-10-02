class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob = 0;
        int len = colors.length();
        for(int i=1;i<len-1;i++){
            if(colors[i] == 'A' && colors[i-1] == colors[i+1] && colors[i-1] == 'A'){
                alice++;
            }
            else if(colors[i] == 'B'&& colors[i-1] == colors[i+1] && colors[i-1] == 'B'){
                bob++;
            }
        }
        if(bob >= alice){
            return false;
        }
        return true;
    }
};