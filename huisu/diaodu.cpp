#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int processingTime;
    int deadline;
    int profit;
};

int maxProfit = 0;
vector<int> bestSchedule;

bool compareJobs(const Job &a, const Job &b) {
    return a.profit > b.profit; // 按利润降序排序
}

void backtrack(vector<Job>& jobs, vector<int>& schedule, vector<bool>& used, int currentTime, int currentProfit) {
    if (currentTime > jobs.size()) { // 确保不会超出作业数量
        return;
    }

    if (currentProfit > maxProfit) {
        maxProfit = currentProfit;
        bestSchedule = schedule;
    }

    for (int i = 0; i < jobs.size(); ++i) {
        if (!used[i] && currentTime + jobs[i].processingTime <= jobs[i].deadline) {
            used[i] = true;
            schedule.push_back(jobs[i].id);
            backtrack(jobs, schedule, used, currentTime + jobs[i].processingTime, currentProfit + jobs[i].profit);
            schedule.pop_back(); // 回溯
            used[i] = false; // 回溯
        }
    }
}

int main() {
    vector<Job> jobs = {
        {1, 2, 4, 50},
        {2, 1, 1, 20},
        {3, 2, 2, 30},
        {4, 1, 3, 40}
    };

    sort(jobs.begin(), jobs.end(), compareJobs); // 对作业按利润降序排序

    vector<int> schedule;
    vector<bool> used(jobs.size(), false);

    backtrack(jobs, schedule, used, 0, 0);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Best Schedule: ";
    for (int id : bestSchedule) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
