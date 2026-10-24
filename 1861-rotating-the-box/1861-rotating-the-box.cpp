class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<char> > b(n,vector<char>(m,'.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        
        vector<vector<char> > ne(n,vector<char>(m,'.'));
        for(int j = 0 ; j<m ; j++){
            int i = n-1;
                while(i>=0){
                    if (b[i][j] == '*') {
                        ne[i][j] = '*';
                        i--;
                        continue;
                    }
                    int k = i;
                    int cnt = 0;
                    while(k>=0){
                        if(b[k][j] == '#'){
                            cnt++;
                        }
                        else if(b[k][j]== '*') break;
                        k--;
                    }
                    int l = i;
                    while(l>=k && cnt>0){
                        ne[l][j] = '#';
                        l--;
                        cnt--;
                    }
                    i = k;
                }
        }
        return ne;
    }  
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna