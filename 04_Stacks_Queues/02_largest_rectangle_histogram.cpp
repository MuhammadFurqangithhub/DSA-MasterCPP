#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()]) {
            int top = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }

        st.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    int area = largestRectangleArea(histogram);

    cout << "Largest Rectangle Area in Histogram: " << area << endl;
    return 0;
}
