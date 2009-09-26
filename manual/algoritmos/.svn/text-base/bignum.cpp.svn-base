void simplify(char v[]) { 
    int i; 
    i=strlen(v)-1; 
    while(i>0 && v[i]=='0') {v[i]='\0';i--;} 
} 
void add(char v[], int q) { 
    int c=q; 
    int i,d; 
    for(i=0;v[i];i++) 
    { 
        d=((v[i]-'0')+c); 
        c=d/10;d%=10; 
        v[i]='0'+d; 
    } 
    while(c) 
    { 
        v[i]='0'+(c%10); 
        c/=10;i++; 
    } 
    v[i]='\0'; 
} 
void multi(char v[], int q) { 
    int c=0; 
    int i,d; 
    for(i=0;v[i];i++) 
    { 
        d=((v[i]-'0')*q+c); 
        c=d/10;d%=10; 
        v[i]='0'+d; 
    } 
    while(c) 
    { 
        v[i]='0'+(c%10); 
        c/=10;i++; 
    } 
    v[i]='\0'; 
} 
int divi(char v[], int q) 
// returns the reminder 
{ 
    int i,l=strlen(v); 
    int c=0,d; 
    for(i=l-1;i>=0;i--) 
    { 
        d=c*10+(v[i]-'0'); 
        c=d%q; d/=q; v[i]='0'+d; 
    } 
    i=l-1; 
    while(i>0 && v[i]=='0') i--; 
    v[i+1]='\0'; 
    return c; 
} 
void add(char v1[], char v2[]) 
// v1 = v1+v2; 
{ 
        int i,d,c=0; 
        int l1=strlen(v1); 
        int l2=strlen(v2); 
        for(i=l1;i<l2;i++) v1[i]='0'; 
        for(i=l2;i<l1;i++) v2[i]='0'; 
        for(i=0;i<l1||i<l2;i++) 
        { 
                d=(v1[i]-'0')+(v2[i]-'0')+c; 
                c=d/10;d%=10; 
                v1[i]='0'+d; 
        } 
        while(c) 
        { 
                v1[i]='0'+(c%10); 
                c/=10;i++; 
        } 
        v1[i]='\0'; 
        v2[l2]='\0'; 
} 
void subs(char v1[], char v2[]) 
// v1=v1-v2; 
{ 
        int i,d,c=0; 
        int l1=strlen(v1); 
        int l2=strlen(v2); 
        for(i=l2;i<l1;i++) v2[i]='0'; 
        for(i=0;i<l1;i++) 
        { 
                d=(v1[i]-'0'-c)-(v2[i]-'0'); 
                if(d<0) {d+=10; c=1;} else c=0; 
                v1[i]='0'+d; 
        } 
        v2[l2]='\0'; 
    i=l1-1; 
    while(i>0 && v1[i]=='0') i--; 
    v1[i+1]='\0'; 
} 
//return the sign of v1-v2 
int comp(char v1[], char v2[]) { 
    int i; 
    int l1=strlen(v1); 
    int l2=strlen(v2); 
    if(l1>l2) return(1); 
    if(l1<l2) return(-1); 
    for(i=l1-1;i>=0;i--) 
    { 
        if(v1[i]>v2[i]) return(1); 
        if(v1[i]<v2[i]) return(-1); 
    } 
    return(0); 
} 
char tmp[10000]; char tmp1[10000]; char tmpd[10][10000]; char 
bs[10000]; 
void multi(char v1[], char v2[]) 
// v1=v1*v2; 
{ 
    bs[0]='\0'; 
    int l2=strlen(v2); 
    int i; 
    strcpy(tmpd[0],"0"); 
    for(i=1;i<10;i++) 
    { 
        strcpy(tmpd[i],tmpd[i-1]); 
        add(tmpd[i],v1); 
    } 
    strcpy(v1,"0"); 
    for(i=0;i<l2;i++) 
    { 
        strcpy(tmp,bs); bs[i]='0';bs[i+1]='\0'; 
        strcat(tmp,tmpd[v2[i]-'0']); 
        add(v1,tmp); 
    } 
} 
void multi(char v1[], char v2[], char v3[]) 
//make sure v1 is not v3 
// v3=v1*v2; 
{ 
    bs[0]='\0'; 
    int l2=strlen(v2); 
    int i; 
    strcpy(tmpd[0],"0"); 
    for(i=1;i<10;i++) 
    { 
        strcpy(tmpd[i],tmpd[i-1]); 
        add(tmpd[i],v1); 
    } 
    strcpy(v3,"0"); 
    for(i=0;i<l2;i++) 
    { 
        strcpy(tmp,bs); bs[i]='0';bs[i+1]='\0'; 
        strcat(tmp,tmpd[v2[i]-'0']); 
        add(v3,tmp); 
    } 
} 
void divi(char v1[], char v2[], char v3[], char v4[]) 
//v1/v2=v3...v4 
// make sure v3, v4 are different from v1, v2 
{ 
    int i; 
    if(strcmp(v2, "1")==0) 
    { 
        strcpy(v3, v1); 
        strcpy(v4, "0"); 
        return; 
    } 
    if(strcmp(v1, "0")==0) 
    { 
        strcpy(v3, "0"); 
        strcpy(v4, "0"); 
        return; 
    } 
    for(i=0;v1[i];i++) v3[i]='0'; 
    v3[i]='\0'; 
    int ff=1; 
    int l=i; 
    for(i=l-1;i>=0;i--) 
    { 
        while(1) 
        { 
            if(v3[i]=='9') break; 
            v3[i]++; 
            multi(v3, v2, v4); 
            if(comp(v4, v1)>0) 
            { 
                v3[i]--; 
                break; 
            } 
            ff=0; 
        } 
        if(ff && i) v3[i]='\0'; 
        //simplify(v3); 
    } 
    multi(v2, v3, tmp1); 
    strcpy(v4, v1); 
    subs(v4, tmp1); 
} 
void showBigint(char v[]) { 
    simplify(v); 
    int l=strlen(v); 
    int i; 
    for(i=l-1;i>=0;i--) cout<<v[i]; 
} 
void rev(char v[]) { 
    int l=strlen(v); 
    int i; char cc; 
    for(i=0;i<l-1-i;i++) 
    { 
        cc=v[i];v[i]=v[l-1-i];v[l-i-1]=cc; 
    } 
}
