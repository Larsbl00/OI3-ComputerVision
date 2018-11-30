#ifndef IVISION_H
#define IVISION_H

#include "Face.h"

#include <vector>

class IVision
{
    public: 
        ~IVision(){}
        
        virtual std::vector<Face>& GetFaces() = 0;
        virtual void ScanFaces() = 0;
};

#endif