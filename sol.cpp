class Solution {
    int cnv(string param) {
        int sum = 0;
        bool negative = false;
        for (int i = 0; i < (int) param.size(); i++) {
            if (param[i] == '-') {
                negative = true;
                continue;
            }
            sum = sum * 10 + (param[i] - '0');
        }
        return (!negative ? sum : -sum);
    }
public:
    int calPoints(vector<string>& operations) {
        vector<int> vec;
        for (string op : operations) {
            if (op == "+") {
                vec.push_back(vec[(int)vec.size()-1] + vec[(int)vec.size()-2]);
            } else if (op == "D") {
                vec.push_back(vec[(int)vec.size()-1] * 2);
            } else if (op == "C") {
                vec.pop_back();
            } else {
                vec.push_back(cnv(op));
            }
        }
        int sum = 0;
        for (int x : vec) {
            sum += x;
        }
        return sum;
    }
};
