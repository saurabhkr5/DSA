class Solution {
public:
    int shipWithinDays(vector<int>& w, int D) {

        int left = *max_element(w.begin(), w.end());
        int right = accumulate(w.begin(), w.end(), 0);

        while(left <= right) {

            int cap = (left + right) / 2;

            int days = 1, load = 0;

            for(int x : w) {
                if(load + x > cap) {
                    days++;
                    load = 0;
                }
                load += x;
            }

            if(days <= D)
                right = cap - 1;
            else
                left = cap + 1;
        }

        return left;
    }
};