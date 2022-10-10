//Redundant Brackets

#include <bits/stdc++.h> 


bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>str;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        
        if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            str.push(ch);
        }
        
        else{
            if(ch==')'){
                bool isRedundant=true;
                
                while(str.top() != '('){
                    char top=str.top();
                    if(top=='+'||top=='/'||top=='*'||top=='-'){
                        isRedundant=false;
                    }
                    str.pop();
               
                }
                if(isRedundant==true){
                    return true;
                }
                str.pop();
            }
        }
    }
    return false;
    
}
