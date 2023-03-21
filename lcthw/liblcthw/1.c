#include <stdio.h>
#define maxn 10005


int a[maxn]; //统计不包括当前的情况下前面有多少个逗号
int b[maxn]; //统计不包括当前的情况下前面有多少个分号
int main() {

    int t; //询问次数
    scanf("%d",&t);
    long long l, r;
    long long l1, l2;
    long long r1, r2;
    while(t--) {
        scanf("%lld%lld",&l,&r);
    
    	l1 = l / 2 - l / 6;
	l2 = r / 2 - r / 6;

	if(l%2 == 0 && l%6 != 0)
		printf("%lld ",l2-l1 + 1);
	else
		printf("%lld ",l2-l1);

	r1 = l/6;
	r2 = r/6;

	if(l%6 == 0)
		printf("%lld\n", r2-r1 +1);
	else
		printf("%lld\n", r2-r1);
    }
}
