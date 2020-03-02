#include <bits/stdc++.h>

using namespace std;

long aCounter(string s){
    long counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == 'a'){
            counter++;
        }
    }
    return counter;
}

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long aCount = aCounter(s);
    long division = n / s.length();

    long remainings = n % s.length();
    string remainingStr = s.substr(0, remainings);
    long remainingAs = aCounter(remainingStr);

    long result = (aCount * division) + remainingAs;

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
