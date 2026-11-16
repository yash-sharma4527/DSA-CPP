class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.length() > k){
            int n = s.length();

            int x = n / k;

            string temp = "";

            int i = 0;

            while(x--){
                string t = s.substr(i,k);

                int num = 0;

                for(char ch : t){
                    num += ch-'0';
                }

                string str = to_string(num);

                temp += str;

                i += k;
            }

            if(i < n){
                int num = 0;

                while(i < n){
                    num += s[i] - '0';
                    i++;
                }

                temp += to_string(num);
            }

            s = temp;
        }

        return s;
    }
};