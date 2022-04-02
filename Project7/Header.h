#ifndef MATH_3d_H
#define MATH_3D_H


struct Vector3f
{
	float x, y, z;

	Vector3f()
	{
	}

	Vector3f(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

#endif /* MATH_3D_H */
#pragma once
