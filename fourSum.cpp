/*
*    4 sum
* 
*    @date  2015/8/7
*
*/
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

vector<vector<int> > threeSum(vector<int> num, int target) {

    vector< vector<int> > result;
    //sort the array (if the qrray is sorted already, it won't waste any time)
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            if (a+b+c == target) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                while(high>0 && num[high]==num[high-1]) high--;
                low++;
                high--;
            } else if (a+b+c > target) {
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                low++;
            }
        }
    }
    return result;
}

/// writed by hqwsky using map  overload
vector<vector<int> > threeSum(vector<int> &num,int target,bool hasmap)
{
	vector<vector<int> > ret;
	ret.clear();
	/// ÅÅÐò
	std::sort(num.begin(),num.end());
	for(int i= 0;i != num.size();i++)
	{
		//È¥ÖØ
		if (i != 0 && num[i] == num[i-1])  
                continue;  
		int j = i+1;
		map<int,int> mp;
		mp.clear();
		for(;j != num.size();j++)
		{
			if(!mp.count(num[j]))
			{
				//mp[num[i]] = i;
				mp.insert(std::pair<int,int>(num[j],j));
			}
			if(mp.count(target-num[i]-num[j]))
			{
				int n = mp[target-num[i]-num[j]];
				if(n<j)
				{
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(target-num[i]-num[j]);
					tmp.push_back(num[j]);
				
					ret.push_back(tmp);
				}
			}
		}
	}
	return ret;
	
}

vector<vector<int> > fourSum(vector<int> &num, int target)
{
    vector< vector<int> > result;
	///carefully
    if (num.size()<4) return result;
    sort( num.begin(), num.end() );
    
    for(int i=0; i<num.size()-3; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        vector<int> n(num.begin()+i+1, num.end());
        vector<vector<int> > ret = threeSum(n, target-num[i],true);
        for(int j=0; j<ret.size(); j++){
            ret[j].insert(ret[j].begin(), num[i]);
            result.push_back(ret[j]);
        }
    }

    return result; 
}


int main()
{
    int a[] = {1,0,-1,0,-2,2};
    vector<int> n(a, a+6);
    int t = 0;
    vector< vector<int> > v = fourSum(n, t);
   
    n.clear();
    int b[] = {-1,-5,-5,-3,2,5,0,4};
    n.insert(n.begin(), b, b+8);
    t = -7;
    v = fourSum(n, t);


    return 0;
}
