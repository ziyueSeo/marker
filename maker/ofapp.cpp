#include "stdafx.h"
#include "ofapp.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//--------------------------------------------------------------
/*void ofApp::setup(){
	//ofSetLogLevel(OF_LOG_VERBOSE);
	///ofBackground(50, 0);
	//ofSetWindowShape(640, 480);

	//ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.

	/*vector<string> model_names;
	model_names.push_back("astroBoy_walk.dae");

	for (int i = 0; i < model_names.size(); ++i)
	{
	ofxAssimpModelLoader model;
	model.loadModel(model_names[i]);
	model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
	model.playAllAnimations();

	m_models.push_back(model);
	}
	m_meshes.resize(model_names.size(), ofMesh());*/

	/*m_video=VideoCapture(0);
	//m_video.(640, 480);

	Point3f corners_3d[] =
	{
		Point3f(-0.5f, -0.5f, 0),
		Point3f(-0.5f, 0.5f, 0),
		Point3f(0.5f, 0.5f, 0),
		Point3f(0.5f, -0.5f, 0)
	};
	float camera_matrix[] =
	{
		848.069f, 0.0f, 268.697f,
		0.0f, 847.687f, 264.266f,
		0.0f, 0.0f, 1.0f
	};
	float dist_coeff[] = { -0.445957f, 0.278828f, -0.002213f, -0.000656f };

	m_corners_3d = vector<Point3f>(corners_3d, corners_3d + 4);
	//Mat���캯�����´�����ݣ�ֻ�Ὣָ��ָ�������������Զ��ھֲ������ڴ棬��Ҫclone
	m_camera_matrix = Mat(3, 3, CV_32FC1, camera_matrix).clone();
	m_dist_coeff = Mat(1, 4, CV_32FC1, dist_coeff).clone();
}*/

//--------------------------------------------------------------
void ofApp::update(){
	//m_video = VideoCapture(0);
	/*for (int i = 0; i < m_models.size(); ++i)
	{
	m_models[i].update();
	m_meshes[i] = m_models[i].getCurrentAnimatedMesh(0);
	}*/

	//m_video.update();
//for (;;)
	//{ 
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
		//case OF_PIXELS_BGRA:
		//	m_img_color.create(height, width, CV_8UC4);
		//	memcpy(m_img_color.data, m_video.getPixels(), height*width * 4);
		//	cvtColor(m_img_color, m_img_gray, CV_BGRA2GRAY);
		//	break;
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
	
}

//--------------------------------------------------------------
/*void ofApp::draw(){

	//ofSetColor(255);
	//float view_width = ofGetViewportWidth();
	//float view_height = ofGetViewportHeight();
	//m_video.draw(0, 0, view_width, view_height);

	//Set camera matrix to the opengl projection matrix;
	intrinsicMatrix2ProjectionMatrix(m_camera_matrix, 640, 480, 0.01f, 100.0f, m_projection_matrix);
	ofSetMatrixMode(OF_MATRIX_PROJECTION);
	//Openframeworks�ｫ(-1, -1)ӳ�䵽��Ļ���Ͻǣ�����һ������½ǣ�������Ҫһ��������д�ֱ����
	static float reflect[] =
	{
		1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	ofLoadMatrix(reflect);
	//OpenGLĬ��Ϊ�ҳ�
	ofMultMatrix(m_projection_matrix);

	//Reset model view matrix to identity;
	ofSetMatrixMode(OF_MATRIX_MODELVIEW);
	ofLoadIdentityMatrix();

	//ofDrawPlane(-1,-1,-1,2,2);

	//Set opengl parameters
	//ofSetColor(255);
	//ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	//ofEnableDepthTest();
	//glShadeModel(GL_SMOOTH); //some model / light stuff
	//m_light.enable();
	//ofEnableSeparateSpecularLight();

	vector<Marker>& markers = m_recognizer.getMarkers();
	Mat r, t;
	for (int i = 0; i < markers.size(); ++i)
	{
		//�������ת����r������ʽΪ+1����Ϊ����任�����Բ��ı�����ϵ������
		markers[i].estimateTransformToCamera(m_corners_3d, m_camera_matrix, m_dist_coeff, r, t);
		extrinsicMatrix2ModelViewMatrix(r, t, m_model_view_matrix);
		ofLoadMatrix(m_model_view_matrix);

		//Draw the model
		/*ofxAssimpModelLoader& model = m_models[i%m_models.size()];
		model.setScale(0.01f,0.01f,0.01f);
		model.setRotation(0, 90, 1, 0, 0);
		model.drawFaces();*/

		//ofSetColor(0x66, 0xcc, 0xff);
		//����Marker����ϵ��OpenCV����ϵ������һ�£�����Marker����ϵ��Z�ᴹֱ��Marker����
		//����Boxʱ��Anchor��Box���ģ�������Ҫ-0.5*size��ƫ�Ʋ���ʹBox�ĵ�����Marker�ϣ���
		//ofDrawBox(0, 0, -0.4f, 0.8f);
	/*}

	//Reset parameters
	//ofDisableDepthTest();
	//m_light.disable();
	//ofDisableLighting();
	//ofDisableSeparateSpecularLight();

	//ofSetMatrixMode(OF_MATRIX_MODELVIEW);
	//ofLoadIdentityMatrix();
	//ofSetMatrixMode(OF_MATRIX_PROJECTION);
	//ofLoadIdentityMatrix();
}*/

