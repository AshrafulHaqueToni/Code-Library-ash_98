
    int countSquares(vector<vector<int>>& matrix) {
        int re=0;
      int boro=0;
      for(int i=0;i<matrix.size();i++)
      {
        for(int j=0;j<matrix[i].size();j++)
        {
          if(i && j && matrix[i][j])
          {
            matrix[i][j]=min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]})+1;
          }
          re+=matrix[i][j];
          boro=max(boro,matrix[i][j]);
        }
      }
      cout<<boro<<endl;
      return re;
    }
