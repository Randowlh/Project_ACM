#include <iostream>
#include <cmath>
#include <cfloat>
#include <cstdlib>

#pragma warning(disable: 4996)
#pragma warning(disable: 4305)
#pragma warning(disable: 4244)

struct vec2 
{
	float x;
	float y;
	vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	vec2(float v)
	{
		x = v;
		y = v;
	}
	vec2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	vec2& operator+=(const vec2& v)
	{ 
		x += v.x;   
		y += v.y; 
		return *this; 
	}
	vec2& operator-=(const vec2& v)
	{ 
		x -= v.x;   
		y -= v.y;   
		return *this; 
	}
	vec2& operator*=(float s)
	{ 
		x *= s;   
		y *= s;   
		return *this; 
	}
	vec2& operator/=(float s)
	{ 
		x /= s; 
		y /= s; 
		return *this; 
	}
};

inline vec2 operator+(const vec2 &u, const vec2 &v)
{ 
	return vec2(u.x + v.x, u.y + v.y);
}

inline vec2 operator-(const vec2 &u, const vec2 &v)
{ 
	return vec2(u.x - v.x, u.y - v.y); 
}

struct mat2
{
    float    _11, _12;
    float    _21, _22;

    mat2() : 
        _11(1.0f), _12(0.0f),
        _21(0.0f), _22(1.0f){};

    mat2(float m11, float m12,
         float m21, float m22) : 
        _11(m11), _12(m12),
        _21(m21), _22(m22){};

    mat2(const vec2& v1,
         const vec2& v2) : 
        _11(v1.x), _12(v1.y),
        _21(v2.x), _22(v2.y){};

    mat2(const mat2 &m) : 
        _11(m._11), _12(m._12),
        _21(m._21), _22(m._22){};

    mat2& operator = (const mat2& m)
    {
        _11 = m._11; _12 = m._12;
        _21 = m._21; _22 = m._22;
        return *this;
    }
};

inline mat2 operator*(const mat2 &m2, const mat2 &m1)
{ 
	return mat2(m1._11*m2._11 + m1._12*m2._21, m1._11*m2._12 + m1._12*m2._22,
				m1._21*m2._11 + m1._22*m2._21, m1._21*m2._12 + m1._22*m2._22);
}

inline vec2 operator*(const vec2 &v, const mat2 &m)
{ 
	return vec2(m._11*v.x + m._12*v.y, m._21*v.x + m._22*v.y);
}

inline vec2 operator*(const mat2 &m, const vec2 &v)
{ 
	return vec2(m._11*v.x + m._21*v.y, m._12*v.x + m._22*v.y);
}

inline vec2 abs(const vec2 &u)
{
	return vec2(fabsf(u.x), fabsf(u.y));
}

inline vec2 normalize(const vec2 &u)
{
	float k = sqrtf(u.x*u.x + u.y*u.y);
	if (k > FLT_EPSILON)
	{
		return vec2(u.x / k, u.y / k);
	}
	else
	{
		return vec2(1.0f, 0.0f);
	}
}

inline float length(const vec2 &u)
{
	return sqrtf(u.x*u.x + u.y*u.y);
}

inline float dot(const vec2 &u, const vec2 &v)
{
	return u.x*v.x + u.y*v.y;
}

inline float distance(const vec2 &u, const vec2 &v)
{
	float x = u.x - v.x;
	float y = u.y - v.y;
	return sqrtf(x*x + y*y);
}

inline mat2 inv(const mat2 &m)
{
	//return m;
	float k = m._11*m._22 - m._12*m._21;
	if (fabsf(k) < FLT_EPSILON)
	{
		return mat2();
	}
	else
	{
		return mat2( m._22/k, -m._12/k, 
			        -m._21/k,  m._11/k);
	}
}

struct bvec2 
{
	bool x;
	bool y;
	bvec2(bool _x, bool _y)
	{
		x = _x;
		y = _y;
	}
};

inline bvec2 lessThan(const vec2 &u, const vec2 &v)
{
	return bvec2(u.x < v.x, u.y < v.y);
}

inline bool all(bvec2 v)
{
	return v.x && v.y;
}

float abs_min(float a, float b)
{
	if(abs(a)<abs(b))
	{
		return a;
	}
	else
	{
		return b;
	}
}

#ifndef max
  #define max(a,b)          (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
  #define min(a,b)          (((a) < (b)) ? (a) : (b))
#endif

inline float smoothstep(float edge0, float edge1, float x)
{
	if (x < edge0)
	{
		return 0.0f;
	}
	else if (x > edge1)
	{
		return 1.0f;
	}

	float t = (x-edge0) / (edge1-edge0);
	return -2*t*t*t + 3*t*t;
}

float border;

float line_dist(const vec2& uv, const vec2& p0, const vec2& p1)
{
	vec2 tang=p1-p0;
	vec2 nor=normalize(vec2(tang.y,-tang.x));

	if(dot(tang,uv)<dot(tang,p0))
	{
		return distance(p0,uv);
	}
	else if(dot(tang,uv)>dot(tang,p1))
	{
		return distance(p1,uv);
	}
	else
	{
		return dot(nor,uv)-dot(nor,p0);
	}
}

bool tri_test(vec2 uv, vec2 p0, vec2 p1, vec2 p2, bool inside)
{
	vec2 nor1=normalize(p0-p1);
	nor1=vec2(nor1.y,-nor1.x);
	vec2 nor2=normalize(p1-p2);
	nor2=vec2(nor2.y,-nor2.x);
	vec2 tan3=normalize(p2-p0);
	vec2 nor3=vec2(tan3.y,-tan3.x);

	if(inside)
	{
		if(dot(tan3,p0)>=dot(tan3,uv) || dot(tan3,p2)<=dot(tan3,uv))
		{
			return false;
		}

		float brd=max(dot(nor3,nor1),dot(nor3,nor2))*border;
		return (dot(uv,nor1)>=dot(p0,nor1) && dot(uv,nor2)>=dot(p1,nor2) && dot(uv,nor3)>=dot(p2,nor3)+brd) ||
			   (dot(uv,nor1)<=dot(p0,nor1) && dot(uv,nor2)<=dot(p1,nor2) && dot(uv,nor3)<=dot(p2,nor3)-brd);
	}
	else
	{
		float brd1=dot(nor1,tan3)*border;
		float brd2=dot(nor2,tan3)*border;

		if(dot(tan3,p0)>=dot(tan3,uv)-brd1 || dot(tan3,p2)<=dot(tan3,uv)-brd2)
		{
			return false;
		}
		return (dot(uv,nor1)>=dot(p0,nor1)-border && dot(uv,nor2)>=dot(p1,nor2)-border && dot(uv,nor3)>=dot(p2,nor3)) ||
			   (dot(uv,nor1)<=dot(p0,nor1)+border && dot(uv,nor2)<=dot(p1,nor2)+border && dot(uv,nor3)<=dot(p2,nor3));
	}

}

float bezier_sd(vec2 uv, vec2 p0, vec2 p1, vec2 p2)
{
	const mat2 trf1 = mat2(-1, 2, 1, 2);
	mat2 trf2 = inv(mat2(p0-p1, p2-p1));
	mat2 trf=trf1*trf2;

	uv-=p1;
	vec2 xy=trf*uv;
	xy.y-=1.;

	vec2 gradient;
	gradient.x=2.*trf._11*(trf._11*uv.x+trf._21*uv.y)-trf._12;
	gradient.y=2.*trf._21*(trf._11*uv.x+trf._21*uv.y)-trf._22;

	return (xy.x*xy.x-xy.y)/length(gradient);
}

