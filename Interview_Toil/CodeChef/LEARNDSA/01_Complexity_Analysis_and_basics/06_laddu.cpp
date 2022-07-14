// https://www.codechef.com/LRNDSA01
#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))
#define char unsigned char
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld;


int32_t main() {
	fast();
    int t;
    cin >> t;
    while(t--) {
    	int points = 0;
    	int activity_count, bug_severity;
    	string origin, queries;
    	cin >> activity_count >> origin;
    	while(activity_count--){
    		cin >> queries;
    		if(queries == "CONTEST_WON" || queries == "BUG_FOUND"){
    			cin >> bug_severity; 
    		}
    		if (queries=="CONTEST_WON") {
    			if(bug_severity < 20) {
    				points += 300 + (20-bug_severity);
    			} else {
    				points += 300;
    			}
    		}
    		else if(queries=="TOP_CONTRIBUTOR"){
    			points += 300;
    		}
    		else if(queries == "BUG_FOUND") {
    			points+=bug_severity;
    		}
    		else if(queries == "CONTEST_HOSTED") {
    			points += 50;
    		}
    	}
    	if(origin=="INDIAN") cout << points/200 << endl;
    	else cout << points/400 << endl;    	
    }
    return 0;
}