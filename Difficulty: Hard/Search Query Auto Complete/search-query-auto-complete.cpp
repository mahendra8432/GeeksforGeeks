//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class AutoCompleteSystem {
 public:
    unordered_map<string, int> ele; // To store sentences and their frequencies
    string currentQuery = "";      // To store the ongoing input query

    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        // Initialize the system with given sentences and frequencies
        for (size_t i = 0; i < sentences.size(); i++) {
            ele[sentences[i]] = times[i];
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            // When the query is complete, save it to historical data
            ele[currentQuery]++;
            currentQuery = ""; // Reset the query
            return {};
        }

        // Append the current character to the query
        currentQuery += c;

        // Find all sentences that start with the current query
        vector<pair<string, int>> matches;
        for (auto& entry : ele) {
            const string& sentence = entry.first;
            int frequency = entry.second;

            if (sentence.find(currentQuery) == 0) { // Prefix match
                matches.push_back({sentence, frequency});
            }
        }

        // Sort matches by frequency (descending) and lexicographically (ascending)
        sort(matches.begin(), matches.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });

        // Collect the top 3 results
        vector<string> result;
        for (size_t i = 0; i < min(size_t(3), matches.size()); i++) {
            result.push_back(matches[i].first);
        }

        return result;
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i) {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query) {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions) {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends