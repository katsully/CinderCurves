//
//  PaintSpot.cpp
//  RandomProject
//
//  Created by Kathleen Sullivan on 5/29/15.
//
//

#include "Line.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"

using namespace ci;

Line::Line(){
}

Line::Line( Vec2f mMousePosition ){
    mMouseLoc = Vec2f( mMousePosition );
    mNOff = Vec2f ( randFloat( 1000 ), randFloat( 1000 ) );
    noiseCount = randFloat( 1000.0f );
    //noiseColor = 0.0f;
    mColor = Color(CM_HSV, Rand::randFloat(), 1.0f, 1.0f );

    //mColor = Color(CM_RGB, Vec3f(1.0f, 0.0f, 0.0f));
    mPerlin = Perlin();
}

void Line::createVectors(){
    mVectors.clear();
    int radius = Rand::randInt(50, 200);
    float numPoints = 100.0f;
    float pointDegree = 300 / numPoints;
    for( int i=0; i < numPoints; i++ ){
        float x = cos( pointDegree * i) * radius;
        float y = sin( pointDegree * i) * radius;
        //float n = mPerlin.fBm( noiseCount ) * 20;
        mVectors.push_back( Vec2f( x + mMouseLoc.x, y + mMouseLoc.y ) );
        //noiseCount += 0.01f;
    }
    mPath.clear();
        for(int i=0;i<mVectors.size()-1;++i) {
                // find out which 4 points are needed for this part of the curve
                int a = i-1; if(a<0) a = 0;
                int b = i;
                int c = i+1; if(c>=mVectors.size()) c = mVectors.size() - 1;
                int d = i+2; if(d>=mVectors.size()) d = mVectors.size() - 1;
        
                // get the 4 points
                Vec2f p0 = mVectors[a];
                Vec2f p1 = mVectors[b];
                Vec2f p2 = mVectors[c];
                Vec2f p3 = mVectors[d];
        
                // calculate the control points
                Vec2f b1 = p1 + (p2 - p0) / 6.0f;
                Vec2f b2 = p2 - (p3 - p1) / 6.0f;
        
                // draw the path
            if(i==0) mPath.moveTo(p1);
//            mColor.r += noiseColor;
//            gl::color( mColor );
           mPath.curveTo(b1, b2, p2);
        }
}

void Line::render(){
   gl::color( Color( mColor) );
    
   gl::draw( mPath );
}

