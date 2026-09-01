class Solution {
public:
    int thirdMax(vector<int>& arr) {
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        bool f = false, s = false, t = false;

        for (int i = 0; i < arr.size(); i++) {

            // Skip duplicate values
            if ((f && arr[i] == first) ||
                (s && arr[i] == second) ||
                (t && arr[i] == third)) {
                continue;
            }

            if (!f || arr[i] > first) {
                third = second;
                t = s;

                second = first;
                s = f;

                first = arr[i];
                f = true;
            }
            else if (!s || arr[i] > second) {
                third = second;
                t = s;

                second = arr[i];
                s = true;
            }
            else if (!t || arr[i] > third) {
                third = arr[i];
                t = true;
            }
        }

        // If third maximum doesn't exist
        if (!t)
            return first;

        return third;
    }
};