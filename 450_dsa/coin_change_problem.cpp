int dp(int *denominations,int index,int len,int value){
    if(index==len){
        if(value==0)
            return 1;
        return 0;
    }
    if(value<0)
        return 0;
    //include current
    int in=dp(denominations,index,len,value-denominations[index]);
    //exclude
    int ex=dp(denominations,index+1,len,value);

    return in+ex;

}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //return dp(denominations,0,n,value);
    int dp[value+1][n];
    for(int i=0;i<=value;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=value;i++){
                dp[i][0]=(denominations[0]%i==0);
    }

    int in=0,ex=0;

    for(int i=1;i<=value;i++){
        for(int j=1;j<n;j++){
            //include
            if(denominations[j]>=i)
            in=dp[i-denominations[j]][j];
            //exclude
            ex=dp[i][j-1];
            dp[i][j]=in+ex;
        }
    }

    return dp[value][n-1];

}
