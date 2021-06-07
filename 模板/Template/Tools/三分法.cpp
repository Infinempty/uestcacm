int SanFen(int l,int r)//找凸点  
{  
    while(l<r-1){  
        int mid=(l+r)/2;  
        int mmid=(mid+r)/2;  
        if(f(mid)>f(mmid)) r=mmid;  
        else l=mid;  
    }  
    return f(l)>f(r) ? l : r;  
}  

int SanFen(int l,int r)//找凹点  
{  
    while(l<r-1)  {  
        int mid=(l+r)/2;  
        int mmid=(mid+r)/2;  
        if(f(mid)>f(mmid)) l=mid;  
        else r=mmid;  
    }  
    return f(l)>f(r) ? l : r;  
}  
