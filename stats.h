
#include <vector>
#include <algorithm>
#include <numeric>

namespace Statistics {
class ComputeStatistics{ 
    public: 
         double average, max,min;  
         ComputeStatistics(const std::vector<float>& numbers );                 
};

class IAlerter{
public:
virtual void Alert();
    
};
class EmailAlert:public IAlerter{
    
public:
    bool emailSent;
                void  Alert()
                    {
                        emailSent = true;
                    }   
    
};



class LEDAlert:public IAlerter{
    
    
    
public:
    bool ledGlows;
                void  Alert()
                    {
                       ledGlows = true;
                    }   
    
};

class StatsAlerter
    {
      public:
        double MaxThresholds;
         std:: vector<IAlerter*> Alerters;
         StatsAlerter( double maxThresholds,const std:: vector<IAlerter*>& alerters);
       void checkAndAlert(const std:: vector<float> &Temperaturedata)
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
       
    };
    
    
    
}
