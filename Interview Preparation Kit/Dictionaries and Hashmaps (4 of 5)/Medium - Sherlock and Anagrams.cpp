#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int count = 0, n = s.length();
    string a,b;
    map<string,int>mp;

    //not my code https://www.hackerrank.com/challenges/sherlock-and-anagrams/forum/comments/486106
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            a=s.substr(i,j);
            sort(a.begin(),a.end());
            mp[a]++;
        }
    }
 
    int k;
    for(auto x:mp)
    {
        k=x.second;
        count+=(k*(k-1))/2;
    }
 
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
