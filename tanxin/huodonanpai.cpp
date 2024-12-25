#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void selectActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities are: " << endl;

    int n = activities.size();
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << endl;

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << ")" << endl;
            i = j;
        }
    }
}

int main() {
    vector<Activity> activities = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    selectActivities(activities);
    return 0;
}