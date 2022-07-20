#include<bits/stdc++.h>

using namespace std;
#include <vector>
#include <algorithm>
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
    
    bool operator< (const Workshop& rhs)
    {
        if (this->end_time < rhs.end_time)
        {
            return true;
        }
        
        return false;
    }
};

struct Available_Workshops
{
    int n;
    vector<Workshop> data;
};

Available_Workshops* initialize (int start_time[], int duration[], int n)
{
    Available_Workshops* workShops = new Available_Workshops();
    workShops->n = n;
    for (int i=0; i<n; i++)
    {
        Workshop w; 
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = w.start_time + w.duration;
        workShops->data.push_back(w);
    }
    
    sort(workShops->data.begin(), workShops->data.end());
    return workShops;
};

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int maxCount = 0;
    int finalEndTime = -1;
    
    for (int i=0; i<ptr->n; i++)
    {
        if (ptr->data[i].start_time >= finalEndTime)
        {
            maxCount++;
            finalEndTime = ptr->data[i].end_time;
        }    
    }
    return maxCount;
}


int main(int argc, char *argv[]) {
    int n = 6; // number of workshops
    
    // create arrays of unknown size n
    int start_time[] = {1, 3, 0, 5, 5, 8};
    int duration[] = {1, 1, 6, 2, 4, 1};

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
