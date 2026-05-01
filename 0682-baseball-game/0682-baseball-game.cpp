class Solution {
public:
    int calPoints(vector<string>& operations) {
         vector<int> stack;

        for (string operation : operations) {
            if (operation == "+") {
                int last = stack.back();
                int secondLast = stack[stack.size() - 2];
                stack.push_back(last + secondLast);
            }
            else if (operation == "D") {
                stack.push_back(2 * stack.back());
            }
            else if (operation == "C") {
                stack.pop_back();
            }
            else {
                stack.push_back(stoi(operation));
            }
        }

        int sum = 0;
        for (int x : stack) {
            sum += x;
        }

        return sum;
    }
};