#pragma once
#include <windows.h>
#include <vector>

#pragma warning ( disable : 26495 )

class vec2
{
public:
	float x;
	float y;

	vec2( )
	{}

	vec2( float x, float y )
		: x( x ), y( y )
	{}

	vec2 operator+( const vec2& vector ) const
	{
		return vec2( x + vector.x, y + vector.y );
	}

	vec2 operator-( const vec2& vector ) const
	{
		return vec2( x - vector.x, y - vector.y );
	}

	auto empty( ) -> bool { return x == 0 && y == 0; }

	auto off_screen( ) -> bool { return x == -1; }
};

class vec3
{
public:
	float x;
	float y;
	float z;

	vec3( )
	{}

	vec3( float x, float y, float z )
		: x( x ), y( y ), z( z )
	{}

	vec3 operator+( const vec3& vector ) const
	{
		return vec3( x + vector.x, y + vector.y, z + vector.z );
	}

	vec3 operator-( const vec3& vector ) const
	{
		return vec3( x - vector.x, y - vector.y, z - vector.z );
	}

	vec3 operator * ( float number ) const
	{
		return vec3( x * number, y * number, z * number );
	}

	vec3 operator/( float number ) const
	{
		return vec3( x / number, y / number, z / number );
	}

	vec3& operator/=( float number )
	{
		x /= number;
		y /= number;
		z /= number;

		return *this;
	}

	auto empty( ) -> bool { return x == 0 && y == 0 && z == 0; }

	auto off_screen( ) -> bool { return x == -1; }
};

class vec4
{
public:
	float x;
	float y;
	float z;
	float w;

	vec4( ) {}
	vec4( float x, float y, float z, float w ) : x( x ), y( y ), z( z ), w( w ) {}

	bool operator==( const vec4& vector ) const
	{
		return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
	}

	bool operator!=( const vec4& vector ) const
	{
		return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
	}

	vec4 operator+( const vec4& vector ) const
	{
		return vec4( x + vector.x, y + vector.y, z + vector.z, w + vector.w );
	}

	vec4 operator-( const vec4& vector ) const
	{
		return vec4( x - vector.x, y - vector.y, z - vector.z, w - vector.w );
	}

	vec4 operator-( ) const
	{
		return vec4( -x, -y, -z, -w );
	}

	vec4 operator*( float number ) const
	{
		return vec4( x * number, y * number, z * number, w * number );
	}

	vec4 operator/( float number ) const
	{
		return vec4( x / number, y / number, z / number, w / number );
	}

	vec4& operator+=( const vec4& vector )
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	vec4& operator-=( const vec4& vector )
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	vec4& operator*=( float number )
	{
		x *= number;
		y *= number;
		z *= number;
		w *= number;
		return *this;
	}

	vec4& operator/=( float number )
	{
		x /= number;
		y /= number;
		z /= number;
		w /= number;
		return *this;
	}
};