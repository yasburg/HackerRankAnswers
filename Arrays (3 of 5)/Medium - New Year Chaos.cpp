#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int bribeCounter (vector<int>& vec, int curIndex){
    int i = curIndex, counter = 0;
    int curVal = vec[curIndex];
    while(i != vec.size()){
        if (curVal > vec[i]) {
            counter++;
        }
        i++;
    }
    return counter;
}

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int totalNumOfBribes = 0;
    bool chaotic = false;
    for(int i = 0; i < q.size(); i++){
        if( q[i] - (i + 1) > 2 ){
            chaotic = true;
            break;
        }
        //Had help from: https://www.hackerrank.com/challenges/new-year-chaos/forum/comments/143969
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) totalNumOfBribes++;
    }
    if(chaotic){
        cout << "Too chaotic" << endl;
    }
    else {
        cout << totalNumOfBribes << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
