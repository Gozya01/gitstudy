#include<stdio.h>
#include<string.h>
int Judge_bi(char *s){
    int n = strlen(s);
    if(n!=8)
        return 0;
    for (int i = 0; i < n;++i){
        if(s[i]<'0'||s[i]>'9')
            return 0;
    }
    
        return 1;
}
int Judge_name(char *s){
    int n = strlen(s);
    for(int i=0; i<n; i++){
        if(s[i]>='a'&&s[i]<='z')
            s[i] -= 32;
        if(s[i]<'A'||s[i]>'Z')
            return 0;
        //printf("%d ", s[i]);
    }
    for (int i = n; i < 8;++i)
        s[i] = '@';
    return 1;
}
#define maxn 100
char s1[maxn], s2[maxn];
char s3[maxn];
int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    if(!Judge_bi(s1)){
        printf("Error: wrong format of date.\n");
        return 0;
    }
    if(!Judge_name(s2)){
        printf("Error: wrong format of name.\n");
        return 0;
    }
    for (int i = 0; i < 4;++i){
        char ch = s1[8 - i - 1];
        s1[8 - i - 1] = s1[i];
        s1[i] = ch;
    }
    //printf("%s+++\n", s1);
    for (int i = 0; i < 8;++i){
        s3[i]=s1[i]+s2[i]-'0';
        //printf("%d+++++\n", s3[i]);
        if(s3[i]>=91&&s3[i]<=96)
            printf("%c", s3[i] - 90 + '0');
        else
            printf("%c", s3[i]);
    }
    printf("\n");
    return 0;
}