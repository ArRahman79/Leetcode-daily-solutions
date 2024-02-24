//  24-02-2024

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ans;
        ans.push_back(0);
        vector<int> secretTime(n,INT_MAX);
        secretTime[0]=0;
        secretTime[firstPerson]=0;
        unordered_map<int, list<pair<int, int>>>adj;
        
        for(int i=0;i<meetings.size();i++)
        {
            int u=meetings[i][0];
            int v=meetings[i][1];
            int w=meetings[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        queue<int> q;
        q.push(0);
        q.push(firstPerson);
        while(!q.empty())
        {
            int person1=q.front();
            q.pop();
            for(auto i:adj[person1])
            {
                int person2=i.first;
                int meetingTime=i.second;
                if(meetingTime>=secretTime[person1] && meetingTime<secretTime[person2])
                {
                    secretTime[person2]=meetingTime;
                    q.push(person2);
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            if(secretTime[i]<INT_MAX)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
