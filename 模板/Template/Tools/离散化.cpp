for(int i=0; i<=n;++i) v.push_back(sum[i]);
sort(v.begin(),v.end());
v.resize(unique(v.begin(),v.end())-v.begin());
for(int i=0;i<=n;++i) sum[i]=lower_bound(v.begin(),v.end(),sum[i])-v.begin()+1;