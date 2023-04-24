#include "Mymath.h"

#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include <cmath>


Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	Matrix4x4 scaleMatrix_ = {
		scale.x,0,0,0,
		0,scale.y,0,0,
		0,0,scale.z,0,
		0,0,0,1
	};

	Matrix4x4 rotZ_ = {
		std::cosf(rot.z),std::sinf(rot.z),0,0,
		-std::sinf(rot.z),std::cosf(rot.z),0,0,
		0,0,1,0,
		0,0,0,1
	};
	Matrix4x4 rotX_ = {
		1,0,0,0,
		0,std::cosf(rot.x),std::sinf(rot.x),0,
		0,-std::sinf(rot.x),std::cosf(rot.x),0,
		0,0,0,1
	};
	Matrix4x4 rotY_ = {
		std::cosf(rot.y),0,-std::sinf(rot.y),0,
		0,1,0,0,
		std::sinf(rot.y),0,std::cosf(rot.y),0,
		0,0,0,1
	};
	Matrix4x4 rotateMatrix_ = Multiply(Multiply(rotX_, rotY_), rotZ_);

	Matrix4x4 translateMatrix_ = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translate.x,translate.y,translate.z,1
	};

	return Multiply(Multiply(scaleMatrix_, rotateMatrix_), translateMatrix_);
}