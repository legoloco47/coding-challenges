#include <vector>

/*
  for each incoming car, we have a pair (start point, end point) and speeds

  
 car 0:
    ex: (7,13) -> 15mph
    ex: (18,22) -> 25mph
 return vector range: (7,22) ? or (0,22)?
 0,0,0,0,0,0,15,15,15,15,15,15,15,0,0,0,0,25,25,25,25,25  
  
 car 1:
    ex: (0,5) -> 40mph
    ex: (10,20) -> 15mph
    ex: (15,20) -> 25mph
    
  map<string, int> speedPoints;
  // key is of the structure: to_string(segment_start) + "|" + to_string(segment_end);
*/

  /*
   car 0:
    ex: [7,13] -> 15mph
    ex: [18,22] -> 25mph
 return vector range: (7,22) ? or (0,22)?
 0,0,0,0,0,0,15,15,15,15,15,15,15,0,0,0,0,25,25,25,25,25  


 SpeedSegmentTotals: 0,0,20,40,0,0,15,15,15,15,15,15,15,0,0,0,0,25,25,25,25,25  
 SpeedSegmentCounts: 0 0 1,2,2,0,1,1...
  */


struct Car {
  int id;
  map<string,int> speedPoints;
};

int getFirstSegment(string key){
  //parse the key
  //return the beginning segment from the string
  
  return number1;
}

int getSecondSegment(string key){
  //parse the key
  //return the beginning segment from the string
  return number2;
}



double [] calculateSewgmentAverages(vector<Car> cars) {
  // need to figure out how many segments i have

  int NumberCars = cars.size(); 
 
  map<int, int> SpeedSegmentTotals; // int->segment number, 2nd int->speed total
  
    //  how many speeds we have seen for the segment, 
   map<int, int> SpeedSegmentCounts; // // int->segment number, 2nd int->how many speeds we have seen for that segment
  
   int maxSegmentSeen = 0;
    
  // TODO: make sure have cars
  if (NumberCars == 0) return [0];

    //O(number of cars * largest # history segments * maxSegmentSeen)
  
    //O(c*h*maxSegmentSeen);
  
    // get all history data for all segments
    for (int i = 0; i < NumberCars; i++) {
        Car c = cars[i];
        map<string, int> speedPoint = c.speedPoints;
        for (map<string,int>::iterator it = speedPoint.begin(); it!=speedPoint.end(); ++it) {
          
            string key= it->first;
            int speed = it->second;
            int s1 = getFirstSegment(key);
            int s2 = getSecondSegment(key);
          
            if (s2 > maxSegmentSeen) maxSegmentSeen = s2;
          
            for (int j = s1; j <= s2; j++){
                if (SpeedSegmentTotals.count(j)) {
                  SpeedSegmentTotals[j] += speed;
                  SpeedSegmentCounts[j]++;
                }
                else {
                  SpeedSegmentTotals[j]  = speed;
                  SpeedSegmentCounts[j] = 1;
                }
            }          
        }
    }
  
  double speedAvgs[maxSegmentSeen + 1];
  memset(speedAvgs, 0, sizeof(speedAvgs));
  
  // calculate averages for all segments
  for (int segment = 0; segment <= maxSegmentSeen; segment++){
      if (SpeedSegmentTotals.count(segment)) {
          speedAvgs[segment] = SpeedSegmentTotals[segment] / SpeedSegmentCounts[segment];
      }
  }
  
  return speedAvgs;
  
}
           
           
           
//problems solved:
//  Note: ensure that, if we see a new incoming segment that is > anything we have seen before, need to "pad" zeros up to that speed
