class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int minLandFinish = INT_MAX;
        int minWaterFinish = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish =
                min(minLandFinish, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            minWaterFinish =
                min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < waterStartTime.size(); i++) {
            int finishTime =
                max(minLandFinish, waterStartTime[i]) + waterDuration[i];

            ans = min(ans, finishTime);
        }

        for (int i = 0; i < landStartTime.size(); i++) {
            int finishTime =
                max(minWaterFinish, landStartTime[i]) + landDuration[i];

            ans = min(ans, finishTime);
        }

        return ans;
    }
};