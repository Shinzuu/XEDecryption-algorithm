#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

#define ll long long
#define vi vector<int>
#define f(i, s, e) for (long long int i = s; i < e; i++)


void decrypt(string text, int n) {
    vi v;
    vi vvv;
    ll sum;
    vi q;
    // transforming char to int
    for (int i = 0; i < n;) {
        if (text[i] != '.') {
            int sum = 0;
            for (int j = 0; j < 3 && i + j < n; ++j) {
                sum = sum * 10 + (text[i + j] - '0');
            }
            v.push_back(sum);
            i += 3;
        } else {
            ++i;
        }
    }
    // adding 3 consecutive numbers because every char of unencrypted text gets broken into 3 part

    n = v.size();  
    for (int i = 0; i < n; i += 3) {
        sum = 0;
        for (int j = 0; j < 3 && i + j < n; ++j) {
            sum += v[i + j];
        }
        vvv.push_back(sum);
    }
    n = vvv.size();
    // duplicate vector
    f(i, 0, n) {
        q.push_back(vvv[i]) ;
    }

    // lowest number would be space in between . vvv[0] ='space' = dec(32)
    sort(vvv.begin(), vvv.end());
    int extra = vvv[0]-10; // since 10 gets added while it encrypt 

    f(i, 0, n){
        cout << static_cast<char>(q[i]-extra) ;
    }
    cout << endl;
}

string importFile(const string &file_name) {
    try {
        ifstream file(file_name);

        if (file.is_open()) {
            string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            return content;
        } else {
            throw runtime_error("Error: Unable to open the file.");
        }
    } catch (const ios_base::failure &e) {
        cerr << "An error occurred: " << e.what() << endl;
        return "";
    } catch (const exception &e) {
        cerr << "An error occurred: " << e.what() << endl;
        return "";
    }
}

int main() {
    string file_name = "encrypted.txt";
    string imported_string = importFile(file_name);
    size_t length = imported_string.length();

    if (imported_string.empty()) {
        cout << "No content in the file" << endl;
    } else {
        decrypt(imported_string, length);
    }

    return 0;
}
