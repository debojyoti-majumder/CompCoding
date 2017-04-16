#include <string>
#include <sstream>

bool bDirty = true;

int slotId = 0;
char instrumentType[100];


int setSlotNumber(String data) {
    bDirty = true;
    slotId = data.toInt();
    
    return 0;
}

int setInstrumentType(String data) {
    bDirty = true;
    data.toCharArray(instrumentType, 100);
    
    return 0;
}

void setup() {
    strcpy(instrumentType,"generic");
    
    // variable name max length is 12 characters long
    Particle.variable("hwSlotId", &slotId, INT);
    Particle.variable("instType", instrumentType, STRING);
    
    Particle.function("setType", setInstrumentType);
    Particle.function("setId", setSlotNumber);
}


void loop() {
    
    if( bDirty ) {
        std::stringstream activationdata;
        
        activationdata << instrumentType << "/" << slotId;
        bool isPublished = Particle.publish("adpater-activated", activationdata.str().c_str());
        
        if( isPublished ) {
            bDirty = false;    
        }
    }
}