float render_sans(vec2 uv)
{
	uv.y-=0.5;
	uv*=1.2;
	border*=1.2;
	uv.y+=.5;

	float d = 1e38;
	float poly_d = 1e38;
	float d1 = 1e38;

	vec2 p0,p1,p2;

	if(all(lessThan(abs(uv-vec2(-0.953247597619,0.496502840202)),vec2(0.0745283174023,0.11602795054)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.02777591502,0.517408076074),vec2(-1.02777591502,0.49098509683)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.02777591502,0.49098509683),vec2(-0.878719280217,0.49098509683)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.878719280217,0.49098509683),vec2(-0.878719280217,0.517408076074)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.878719280217,0.517408076074),vec2(-1.02777591502,0.517408076074)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.878719280217,0.612530790742),vec2(-0.910271441312,0.612530790742)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.878719280217,0.380474889663),vec2(-0.878719280217,0.612530790742)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.910271441312,0.380474889663),vec2(-0.878719280217,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.910271441312,0.612530790742),vec2(-0.910271441312,0.380474889663)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.99622380698,0.612530790742),vec2(-1.02777591502,0.612530790742)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.02777591502,0.612530790742),vec2(-1.02777591502,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.02777591502,0.380474889663),vec2(-0.99622380698,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.99622380698,0.380474889663),vec2(-0.99622380698,0.612530790742)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.761603341502,0.46735985073)),vec2(0.0768597661097,0.0913924126519)+vec2(border))))
	{
		p0=vec2(-0.808620691485,0.459743827395);
		p1=vec2(-0.808620691485,0.431300264576);
		p2=vec2(-0.793814279668,0.415796146544);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.793814279668,0.415796146544);
		p1=vec2(-0.778933721187,0.400214387917);
		p2=vec2(-0.751889011678,0.400214387917);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.751889011678,0.400214387917);
		p1=vec2(-0.738211264146,0.400214387917);
		p2=vec2(-0.723290048952,0.404566422279);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.723290048952,0.404566422279);
		p1=vec2(-0.708368848019,0.408918452481);
		p2=vec2(-0.691427056381,0.417777909821);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.691427056381,0.389334347003);
		p1=vec2(-0.707747117753,0.382650919067);
		p2=vec2(-0.722979164423,0.379386874961);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.722979164423,0.379386874961);
		p1=vec2(-0.738055818316,0.375967438078);
		p2=vec2(-0.752199903337,0.375967438078);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.752199903337,0.375967438078);
		p1=vec2(-0.792766914549,0.375967438078);
		p2=vec2(-0.81561501108,0.400214387917);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.81561501108,0.400214387917);
		p1=vec2(-0.838463107611,0.424616783587);
		p2=vec2(-0.838463107611,0.467359824203);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.838463107611,0.467359824203);
		p1=vec2(-0.838463107611,0.50901490317);
		p2=vec2(-0.816081295516,0.533883583276);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.816081295516,0.533883583276);
		p1=vec2(-0.793699483421,0.558752263381);
		p2=vec2(-0.756396463263,0.558752263381);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.756396463263,0.558752263381);
		p1=vec2(-0.723134610253,0.558752263381);
		p2=vec2(-0.704016789211,0.536215005457);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.704016789211,0.536215005457);
		p1=vec2(-0.684743575392,0.513677747532);
		p2=vec2(-0.684743575392,0.474665035458);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.71334258404,0.483058208362);
		p1=vec2(-0.713964261253,0.508237727074);
		p2=vec2(-0.725227459928,0.521365164695);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.725227459928,0.521365164695);
		p1=vec2(-0.736501519178,0.534505260488);
		p2=vec2(-0.757639923794,0.534505260488);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.757639923794,0.534505260488);
		p1=vec2(-0.778311990922,0.534505260488);
		p2=vec2(-0.791678886587,0.520827499998);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.791678886587,0.520827499998);
		p1=vec2(-0.805045808772,0.507149712372);
		p2=vec2(-0.807532676782,0.482902762532);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.691427056381,0.389334347003),vec2(-0.691427056381,0.417777909821)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.722979164423,0.379386874961),vec2(-0.691427056381,0.389334347003)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.752199903337,0.375967438078),vec2(-0.722979164423,0.379386874961)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.763279490969,0.380203750451),vec2(-0.752199903337,0.375967438078)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.691427056381,0.417777909821),vec2(-0.763279490969,0.380203750451)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.757835870413,0.378122366388),vec2(-0.835919877118,0.459885839628)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.835919877118,0.459885839628),vec2(-0.81561501108,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.81561501108,0.400214387917),vec2(-0.757835870413,0.378122366388)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.691427056381,0.389334347003),vec2(-0.691427056381,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.722979164423,0.379386874961),vec2(-0.691427056381,0.389334347003)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.752199903337,0.375967438078),vec2(-0.722979164423,0.379386874961)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.81561501108,0.400214387917),vec2(-0.752199903337,0.375967438078)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.691427056381,0.400214387917),vec2(-0.81561501108,0.400214387917)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.756396463263,0.558752263381),vec2(-0.814589270206,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.814589270206,0.534505260488),vec2(-0.703481414777,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.703481414777,0.534505260488),vec2(-0.704016789211,0.536215005457)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.704016789211,0.536215005457),vec2(-0.756396463263,0.558752263381)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.816081295516,0.533883583276),vec2(-0.835592138563,0.475892987311)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.835592138563,0.475892987311),vec2(-0.755143094745,0.558212979966)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.755143094745,0.558212979966),vec2(-0.756396463263,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.756396463263,0.558752263381),vec2(-0.816081295516,0.533883583276)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.704016789211,0.536215005457),vec2(-0.71476924014,0.540841432869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.684743575392,0.474665035458),vec2(-0.704016789211,0.536215005457)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.684743575392,0.460676396267),vec2(-0.684743575392,0.474665035458)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.712789981637,0.460676396267),vec2(-0.684743575392,0.460676396267)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.71476924014,0.540841432869),vec2(-0.712789981637,0.460676396267)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.687385153512,0.48310104699),vec2(-0.833247989478,0.482860323482)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.684743575392,0.474665035458),vec2(-0.687385153512,0.48310104699)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.684743575392,0.460676396267),vec2(-0.684743575392,0.474665035458)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.836188885936,0.460676396267),vec2(-0.684743575392,0.460676396267)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.838463107611,0.467359824203),vec2(-0.836188885936,0.460676396267)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.833247989478,0.482860323482),vec2(-0.838463107611,0.467359824203)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.691427056381,0.413859823435),vec2(-0.782120238418,0.387407564724)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.691427056381,0.389334347003),vec2(-0.691427056381,0.413859823435)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.722979164423,0.379386874961),vec2(-0.691427056381,0.389334347003)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.752199903337,0.375967438078),vec2(-0.722979164423,0.379386874961)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.782120238418,0.387407564724),vec2(-0.752199903337,0.375967438078)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.684743575392,0.474180551849),vec2(-0.684743575392,0.474665035458)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.757065872962,0.558473342673),vec2(-0.684743575392,0.474180551849)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.756396463263,0.558752263381),vec2(-0.757065872962,0.558473342673)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.704016789211,0.536215005457),vec2(-0.756396463263,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.684743575392,0.474665035458),vec2(-0.704016789211,0.536215005457)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.808620691485,0.536992168289),vec2(-0.816081295516,0.533883583276)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.816081295516,0.533883583276),vec2(-0.838463107611,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.838463107611,0.467359824203),vec2(-0.81561501108,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.81561501108,0.400214387917),vec2(-0.808620691485,0.397540089593)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.808620691485,0.397540089593),vec2(-0.808620691485,0.536992168289)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.801688807884,0.539880453122),vec2(-0.816081295516,0.533883583276)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.816081295516,0.533883583276),vec2(-0.838463107611,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.838463107611,0.467359824203),vec2(-0.815921239196,0.401114323736)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.815921239196,0.401114323736),vec2(-0.801688807884,0.539880453122)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.573300825879,0.502253699266)),vec2(0.0679225858546,0.121778809603)+vec2(border))))
	{
		p0=vec2(-0.566772764193,0.443579158799);
		p1=vec2(-0.566772764193,0.424305944981);
		p2=vec2(-0.559727394949,0.414550787843);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.559727394949,0.414550787843);
		p1=vec2(-0.552628732225,0.404721839502);
		p2=vec2(-0.538795538864,0.404721839502);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.541593245481,0.380474889663);
		p1=vec2(-0.567239048629,0.380474889663);
		p2=vec2(-0.58138313365,0.396950396864);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.58138313365,0.396950396864);
		p1=vec2(-0.595371772841,0.413425904066);
		p2=vec2(-0.595371772841,0.443579158799);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.641223411734,0.624032508869),vec2(-0.641223411734,0.601650696774)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.641223411734,0.601650696774),vec2(-0.566772764193,0.601650696774)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.566772764193,0.601650696774),vec2(-0.566772764193,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.566772764193,0.624032508869),vec2(-0.641223411734,0.624032508869)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.58371456821,0.404721839502),vec2(-0.58138313365,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.58138313365,0.396950396864),vec2(-0.541593245481,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.541593245481,0.380474889663),vec2(-0.505378240024,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.505378240024,0.380474889663),vec2(-0.505378240024,0.404721839502)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.505378240024,0.404721839502),vec2(-0.58371456821,0.404721839502)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.541593245481,0.380474889663),vec2(-0.535117100967,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.58138313365,0.396950396864),vec2(-0.541593245481,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.595371772841,0.443579158799),vec2(-0.58138313365,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.595371772841,0.463904696116),vec2(-0.595371772841,0.443579158799)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.535117100967,0.380474889663),vec2(-0.595371772841,0.463904696116)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.566772764193,0.624032508869),vec2(-0.595371772841,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.566772764193,0.390900788326),vec2(-0.566772764193,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.58138313365,0.396950396864),vec2(-0.566772764193,0.390900788326)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.595371772841,0.443579158799),vec2(-0.58138313365,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.595371772841,0.624032508869),vec2(-0.595371772841,0.443579158799)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.381811989065,0.502253699266)),vec2(0.0679225858546,0.121778809603)+vec2(border))))
	{
		p0=vec2(-0.375283927379,0.443579158799);
		p1=vec2(-0.375283927379,0.424305944981);
		p2=vec2(-0.368238558135,0.414550787843);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.368238558135,0.414550787843);
		p1=vec2(-0.361139895411,0.404721839502);
		p2=vec2(-0.34730670205,0.404721839502);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.350104408667,0.380474889663);
		p1=vec2(-0.375750211815,0.380474889663);
		p2=vec2(-0.389894296836,0.396950396864);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.389894296836,0.396950396864);
		p1=vec2(-0.403882936027,0.413425904066);
		p2=vec2(-0.403882936027,0.443579158799);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.449734574919,0.624032508869),vec2(-0.449734574919,0.601650696774)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.449734574919,0.601650696774),vec2(-0.375283927379,0.601650696774)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.375283927379,0.601650696774),vec2(-0.375283927379,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.375283927379,0.624032508869),vec2(-0.449734574919,0.624032508869)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.392225731396,0.404721839502),vec2(-0.389894296836,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.389894296836,0.396950396864),vec2(-0.350104408667,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.350104408667,0.380474889663),vec2(-0.31388940321,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.31388940321,0.380474889663),vec2(-0.31388940321,0.404721839502)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.31388940321,0.404721839502),vec2(-0.392225731396,0.404721839502)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.350104408667,0.380474889663),vec2(-0.343628264153,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.389894296836,0.396950396864),vec2(-0.350104408667,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.403882936027,0.443579158799),vec2(-0.389894296836,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.403882936027,0.463904696116),vec2(-0.403882936027,0.443579158799)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.343628264153,0.380474889663),vec2(-0.403882936027,0.463904696116)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.375283927379,0.624032508869),vec2(-0.403882936027,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.375283927379,0.390900788326),vec2(-0.375283927379,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.389894296836,0.396950396864),vec2(-0.375283927379,0.390900788326)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.403882936027,0.443579158799),vec2(-0.389894296836,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.403882936027,0.624032508869),vec2(-0.403882936027,0.443579158799)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.187292250362,0.46735985073)),vec2(0.0745283174023,0.0913924126519)+vec2(border))))
	{
		p0=vec2(-0.187369973277,0.534505260488);
		p1=vec2(-0.209130055106,0.534505260488);
		p2=vec2(-0.220320957013,0.517563501646);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.220320957013,0.517563501646);
		p1=vec2(-0.231511867202,0.500621730266);
		p2=vec2(-0.231511867202,0.467359824203);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.231511867202,0.467359824203);
		p1=vec2(-0.231511867202,0.434253417023);
		p2=vec2(-0.22028528974,0.417179652158);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.22028528974,0.417179652158);
		p1=vec2(-0.209130055106,0.400214387917);
		p2=vec2(-0.187369973277,0.400214387917);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.187369973277,0.400214387917);
		p1=vec2(-0.165454445618,0.400214387917);
		p2=vec2(-0.154299226998,0.417179627803);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.154299226998,0.417179627803);
		p1=vec2(-0.143072633523,0.434253417023);
		p2=vec2(-0.143072633523,0.467359824203);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.143072633523,0.467359824203);
		p1=vec2(-0.143072633523,0.500621730266);
		p2=vec2(-0.154263559828,0.517563526045);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.154263559828,0.517563526045);
		p1=vec2(-0.165454445618,0.534505260488);
		p2=vec2(-0.187369973277,0.534505260488);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.187369973277,0.558752263381);
		p1=vec2(-0.151154967821,0.558752263381);
		p2=vec2(-0.132037146779,0.535282436584);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.132037146779,0.535282436584);
		p1=vec2(-0.11276393296,0.511812609787);
		p2=vec2(-0.11276393296,0.467359824203);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.11276393296,0.467359824203);
		p1=vec2(-0.11276393296,0.422751645842);
		p2=vec2(-0.131881754002,0.399281819045);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.131881754002,0.399281819045);
		p1=vec2(-0.150999521991,0.375967438078);
		p2=vec2(-0.187369973277,0.375967438078);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.187369973277,0.375967438078);
		p1=vec2(-0.223584978734,0.375967438078);
		p2=vec2(-0.242702799776,0.399281819045);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.242702799776,0.399281819045);
		p1=vec2(-0.261820567765,0.422751645842);
		p2=vec2(-0.261820567765,0.467359824203);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.261820567765,0.467359824203);
		p1=vec2(-0.261820567765,0.511812609787);
		p2=vec2(-0.242702799776,0.535282436584);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.242702799776,0.535282436584);
		p1=vec2(-0.223584978734,0.558752263381);
		p2=vec2(-0.187369973277,0.558752263381);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.11525110338,0.458503082615),vec2(-0.11276393296,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.11276393296,0.467359824203),vec2(-0.132037146779,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.132037146779,0.535282436584),vec2(-0.17917470462,0.555276179687)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.17917470462,0.555276179687),vec2(-0.11525110338,0.458503082615)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.11276393296,0.467359824203),vec2(-0.115338367896,0.476432641425)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.115338367896,0.476432641425),vec2(-0.179117755228,0.37943475705)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.179117755228,0.37943475705),vec2(-0.131881754002,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.131881754002,0.399281819045),vec2(-0.11276393296,0.467359824203)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.259260672694,0.476454754152),vec2(-0.261820567765,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.261820567765,0.467359824203),vec2(-0.242702799776,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.242702799776,0.399281819045),vec2(-0.195416031419,0.379357629338)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.195416031419,0.379357629338),vec2(-0.259260672694,0.476454754152)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.261820567765,0.467359824203),vec2(-0.259333402187,0.458503075283)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.259333402187,0.458503075283),vec2(-0.19534929164,0.555367776599)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.19534929164,0.555367776599),vec2(-0.242702799776,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.242702799776,0.535282436584),vec2(-0.261820567765,0.467359824203)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.131816621087,0.534505260488),vec2(-0.132037146779,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.132037146779,0.535282436584),vec2(-0.187369973277,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.187369973277,0.558752263381),vec2(-0.242702799776,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.242702799776,0.535282436584),vec2(-0.242921546843,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.242921546843,0.534505260488),vec2(-0.131816621087,0.534505260488)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.242964685172,0.400214387917),vec2(-0.242702799776,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.242702799776,0.399281819045),vec2(-0.187369973277,0.375967438078)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.187369973277,0.375967438078),vec2(-0.131881754002,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.131881754002,0.399281819045),vec2(-0.131619867879,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.131619867879,0.400214387917),vec2(-0.242964685172,0.400214387917)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.242702799776,0.399281819045),vec2(-0.231511867202,0.394566540938)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.261820567765,0.467359824203),vec2(-0.242702799776,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.242702799776,0.535282436584),vec2(-0.261820567765,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.231511867202,0.540029153241),vec2(-0.242702799776,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.231511867202,0.394566540938),vec2(-0.231511867202,0.540029153241)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.132037146779,0.535282436584),vec2(-0.143072633523,0.539963219745)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.11276393296,0.467359824203),vec2(-0.132037146779,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.131881754002,0.399281819045),vec2(-0.11276393296,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.143072633523,0.394579768197),vec2(-0.131881754002,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.143072633523,0.539963219745),vec2(-0.143072633523,0.394579768197)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.19568539674,0.496502840202)),vec2(0.095822141322,0.11602795054)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.134524014789,0.380474889663),vec2(0.157862354317,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.0998632554177,0.612530790742),vec2(0.134524014789,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.13048284764,0.612530790742),vec2(0.0998632554177,0.612530790742)));
		d1=abs_min(d1,line_dist(uv,vec2(0.157862354317,0.380474889663),vec2(0.13048284764,0.612530790742)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.17913219315,0.548804791339),vec2(0.143451291834,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.202545421239,0.548804791339),vec2(0.17913219315,0.548804791339)));
		d1=abs_min(d1,line_dist(uv,vec2(0.164210985086,0.380474889663),vec2(0.202545421239,0.548804791339)));
		d1=abs_min(d1,line_dist(uv,vec2(0.143451291834,0.380474889663),vec2(0.164210985086,0.380474889663)));

		if(d1<=0.)
		{
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.260887998892,0.612530790742),vec2(0.233553530349,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.291507538062,0.612530790742),vec2(0.260887998892,0.612530790742)));
		d1=abs_min(d1,line_dist(uv,vec2(0.256846831743,0.380474889663),vec2(0.291507538062,0.612530790742)));
		d1=abs_min(d1,line_dist(uv,vec2(0.233553530349,0.380474889663),vec2(0.256846831743,0.380474889663)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.227159808393,0.380474889663),vec2(0.247938614523,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.188635642378,0.548804791339),vec2(0.227159808393,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.211927761723,0.548804791339),vec2(0.188635642378,0.548804791339)));
		d1=abs_min(d1,line_dist(uv,vec2(0.247938614523,0.380474889663),vec2(0.211927761723,0.548804791339)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.387174260081,0.46735985073)),vec2(0.0745283174023,0.0913924126519)+vec2(border))))
	{
		p0=vec2(0.387096537166,0.534505260488);
		p1=vec2(0.365336455336,0.534505260488);
		p2=vec2(0.35414555343,0.517563501646);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.35414555343,0.517563501646);
		p1=vec2(0.342954643241,0.500621730266);
		p2=vec2(0.342954643241,0.467359824203);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.342954643241,0.467359824203);
		p1=vec2(0.342954643241,0.434253417023);
		p2=vec2(0.354181220703,0.417179652158);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.354181220703,0.417179652158);
		p1=vec2(0.365336455336,0.400214387917);
		p2=vec2(0.387096537166,0.400214387917);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.387096537166,0.400214387917);
		p1=vec2(0.409012064825,0.400214387917);
		p2=vec2(0.420167283444,0.417179627803);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.420167283444,0.417179627803);
		p1=vec2(0.43139387692,0.434253417023);
		p2=vec2(0.43139387692,0.467359824203);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.43139387692,0.467359824203);
		p1=vec2(0.43139387692,0.500621730266);
		p2=vec2(0.420202950615,0.517563526045);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.420202950615,0.517563526045);
		p1=vec2(0.409012064825,0.534505260488);
		p2=vec2(0.387096537166,0.534505260488);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.387096537166,0.558752263381);
		p1=vec2(0.423311542622,0.558752263381);
		p2=vec2(0.442429363664,0.535282436584);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.442429363664,0.535282436584);
		p1=vec2(0.461702577483,0.511812609787);
		p2=vec2(0.461702577483,0.467359824203);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.461702577483,0.467359824203);
		p1=vec2(0.461702577483,0.422751645842);
		p2=vec2(0.442584756441,0.399281819045);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.442584756441,0.399281819045);
		p1=vec2(0.423466988452,0.375967438078);
		p2=vec2(0.387096537166,0.375967438078);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.387096537166,0.375967438078);
		p1=vec2(0.350881531709,0.375967438078);
		p2=vec2(0.331763710667,0.399281819045);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.331763710667,0.399281819045);
		p1=vec2(0.312645942678,0.422751645842);
		p2=vec2(0.312645942678,0.467359824203);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.312645942678,0.467359824203);
		p1=vec2(0.312645942678,0.511812609787);
		p2=vec2(0.331763710667,0.535282436584);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.331763710667,0.535282436584);
		p1=vec2(0.350881531709,0.558752263381);
		p2=vec2(0.387096537166,0.558752263381);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.459215407063,0.458503082615),vec2(0.461702577483,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(0.461702577483,0.467359824203),vec2(0.442429363664,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(0.442429363664,0.535282436584),vec2(0.395291805823,0.555276179687)));
		d1=abs_min(d1,line_dist(uv,vec2(0.395291805823,0.555276179687),vec2(0.459215407063,0.458503082615)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.461702577483,0.467359824203),vec2(0.459128142547,0.476432641425)));
		d1=abs_min(d1,line_dist(uv,vec2(0.459128142547,0.476432641425),vec2(0.395348755215,0.37943475705)));
		d1=abs_min(d1,line_dist(uv,vec2(0.395348755215,0.37943475705),vec2(0.442584756441,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(0.442584756441,0.399281819045),vec2(0.461702577483,0.467359824203)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.315205837749,0.476454754152),vec2(0.312645942678,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(0.312645942678,0.467359824203),vec2(0.331763710667,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(0.331763710667,0.399281819045),vec2(0.379050479023,0.379357629338)));
		d1=abs_min(d1,line_dist(uv,vec2(0.379050479023,0.379357629338),vec2(0.315205837749,0.476454754152)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.312645942678,0.467359824203),vec2(0.315133108255,0.458503075283)));
		d1=abs_min(d1,line_dist(uv,vec2(0.315133108255,0.458503075283),vec2(0.379117218803,0.555367776599)));
		d1=abs_min(d1,line_dist(uv,vec2(0.379117218803,0.555367776599),vec2(0.331763710667,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(0.331763710667,0.535282436584),vec2(0.312645942678,0.467359824203)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.442649889356,0.534505260488),vec2(0.442429363664,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(0.442429363664,0.535282436584),vec2(0.387096537166,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(0.387096537166,0.558752263381),vec2(0.331763710667,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(0.331763710667,0.535282436584),vec2(0.331544963599,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(0.331544963599,0.534505260488),vec2(0.442649889356,0.534505260488)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.331501825271,0.400214387917),vec2(0.331763710667,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(0.331763710667,0.399281819045),vec2(0.387096537166,0.375967438078)));
		d1=abs_min(d1,line_dist(uv,vec2(0.387096537166,0.375967438078),vec2(0.442584756441,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(0.442584756441,0.399281819045),vec2(0.442846642563,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(0.442846642563,0.400214387917),vec2(0.331501825271,0.400214387917)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.331763710667,0.399281819045),vec2(0.342954643241,0.394566540938)));
		d1=abs_min(d1,line_dist(uv,vec2(0.312645942678,0.467359824203),vec2(0.331763710667,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(0.331763710667,0.535282436584),vec2(0.312645942678,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(0.342954643241,0.540029153241),vec2(0.331763710667,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(0.342954643241,0.394566540938),vec2(0.342954643241,0.540029153241)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.442429363664,0.535282436584),vec2(0.43139387692,0.539963219745)));
		d1=abs_min(d1,line_dist(uv,vec2(0.461702577483,0.467359824203),vec2(0.442429363664,0.535282436584)));
		d1=abs_min(d1,line_dist(uv,vec2(0.442584756441,0.399281819045),vec2(0.461702577483,0.467359824203)));
		d1=abs_min(d1,line_dist(uv,vec2(0.43139387692,0.394579768197),vec2(0.442584756441,0.399281819045)));
		d1=abs_min(d1,line_dist(uv,vec2(0.43139387692,0.539963219745),vec2(0.43139387692,0.394579768197)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.60073401733,0.469613576522)),vec2(0.0616276929133,0.0891386868594)+vec2(border))))
	{
		p0=vec2(0.662361710244,0.518651483553);
		p1=vec2(0.653191414297,0.525801248978);
		p2=vec2(0.643710234855,0.529065263747);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.643710234855,0.529065263747);
		p1=vec2(0.634229039085,0.532329284137);
		p2=vec2(0.622882713734,0.532329284137);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.622882713734,0.532329284137);
		p1=vec2(0.596148895884,0.532329284137);
		p2=vec2(0.582004823934,0.515542927316);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.582004823934,0.515542927316);
		p1=vec2(0.567860725842,0.498756539468);
		p2=vec2(0.567860725842,0.467048985597);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.567860725842,0.520516674351);
		p1=vec2(0.575010491267,0.539012712073);
		p2=vec2(0.589776253501,0.548804791339);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.589776253501,0.548804791339);
		p1=vec2(0.604697461564,0.558752263381);
		p2=vec2(0.625058690085,0.558752263381);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.625058690085,0.558752263381);
		p1=vec2(0.635627892393,0.558752263381);
		p2=vec2(0.644798241393,0.556109949541);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.644798241393,0.556109949541);
		p1=vec2(0.65396853734,0.553467635701);
		p2=vec2(0.662361710244,0.547872222467);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.662361710244,0.518651483553),vec2(0.662361710244,0.547872222467)));
		d1=abs_min(d1,line_dist(uv,vec2(0.662361710244,0.547872222467),vec2(0.644798241393,0.556109949541)));
		d1=abs_min(d1,line_dist(uv,vec2(0.644798241393,0.556109949541),vec2(0.625058690085,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(0.625058690085,0.558752263381),vec2(0.614681098411,0.555826422282)));
		d1=abs_min(d1,line_dist(uv,vec2(0.614681098411,0.555826422282),vec2(0.662361710244,0.518651483553)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.539106324417,0.380474889663),vec2(0.567860725842,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.567860725842,0.380474889663),vec2(0.567860725842,0.554555650403)));
		d1=abs_min(d1,line_dist(uv,vec2(0.567860725842,0.554555650403),vec2(0.539106324417,0.554555650403)));
		d1=abs_min(d1,line_dist(uv,vec2(0.539106324417,0.554555650403),vec2(0.539106324417,0.380474889663)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.539106324417,0.483401078317),vec2(0.539106324417,0.464630465716)));
		d1=abs_min(d1,line_dist(uv,vec2(0.589776253501,0.548804791339),vec2(0.539106324417,0.483401078317)));
		d1=abs_min(d1,line_dist(uv,vec2(0.6163419869,0.556294690446),vec2(0.589776253501,0.548804791339)));
		d1=abs_min(d1,line_dist(uv,vec2(0.539106324417,0.464630465716),vec2(0.6163419869,0.556294690446)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.589059404087,0.547879496708),vec2(0.662361710244,0.522644259746)));
		d1=abs_min(d1,line_dist(uv,vec2(0.589776253501,0.548804791339),vec2(0.589059404087,0.547879496708)));
		d1=abs_min(d1,line_dist(uv,vec2(0.625058690085,0.558752263381),vec2(0.589776253501,0.548804791339)));
		d1=abs_min(d1,line_dist(uv,vec2(0.644798241393,0.556109949541),vec2(0.625058690085,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(0.662361710244,0.547872222467),vec2(0.644798241393,0.556109949541)));
		d1=abs_min(d1,line_dist(uv,vec2(0.662361710244,0.522644259746),vec2(0.662361710244,0.547872222467)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.589776253501,0.548804791339),vec2(0.577012256734,0.532329284137)));
		d1=abs_min(d1,line_dist(uv,vec2(0.625058690085,0.558752263381),vec2(0.589776253501,0.548804791339)));
		d1=abs_min(d1,line_dist(uv,vec2(0.644798241393,0.556109949541),vec2(0.625058690085,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(0.662361710244,0.547872222467),vec2(0.644798241393,0.556109949541)));
		d1=abs_min(d1,line_dist(uv,vec2(0.662361710244,0.532329284137),vec2(0.662361710244,0.547872222467)));
		d1=abs_min(d1,line_dist(uv,vec2(0.577012256734,0.532329284137),vec2(0.662361710244,0.532329284137)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.767121031821,0.502253699266)),vec2(0.0679225858546,0.121778809603)+vec2(border))))
	{
		p0=vec2(0.773649093507,0.443579158799);
		p1=vec2(0.773649093507,0.424305944981);
		p2=vec2(0.78069446275,0.414550787843);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.78069446275,0.414550787843);
		p1=vec2(0.787793125474,0.404721839502);
		p2=vec2(0.801626318836,0.404721839502);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.798828612219,0.380474889663);
		p1=vec2(0.773182809071,0.380474889663);
		p2=vec2(0.75903872405,0.396950396864);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.75903872405,0.396950396864);
		p1=vec2(0.745050084859,0.413425904066);
		p2=vec2(0.745050084859,0.443579158799);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.699198445966,0.624032508869),vec2(0.699198445966,0.601650696774)));
		d1=abs_min(d1,line_dist(uv,vec2(0.699198445966,0.601650696774),vec2(0.773649093507,0.601650696774)));
		d1=abs_min(d1,line_dist(uv,vec2(0.773649093507,0.601650696774),vec2(0.773649093507,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(0.773649093507,0.624032508869),vec2(0.699198445966,0.624032508869)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.75670728949,0.404721839502),vec2(0.75903872405,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(0.75903872405,0.396950396864),vec2(0.798828612219,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.798828612219,0.380474889663),vec2(0.835043617675,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.835043617675,0.380474889663),vec2(0.835043617675,0.404721839502)));
		d1=abs_min(d1,line_dist(uv,vec2(0.835043617675,0.404721839502),vec2(0.75670728949,0.404721839502)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.798828612219,0.380474889663),vec2(0.805304756733,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.75903872405,0.396950396864),vec2(0.798828612219,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(0.745050084859,0.443579158799),vec2(0.75903872405,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(0.745050084859,0.463904696116),vec2(0.745050084859,0.443579158799)));
		d1=abs_min(d1,line_dist(uv,vec2(0.805304756733,0.380474889663),vec2(0.745050084859,0.463904696116)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.773649093507,0.624032508869),vec2(0.745050084859,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(0.773649093507,0.390900788326),vec2(0.773649093507,0.624032508869)));
		d1=abs_min(d1,line_dist(uv,vec2(0.75903872405,0.396950396864),vec2(0.773649093507,0.390900788326)));
		d1=abs_min(d1,line_dist(uv,vec2(0.745050084859,0.443579158799),vec2(0.75903872405,0.396950396864)));
		d1=abs_min(d1,line_dist(uv,vec2(0.745050084859,0.624032508869),vec2(0.745050084859,0.443579158799)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.956356169369,0.499145127516)),vec2(0.0714197456524,0.123177689438)+vec2(border))))
	{
		p0=vec2(0.999176906373,0.402390417322);
		p1=vec2(0.992027194001,0.389489792833);
		p2=vec2(0.980059138384,0.382650919067);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.980059138384,0.382650919067);
		p1=vec2(0.968246475544,0.375967438078);
		p2=vec2(0.952703590268,0.375967438078);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.952703590268,0.375967438078);
		p1=vec2(0.921151429173,0.375967438078);
		p2=vec2(0.902966230057,0.400369833747);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.902966230057,0.400369833747);
		p1=vec2(0.884936423717,0.424927675247);
		p2=vec2(0.884936423717,0.467981554469);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.884936423717,0.467981554469);
		p1=vec2(0.884936423717,0.510413756478);
		p2=vec2(0.903121622833,0.534505260488);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.903121622833,0.534505260488);
		p1=vec2(0.921306875003,0.558752263381);
		p2=vec2(0.952703590268,0.558752263381);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.952703590268,0.558752263381);
		p1=vec2(0.968401921374,0.558752263381);
		p2=vec2(0.980369976991,0.551913336563);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.980369976991,0.551913336563);
		p1=vec2(0.992338032608,0.545229908627);
		p2=vec2(0.999176906373,0.532329284137);
		if(tri_test(uv, p0, p1, p2, false))
		{
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.91508967845,0.467359824203);
		p1=vec2(0.91508967845,0.434097971193);
		p2=vec2(0.925658880758,0.417156179555);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.925658880758,0.417156179555);
		p1=vec2(0.936228083066,0.400214387917);
		p2=vec2(0.956900150194,0.400214387917);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.956900150194,0.400214387917);
		p1=vec2(0.977572270374,0.400214387917);
		p2=vec2(0.988352413879,0.417276528973);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.988352413879,0.417276528973);
		p1=vec2(0.999176906373,0.434408862853);
		p2=vec2(0.999176906373,0.467359824203);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.999176906373,0.467359824203);
		p1=vec2(0.999176906373,0.500466284436);
		p2=vec2(0.988387421998,0.51746555257);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.988387421998,0.51746555257);
		p1=vec2(0.977572270374,0.534505260488);
		p2=vec2(0.956900150194,0.534505260488);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.956900150194,0.534505260488);
		p1=vec2(0.936228083066,0.534505260488);
		p2=vec2(0.925658892671,0.517563514472);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.925658892671,0.517563514472);
		p1=vec2(0.91508967845,0.500621730266);
		p2=vec2(0.91508967845,0.467359824203);
		if(tri_test(uv, p0, p1, p2, true))
		{
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.980369976991,0.551913336563),vec2(0.952703590268,0.558752263381)));
		d1=abs_min(d1,line_dist(uv,vec2(0.997087275857,0.534505260488),vec2(0.980369976991,0.551913336563)));
		d1=abs_min(d1,line_dist(uv,vec2(0.903121622833,0.534505260488),vec2(0.997087275857,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(0.952703590268,0.558752263381),vec2(0.903121622833,0.534505260488)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.963946584847,0.555973078014),vec2(1.02777591502,0.45540739196)));
		d1=abs_min(d1,line_dist(uv,vec2(0.980369976991,0.551913336563),vec2(0.963946584847,0.555973078014)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.502548532943),vec2(0.980369976991,0.551913336563)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.45540739196),vec2(1.02777591502,0.502548532943)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.884936423717,0.467981554469),vec2(0.88786819737,0.456987411896)));
		d1=abs_min(d1,line_dist(uv,vec2(0.88786819737,0.456987411896),vec2(0.950762499914,0.557803014575)));
		d1=abs_min(d1,line_dist(uv,vec2(0.950762499914,0.557803014575),vec2(0.903121622833,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(0.903121622833,0.534505260488),vec2(0.884936423717,0.467981554469)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.96399575913,0.378726329824),vec2(0.980059138384,0.382650919067)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.479673596053),vec2(0.96399575913,0.378726329824)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.431919496324),vec2(1.02777591502,0.479673596053)));
		d1=abs_min(d1,line_dist(uv,vec2(0.980059138384,0.382650919067),vec2(1.02777591502,0.431919496324)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.95075963354,0.376921191977),vec2(0.887683066161,0.478029112008)));
		d1=abs_min(d1,line_dist(uv,vec2(0.887683066161,0.478029112008),vec2(0.884936423717,0.467981554469)));
		d1=abs_min(d1,line_dist(uv,vec2(0.884936423717,0.467981554469),vec2(0.902966230057,0.400369833747)));
		d1=abs_min(d1,line_dist(uv,vec2(0.902966230057,0.400369833747),vec2(0.95075963354,0.376921191977)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.903121622833,0.534505260488),vec2(0.884936423717,0.467981554469)));
		d1=abs_min(d1,line_dist(uv,vec2(0.91508967845,0.540357982641),vec2(0.903121622833,0.534505260488)));
		d1=abs_min(d1,line_dist(uv,vec2(0.91508967845,0.394421766071),vec2(0.91508967845,0.540357982641)));
		d1=abs_min(d1,line_dist(uv,vec2(0.902966230057,0.400369833747),vec2(0.91508967845,0.394421766071)));
		d1=abs_min(d1,line_dist(uv,vec2(0.884936423717,0.467981554469),vec2(0.902966230057,0.400369833747)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.980059138384,0.382650919067),vec2(0.997069414848,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(0.997069414848,0.400214387917),vec2(0.903283062278,0.400214387917)));
		d1=abs_min(d1,line_dist(uv,vec2(0.903283062278,0.400214387917),vec2(0.952703590268,0.375967438078)));
		d1=abs_min(d1,line_dist(uv,vec2(0.952703590268,0.375967438078),vec2(0.980059138384,0.382650919067)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.45540739196),vec2(1.02777591502,0.540194938196)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.540194938196),vec2(0.999176906373,0.547264402279)));
		d1=abs_min(d1,line_dist(uv,vec2(0.999176906373,0.547264402279),vec2(0.999176906373,0.500466284436)));
		d1=abs_min(d1,line_dist(uv,vec2(0.999176906373,0.500466284436),vec2(1.02777591502,0.45540739196)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.999176906373,0.380474889663),vec2(1.02777591502,0.380474889663)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.380474889663),vec2(1.02777591502,0.622322816954)));
		d1=abs_min(d1,line_dist(uv,vec2(1.02777591502,0.622322816954),vec2(0.999176906373,0.622322816954)));
		d1=abs_min(d1,line_dist(uv,vec2(0.999176906373,0.622322816954),vec2(0.999176906373,0.380474889663)));

		if(d1<=0.)
		{
			return d1;
		}
		else
		{
			poly_d=min(d1,poly_d);
		}
	}

	d=min(poly_d,d);

	return d;
}

