/*
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Vector2D {

public:
	Vector2D(float X = 0, float Y = 0) {
		x = X;
		y = Y;
	};

	~Vector2D() {
	};

	float x, y;

	Vector2D operator*(float scalar) const {
		return Vector2D(x * scalar, y * scalar);
	}

	Vector2D operator+(const Vector2D &vect) const {
		return Vector2D(x + vect.x, y + vect.y);
	}

	Vector2D operator-(const Vector2D &vect) const {
		return Vector2D(x - vect.x, y - vect.y);
	}

	void rotate(float angle) {
		float xt = (x * cosf(angle)) - (y * sinf(angle));
		float yt = (y * cosf(angle)) + (x * sinf(angle));
		x = xt;
		y = yt;
	}

	float crossproduct(const Vector2D &vect2) const {
		return (this->x * vect2.y) - (this->y * vect2.x);
	}

	float magnitude() {
		return sqrtf(x * x + y * y);
	}

	void normalise() {
		float mag = sqrtf(x * x + y * y);
		this->x = x / mag;
		this->y = y / mag;
	}

	// return dot product
	float dotproduct(const Vector2D &vect) const {
		return (x * vect.x) + (y * vect.y);
	}
};

int main() {
	cout << "### VECTOR INITIALISE ###" << endl;
	cout << "We are now initilising a vector [3, 3]. Results: " << endl;
	Vector2D vec(3, 3);
	cout << "new x: " << vec.x << endl;
	cout << "new y: " << vec.y << endl;

	cout << endl << "### VECTOR NORMALISE ###" << endl;
	vec.normalise();
	cout << "We are now normalising a vector [3, 3]. Results: " << endl;
	cout << "new x: " << vec.x << endl;
	cout << "new y: " << vec.y << endl;
	cout << "new mag: " << vec.magnitude() << endl;

	cout << endl << "### VECTOR MULTIPLICATION BY SCALAR ###" << endl;
	cout << "We are now multiplying a vector [10,10] by the scalar 5. Results: "
			<< endl;
	Vector2D vec2(10, 10);
	Vector2D vec3 = vec2 * 5;
	cout << "new x: " << vec3.x << endl;
	cout << "new y: " << vec3.y << endl;

	cout << endl << "### VECTOR CROSS PRODUCT ###" << endl;
	cout << "Cross product between vectors [1,2] and [2,4] Results: " << endl;
	Vector2D vec4(1, 2);
	Vector2D vec5(2, 4);
	double cp = vec4.crossproduct(vec5);
	cout << "Cross product: " << cp << endl;

	cout << endl << "### VECTOR ROTATION ###" << endl;
	cout << "Rotating a vector (10, 0) by 90 degrees CCW. Results: " << endl;
	Vector2D vec6(10, 0);
	vec6.rotate(90 * (3.14159265 / 180)); // remember to convert deg to rad
	cout << "new x: " << vec6.x << endl;
	cout << "new y: " << vec6.y << endl;

	cout << endl << "### VECTOR DOT PRODUCT ###" << endl;
	cout << "Dot product between vectors [5,5] and [10,10] Results: " << endl;
	Vector2D vec7(5, 5);
	Vector2D vec8(10, 10);
	double dp = vec7.dotproduct(vec8);
	cout << "Dot product: " << dp << endl;
	return 0;
}
*/
