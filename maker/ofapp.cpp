#include "stdafx.h"
#include "ofapp.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::update(){
	
	Mat frame=imread("E:\\xuexi\\chengxu\\maker\\marker.jpg");
	resize(frame, frame, Size(400, 300));
	imshow("frame_1", frame);
		//m_video >> frame;
	if (!frame.empty())
	{
		bool good_format = true;
		int width = frame.rows;
		int height = frame.cols;
		m_img_gray.create(height, width, CV_8UC1);

		//ofPixelFormat format = m_video.getPixelFormat();
		switch (frame.channels())
		{
		case 3:
			m_img_color.create(height, width, CV_8UC3);
			//memcpy(m_img_color.data, m_video.getPixels(), height*width * 3);
			m_img_color = frame.clone();
			cvtColor(m_img_color, m_img_gray, CV_RGB2GRAY);
			break;
		case 4:
			m_img_color.create(height, width, CV_8UC4);
			//memcpy(m_img_color.data, m_video.getPixels(), height*width * 4);
			m_img_color = frame.clone();
			cvtColor(m_img_color, m_img_gray, CV_RGBA2GRAY);
			break;
		
		default:
			good_format = false;
			cout << "Unsupported video format!" << endl;
			break;
		}
	
		if (!good_format) return;
		cout<<m_recognizer.update(m_img_gray, 100);
	}
	else cout << "you input an wrong image." << endl;
	//m_recognizer.drawToImage();
	waitKey(30);
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){

//}

//--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){

//}


int _tmain(int argc, _TCHAR* argv[])
{
	ofApp test;
	test.update();
	//delete ofApp();
	system("pause");
	return 0;
}

