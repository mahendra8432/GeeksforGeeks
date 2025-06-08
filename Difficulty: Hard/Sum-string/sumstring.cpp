class Solution {
  public:
    string addStrings(string a, string b) {
        if (a.size() < b.size()) swap(a, b);

        int carry = 0;
        int lenA = a.size(), lenB = b.size();
        string result = "";

        for (int i = 0; i < lenB; ++i) {
            int sum = (a[lenA - 1 - i] - '0') + (b[lenB - 1 - i] - '0') + carry;
            result = char((sum % 10) + '0') + result;
            carry = sum / 10;
        }

        for (int i = lenB; i < lenA; ++i) {
            int sum = (a[lenA - 1 - i] - '0') + carry;
            result = char((sum % 10) + '0') + result;
            carry = sum / 10;
        }

        if (carry) result = char(carry + '0') + result;

        return result;
    }

    bool check(string &s, int i, int len1, int len2) {
        string num1 = s.substr(i, len1);
        string num2 = s.substr(i + len1, len2);

        if ((num1[0] == '0' && len1 > 1) || (num2[0] == '0' && len2 > 1)) return false;

        string sum = addStrings(num1, num2);
        int len3 = sum.size();

        if (i + len1 + len2 + len3 > s.size()) return false;
        if (sum != s.substr(i + len1 + len2, len3)) return false;
        if (i + len1 + len2 + len3 == s.size()) return true;

        return check(s, i + len1, len2, len3);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int len1 = 1; len1 < n; ++len1) {
            for (int len2 = 1; len1 + len2 < n; ++len2) {
                if (check(s, 0, len1, len2)) return true;
            }
        }
        return false;
    }
};
