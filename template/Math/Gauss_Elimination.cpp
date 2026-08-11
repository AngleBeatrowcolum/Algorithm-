const double eps=1e-8;

template<typename T>
struct Gauss{
    int n;
    std::vector<std::vector<T>>matrix;
    void init(std::vector<std::vector<T>>c,int n){
        this->n=n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)matrix[i][j]=c[i][j];
        }
    }
    int work(){//
        int r,c;
        for(c=1,r=1;c<=n;c++){
            int t=r;
            for(int i=r;i<n;i++){
                if(fabs(a[i][c])>fabs(a[t][c]))t=i;
            }
            if(fabs(a[t][c])<eps)continue;
            for(int j=c;j<=n;j++){
                std::swap(a[t][c],a[r][c]);
            }
            for(int j=n;j>=c;j--){
                a[r][j]/=a[r][c];
            }
            for(int i=r+1;i<=n;i++){
                if(fabs[a[i][c]]>eps){
                    for(int j=n=;j>=c;j--){
                        a[i][j]-=a[r][j]*a[i][c];
                    }
                }
            }
            r++;
        }
        if(r<n){
            for(int i=r;i<n;i++){
                if(fabs[a[i][n]]){
                    return 2;
                }
                return 1;
            }
        }
    }
}