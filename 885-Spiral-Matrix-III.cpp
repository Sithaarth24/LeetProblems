class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstrt,
                                        int cstrt) {
        int c = 1;
        vector<vector<int>> res;
        while(c < 2*rows || c < 2* cols) {
            if (c % 2) {
                if(rstrt >=0 && rstrt< rows){
                    for(int i = cstrt;i<cstrt+c;i++)
                        if(i >=0 && i<cols)
                            res.push_back({rstrt,i});
                }
                cstrt += c;
                if(cstrt >=0 && cstrt< cols){
                    for(int i = rstrt;i<rstrt+c;i++)
                        if(i >=0 && i<rows)
                            res.push_back({i,cstrt});
                }
                rstrt += c;

            } else {
                if(rstrt >=0 && rstrt< rows){
                    for(int i = cstrt;i>cstrt-c;i--)
                        if(i >=0 && i<cols)
                            res.push_back({rstrt,i});
                }
                cstrt -= c;
                if(cstrt >=0 && cstrt< cols){
                    for(int i = rstrt;i>rstrt-c;i--)
                        if(i >=0 && i<rows)
                            res.push_back({i,cstrt});
                }
                rstrt -= c;
            }
            c++;
        }
        return res;
    }
};