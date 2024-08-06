class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = n/2;
        int i=0;
        int n1 = n;
        while(i<m){
            int j;
            int i1=i,j1=i;
            for(j=0;j<n-1;j++){
                int dir[4] = {(n1-i)-1,(n1-i)-j-1,i,j1};
                int temp = matrix[i1][j1];
                for(int k=0;k<4;k++){
                    i1=j1;
                    j1 = dir[k];
                    swap(temp,matrix[i1][j1]);
                }
                j1++;
            }
            n-=2;
            i++;
        }
    }
};