class Solution {
public:
    bool check(int a,int b,vector<vector<int>>& img, int t){
        for(int i=a+1;i<a+3;i++)
            for(int j=b;j<b+3;j++)
                if(abs(img[i-1][j]-img[i][j])>t)return false;
        for(int i=a;i<a+3;i++)
            for(int j=b+1;j<b+3;j++)
                if(abs(img[i][j-1]-img[i][j])>t)return false;
        return true;
    }
    int aver(int a,int b,vector<vector<int>> &img){
        int ans=0;
        for(int i=a;i<a+3;i++)
            for(int j=b;j<b+3;j++)
                ans+=img[i][j];
        return ans/9;
    }
    void update(int a,int b,int avg,vector<vector<int>> &img,vector<vector<int>> &cnt){
    // void update(int a,int b,int avg,vector<vector<int>> &img,vector<vector<pair<float,int>>> &cnt){
        float sz;
        for(int i=a;i<a+3;i++)
            for(int j=b;j<b+3;j++){
                // cnt[i][j].second++;
                // sz=cnt[i][j].first*cnt[i][j].second;
                // // cnt[i][j].first=(sz*img[i][j]+avg)/(cnt[i][j].second);
                // img[i][j]=cnt[i][j].first;
                if(cnt[i][j]==0)
                    img[i][j]=avg;
                else
                    img[i][j]+=avg;
                // img[i][j]+=avg;
                cnt[i][j]++;
            }
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m=image.size(),n=image[0].size(),avg;
        vector<vector<int>> count(m,vector<int>(n,0));
        // vector<vector<pair<float,int>>> count(m,vector<pair<float,int>>(n));
        // vector<vector<int>> nimage(m,vector<int>(n,0));
        vector<vector<int>> nimage=image;
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                bool val=check(i,j,image,threshold);
                // cout<<"here"<<i<<" "<<j<<" "<<val<<endl;
                if(!val)continue;
                avg=aver(i,j,image);
                update(i,j,avg,nimage,count);
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                // if(nimage[i][j]>0)
                if(count[i][j]>0)
                    nimage[i][j]/=(count[i][j]);
                // else
                //     nimage[i][j]=image[i][j];
        return nimage;
    }
};



/*
[[1,18,11,0],[23,1,6,18],[40,20,19,18],[6,19,26,26]]
38

[[15,13,13,12],[16,15,15,14],[16,15,15,14],[17,17,17,17]]
*/


