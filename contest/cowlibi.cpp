#include <bits/stdc++.h>
using namespace std;

int G, N;

map<int, bool> hasTrivialPosition;
map<int, pair<double,double>> trivialPosition;

struct Trip {
    double startX, startY, endX, endY;
    int timeStart, timeEnd;
    bool includes(int t){
        return t >= timeStart && t <= timeEnd;
    }
};

double sqr(double inp){
    double inp2 = inp;
    return inp2 * inp2;
}

double calcDist(pair<double,double> a, pair<double,double> b){
    // if(a.first == b.first) return abs((double) a.second - (double) b.second);
    // if(a.second == b.second) return abs((double) a.first - (double) b.first);
    // return abs((double) a.first - (double) b.first) + ((double) a.second - (double) b.second);
    return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}

bool checkDist(pair<double,double> a, pair<double,double> b, int maximum){
    // cout << calcDist(a,b) << " max: " << maximum << endl;
    return calcDist(a, b) <= maximum;
}

bool viableDetour(Trip trip, pair<double,double> detourLocation, int detourArrival){
    double allowedDistanceA = (double) (detourArrival - trip.timeStart);
    double allowedDistanceB = (double) (trip.timeEnd - detourArrival);
    bool verdict = checkDist(make_pair(trip.startX,trip.startY),detourLocation,allowedDistanceA) && checkDist(make_pair(trip.endX,trip.endY),detourLocation,allowedDistanceB);
    /*if(verdict){
        cout << "Viable detour: " << trip.startX << "," << trip.startY << " " << trip.endX << "," << trip.endY << " " << trip.timeStart << " " << trip.timeEnd << " " << detourLocation.first << "," << detourLocation.second << endl;
    }*/
    return verdict;
}

//               location         time
vector<pair<pair<double, double>, int>> incidents;
vector<pair<pair<double, double>, int>> alibis;
vector<Trip> trips;
int starter = 0;

// requires inputs to be recieved sorted
int tripIndexOfTime(int t){
    int l = 0, r = G - 1;
    if(G == 1){
        return -1;
    }else if(G == 2){
        if(trips[0].timeStart <= t && trips[0].timeEnd >= t){
            return 0;
        }else{
            return -1;
        }
    }
    for(int i = starter; i < G - 1; i ++){
        if(trips[i].timeEnd < t){
            starter = i;
        }
        if(trips[i].includes(t)){
            return i;
        }
    }

    /*while(l < r){
        int mid = (l + r) / 2;
        if(trips[mid].timeStart <= t && trips[mid].timeEnd >= t){
            return mid;
        }else if(trips[mid].timeStart > t){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }*/
    /*for(int i = 0; i < G - 1; i ++){
        if(trips[i].includes(t)){
            return i;
        }
    }*/
    return -1;
}

void solve(){
    cin >> G >> N;
    // Incident reader
    for(int i = 0; i < G; i++){
        int x, y, t;
        cin >> x >> y >> t;
        incidents.push_back({{x, y}, t});
        hasTrivialPosition[t] = true;
        trivialPosition[t] = {x, y};
    }
    sort(incidents.begin(), incidents.end(), [](pair<pair<double,double>,int> a, pair<pair<double,double>,int> b){
        return a.second < b.second;
    });
    // cout << (incidents[0].second == 100) << endl;
    // cout << (incidents[1].second == 200) << endl;
    // assert(incidents[0].second == 100);
    // Alibis reader
    for(int i = 0; i < N; i++){
        int x, y, t;
        cin >> x >> y >> t;
        alibis.push_back({{x, y}, t});
    }
    // Trips
    for(int i = 0; i < G - 1; i ++){
        pair<double,double> pointA = incidents[i].first;
        pair<double,double> pointB = incidents[i + 1].first;
        int timeA = incidents[i].second;
        int timeB = incidents[i + 1].second;
        Trip t;
        t.startX = pointA.first;
        t.startY = pointA.second;
        t.endX = pointB.first;
        t.endY = pointB.second;
        t.timeStart = timeA;
        t.timeEnd = timeB;
        double duration = timeB - timeA;
        double distance = calcDist(pointA, pointB);
        /*if(duration < distance){
            cout << N << endl;
            return;
        }*/
        trips.push_back(t);
    }
    // Now we have all the trips
    // calc each alibi good or not
    // cout << "C" << endl;
    int bad = 0;
    sort(alibis.begin(), alibis.end(), [](pair<pair<double,double>,int> a, pair<pair<double,double>,int> b){
        return a.second < b.second;
    });
    for(int i = 0; i < N; i ++){
        pair<double,double> alibi = alibis[i].first;
        int time = alibis[i].second;
        int tripIndex = tripIndexOfTime(time);
        // cout << i << " ti " << tripIndex << endl;
        /*if(hasTrivialPosition[time]){
            pair<double,double> badPos = trivialPosition[time];
            if(calcDist(alibi, badPos) <= 0){
                bad ++;
                continue;
            }
        }*/
        if(tripIndex == -1){
            if(G == 1){
                if(checkDist(alibi, incidents[0].first, abs(time - incidents[0].second))){
                    // cout << i << " bad trivial " << endl;
                    bad ++;
                }
            }else{
                if(time < trips[0].timeStart){
                    int prequel = trips[0].timeStart - time;
                    if(checkDist(alibi, incidents[0].first, prequel)){
                        // cout << i << " bad prequel " << endl;
                        bad ++;
                    }
                }else if(time > trips[G - 1].timeEnd){
                    int sequel = time - trips[G - 1].timeEnd;
                    if(checkDist(alibi, incidents[G - 1].first, sequel)){
                        // cout << i << " bad sequel " << endl;
                        bad ++;
                    }
                }
            }
            continue;
        }

        Trip trip = trips[tripIndex];
        // cout << i << " " << tripIndex << " " << trip.timeStart << " " << trip.timeEnd << " detouring " << alibi.first << " " << alibi.second << " at: " << time << endl;
        if(viableDetour(trip, alibi, time)){
            // cout << i << " bad " << endl;
            bad ++;
        }
    }
    cout << (N - bad) << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
