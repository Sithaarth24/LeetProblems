class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstrt,
                                        int cstrt) {
        int c = 1;
        vector<vector<int>> res(rows*cols,vector<int>(2,{}));
        int i,k = 0;
        int m = max(2*rows,2*cols);
        while(c < m) {
            if (c % 2) {
                if(rstrt >=0 && rstrt< rows){
                    i = (cstrt < 0)?0 : cstrt;
                    for(i;i<cstrt+c;i++)
                    {
                        if( i < cols) res[k++] = {rstrt,i};
                        else break;
                    }
                }
                cstrt += c;
                if(cstrt >=0 && cstrt< cols){
                    i = (rstrt < 0)?0 : rstrt;
                    for(i;i<rstrt+c;i++)
                    {
                        if( i < rows) res[k++] = {i,cstrt};
                        else break;
                    }
                }
                rstrt += c;

            } 
            else {
                if(rstrt >=0 && rstrt< rows){
                    i = (cstrt >= cols)?cols-1:cstrt;
                    for(i;i>cstrt-c;i--)
                    {
                        if(i < cols){
                            if( i >= 0) res[k++] = {rstrt,i};
                            else break;
                        }
                    }
                }
                cstrt -= c;
                if(cstrt >=0 && cstrt< cols){
                    i = (rstrt >= rows)?rows-1:rstrt;
                    for(i;i>rstrt-c;i--)
                    {
                        if(i < rows){
                            if( i >= 0) res[k++] = {i,cstrt};
                            else break;
                        }
                    }
                }
                rstrt -= c;
            }
            c++;
        }
        return res;
    }
};