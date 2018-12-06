#include "Face.h"

/////////////////////
//Constructor
/////////////////////
Face::Face(const cv::Rect& faceRect)
    :center(faceRect.x + faceRect.width / 2, faceRect.y + faceRect.height / 2), face(faceRect)
{

}