float render_serif(vec2 uv)
{
	uv.y-=.5;
	uv*=1.8;
	border*=1.8;
	uv.y+=.5;

	uv.x+=.1;

	float d = 1e38;
	float poly_d = 1e38;
	float d1 = 1e38;

	vec2 p0,p1,p2;

	if(all(lessThan(abs(uv-vec2(-1.29705090246,0.49556210191)),vec2(0.203622751405,0.194877434267)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.50067365386,0.690439536177),vec2(-1.50067365386,0.662506649919)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.34847869375,0.690439536177),vec2(-1.50067365386,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.34847869375,0.662506649919),vec2(-1.34847869375,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.50067365386,0.662506649919),vec2(-1.34847869375,0.662506649919)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.50067365386,0.328356479174),vec2(-1.50067365386,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.50067365386,0.300684667642),vec2(-1.34847869375,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.34847869375,0.300684667642),vec2(-1.34847869375,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.34847869375,0.328356479174),vec2(-1.50067365386,0.328356479174)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.24562309793,0.328356479174),vec2(-1.24562309793,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.09342815105,0.328356479174),vec2(-1.24562309793,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.09342815105,0.300684667642),vec2(-1.09342815105,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.24562309793,0.300684667642),vec2(-1.09342815105,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.24562309793,0.690439536177),vec2(-1.24562309793,0.662506649919)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.09342815105,0.690439536177),vec2(-1.24562309793,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.09342815105,0.662506649919),vec2(-1.09342815105,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.24562309793,0.662506649919),vec2(-1.09342815105,0.662506649919)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.45107323965,0.300684667642),vec2(-1.39807911127,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.39807911127,0.300684667642),vec2(-1.39807911127,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.39807911127,0.690439536177),vec2(-1.45107323965,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.45107323965,0.690439536177),vec2(-1.45107323965,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.45107323965,0.527802348895),vec2(-1.45107323965,0.495953672637)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.45107323965,0.495953672637),vec2(-1.14302855203,0.495953672637)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.14302855203,0.495953672637),vec2(-1.14302855203,0.527802348895)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.14302855203,0.527802348895),vec2(-1.45107323965,0.527802348895)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.19602268041,0.300684667642),vec2(-1.14302855203,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.14302855203,0.300684667642),vec2(-1.14302855203,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.14302855203,0.690439536177),vec2(-1.19602268041,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.19602268041,0.690439536177),vec2(-1.19602268041,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.905207605282,0.43943531671)),vec2(0.131571631799,0.146321237064)+vec2(border))))
	{
		p0=vec2(-0.980652472562,0.432256320122);p1=vec2(-0.980652472562,0.376129514241);p2=vec2(-0.959444621888,0.347459653556);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.959444621888,0.347459653556);p1=vec2(-0.938361593128,0.318958533541);p2=vec2(-0.897114929876,0.318958533541);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.897114929876,0.318958533541);p1=vec2(-0.865527286983,0.318958533541);p2=vec2(-0.845437632053,0.335419078254);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.845437632053,0.335419078254);p1=vec2(-0.825063806547,0.352112459345);p2=vec2(-0.81697111046,0.384744318419);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.778334987661,0.384744318419);p1=vec2(-0.789821407019,0.339059715715);p2=vec2(-0.82088690046,0.316086918361);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.82088690046,0.316086918361);p1=vec2(-0.851691401898,0.293114079646);p2=vec2(-0.902074977419,0.293114079646);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.902074977419,0.293114079646);p1=vec2(-0.962900714754,0.293114079646);p2=vec2(-0.999970513281,0.333055493352);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.999970513281,0.333055493352);p1=vec2(-1.03677923708,0.373257899062);p2=vec2(-1.03677923708,0.439565833392);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-1.03677923708,0.439565833392);p1=vec2(-1.03677923708,0.505351659632);p2=vec2(-1.00049262137,0.545554106703);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-1.00049262137,0.545554106703);p1=vec2(-0.964206005662,0.585756553774);p2=vec2(-0.905207625963,0.585756553774);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.905207625963,0.585756553774);p1=vec2(-0.842293414903,0.585756553774);p2=vec2(-0.808617339647,0.546859356249);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.808617339647,0.546859356249);p1=vec2(-0.774941264391,0.508223274812);p2=vec2(-0.773635973483,0.434344752485);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.830284887455,0.462016564017);p1=vec2(-0.831851211727,0.510572740539);p2=vec2(-0.850763015272,0.535223303252);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.850763015272,0.535223303252);p1=vec2(-0.869704151709,0.559912099879);p2=vec2(-0.905207625963,0.559912099879);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.905207625963,0.559912099879);p1=vec2(-0.938361593128,0.559912099879);p2=vec2(-0.957418587479,0.535111893535);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.957418587479,0.535111893535);p1=vec2(-0.976475566475,0.510311707175);p2=vec2(-0.980652472562,0.462016564017);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.966462321887,0.559912099879),vec2(-0.841030169481,0.559912099879)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.905207625963,0.585756553774),vec2(-0.966462321887,0.559912099879)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.841030169481,0.559912099879),vec2(-0.905207625963,0.585756553774)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.82088690046,0.316086918361),vec2(-0.81910715467,0.318958533541)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.81910715467,0.318958533541),vec2(-0.965419171536,0.318958533541)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.965419171536,0.318958533541),vec2(-0.902074977419,0.293114079646)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.902074977419,0.293114079646),vec2(-0.82088690046,0.316086918361)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.773817587078,0.434928897242),vec2(-0.808617339647,0.546859356249)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.808617339647,0.546859356249),vec2(-0.882523641701,0.576621645388)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.882523641701,0.576621645388),vec2(-0.773817587078,0.434928897242)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.81697111046,0.384744318419),vec2(-0.834987634664,0.312096998846)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.834987634664,0.312096998846),vec2(-0.82088690046,0.316086918361)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.82088690046,0.316086918361),vec2(-0.778334987661,0.384744318419)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.778334987661,0.384744318419),vec2(-0.81697111046,0.384744318419)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.82088690046,0.316086918361),vec2(-0.778334987661,0.384744318419)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.778334987661,0.384744318419),vec2(-0.785237494603,0.384744318419)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.785237494603,0.384744318419),vec2(-0.894429408392,0.295277456717)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.894429408392,0.295277456717),vec2(-0.82088690046,0.316086918361)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.829392250654,0.434344752485),vec2(-0.773635973483,0.434344752485)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.833342939816,0.556816429474),vec2(-0.829392250654,0.434344752485)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.808617339647,0.546859356249),vec2(-0.833342939816,0.556816429474)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.773635973483,0.434344752485),vec2(-0.808617339647,0.546859356249)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.00049262137,0.545554106703),vec2(-1.03677923708,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03677923708,0.439565833392),vec2(-1.03493619641,0.434232780007)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03493619641,0.434232780007),vec2(-0.924880247944,0.577456322027)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.924880247944,0.577456322027),vec2(-1.00049262137,0.545554106703)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.033868039,0.448069047365),vec2(-1.03677923708,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03677923708,0.439565833392),vec2(-0.999970513281,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.999970513281,0.333055493352),vec2(-0.926665359012,0.303146964146)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.926665359012,0.303146964146),vec2(-1.033868039,0.448069047365)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-1.02909290529,0.462016564017),vec2(-1.03677923708,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03677923708,0.439565833392),vec2(-1.03497489278,0.434344752485)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03497489278,0.434344752485),vec2(-0.773635973483,0.434344752485)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.773635973483,0.434344752485),vec2(-0.782239281314,0.462016564017)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.782239281314,0.462016564017),vec2(-1.02909290529,0.462016564017)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.972402534183,0.557405817862),vec2(-1.00049262137,0.545554106703)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.00049262137,0.545554106703),vec2(-1.03677923708,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03677923708,0.439565833392),vec2(-0.999970513281,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.999970513281,0.333055493352),vec2(-0.992084221177,0.329837883348)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.992084221177,0.329837883348),vec2(-0.972402534183,0.557405817862)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.980652472562,0.553925021021),vec2(-1.00049262137,0.545554106703)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.00049262137,0.545554106703),vec2(-1.03677923708,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-1.03677923708,0.439565833392),vec2(-0.999970513281,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.999970513281,0.333055493352),vec2(-0.980652472562,0.325173725818)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.980652472562,0.325173725818),vec2(-0.980652472562,0.553925021021)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.661774035854,0.503785314679)),vec2(0.0698321742834,0.203100647037)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.731606210137,0.706885961716),vec2(-0.731606210137,0.679214150184)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.63736543091,0.706885961716),vec2(-0.731606210137,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.63736543091,0.679214150184),vec2(-0.63736543091,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.731606210137,0.679214150184),vec2(-0.63736543091,0.679214150184)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.685399499342,0.300684667642),vec2(-0.63736543091,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.63736543091,0.300684667642),vec2(-0.63736543091,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.63736543091,0.706885961716),vec2(-0.685399499342,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.685399499342,0.706885961716),vec2(-0.685399499342,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.59194186157,0.300684667642),vec2(-0.59194186157,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.59194186157,0.328356479174),vec2(-0.731606210137,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.731606210137,0.328356479174),vec2(-0.731606210137,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.731606210137,0.300684667642),vec2(-0.59194186157,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.490522065075,0.503785314679)),vec2(0.0698321536026,0.203100647037)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.560354218677,0.706885961716),vec2(-0.560354218677,0.679214150184)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.46611343945,0.706885961716),vec2(-0.560354218677,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.46611343945,0.679214150184),vec2(-0.46611343945,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.560354218677,0.679214150184),vec2(-0.46611343945,0.679214150184)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.514147549244,0.300684667642),vec2(-0.46611343945,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.46611343945,0.300684667642),vec2(-0.46611343945,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.46611343945,0.706885961716),vec2(-0.514147549244,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.514147549244,0.706885961716),vec2(-0.514147549244,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.420689911472,0.300684667642),vec2(-0.420689911472,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.420689911472,0.328356479174),vec2(-0.560354218677,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.560354218677,0.328356479174),vec2(-0.560354218677,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.560354218677,0.300684667642),vec2(-0.420689911472,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(-0.243694731014,0.43943531671)),vec2(0.134182192933,0.146321237064)+vec2(border))))
	{
		p0=vec2(-0.243694731014,0.318958533541);p1=vec2(-0.205058608215,0.318958533541);p2=vec2(-0.185387356135,0.349442463204);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.185387356135,0.349442463204);p1=vec2(-0.165639343961,0.380045345603);p2=vec2(-0.165639343961,0.439565833392);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.165639343961,0.439565833392);p1=vec2(-0.165639343961,0.499086321182);p2=vec2(-0.185328022256,0.529466877781);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.185328022256,0.529466877781);p1=vec2(-0.205058608215,0.559912099879);p2=vec2(-0.243694731014,0.559912099879);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.243694731014,0.559912099879);p1=vec2(-0.282330853813,0.559912099879);p2=vec2(-0.30213864587,0.529347745141);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.30213864587,0.529347745141);p1=vec2(-0.321750118067,0.499086321182);p2=vec2(-0.321750118067,0.439565833392);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.321750118067,0.439565833392);p1=vec2(-0.321750118067,0.380045345603);p2=vec2(-0.301909945266,0.349501934475);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.301909945266,0.349501934475);p1=vec2(-0.282069779087,0.318958533541);p2=vec2(-0.243694731014,0.318958533541);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.243694731014,0.293114079646);p1=vec2(-0.304259434985,0.293114079646);p2=vec2(-0.341068158785,0.333055493352);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.341068158785,0.333055493352);p1=vec2(-0.377876923947,0.373257899062);p2=vec2(-0.377876923947,0.439565833392);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.377876923947,0.439565833392);p1=vec2(-0.377876923947,0.505873767723);p2=vec2(-0.341329233512,0.545815140068);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.341329233512,0.545815140068);p1=vec2(-0.304520509711,0.585756553774);p2=vec2(-0.243694731014,0.585756553774);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.243694731014,0.585756553774);p1=vec2(-0.182868952317,0.585756553774);p2=vec2(-0.146321261881,0.545815140068);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.146321261881,0.545815140068);p1=vec2(-0.109512538081,0.505873767723);p2=vec2(-0.109512538081,0.439565833392);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.109512538081,0.439565833392);p1=vec2(-0.109512538081,0.373257899062);p2=vec2(-0.146321261881,0.333055493352);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(-0.146321261881,0.333055493352);p1=vec2(-0.182868952317,0.293114079646);p2=vec2(-0.243694731014,0.293114079646);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.306870021126,0.559912099879),vec2(-0.180688344908,0.559912099879)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.243694731014,0.585756553774),vec2(-0.306870021126,0.559912099879)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.180688344908,0.559912099879),vec2(-0.243694731014,0.585756553774)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.306701090357,0.318958533541),vec2(-0.243694731014,0.293114079646)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.243694731014,0.293114079646),vec2(-0.180688344908,0.318958533541)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.180688344908,0.318958533541),vec2(-0.306701090357,0.318958533541)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.146321261881,0.545815140068),vec2(-0.165639343961,0.553739182574)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.109512538081,0.439565833392),vec2(-0.146321261881,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.146321261881,0.333055493352),vec2(-0.109512538081,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.165639343961,0.325131450846),vec2(-0.146321261881,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.165639343961,0.553739182574),vec2(-0.165639343961,0.325131450846)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.213882640353,0.573527996477),vec2(-0.115617533794,0.421900315486)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.115617533794,0.421900315486),vec2(-0.109512538081,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.109512538081,0.439565833392),vec2(-0.146321261881,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.146321261881,0.545815140068),vec2(-0.213882640353,0.573527996477)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.27312299534,0.305185201173),vec2(-0.371830702361,0.457143054931)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.371830702361,0.457143054931),vec2(-0.377876923947,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.377876923947,0.439565833392),vec2(-0.341068158785,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.341068158785,0.333055493352),vec2(-0.27312299534,0.305185201173)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.213831360421,0.305363671348),vec2(-0.146321261881,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.146321261881,0.333055493352),vec2(-0.109512538081,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.109512538081,0.439565833392),vec2(-0.115701961444,0.457431759541)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.115701961444,0.457431759541),vec2(-0.213831360421,0.305363671348)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.377876923947,0.439565833392),vec2(-0.37177192376,0.42190032239)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.341329233512,0.545815140068),vec2(-0.377876923947,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.273477989873,0.573572485302),vec2(-0.341329233512,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.37177192376,0.42190032239),vec2(-0.273477989873,0.573572485302)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(-0.341068158785,0.333055493352),vec2(-0.321750118067,0.325131464446)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.377876923947,0.439565833392),vec2(-0.341068158785,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.341329233512,0.545815140068),vec2(-0.377876923947,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.321750118067,0.553824783482),vec2(-0.341329233512,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(-0.321750118067,0.325131464446),vec2(-0.321750118067,0.553824783482)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.362605140277,0.49556210191)),vec2(0.272671767275,0.194877434267)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.0899333730019,0.690439536177),vec2(0.0899333730019,0.662506649919)));
		d1=abs_min(d1,line_dist(uv,vec2(0.0899333730019,0.662506649919),vec2(0.232208262022,0.662506649919)));
		d1=abs_min(d1,line_dist(uv,vec2(0.232208262022,0.662506649919),vec2(0.232208262022,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.232208262022,0.690439536177),vec2(0.0899333730019,0.690439536177)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.523023337152,0.690439536177),vec2(0.523023337152,0.662506649919)));
		d1=abs_min(d1,line_dist(uv,vec2(0.635276907552,0.690439536177),vec2(0.523023337152,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.635276907552,0.662506649919),vec2(0.635276907552,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.523023337152,0.662506649919),vec2(0.635276907552,0.662506649919)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.47094286277,0.300684667642),vec2(0.49482941753,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.466446031137,0.300684667642),vec2(0.47094286277,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.575758978969,0.690439536177),vec2(0.466446031137,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.604781916664,0.690439536177),vec2(0.575758978969,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.49482941753,0.300684667642),vec2(0.604781916664,0.690439536177)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.47094286277,0.300684667642),vec2(0.49482941753,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.49482941753,0.300684667642),vec2(0.500484415604,0.320730260499)));
		d1=abs_min(d1,line_dist(uv,vec2(0.500484415604,0.320730260499),vec2(0.395889624124,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.395889624124,0.690439536177),vec2(0.353598744691,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.353598744691,0.690439536177),vec2(0.347915299436,0.670213153114)));
		d1=abs_min(d1,line_dist(uv,vec2(0.347915299436,0.670213153114),vec2(0.452016430005,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.452016430005,0.300684667642),vec2(0.47094286277,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.383254048367,0.690439536177),vec2(0.353598744691,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.353598744691,0.690439536177),vec2(0.244080871367,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.244080871367,0.300684667642),vec2(0.273454925275,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.273454925275,0.300684667642),vec2(0.383254048367,0.690439536177)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.27956019829,0.322356606492),vec2(0.175776177625,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.175776177625,0.690439536177),vec2(0.120689438616,0.690439536177)));
		d1=abs_min(d1,line_dist(uv,vec2(0.120689438616,0.690439536177),vec2(0.23064193775,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.23064193775,0.300684667642),vec2(0.273454925275,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.273454925275,0.300684667642),vec2(0.27956019829,0.322356606492)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(0.76084411018,0.43943531671)),vec2(0.134182172253,0.146321237064)+vec2(border))))
	{
		p0=vec2(0.760844130861,0.318958533541);p1=vec2(0.799480253659,0.318958533541);p2=vec2(0.81915149358,0.34944244436);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.81915149358,0.34944244436);p1=vec2(0.838899517913,0.380045345603);p2=vec2(0.838899517913,0.439565833392);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.838899517913,0.439565833392);p1=vec2(0.838899517913,0.499086321182);p2=vec2(0.819210827385,0.529466896658);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.819210827385,0.529466896658);p1=vec2(0.799480253659,0.559912099879);p2=vec2(0.760844130861,0.559912099879);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.760844130861,0.559912099879);p1=vec2(0.722208008062,0.559912099879);p2=vec2(0.702400216004,0.529347745141);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.702400216004,0.529347745141);p1=vec2(0.682788743808,0.499086321182);p2=vec2(0.682788743808,0.439565833392);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.682788743808,0.439565833392);p1=vec2(0.682788743808,0.380045345603);p2=vec2(0.702628916609,0.349501934475);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.702628916609,0.349501934475);p1=vec2(0.722469082788,0.318958533541);p2=vec2(0.760844130861,0.318958533541);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.760844130861,0.293114079646);p1=vec2(0.700279385528,0.293114079646);p2=vec2(0.663470661728,0.333055493352);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.663470661728,0.333055493352);p1=vec2(0.626661937927,0.373257899062);p2=vec2(0.626661937927,0.439565833392);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.626661937927,0.439565833392);p1=vec2(0.626661937927,0.505873767723);p2=vec2(0.663209628363,0.545815140068);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.663209628363,0.545815140068);p1=vec2(0.700018352163,0.585756553774);p2=vec2(0.760844130861,0.585756553774);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.760844130861,0.585756553774);p1=vec2(0.821669909558,0.585756553774);p2=vec2(0.858217558632,0.545815140068);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.858217558632,0.545815140068);p1=vec2(0.895026282432,0.505873767723);p2=vec2(0.895026282432,0.439565833392);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.895026282432,0.439565833392);p1=vec2(0.895026282432,0.373257899062);p2=vec2(0.858217558632,0.333055493352);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(0.858217558632,0.333055493352);p1=vec2(0.821669909558,0.293114079646);p2=vec2(0.760844130861,0.293114079646);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.697668840749,0.559912099879),vec2(0.823850490203,0.559912099879)));
		d1=abs_min(d1,line_dist(uv,vec2(0.760844130861,0.585756553774),vec2(0.697668840749,0.559912099879)));
		d1=abs_min(d1,line_dist(uv,vec2(0.823850490203,0.559912099879),vec2(0.760844130861,0.585756553774)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.697837744754,0.318958533541),vec2(0.760844130861,0.293114079646)));
		d1=abs_min(d1,line_dist(uv,vec2(0.760844130861,0.293114079646),vec2(0.823850490203,0.318958533541)));
		d1=abs_min(d1,line_dist(uv,vec2(0.823850490203,0.318958533541),vec2(0.697837744754,0.318958533541)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.858217558632,0.545815140068),vec2(0.838899517913,0.553739168974)));
		d1=abs_min(d1,line_dist(uv,vec2(0.895026282432,0.439565833392),vec2(0.858217558632,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(0.858217558632,0.333055493352),vec2(0.895026282432,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(0.838899517913,0.325131464446),vec2(0.858217558632,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(0.838899517913,0.553739168974),vec2(0.838899517913,0.325131464446)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.790656226107,0.573527989401),vec2(0.888921301104,0.421900357111)));
		d1=abs_min(d1,line_dist(uv,vec2(0.888921301104,0.421900357111),vec2(0.895026282432,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(0.895026282432,0.439565833392),vec2(0.858217558632,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(0.858217558632,0.545815140068),vec2(0.790656226107,0.573527989401)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.731415871075,0.305185194183),vec2(0.632708159513,0.457143054931)));
		d1=abs_min(d1,line_dist(uv,vec2(0.632708159513,0.457143054931),vec2(0.626661937927,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(0.626661937927,0.439565833392),vec2(0.663470661728,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(0.663470661728,0.333055493352),vec2(0.731415871075,0.305185194183)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.79070750602,0.305363678424),vec2(0.858217558632,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(0.858217558632,0.333055493352),vec2(0.895026282432,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(0.895026282432,0.439565833392),vec2(0.888836873518,0.457431717835)));
		d1=abs_min(d1,line_dist(uv,vec2(0.888836873518,0.457431717835),vec2(0.79070750602,0.305363678424)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.626661937927,0.439565833392),vec2(0.632766933641,0.421900315486)));
		d1=abs_min(d1,line_dist(uv,vec2(0.663209628363,0.545815140068),vec2(0.626661937927,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(0.731060872001,0.573572485302),vec2(0.663209628363,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(0.632766933641,0.421900315486),vec2(0.731060872001,0.573572485302)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.663470661728,0.333055493352),vec2(0.682788743808,0.325131450846)));
		d1=abs_min(d1,line_dist(uv,vec2(0.626661937927,0.439565833392),vec2(0.663470661728,0.333055493352)));
		d1=abs_min(d1,line_dist(uv,vec2(0.663209628363,0.545815140068),vec2(0.626661937927,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(0.682788743808,0.553824783482),vec2(0.663209628363,0.545815140068)));
		d1=abs_min(d1,line_dist(uv,vec2(0.682788743808,0.325131450846),vec2(0.682788743808,0.553824783482)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(1.05909936003,0.443220610708)),vec2(0.118127317441,0.142535943066)+vec2(border))))
	{
		p0=vec2(1.14955486594,0.509267490993);p1=vec2(1.14824957503,0.529890822619);p2=vec2(1.13806844658,0.54007195107);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.13806844658,0.54007195107);p1=vec2(1.12788731813,0.55025307952);p2=vec2(1.10830820268,0.55025307952);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.10830820268,0.55025307952);p1=vec2(1.07280472843,0.55025307952);p2=vec2(1.05382955946,0.525650796486);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.05382955946,0.525650796486);p1=vec2(1.03495178845,0.501174794906);p2=vec2(1.03495178845,0.455229117476);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.03495178845,0.528846606438);p1=vec2(1.04904874826,0.557823667516);p2=vec2(1.07123840416,0.571659593963);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.07123840416,0.571659593963);p1=vec2(1.09342806006,0.585756553774);p2=vec2(1.12527673631,0.585756553774);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.12527673631,0.585756553774);p1=vec2(1.1370242304,0.585756553774);p2=vec2(1.1498158993,0.583929154776);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.1498158993,0.583929154776);p1=vec2(1.16286864293,0.582101755777);p2=vec2(1.17722667747,0.578708073868);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.09055644488,0.300684667642),vec2(1.09055644488,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(1.09055644488,0.328356479174),vec2(0.94358258304,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(0.94358258304,0.328356479174),vec2(0.94358258304,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.94358258304,0.300684667642),vec2(1.09055644488,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.03495178845,0.55077518761),vec2(1.03495178845,0.578185965778)));
		d1=abs_min(d1,line_dist(uv,vec2(1.03495178845,0.578185965778),vec2(0.940972042586,0.578185965778)));
		d1=abs_min(d1,line_dist(uv,vec2(0.940972042586,0.578185965778),vec2(0.940972042586,0.55077518761)));
		d1=abs_min(d1,line_dist(uv,vec2(0.940972042586,0.55077518761),vec2(1.03495178845,0.55077518761)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.14955486594,0.509267490993),vec2(1.17722667747,0.509267490993)));
		d1=abs_min(d1,line_dist(uv,vec2(1.17722667747,0.509267490993),vec2(1.17722667747,0.578708073868)));
		d1=abs_min(d1,line_dist(uv,vec2(1.17722667747,0.578708073868),vec2(1.1498158993,0.583929154776)));
		d1=abs_min(d1,line_dist(uv,vec2(1.1498158993,0.583929154776),vec2(1.14480576944,0.584302252517)));
		d1=abs_min(d1,line_dist(uv,vec2(1.14480576944,0.584302252517),vec2(1.14955486594,0.509267490993)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(0.986917678655,0.472173265507),vec2(0.986917678655,0.438896099705)));
		d1=abs_min(d1,line_dist(uv,vec2(0.986917678655,0.438896099705),vec2(1.09386826385,0.577563037127)));
		d1=abs_min(d1,line_dist(uv,vec2(1.09386826385,0.577563037127),vec2(1.07123840416,0.571659593963)));
		d1=abs_min(d1,line_dist(uv,vec2(1.07123840416,0.571659593963),vec2(0.986917678655,0.472173265507)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.12527673631,0.585756553774),vec2(1.09918927127,0.578951126375)));
		d1=abs_min(d1,line_dist(uv,vec2(1.09918927127,0.578951126375),vec2(1.16887290666,0.509267490993)));
		d1=abs_min(d1,line_dist(uv,vec2(1.16887290666,0.509267490993),vec2(1.17722667747,0.509267490993)));
		d1=abs_min(d1,line_dist(uv,vec2(1.17722667747,0.509267490993),vec2(1.17722667747,0.578708073868)));
		d1=abs_min(d1,line_dist(uv,vec2(1.17722667747,0.578708073868),vec2(1.1498158993,0.583929154776)));
		d1=abs_min(d1,line_dist(uv,vec2(1.1498158993,0.583929154776),vec2(1.12527673631,0.585756553774)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.03495178845,0.578185965778),vec2(0.986917678655,0.578185965778)));
		d1=abs_min(d1,line_dist(uv,vec2(0.986917678655,0.578185965778),vec2(0.986917678655,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(0.986917678655,0.300684667642),vec2(1.03495178845,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(1.03495178845,0.300684667642),vec2(1.03495178845,0.578185965778)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.07123840416,0.571659593963),vec2(1.05309507878,0.55025307952)));
		d1=abs_min(d1,line_dist(uv,vec2(1.12527673631,0.585756553774),vec2(1.07123840416,0.571659593963)));
		d1=abs_min(d1,line_dist(uv,vec2(1.1498158993,0.583929154776),vec2(1.12527673631,0.585756553774)));
		d1=abs_min(d1,line_dist(uv,vec2(1.17722667747,0.578708073868),vec2(1.1498158993,0.583929154776)));
		d1=abs_min(d1,line_dist(uv,vec2(1.17722667747,0.55025307952),vec2(1.17722667747,0.578708073868)));
		d1=abs_min(d1,line_dist(uv,vec2(1.05309507878,0.55025307952),vec2(1.17722667747,0.55025307952)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(1.26272219788,0.503785314679)),vec2(0.0698321536026,0.203100647037)+vec2(border))))
	{
		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.19289004428,0.706885961716),vec2(1.19289004428,0.679214150184)));
		d1=abs_min(d1,line_dist(uv,vec2(1.2871308235,0.706885961716),vec2(1.19289004428,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.2871308235,0.679214150184),vec2(1.2871308235,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.19289004428,0.679214150184),vec2(1.2871308235,0.679214150184)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.23909675507,0.300684667642),vec2(1.2871308235,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(1.2871308235,0.300684667642),vec2(1.2871308235,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.2871308235,0.706885961716),vec2(1.23909675507,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.23909675507,0.706885961716),vec2(1.23909675507,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.33255435148,0.300684667642),vec2(1.33255435148,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(1.33255435148,0.328356479174),vec2(1.19289004428,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(1.19289004428,0.328356479174),vec2(1.19289004428,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(1.19289004428,0.300684667642),vec2(1.33255435148,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	if(all(lessThan(abs(uv-vec2(1.52534337407,0.500000020681)),vec2(0.149975993699,0.206885941035)+vec2(border))))
	{
		p0=vec2(1.5813396219,0.344019763258);p1=vec2(1.56724266209,0.317914275998);p2=vec2(1.54531403956,0.30538368182);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.54531403956,0.30538368182);p1=vec2(1.52364649175,0.293114079646);p2=vec2(1.49153674077,0.293114079646);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.49153674077,0.293114079646);p1=vec2(1.44037002379,0.293114079646);p2=vec2(1.40773816472,0.333577601443);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.40773816472,0.333577601443);p1=vec2(1.37536738037,0.374302115243);p2=vec2(1.37536738037,0.439565833392);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.37536738037,0.439565833392);p1=vec2(1.37536738037,0.504829551541);p2=vec2(1.40773816472,0.545293031977);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.40773816472,0.545293031977);p1=vec2(1.44010894906,0.585756553774);p2=vec2(1.49153674077,0.585756553774);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.49153674077,0.585756553774);p1=vec2(1.52364649175,0.585756553774);p2=vec2(1.54531403956,0.573225918235);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.54531403956,0.573225918235);p1=vec2(1.56724266209,0.56095631606);p2=vec2(1.5813396219,0.534850828801);
		if(tri_test(uv, p0, p1, p2, false)){
			d=min(d,bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.5813396219,0.453140685113);p1=vec2(1.5813396219,0.503002152543);p2=vec2(1.56210689979,0.529430802795);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.56210689979,0.529430802795);p1=vec2(1.54296457383,0.555735235153);p2=vec2(1.50641688339,0.555735235153);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.50641688339,0.555735235153);p1=vec2(1.46934708487,0.555735235153);p2=vec2(1.45038208061,0.526437570551);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.45038208061,0.526437570551);p1=vec2(1.43149414489,0.497258963545);p2=vec2(1.43149414489,0.439565833392);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.43149414489,0.439565833392);p1=vec2(1.43149414489,0.382133777966);p2=vec2(1.45038257102,0.35269388407);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.45038257102,0.35269388407);p1=vec2(1.46934708487,0.323135398267);p2=vec2(1.50641688339,0.323135398267);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.50641688339,0.323135398267);p1=vec2(1.54296457383,0.323135398267);p2=vec2(1.56204442634,0.349224177873);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}
		p0=vec2(1.56204442634,0.349224177873);p1=vec2(1.5813396219,0.375607406151);p2=vec2(1.5813396219,0.425729948307);
		if(tri_test(uv, p0, p1, p2, true)){
			d=min(d,-bezier_sd(uv, p0, p1, p2));
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.679214150184),vec2(1.62937369034,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.706885961716),vec2(1.53591609393,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.53591609393,0.706885961716),vec2(1.53591609393,0.679214150184)));
		d1=abs_min(d1,line_dist(uv,vec2(1.53591609393,0.679214150184),vec2(1.62937369034,0.679214150184)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.436996124513),vec2(1.62937369034,0.483684086947)));
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.483684086947),vec2(1.54531403956,0.573225918235)));
		d1=abs_min(d1,line_dist(uv,vec2(1.54531403956,0.573225918235),vec2(1.52715746558,0.577456577198)));
		d1=abs_min(d1,line_dist(uv,vec2(1.52715746558,0.577456577198),vec2(1.62937369034,0.436996124513)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.37536738037,0.439565833392),vec2(1.38138790762,0.419853458425)));
		d1=abs_min(d1,line_dist(uv,vec2(1.40773816472,0.545293031977),vec2(1.37536738037,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(1.48752729393,0.583820526371),vec2(1.40773816472,0.545293031977)));
		d1=abs_min(d1,line_dist(uv,vec2(1.38138790762,0.419853458425),vec2(1.48752729393,0.583820526371)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.56173385911,0.555735235153),vec2(1.54531403956,0.573225918235)));
		d1=abs_min(d1,line_dist(uv,vec2(1.42936361199,0.555735235153),vec2(1.56173385911,0.555735235153)));
		d1=abs_min(d1,line_dist(uv,vec2(1.49153674077,0.585756553774),vec2(1.42936361199,0.555735235153)));
		d1=abs_min(d1,line_dist(uv,vec2(1.54531403956,0.573225918235),vec2(1.49153674077,0.585756553774)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.395534494148),vec2(1.62937369034,0.441286646804)));
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.441286646804),vec2(1.52691128963,0.301184987843)));
		d1=abs_min(d1,line_dist(uv,vec2(1.52691128963,0.301184987843),vec2(1.54531403956,0.30538368182)));
		d1=abs_min(d1,line_dist(uv,vec2(1.54531403956,0.30538368182),vec2(1.62937369034,0.395534494148)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.5813396219,0.300684667642),vec2(1.67531936777,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(1.67531936777,0.300684667642),vec2(1.67531936777,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(1.67531936777,0.328356479174),vec2(1.5813396219,0.328356479174)));
		d1=abs_min(d1,line_dist(uv,vec2(1.5813396219,0.328356479174),vec2(1.5813396219,0.300684667642)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.37536738037,0.439565833392),vec2(1.40773816472,0.333577601443)));
		d1=abs_min(d1,line_dist(uv,vec2(1.40773816472,0.333577601443),vec2(1.43149414489,0.322106635387)));
		d1=abs_min(d1,line_dist(uv,vec2(1.43149414489,0.322106635387),vec2(1.43149414489,0.556763998033)));
		d1=abs_min(d1,line_dist(uv,vec2(1.43149414489,0.556763998033),vec2(1.40773816472,0.545293031977)));
		d1=abs_min(d1,line_dist(uv,vec2(1.40773816472,0.545293031977),vec2(1.37536738037,0.439565833392)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.48729419162,0.295162664335),vec2(1.381595326,0.459907115119)));
		d1=abs_min(d1,line_dist(uv,vec2(1.381595326,0.459907115119),vec2(1.37536738037,0.439565833392)));
		d1=abs_min(d1,line_dist(uv,vec2(1.37536738037,0.439565833392),vec2(1.40773816472,0.333577601443)));
		d1=abs_min(d1,line_dist(uv,vec2(1.40773816472,0.333577601443),vec2(1.48729419162,0.295162664335)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.54531403956,0.30538368182),vec2(1.56186633728,0.323135398267)));
		d1=abs_min(d1,line_dist(uv,vec2(1.56186633728,0.323135398267),vec2(1.42936361199,0.323135398267)));
		d1=abs_min(d1,line_dist(uv,vec2(1.42936361199,0.323135398267),vec2(1.49153674077,0.293114079646)));
		d1=abs_min(d1,line_dist(uv,vec2(1.49153674077,0.293114079646),vec2(1.54531403956,0.30538368182)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}

		d1=1e38;
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.706885961716),vec2(1.5813396219,0.706885961716)));
		d1=abs_min(d1,line_dist(uv,vec2(1.5813396219,0.706885961716),vec2(1.5813396219,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(1.5813396219,0.300684667642),vec2(1.62937369034,0.300684667642)));
		d1=abs_min(d1,line_dist(uv,vec2(1.62937369034,0.300684667642),vec2(1.62937369034,0.706885961716)));

		if(d1<=0.){
			return d1;
		}
		else{
			poly_d=min(d1,poly_d);
		}
	}

	d=min(poly_d,d);

	return d;
}

