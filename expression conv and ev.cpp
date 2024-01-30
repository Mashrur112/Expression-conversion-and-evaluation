#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
    return 100;
    else if(c=='*' || c=='/')
    return 50;
    else if(c=='+' || c=='-')
    return 10;
    else
    return 0;

}
string in_post(string s)
{
    string post="";
    stack<char>s1;
    for(int i=0;i<s.size();i++)
    {
        char sym=s[i];
        if(sym>='0' && sym<='9')
        {
            post=post+sym;
        }
        else if(sym=='(')
        {
            s1.push(sym);
        }
        else if(sym==')')
        {
            while(!s1.empty()&&s1.top()!='(')
            {
                post=post+s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else 
        {
            while(!s1.empty() && prec(s1.top())>=prec(sym))
            {
                post=post+s1.top();
                s1.pop();
            }
            s1.push(sym);

        }
    }
    while(!s1.empty())
    {
        post=post+s1.top();
        s1.pop();
    }
    return post;
}
string in_pre(string s)
{
    reverse(s.begin(),s.end());
   string s1= in_post(s);
     reverse(s1.begin(),s1.end());
     return s1;
}
string pre_in(string s)
{
    stack<string >s1;
    for(int i=s.size()-1;i>=0;i--)
    {
        char sym=s[i];
        if(sym>='0' && sym<='9')
        {
            s1.push(to_string(sym-'0'));
        }
        else
        {
            string a=s1.top();
            s1.pop();
            string b=s1.top();
            s1.pop();
            string c;
            c=a+sym+b;
            s1.push(c);


        }
    }
    return s1.top();
}
string post_in(string s)
{
   stack<string >s1;
    for(int i=0;i<s.size();i++)
    {
        char sym=s[i];
        if(sym>='0' && sym<='9')
        {
            s1.push(to_string(sym-'0'));
        }
        else
        {
            string a=s1.top();
            s1.pop();
            string b=s1.top();
            s1.pop();
            string c;
            c=b+sym+a;
            s1.push(c);


        }
    }
    return s1.top(); 
}
string pre_post(string s)
{
    stack <string>s1;

    for(int i=s.size()-1;i>=0;i--)
    {
        char sym=s[i];
        //cout<<sym;
        if(sym>='0' && sym<='9')
        {
            s1.push(to_string(sym-'0'));
        }
        else
        {
            string a=s1.top();
            s1.pop();
            string b=s1.top();
            s1.pop();
            string c;
            c= a+b+sym;
            s1.push(c);
        }
        
    }
    return s1.top();

}
int pre_ev(string s)
{
    stack<int >s1;
    for(int i=s.size()-1;i>=0;i--)
    {
        char sym=s[i];
        if(sym>='0' && sym<='9')
        s1.push(sym-'0');
        else
        {
            int a=s1.top();
            s1.pop();
            int b=s1.top();
            s1.pop();
            int c;
            if(sym=='^')
            c=pow(a,b);
            else if(sym=='+')
            c=a+b;
            else if(sym=='-')
            c=a-b;
            else if(sym=='*')
            c=a*b;
            else if(sym=='/')
            c=a/b;
            s1.push(c);

        }

    }
    return s1.top();
}
int post_ev(string s)
{
    stack<int >s1;
    for(int i=0;i<s.size();i++)
    {
        char sym=s[i];
        if(sym>='0' && sym<='9')
        s1.push(sym-'0');
        else
        {
            int a=s1.top();
            s1.pop();
            int b=s1.top();
            s1.pop();
            int c;
            if(sym=='^')
            c=pow(b,a);
            else if(sym=='+')
            c=b+a;
            else if(sym=='-')
            c=b-a;
            else if(sym=='*')
            c=b*a;
            else if(sym=='/')
            c=b/a;
            s1.push(c);

        }

    }
    return s1.top();
}
int main()
{
    string s;
    
    getline(cin,s);
 //  cout<<in_post(s)<<endl;
  // cout<< in_pre(s)<<endl;
   //cout<<pre_in(s)<<endl;
  //cout<<post_in(s)<<endl;
  //cout<<pre_post(s)<<endl;
  cout<<pre_ev(in_pre(s))<<endl;
  cout<<post_ev(in_post(s))<<endl;

    
    


}