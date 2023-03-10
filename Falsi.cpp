#include<bits/stdc++.h>
using namespace std;
const int N = 100000+5;

class falsePosition{
private:
	double epsilon = 0.0001;
	double upper, lower;

	double functon(double x){
		return x*x*x + 27;
	}
public:
	double root=0;

	void solve() {
// upper bound
		for(int i=0; ; i++){
			if(functon(i)>=0){
				upper=i;	break;
			}
			if(functon(-i)>=0){
				upper=-i;	break;
			}
		}
//lower bound
		for(int i=0; ; i++){
			if(functon(i)<=0){
				lower=i;	break;
			}
			if(functon(-i)<=0){
				lower=-i;	break;
			}
		}
		if(upper<lower) swap(upper, lower);
		double previousRoot = (upper+lower)/2;
		double root = 0;
		while(1){
            cout << "Upper : " << upper << ", Lower : " << lower << ", Root : " << root << endl;
			root = lower - (functon(lower)*(upper-lower))/(functon(upper)-functon(lower));
			if(functon(root)==0.0 || abs((root-previousRoot) / root) < epsilon){
				break;
			}
			else{
				if(functon(root)*functon(lower) <= 0){
					upper=root;
				}
			}
			previousRoot = root;
		}
		cout << "The root is " << root << endl;
	}
};
int main()
{
	falsePosition x = falsePosition();
	x.solve();
	
}