//--------------------------------------------------------------
/*void ofApp::keyPressed(int key){
	if (key == 's')
	{
		string name = ofGetTimestampString();
		imwrite(name + ".jpg", m_img_gray);
		cout << "Frame " << name << " has been saved!" << endl;
	}
}*/

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

void ofApp::intrinsicMatrix2ProjectionMatrix(cv::Mat& camera_matrix, float width, float height, float near_plane, float far_plane, float* projection_matrix)
{
	float f_x = camera_matrix.at<float>(0, 0);
	float f_y = camera_matrix.at<float>(1, 1);

	float c_x = camera_matrix.at<float>(0, 2);
	float c_y = camera_matrix.at<float>(1, 2);

	projection_matrix[0] = 2 * f_x / width;
	projection_matrix[1] = 0.0f;
	projection_matrix[2] = 0.0f;
	projection_matrix[3] = 0.0f;

	projection_matrix[4] = 0.0f;
	projection_matrix[5] = 2 * f_y / height;
	projection_matrix[6] = 0.0f;
	projection_matrix[7] = 0.0f;

	projection_matrix[8] = 1.0f - 2 * c_x / width;
	projection_matrix[9] = 2 * c_y / height - 1.0f;
	projection_matrix[10] = -(far_plane + near_plane) / (far_plane - near_plane);
	projection_matrix[11] = -1.0f;

	projection_matrix[12] = 0.0f;
	projection_matrix[13] = 0.0f;
	projection_matrix[14] = -2.0f*far_plane*near_plane / (far_plane - near_plane);
	projection_matrix[15] = 0.0f;
}

void ofApp::extrinsicMatrix2ModelViewMatrix(cv::Mat& rotation, cv::Mat& translation, float* model_view_matrix)
{
	//��X����ת180�ȣ���OpenCV����ϵ�任ΪOpenGL����ϵ
	static double d[] =
	{
		1, 0, 0,
		0, -1, 0,
		0, 0, -1
	};
	Mat_<double> rx(3, 3, d);

	rotation = rx*rotation;
	translation = rx*translation;

	model_view_matrix[0] = rotation.at<double>(0, 0);
	model_view_matrix[1] = rotation.at<double>(1, 0);
	model_view_matrix[2] = rotation.at<double>(2, 0);
	model_view_matrix[3] = 0.0f;

	model_view_matrix[4] = rotation.at<double>(0, 1);
	model_view_matrix[5] = rotation.at<double>(1, 1);
	model_view_matrix[6] = rotation.at<double>(2, 1);
	model_view_matrix[7] = 0.0f;

	model_view_matrix[8] = rotation.at<double>(0, 2);
	model_view_matrix[9] = rotation.at<double>(1, 2);
	model_view_matrix[10] = rotation.at<double>(2, 2);
	model_view_matrix[11] = 0.0f;

	model_view_matrix[12] = translation.at<double>(0, 0);
	model_view_matrix[13] = translation.at<double>(1, 0);
	model_view_matrix[14] = translation.at<double>(2, 0);
	model_view_matrix[15] = 1.0f;
}
int _tmain(int argc, _TCHAR* argv[])
{
	ofApp test;
	test.update();
	//delete ofApp();
	system("pause");
	return 0;
}

