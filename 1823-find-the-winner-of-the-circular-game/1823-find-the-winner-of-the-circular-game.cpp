class Solution {
public:
    int winner(vector<bool>& person, int n, int index, int person_left, int k) {

        // Only one person is left
        if (person_left == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == false)
                    return i;
            }
        }

        // Find the person to kill
        int kill = (k - 1) % person_left;

        while (kill--) {
            index = (index + 1) % n;

            // Skip already killed persons
            while (person[index] == true) {
                index = (index + 1) % n;
            }
        }

        // Kill this person
        person[index] = true;

        // Move to next alive person
        index = (index + 1) % n;

        while (person[index] == true) {
            index = (index + 1) % n;
        }

        return winner(person, n, index, person_left - 1, k);
    }

    int findTheWinner(int n, int k) {
        vector<bool> person(n, false);

        return winner(person, n, 0, n, k) + 1;
    }
};