#define DIM 1000

void pixel_write(unsigned char);
FILE *fp;

int main()
{
	fp = fopen("hello_world.ppm","wb");
	if (!fp)
	{
		return -1;
	}

	unsigned char gray;

	float scale = 0.002f;

	fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
	for(int j=0;j<DIM;j++)
	{
		for(int i=0;i<DIM;i++)
		{
			border = 2.0f/DIM;
			vec2 uv(i*scale - 1.0f, 1.5f-j*scale);
			float d = 1e38;
#if 0
			if(all(lessThan(abs(uv-vec2(-1.11022302463e-16,0.499999973473)),vec2(1.02777591502,0.124032535396)+vec2(border))))
			{
				d=min(d,render_sans(uv));
			}
#else
			if(all(lessThan(abs(uv-vec2(0.0873228569516,0.500000020681)),vec2(1.58799651081,0.206885941035)+vec2(border))))
			{
				d=min(d,render_serif(uv));
			}
#endif
			d = smoothstep(0.0f, border, d);
			if (d < 0.0f)
			{
				gray = 0;
			}
			else if (d > 1.0f)
			{
				gray = 255;
			}
			else
			{
				gray = (unsigned char)(d*255);
			}
			pixel_write(gray);
		}
	}
	fclose(fp);

	return 0;
}

void pixel_write(unsigned char gray)
{
	static unsigned char color[3];
	color[0] = gray;
	color[1] = gray;		
	color[2] = gray;
	fwrite(color, 1, 3, fp);
}