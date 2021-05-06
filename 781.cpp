class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int ans: answers) {
            ++count[ans];
        }
        int res = 0;
        for (auto &[k, v]: count) { // C++17
            res += ((v + k) / (k + 1)) * (k + 1);
        }
        return res;
    }
};

// class Solution {
// public:
//     int numRabbits(vector<int>& answers) {
//         unordered_map<int, int> map;
//         int res = 0;
//         for (int ans: answers) {
//             if (map.find(ans + 1) != map.end()) {
//                 ++map[ans + 1];
//                 if (map[ans + 1] == ans + 1) {
//                     map.erase(ans + 1);
//                     res += ans + 1;
//                 }
//             } else if (ans == 0) {
//                 ++res;
//             } else {
//                 map[ans + 1] = 1;
//             }
//         }
//         for (auto i = map.begin(); i != map.end(); ++i) {
//             res += i->first;
//         }
//         return res;
//     }
// };
