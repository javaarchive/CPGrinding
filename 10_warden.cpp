#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
#define SIDE 150
//            123456
#define FULL 1000000
//            12345
#define HALF 500000
#define TEST_MULT 1.0f

double sin_deg(double deg){
    return sin(deg * M_PI / 180);
}

double cos_deg(double deg){
    return cos(deg * M_PI / 180);
}

double pulseAt(double x, double y){
    cout << "P " << x << " " << y << endl;
    double dist; 
    cin >> dist;
    // subtract warden -> pulse loc
    dist -= sqrt(x*x + y*y);
    dist = dist/2; // divide by 2 cause symmetry
    return dist; 
}

double pulseDeg(double deg){
    double dist = pulseAt(cos_deg(deg) * TEST_MULT, sin_deg(deg)*TEST_MULT);
    return dist;
}

double pulseRange(int degStart, int degEnd,int count){
    double starting = degStart;
    double startingDist = pulseDeg(starting);
    double ending = degEnd;
    double endingDist = pulseDeg(ending);
    for(int i = 0; i < count; i ++){
        double mid = (starting + ending)/2.0f;
        // cout << starting << " " << mid << " " << ending << endl;
        double midDist = pulseDeg(mid);
        double startDiff = startingDist - midDist;
        double endDiff = endingDist - midDist;
        if(startDiff < endDiff){
            ending = mid;
            endingDist = midDist;
        }else{
            starting = mid;
            startingDist = midDist;
        }
    }
    return (starting + ending) / 2.0f;
}

void solve(){
    double q1 = pulseAt(HALF, HALF);
    double q2 = pulseAt(-HALF, HALF);
    double q3 = pulseAt(-HALF, -HALF);
    double q4 = pulseAt(HALF, -HALF);
    // Now we find which one is the best of them all
    double finalDegree = 0;
    if(q1 < q2 && q1 < q3 && q1 < q4){
        finalDegree = pulseRange(0, 90,SIDE);
    }else if(q2 < q1 && q2 < q3 && q2 < q4){
        finalDegree = pulseRange(90, 180,SIDE);
    }else if(q3 < q1 && q3 < q2 && q3 < q4){
        finalDegree = pulseRange(180, 270,SIDE);
    }else if(q4 < q1 && q4 < q2 && q4 < q3){
        finalDegree = pulseRange(270, 360,SIDE);
    }
    // cout << "Angle determined to be " << finalDegree << endl;
    // Determined degree, now start the process of extending
    double y = sin_deg(finalDegree);
    double x = cos_deg(finalDegree);
    double multiplier = pulseAt(x,y) + 1;
    x = x * multiplier;
    y = y * multiplier;
    // pray!
    cout << "B " << x << " " << y << endl;
    string verdict;
    cin >> verdict;
    if(verdict[0] == 'W'){
        exit(0);
    }
}

int main(int argc, char const *argv[])
{
    setprecision(10);
    while(true) solve();
    return 0;
}
