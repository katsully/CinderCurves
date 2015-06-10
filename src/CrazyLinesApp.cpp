#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Line.h"
#include <list>

using namespace ci;
using namespace ci::app;

class CrazyLinesApp : public AppNative {
public:
    void prepareSettings ( Settings *settings );
    void setup();
    void mouseDown( MouseEvent event );
    void dS();
    void draw();
    
    Vec2f mMousePosition;
    
    std::list<Line> mPaintSpots;
};

void CrazyLinesApp::prepareSettings( Settings *settings ){
    settings->setWindowSize( 1000, 1000 );
}

void CrazyLinesApp::setup(){
    gl::clear( Color ( 1, 1, 1 ) );
}

void CrazyLinesApp::mouseDown( MouseEvent event ){
    mMousePosition = event.getPos();
    Line mPaintSpot = Line( mMousePosition );
    mPaintSpot.createVectors();
    mPaintSpots.push_back( mPaintSpot );
}

void CrazyLinesApp::draw(){
    for( std::list<Line>::iterator p = mPaintSpots.begin(); p != mPaintSpots.end(); ++p ){
        p->render();
    }
}

CINDER_APP_NATIVE( CrazyLinesApp, RendererGl )
