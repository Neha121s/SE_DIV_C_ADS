#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long long int PowerMod(int base, int exp, int modx)
{ 
    long long int result = 1;
    long long int a = base;
    while (exp > 0) {
        if (exp & 1)
            result = result * a % modx;
        a = a * a % modx;
        exp >>= 1;
    }
    return result;
}


int ModInv(int a, int b)
{
    int b0 = b;
    int t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) 
        return 1;
    while (a > 1)
    {
        q = a / b;
        t = b;
        b = a % b;
        a = t;
        t = x0;
        x0 = x1-q*x0;
        x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}


// Complete the solve function below.
int solve(int a, int b, int x) {
    if (b<0){
         return PowerMod(ModInv(a, x), -b, x);
        }
        else
            return PowerMod(a,b,x);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abx_temp;
        getline(cin, abx_temp);

        vector<string> abx = split_string(abx_temp);

        int a = stoi(abx[0]);

        int b = stoi(abx[1]);

        int x = stoi(abx[2]);

        int result = solve(a, b, x);

        fout << result << "\n";
    }

    fout.close();

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
