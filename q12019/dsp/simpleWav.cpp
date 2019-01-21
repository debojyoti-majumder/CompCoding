// This is a smaple file just to show the signal genration

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class SinWave {
    private:
        double _amplitude;
        double _frequency;
        double _phase;
        double _t;

        long _sampleCount;
        
    public:
        SinWave(double amp, double f) : _amplitude(amp), _frequency(f) {
            _sampleCount = 44100;
            _t = 1.0 / _sampleCount;
            _phase = 0;
        }

        double next() {
            auto omega = 2 * M_PI * _frequency;
            auto retVal = _amplitude*sin(omega * _t + _phase);
            
            _t += 1.0 / _sampleCount;
            return retVal;
        }

        inline void reset() { _sampleCount = 0; }
};

class CompoundSinwave {
    private:
        vector<SinWave> _componenets; 

    public:
        CompoundSinwave(initializer_list<SinWave> waves) : _componenets(waves) {
        }

        double next() {
            double accumulatedValue {0.0};
            
            // TODO: Fix this Adding up all the components
            for(auto& waveform : _componenets)
                accumulatedValue += waveform.next();

            return accumulatedValue;
        }
};


int main() {
  // This is still buggy
  CompoundSinwave wave{
        SinWave {0.6, 440}
    };
    
    
    for(auto i=0; i<1200; i++) {
        cout << wave.next() << endl;
    }

    return 0;
}
