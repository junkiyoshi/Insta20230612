#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int y = -300; y <= 300; y += 10) {

		auto radius = 300;

		ofPushMatrix();
		ofRotateY(ofRandom(360) + ofGetFrameNum() * ofRandom(1, 5));

		this->draw_arrow(glm::vec3(0, y, radius), glm::vec3(1, y, radius), 30, ofColor(0), ofColor(255));

		ofNoFill();
		ofSetColor(255, 64);
		ofSetLineWidth(1);
		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 3) {

			ofVertex(glm::vec3((radius - 3) * cos(deg * DEG_TO_RAD), y, (radius - 3) * sin(deg * DEG_TO_RAD)));
		}
		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_arrow(glm::vec3 location, glm::vec3 next_location, float size, ofColor fill_color, ofColor no_fill_color) {

	auto angle = std::atan2(next_location.y - location.y, next_location.x - location.x);

	ofSetColor(fill_color);
	ofFill();
	ofBeginShape();
	ofVertex(glm::vec3(size * 0.8 * cos(angle), size * 0.8 * sin(angle), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) + location);
	ofEndShape(true);

	ofBeginShape();
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 + location);
	ofEndShape(true);

	ofSetColor(no_fill_color);
	ofNoFill();
	ofSetLineWidth(3);
	ofBeginShape();
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) + location);
	ofVertex(glm::vec3(size * 0.8 * cos(angle), size * 0.8 * sin(angle), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 + location);
	ofEndShape();

	ofBeginShape();
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 + location);
	ofEndShape();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}