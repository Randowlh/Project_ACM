const double eps = 1e-8;

#define lt(x, y) ((x) < (y) - eps)
#define gt(x, y) ((x) > (y) + eps)
#define le(x, y) ((x) <= (y) + eps)
#define ge(x, y) ((x) >= (y) - eps)
#define eq(x, y) (le(x, y) && ge(x, y))
#define dot(x, y, z) (((y) - (x)) * ((z) - (x)))
#define cross(x, y, z) (((y) - (x)) ^ ((z) - (x)))

struct vec2 {
	double x, y;
	vec2 (double x0 = 0.0, double y0 = 0.0) : x(x0), y(y0) {}
	vec2 * read() {scanf("%lf%lf", &x, &y); return this;}
	inline vec2 operator - () const {return vec2(-x, -y);}
	inline vec2 operator + (const vec2 &B) const {return vec2(x + B.x, y + B.y);}
	inline vec2 operator - (const vec2 &B) const {return vec2(x - B.x, y - B.y);}
	inline vec2 operator * (double k) const {return vec2(x * k, y * k);}
	inline vec2 operator / (double k) const {return *this * (1.0 / k);}
	inline double operator * (const vec2 &B) const {return x * B.x + y * B.y;}
	inline double operator ^ (const vec2 &B) const {return x * B.y - y * B.x;}
	inline double norm2() const {return x * x + y * y;}
	inline double norm() const {return sqrt(x * x + y * y);}
	inline bool operator < (const vec2 &B) const {return lt(x, B.x) || le(x, B.x) && lt(y, B.y);}
	inline bool operator == (const vec2 &B) const {return eq(x, B.x) && eq(y, B.y);}
	inline bool operator << (const vec2 &B) const {return lt(y, 0) ^ lt(B.y, 0) ? lt(B.y, 0) : gt(*this ^ B, 0) || ge(*this ^ B, 0) && ge(x, 0) && lt(B.x, 0);}
	inline vec2 trans(double a11, double a12, double a21, double a22) const {return vec2(x * a11 + y * a12, x * a21 + y * a22);}
};

/*
operator * : Dot product
operator ^ : Cross product
norm2() : |v|^2 = v.v
norm() : |v| = sqrt(v.v)
operator < : Two-key compare
operator << : Polar angle compare
trans : Transition with a 2x2 matrix
*/