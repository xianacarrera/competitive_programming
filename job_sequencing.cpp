/*
We are given n jobs, J_1, J_2, ..., J_n, with profits p[0], p[1], ..., p[n - 1].
Each job must be completed before its respective deadline, d[0], d[1], ..., d[n - 1].

If a job is completed before its deadline, we will receive its profit. If the job is not completed, no profil will
be received.

Which job sequence maximizes the total profit?


This problem can be solved by a greedy algorithm. It is an optimization problem with a maximization objective.
Our approach will consist of sorting the jobs by their profit decreasingly. Then, we will iterate through the sorted 
jobs and assign each one to the empty time slot that is closest to its deadline. If no such time slot exists, the job 
will be ignored.
 
Example
Input:
JobID  Deadline   Profit
  1           2          40   
  2           2          27
  3           1           8  
  4           3           3
  5	          3           2

Output:
Job timeline: 2 1 4
*/


#include <bits/stdc++.h>
using namespace std;

typedef struct Job {
    int id, profit, deadline;
} Job;


int main(){
    int n;      // number of jobs

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    for (int i = 0; i < n; ++i){
        cout << "Enter new job id: ";
        cin >> jobs[i].id;
        cout << "Enter profit, deadline for job " << jobs[i].id << ": ";
        cin >> jobs[i].profit >> jobs[i].deadline;
    }

    // Sort jobs by profit decreasingly
    sort(jobs, jobs + n, [](const Job &a, const Job &b){
        return a.profit > b.profit;
    });

    vector<int> timeline(n);
    vector<bool> used(n);               // All false by default
    // If we add a constraint to the jobs ids, such as 'all of them must be greater than 0', the used vector would not
    // be necessary and can be combined with the timeline vector (in this case, initializing as -1, for example).

    for (int i = 0; i < n; ++i){
        Job job = jobs[i];

        int slot = job.deadline - 1;
        while (slot >= 0 && used[slot])          // Go backwards searching for the first unused slot
            --slot;
        
        if (slot >= 0){
            used[slot] = true;
            timeline[slot] = job.id;
        }
    }

    cout << "\nJob timeline: ";
    for (int i = 0; i < n; ++i)
        if (used[i]) cout << timeline[i] << " ";
        else cout << "_ ";
}