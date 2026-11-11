class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total = 0;
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                total += customers[i];
            }
        }
        int sum = 0;
        for(int i = 0; i < minutes; i++) {
            if(grumpy[i] == 1) {
                sum += customers[i];
            }
        }
        int maximum = sum;
        for(int i = minutes; i < n; i++) {
            if(grumpy[i] == 1) {
                sum += customers[i];
            }
            if(grumpy[i - minutes] == 1) {
                sum -= customers[i - minutes];
            }
            maximum = max(maximum, sum);
        }
        return total + maximum;
    }
};