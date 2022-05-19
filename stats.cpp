#include "stats.h"
#include <algorithm>
#include <numeric>
#include <math.h> 
#include <vector>

using namespace Statistics;
using namespace std;
ComputeStatistics::ComputeStatistics(const std::vector<float>&numbers) {
       
    if (numbers.empty())        
        {            
        max = NAN;
        min = NAN;
        average=NAN; 
        }
    else
        {
        max = *max_element(numbers.begin(), numbers.end());
        min = *min_element(numbers.begin(), numbers.end());
        average=std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();        
        }  
}
StatsAlerter::StatsAlerter(double maxThresholds, const std:: vector<IAlerter*> &alerters){
    MaxThresholds=maxThresholds;    
    Alerters= alerters; 
    }

 StatsAlerter :: checkAndAlert(const std:: vector<float> &Temperaturedata)
        {
            double maximum = *max_element(Temperaturedata.begin(), Temperaturedata.end());
            if (maximum >= MaxThresholds)
            {
                EmailAlert TempemailAlert;
                LEDAlert TempledAlert;
                TempemailAlert.Alert();
                TempledAlert.Alert();
               
            }
        }

        


       

      

