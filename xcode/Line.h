//
//  PaintSpot.h
//  RandomProject
//
//  Created by Kathleen Sullivan on 5/29/15.
//
//

#include "cinder/Perlin.h"
#include <vector>

using namespace ci;
using namespace std;

class Line {
public:
    Line();
    Line( Vec2f );
    void createVectors();
    void render();
    
    ci::Color mColor;
    float noiseCount;
    float noiseColor;
    Vec2f mMouseLoc;
    Vec2f mNOff;
    
    std::vector<ci::Vec2f> mVectors;
    ci::Perlin mPerlin;
    
    Path2d mPath;
};