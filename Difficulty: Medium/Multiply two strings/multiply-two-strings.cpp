class Solution {
  public:
    string multiplyStrings(string &s1, string &s2) {
        // code here
         int a=s1.length(),b=s2.length();
       string s="";
       int sign1 = (s1[0] == '-') ? -1 : 1;
       int sign2 = (s2[0] == '-') ? -1 : 1;
       if (s1[0] == '-') {s1=s1.substr(1);a--;}
       if (s2[0] == '-') {s2=s2.substr(1);b--;}
       vector<int>v(a+b,0);
       for(int i=a-1;i>=0;i--){
           for(int j=b-1;j>=0;j--){
               int p=(s1[i]-'0')*(s2[j]-'0');
               int s=p+v[i+j+1];
               v[i+j+1]=s%10;
               v[i+j]+=s/10;
           }
       }
       int finalsign=sign1*sign2;
       for(int i=0;i<v.size();i++) {
          if (finalsign ==-1&&!(s.empty()&&v[i] == 0)) {
              s ="-"+s;finalsign=1;
          }
           if(!(s.empty()&&v[i]==0)) s+=to_string(v[i]);
       }
       return s.empty()?"0":s;
    }
};