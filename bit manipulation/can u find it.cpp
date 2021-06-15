void solve(){
    int t;
    cin>>t;
    while(t--){
        ll n, ans=0;
        cin>>n;
        vector<ll>v(n);
        ff(i,0,n) cin>>v[i];
        ll curr=0;
        for(ll j=30;j>=0;j--){
            curr=0;
            for(ll i=0;i<n;i++){
                if(v[i]&(1<<j)){
                    v[i] = 0;
                    curr++;
                }
            }
            ans += (curr*(curr-1))/2;
        }
        cout<<ans<<"\n";
